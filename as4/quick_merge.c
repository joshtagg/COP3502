
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArray(int * arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/*
void quick(int * arr, int n) {
    if (n <= 1) return;
    int pivot = arr[0];
    int fs = 0;
    int bs = 0;
    for (int i = 1; i < n; i++) {
        if (pivot < arr[fs+1]) {
            bs++;
            int tmp = arr[fs+1];
            arr[fs+1] = arr[n-bs];
            arr[n-bs] = tmp;
        } else {
            fs++;
        }
    }
    int tmp = arr[fs];
    arr[fs] = arr[0];
    arr[0] = tmp;
    quick(arr, fs);
    quick(arr+1+fs, bs);
}
*/

// Sort an array (arr) of size n
void merge(int * arr, int n) {
    //printArray(arr, n);
    // base case first pl0x
    if (n <= 1) {
        return;// do nothing (already sorted B) )
    }
    // recursive step
    int mid = (n / 2);
    merge(arr, mid);
    merge(arr + mid, n - mid); // arr + mid == &(arr[mid])
                               // *(arr+mid) == arr[mid]
    int * ans = calloc(n, sizeof(int));
    int fptr = 0;
    int bptr = mid;
    for (int i = 0; i < n; i++) {
        if (fptr != mid && bptr != n && arr[fptr] <= arr[bptr]) {
            ans[i] = arr[fptr];
            fptr++;
        } else if (fptr != mid && bptr != n && arr[fptr] > arr[bptr]) {
            ans[i] = arr[bptr];
            bptr++;
        } else if (fptr == mid) {
            ans[i] = arr[bptr];
            bptr++;
        } else {
            ans[i] = arr[fptr];
            fptr++;
        }
    }
    // x = y; strcpy(x, y);
    // for (int i = 0; i < n; i++) arr[i] = ans[i];
    memcpy(arr, ans, sizeof(int) * n);
    free(ans);
    //printArray(arr, n);
}
int main(int argc, char ** argv) {
    /*
    int n = 100000;
    if (argc != 1)
        n = atoi(argv[1]);
    int * arr = calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 101;
    }*/
    int n = 11;
    int arr[11] = {5, 4, 3, 9, 2, 3, 5, 8, 7, 4, 5};
    printArray(arr, n);
    merge(arr, n);
    printArray(arr, n);
    // free(arr);
    return 0;
}
/*
T(N) = 2T(N/2) + N - 1
T(1) = 0
--------------------------------
T(N) = 2T(N/2) + N - 1                      (1)
    T(N/2) = 2T(N/2/2) + N/2 - 1
T(N) = 4T(N/4) + N + N -1 -2                (2)
    T(N/4) = 2T(N/4/2) + N/4 - 1
T(N) = 8T(N/8) +N +N +N -1 -2 -4            (3)

T(N) = 16T(N/16) +N +N +N +N -1 -2 -4 -8    (4)

T(N) = 2^kT(N/2^k) +kN  -((2^k)-1)            (k)

T(N/2^k) = T(1) = 0
N/2^k = 1
N = 2^k
log_2(N) = k

T(N) = N*0 + log_2(N)N - (N-1)

T(N) is in O(Nlog(N))

















*/
