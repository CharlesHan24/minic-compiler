#include "riscv_translate.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define BUFFER_LEN 1000
#define IS_TIGGER_OPTIMIZE

const char helper_reg[5] = "t3";

void tigger_readin(char* file_name, char** ret_code){
    FILE* fin;
    fin = fopen(file_name, "r");
    int tot_len = 0;
    char buffer[BUFFER_LEN];

    while (fgets(buffer, BUFFER_LEN, fin) != NULL){
        tot_len += strlen(buffer);
    }
    char* code = calloc(tot_len + 5, 1);
    *ret_code = code;
    
    fclose(fin);
    fin = fopen(file_name, "r");

    while (fgets(buffer, BUFFER_LEN, fin) != NULL){
        strcat(code, buffer);
        code += strlen(buffer);
    }
    strcat(code, "\n");
    fclose(fin);
}


static void process_arithmetic(FILE* fout, char* reg1, char* reg2, char* op, char* reg3){
    if (is_digit(reg3[0])){
        int tmp = atoi(reg3);
        if ((op[0] == '+') || (op[0] == '<')){
            if ((tmp >= -2048) && (tmp <= 2047)){
                if (op[0] == '+'){
                    fprintf(fout, "addi ");
                }
                else{
                    fprintf(fout, "slti ");
                }
                fprintf(fout, "%s, %s, %s\n", reg1, reg2, reg3);
                return;
            }
        }
        else{
            fprintf(fout, "li t4, %s\n", reg3);
            sprintf(reg3, "t4");
        }
    }
    if (strlen(op) == 1){
        switch (op[0]){
            case '+':{
                fprintf(fout, "add ");
                break;
            }
            case '-':{
                fprintf(fout, "sub ");
                break;
            }
            case '*':{
                fprintf(fout, "mul ");
                break;
            }
            case '/':{
                fprintf(fout, "div ");
                break;
            }
            case '%':{
                fprintf(fout, "rem ");
                break;
            }
            case '<':{
                fprintf(fout, "slt ");
                break;
            }
            case '>':{
                fprintf(fout, "sgt ");
                break;
            }
        }
        fprintf(fout, "%s, %s, %s\n", reg1, reg2, reg3);
        return;
    }
    switch (op[0]){
        case '>':{
            fprintf(fout, "slt %s, %s, %s\nseqz %s, %s\n", reg1, reg2, reg3, reg1, reg1);
            break;
        }
        case '<':{
            fprintf(fout, "sgt %s, %s, %s\nseqz %s, %s\n", reg1, reg2, reg3, reg1, reg1);
            break;
        }
        case '|':{
            fprintf(fout, "or %s, %s, %s\nsnez %s, %s\n", reg1, reg2, reg3, reg1, reg1);
            break;
        }
        case '!':{
            fprintf(fout, "xor %s, %s, %s\nsnez %s, %s\n", reg1, reg2, reg3, reg1, reg1);
            break;
        }
        case '=':{
            fprintf(fout, "xor %s, %s, %s\nseqz %s, %s\n", reg1, reg2, reg3, reg1, reg1);
            break;
        }
        case '&':{
            fprintf(fout, "snez %s, %s\nseqz t3, %s\nand %s, %s, t3\n", reg1, reg2, reg3, reg1, reg1);
            break;
        }
    }
    return;
}

