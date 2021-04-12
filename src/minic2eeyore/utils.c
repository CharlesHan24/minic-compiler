#include <malloc.h>
#include <stdlib.h>
#include <string.h>


char* mystrdup(const char* str){
    size_t len = strlen(str);
    char *x = (char *)malloc(len+1);
    if(!x){
        return NULL;
    }
    memcpy(x,str,len+1);
    return x;
}