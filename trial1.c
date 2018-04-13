#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[]){

    FILE *input, *output;
    char SET1[80];
    char SET2[80];
    int hash[256];
    int i = 0;
    char c = 'a';
    int delete = 1;
    int in = 1;
    int out = 1;

    if(argc < 3 || argc > 7){
        fprintf(stderr, "Usage:  tr [-d] set1 set2\n");
        return 0;
    }
    /*
    if(strcmp(argv[1], "-d")){
        delete = 0;
        strcpy(SET1, argv[2]);
        if(argc <= 5){ 
            if(strcmp(argv[3], "<")){
                input = fopen(argv[4], "r");
                in = 0;
            }
            if(strcmp(argv[3], ">")){
                output = fopen(argv[4], "w");
                out = 0;
            }
        }
        else{
            input = fopen(argv[4], "r");
            output = fopen(argv[6], "w");
            in = 0; out = 0;
        }
    }
    else{
       strcpy(SET1, argv[1]);
       strcpy(SET2, argv[2]);
       if(strcmp(argv[3], "<")){
            input = fopen(argv[4], "r");
            in = 0;
       }
       if(strcmp(argv[3], ">")){
           output = fopen(argv[4], "w");
           out = 0;
       }
       else{
           input = fopen(argv[4], "r");
           output = fopen(argv[6], "w");
           in = 0; out = 0;
       }
    }*/
    /* ask about this?*/
    if(in == 0){
        if(input == NULL){
            fprintf(stderr, "Unable to open input\n");
            return 0;
        }
    }

    if(delete == 0){
        for(i = 0; i < 256; i++){
            c = i;
            if(strstr(SET1, &c)){
                hash[i] = 1;
            }
            else{
                hash[i] = 0;
            }
        }

        if(in == 0 && out == 0){
            while((c = fgetc(input)) != EOF){
                if(hash[(unsigned)c] == 0){
                    fputc(c, output);
                }
            }
            fputc(EOF, output);
            fclose(input);
            fclose(output);
        }
        if(in == 1 && out == 0){
            while((c = getchar()) != EOF){
                if(hash[(unsigned)c] == 0){
                    fputc(c, output);
                }
            }
            fputc(EOF, output);
            fclose(output);
        }
        if(in == 0 && out == 1){
            while((c = fgetc(input)) != EOF){
                if(hash[(unsigned)c] == 0){
                    printf("%c", c);
                }
            }
            printf("\n");
            fclose(input);
        }
        if(in == 1 && out == 1){
            while((c = getchar()) != EOF){
                if(hash[(unsigned)c] == 0){
                    printf("%c", c);
                }
             }
             printf("\n");
        }
    }

    else{
        for(i = 0; i < 256; i++){
            hash[i] = i;
        }
    
        if(strlen(SET1) > strlen(SET2)){
            for(i = 0; SET1[i]; i++){
                SET1[strlen(SET2)+ i] = SET2[strlen(SET2)-1];
            }
        }

    /*add check for special // chars and change them in SET2*/
    /*modify hash table to replace original chars with those modified*/
        for(i=0; SET1[i]; i++){
            hash[(unsigned)SET1[i]] = SET2[i];
        }
    }
    /* i think i can use stdin to simplify this but i'm not sure how*/
    if(in == 0 && out == 0){
        while((c = fgetc(input)) != EOF){
            c = hash[(unsigned)c];
            fputc(c, output);
        }
        fputc(EOF, output);
        fclose(input);
        fclose(output);
    }
    if(in == 1 && out == 0){
        while((c = getchar()) != EOF){
            c = hash[(unsigned)c];
            fputc(c, output);
        }
        fputc(EOF, output);
        fclose(output);
    }
    if(in == 0 && out == 1){
        while((c = fgetc(input)) != EOF){
            c = hash[(unsigned)c];
            printf("%c", c);
        }
        printf("\n");
        fclose(input);
    }
    if(in == 1 && out == 1){
        while((c = getchar()) != EOF){
            c = hash[(unsigned)c];
            printf("%c", c);
        }
        printf("\n");
    }

return 0;
} 