static void riscv_output(FILE* fout, char* code){
    char buffer[BUFFER_LEN];
    memset(buffer, 0, sizeof(buffer));
    char words[10][BUFFER_LEN];
    char* ed_line;

    int stk_val;

    while ((ed_line = strchr(code, '\n')) != NULL){
        int tmp_len = strlen(buffer);
        memset(buffer, 0, tmp_len);

        strncpy(buffer, code, ed_line - code + 1);
        buffer[ed_line - code + 1] = 0;

        int tmp_res = sscanf(buffer, "%s", words[0]);
        code = ed_line + 1;
        if (tmp_res <= 0){
            continue;
        }
        switch (words[0][0]){
            case 'l':{
                // label
                if (words[0][1] != 'o'){
                    fprintf(fout, ".%s\n", words[0]);
                }
                else{
                    // load & loadaddr
                    sscanf(buffer, "%s%s%s", words[0], words[1], words[2]);
                    if (strlen(words[0]) == 4){
                        if (is_digit(words[1][0])){
                            int tmp = atoi(words[1]);
                            if ((tmp + 512 >= 0) && (tmp + 512 < 1024)){
                                fprintf(fout, "lw %s, %d(sp)\n", words[2], atoi(words[1]) * 4);
                            }
                            else{
                                fprintf(fout, "li t3, %d\n", tmp * 4);
                                fprintf(fout, "add t3, t3, sp\n");
                                fprintf(fout, "lw %s, 0(t3)\n", words[2]);
                            }
                        }
                        else{
                            fprintf(fout, "lui %s, %%hi(%s)\n", words[2], words[1]);
                            fprintf(fout, "lw %s, %%lo(%s)(%s)\n", words[2], words[1], words[2]);
                        }
                    }
                    else{
                        if (is_digit(words[1][0])){
                            int tmp = atoi(words[1]);
                            if ((tmp + 512 >= 0) && (tmp + 512 < 1024)){
                                fprintf(fout, "addi %s, sp, %d\n", words[2], tmp * 4);
                            }
                            else{
                                fprintf(fout, "li t3, %d\n", tmp * 4);
                                fprintf(fout, "add %s, t3, sp\n", words[2]);
                            }
                        }
                        else{
                            fprintf(fout, "la %s, %s\n", words[2], words[1]);
                        }
                    }
                }
                break;
            }
            case 'g':{
                // goto 
                sscanf(buffer, "%s %s", words[0], words[1]);
                fprintf(fout, "j .%s\n", words[1]);
                break;
            }
            case 'v':{
                // v0, etc
                int cnt = sscanf(buffer, "%s %s %s %s", words[0], words[1], words[2], words[3]);
                if (cnt == 4){
                    fprintf(fout, ".comm %s, %d, 4\n", words[0], atoi(words[3]));
                }
                else{
                    fprintf(fout, ".global %s\n", words[0]);
                    fprintf(fout, ".section .sdata\n.align 2\n.type %s, @object\n.size %s, 4\n", words[0], words[0]);
                    fprintf(fout, "%s:\n.word %d\n", words[0], atoi(words[1]));
                }
                break;
            }
            case 'f':{
                // f_???
                int param_a, param_b;
                sscanf(buffer, "%s [%d] [%d]", words[0], &param_a, &param_b);
                stk_val = (param_b >> 2) * 16 + 16;
                fprintf(fout, ".text\n.align 2\n.global %s\n.type %s, @function\n%s:\n", words[0] + 2, words[0] + 2, words[0] + 2);
                
                fprintf(fout, "li t3, %d\n", -stk_val);
                fprintf(fout, "add sp, sp, t3\n");
                fprintf(fout, "li t3, %d\n", stk_val - 4);
                fprintf(fout, "add t4, t3, sp\n");
                fprintf(fout, "sw ra, 0(t4)\n");

                break;
            }
            case 'e':{
                // end
                sscanf(buffer, "%s %s", words[0], words[1]);
                fprintf(fout, ".size %s, .-%s\n", words[1] + 2, words[1] + 2);
                break;
            }
            case 'c':{
                // call
                sscanf(buffer, "%s %s", words[0], words[1]);
                if (strcmp(words[1], "f_starttime") == 0){
                    sprintf(words[1], "f__sysy_starttime");
                }
                else if (strcmp(words[1], "f_stoptime") == 0){
                    sprintf(words[1], "f__sysy_stoptime");
                }
                fprintf(fout, "call %s\n", words[1] + 2);
                break;
            }
            case 's':{
                if (words[0][1] != 't'){
                    goto riscv_arith;
                }
                sscanf(buffer, "%s%s%s", words[0], words[1], words[2]);

                int tmp = atoi(words[2]);
                if ((tmp + 512 >= 0) && (tmp + 512 < 1024)){
                    fprintf(fout, "sw %s, %d(sp)\n", words[1], atoi(words[2]) * 4);
                }
                else{
                    fprintf(fout, "li t3, %d\n", tmp * 4);
                    fprintf(fout, "add t3, t3, sp\n");
                    fprintf(fout, "sw %s, 0(t3)\n", words[1]);
                }
                break;
            }
            case 'r':{
                fprintf(fout, "li t3, %d\n", stk_val - 4);
                fprintf(fout, "add t4, t3, sp\n");
                fprintf(fout, "lw ra, 0(t4)\n");
                fprintf(fout, "li t3, %d\n", stk_val);
                fprintf(fout, "add sp, sp, t3\n");
                fprintf(fout, "ret\n");
                break;
            }
            case 'i':{
                sscanf(buffer, "%s %s %s %s %s %s", words[0], words[1], words[2], words[3], words[4], words[5]);
                if (words[2][0] == '='){
                    fprintf(fout, "beq ");
                }
                else if (words[2][0] == '!'){
                    fprintf(fout, "bne ");
                }
                else if (strcmp(words[2], ">=") == 0){
                    fprintf(fout, "bge ");
                }
                else if (strcmp(words[2], ">") == 0){
                    fprintf(fout, "bgt ");
                }
                else if (strcmp(words[2], "<=") == 0){
                    fprintf(fout, "ble ");
                }
                else{
                    fprintf(fout, "blt ");
                }
                fprintf(fout, "%s, %s, .%s\n", words[1], words[3], words[5]);
                break;
            }
            case 't':
            case 'a':{
                riscv_arith:;
                int cnt, index, idx;
                cnt = sscanf(buffer, "%c%d[%d] = %s", words[0], &idx, &index, words[1]);
                if (cnt == 4){
                    sprintf(words[0] + 1, "%d", idx);
                    fprintf(fout, "sw %s, %d(%s)\n", words[1], index, words[0]);
                    break;
                }
                cnt = sscanf(buffer, "%s = %c%d[%d]", words[0], words[1], &idx, &index);
                if (cnt == 4){
                    sprintf(words[1] + 1, "%d", idx);
                    fprintf(fout, "lw %s, %d(%s)\n", words[0], index, words[1]);
                    break;
                }
                cnt = sscanf(buffer, "%s = %s %s %s", words[0], words[1], words[2], words[3]);
                if (cnt == 2){
                    if (is_digit(words[1][0])){
                        fprintf(fout, "li %s, %s\n", words[0], words[1]);
                    }
                    else if (words[1][0] == '!'){
                        fprintf(fout, "seqz %s, %s\n", words[0], words[1] + 1);
                    }
                    else if (words[1][0] == '-'){
                        fprintf(fout, "neg %s, %s\n", words[0], words[1] + 1);
                    }
                    else{
                        fprintf(fout, "mv %s, %s\n", words[0], words[1]);
                    }
                    break;
                }

                process_arithmetic(fout, words[0], words[1], words[2], words[3]);
                break;
            }
        }
    }
}

