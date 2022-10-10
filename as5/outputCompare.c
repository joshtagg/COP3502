#include <stdio.h>
#include <string.h>

#define FILE_SIZE 10000
int main(int argc,char ** argv){
    FILE * fp1 = fopen(argv[1], "r");
    FILE * fp2 = fopen(argv[2], "r");
    
    char temp1[30];
    char temp2[30];
    for(int i = 0; i < FILE_SIZE; i++){
        fscanf(fp1, "%s", temp1);
        fscanf(fp2, "%s", temp2);
        if(strcmp(temp1, temp2) != 0){
            printf("There is a difference. Line %d\n", i + 1);
            return 0;
        }
    }
    printf("All good\n");
}