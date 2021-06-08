#include <malloc.h>
#include <stdlib.h>
#include <string.h>

char* mystrdup(const char* str){
    if (str == NULL){
        return NULL;
    }
    size_t len = strlen(str);
    char* x = (char*)malloc(len + 1);
    if (!x){
        return NULL;
    }
    memcpy(x, str, len + 1);
    return x;
}

int is_digit(char x){
    return ((x >= '0') && (x <= '9'));
}