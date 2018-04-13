#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[]){

    char SET1[80];
    char SET2[80];
    int hash[256];
    int i = 0;
    int j = 0;
    char c = 'a';
    char d = 'a';
    int delete = 1;

    if(argc < 3){
        fprintf(stderr, "usage: missing operand\n");
        return 0;
    }
    if(argc > 3){
        fprintf(stderr, "usage: extra operand\n");
        return 0;
    }
    if(argv[1][0] == '-'){
        if(argv[1][1] != 'd'){
            fprintf(stderr, "usage: invalid option\n");
            return 0;
        }
        else{
            delete = 0;
            strcpy(SET1, argv[2]);
        }
    }
    else{ 
        strcpy(SET1, argv[1]);
        strcpy(SET2, argv[2]);
    }
/*
    for(i = 0; i < strlen(SET1); i++){
        c = SET1[i];
        if((SET1[i] == '\\') && (SET1[i+1] == '\n')){
            SET1[i] = '\n';
            for(j = (i + 1); j < strlen(SET1) - 1; j++){
                SET1[j] = c;
                c = SET1[j];
                SET1[j] = SET1[i];
            }

        }
        if((SET1[i] == '\\') && (SET1[i+1] == '\t')){
            SET1[i] = '\t';
            for(j = (i + 1); j < strlen(SET1) - 1; j++){
                SET1[j] = c;
                c = SET1[j];
                SET1[j] = SET1[i];
            }
        }
    }
*/
    if(delete == 0){
        for(i = 0; i < 256; i++){
            hash[i] = 0;
        }
        for(i = 0; i < strlen(SET1); i++){
            j = (unsigned) SET1[i];
            hash[j] = 1;
        }
        while((c=getchar()) != EOF){
            if(hash[(unsigned)c] == 0){
                    putchar(c);
             }
        }
    }

    else{
        if(strlen(SET1) > strlen(SET2)){
            j = strlen(SET2);
            for(i = j; i <= strlen(SET1); i++){
                SET2[i] = SET2[j-1];
            }
        }
        for(i = 0; i < 256; i++){
            hash[i] = i;
        }
        /*for(i=0; i < strlen(SET1); i++){*/
        for(i = 0; SET1[i] != '\0'; i++){
            if(SET1[i] != SET2[i]){
                j = (unsigned)SET1[i];
                hash[j] = SET2[i];
            }
            d = hash[(unsigned)c];
            putchar(d);
        }
    }

    return 0;
}
