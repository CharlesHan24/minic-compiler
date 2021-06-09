#include "y.tab.h"
#include "utils.h"
#include "eeyore_parser.h"
#include "tigger_gen.h"
#include "riscv_translate.h"
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <stdint.h>

#define DEBUG_MODE

int parse_args(int argc, char* argv[], FILE** fin, FILE** fout, char** fout_name){
    int opt = 0;
    static struct option long_options[] = {
        {"src2eeyore", optional_argument, 0, 'e' },
        {"src2tigger", optional_argument, 0, 't' },
        {"oup_file", required_argument, 0, 'o'},
        {"lan_opt", optional_argument, 0, 'S'},
        {0, 0, 0, 0},
    };

    int mode = 2;

	int long_index = 0;
	while ((opt = getopt_long(argc, argv, "t:e:o:S", 
                   long_options, &long_index)) != -1) {
        switch (opt) {
			case 'e':
				*fin = fopen(optarg, "r");
                mode = 0;
				break;
            case 't':
                *fin = fopen(optarg, "r");
                mode = 1;
                break;
            case 'o':
                *fout = fopen(optarg, "w");
                *fout_name = mystrdup(optarg);
                break;
            case 'S':
                break;
			default:
				printf("Usage: ./minic2eeyore -S -e/-t testcase.c -o testcase.S\n");
				exit(0);
        }
    }
    if (mode == 2){
        *fin = fopen(argv[4], "r");
    }
    return mode;
}

int main(int argc, char* argv[]){
    FILE* inp_file;
    FILE* oup_file;
    char* fout_name;
    int mode = parse_args(argc, argv, &inp_file, &oup_file, &fout_name);

    minic2eeyore(inp_file, oup_file);
    fflush(oup_file);
    fclose(inp_file);
    fclose(oup_file);


    if (mode >= 1){
        inp_file = fopen(fout_name, "r");
        eeyore_parser(inp_file);
        fclose(inp_file);

        oup_file = fopen(fout_name, "w");
        tigger_generator(oup_file);
        fflush(oup_file);
        fclose(oup_file);

        if (mode >= 2){
            #ifdef DEBUG_MODE
                tigger2riscv_translate(fout_name, "riscv.S");
            #else
                tigger2riscv_translate(fout_name, fout_name);
            #endif
        }
    }

    return 0;
}