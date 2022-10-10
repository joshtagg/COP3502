#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define stringSize 20

int main()
{
    int n = 4;
    char **arr = malloc(n * sizeof(char*));

    for(int j = 0;j<n;j++)
    {
        arr[j] = malloc(stringSize+1); // remember to free this after recursion
    }
    for(int i=0;i<n;i++)
    {
        scanf("%s",arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        printf("%c\n",arr[i][strlen(arr[i])-1]);
        // printf("%c\n",*arr[i]);
    }
    return 0;
}
