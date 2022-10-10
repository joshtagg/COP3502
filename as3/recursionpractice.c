#include <stdio.h>
#include <stdlib.h>

int factorial(int n);

int main() {

    printf("%d", factorial(3));

    return 0;
}

factorial(int n) {
    if(n<0) {
        printf("this\n");
        return -1;
    }
    else if(n== 0) {
        printf("n = 0\n");
        return 1;
    }
    else {
        printf("something\n");
        //printf("%d\n", n * factorial(n-1));
        return n * factorial(n-1);
    }


}
