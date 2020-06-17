#include <stdlib.h>
#include <stdio.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}


int *array_diff(const int *a, size_t n1, const int *b, size_t n2, size_t *z) {

    //  <----  hajime!
    size_t i = 0, j = 0, k = 0;
    int *diff = calloc(n1, sizeof(int));
 
    qsort((int *)a, n1, sizeof(int), cmpfunc);
    qsort((int *)b, n2, sizeof(int), cmpfunc);  
   
    for (i = 0 ; (i < n1 && j < n2);) {
        if (b[j] > a[i]) {
            diff[k] = a[i];
            k++; i++;
        } else if (b[j] < a[i]) {
            j++;
        } else {
            while (i < n1) {
                if (b[j] == a[i]) {
                    i++;    
                } else {
                    break;
                }
            }
            j++;
        }
    }
     
    while (i < n1) {
        diff[k] = a[i];
        k++;
        i++;
    }

    *z = k;
    printf("value of k <%d>..\n", k);
    return diff;
}

int main() {

const int arr1[] ={-4, 0, 1, 5, 7, 7, 9, 13, 16, 17, 18, 18, 24}
 
const int arr2 = {-4, -1, -1, 1, 2, 3, 8, 9, 9, 10, 10, 12, 13, 14, 15, 15, 16, 17, 18, 18, 19, 19, 24, 24}

/*
Submitted: {0, 5, 7, 7}
 
Expected:  {5, 7, 7, 0}
*/
    const int arr1[13] = {16, 2, 0, -1, 6, 7, 6, -1, 22, 1, 9, 13, 13};
    const int arr2[22] = {-2, -4, 7, 14, 18, 0 , 2, 2, 13, 23, 5, 2, 15, 9, 1, -5, 23, 14, 2, -2, 18, 13};
    
    size_t i, z;
    int *array = array_diff(arr1, 13, arr2, 22, &z);
    for (i = 0; i<z; i++) {
        printf("<%d>", array[i]);
    }
}