static void tigger_optimize(FILE* fout, char* code){
    char buffer[BUFFER_LEN];
    char old_buffer[BUFFER_LEN];
    memset(buffer, 0, sizeof(buffer));
    memset(old_buffer, 0, sizeof(old_buffer));
    char words[10][BUFFER_LEN];
    char* ed_line;

    int stk_val;

    while ((ed_line = strchr(code, '\n')) != NULL){
        int tmp_len = strlen(buffer);
        memset(buffer, 0, tmp_len);
        strncpy(buffer, code, ed_line - code + 1);
        buffer[ed_line - code + 1] = 0;
        code = ed_line + 1;

        int cnt;
        int flag = 0;
        cnt = sscanf(buffer, "load %s %s", words[0], words[1]);
        if (cnt == 2){
            cnt = sscanf(old_buffer, "store %s %s", words[2], words[3]);
            if (cnt == 2){
                if (strcmp(words[3], words[0]) == 0){
                    flag = 1;
                    fprintf(fout, "%s = %s\n", words[1], words[2]);
                }
            }
        }
        if (!flag){
            fprintf(fout, "%s", buffer);
        }

        strcpy(old_buffer, buffer);
    }
}

void tigger2riscv_translate(char* fin_name, char* fout_name){
    char* code;
    tigger_readin(fin_name, &code);
    FILE* fout = fopen(fout_name, "w");

    #ifdef IS_TIGGER_OPTIMIZE
        tigger_optimize(fout, code);
        fflush(fout);
        fclose(fout);
        tigger_readin(fout_name, &code);
        fout = fopen(fout_name, "w");
    #endif

    riscv_output(fout, code);
    fflush(fout);
    fclose(fout);
}