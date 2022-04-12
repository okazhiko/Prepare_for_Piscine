//http://www1.cts.ne.jp/~clab/hsample/Sort/Sort9.html

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Qsort(int x[], int left, int right);
void Swap(int x[], int i, int j);
void ShowData(int x[], int n);
void main(void);

void Qsort(int x[], int left, int right){
    int i, j;
    int pivot;

    i = left;       
    j = right;

    pivot = x[(left + right) / 2];

    while(1){
        while(x[i] < pivot){
            i++;
        }
        while(x[j] > pivot){
            j--;
        }
        if(i >= j){
            break;
        }

        Swap(x, i, j);
        i++;
        j--;
    }
    ShowData(x, 10);

    if (left < i -1 ){
        Qsort(x, left, i - 1);
    }
    if(j + 1 < right){
        Qsort(x, j + 1, right);
    }
}

void Swap(int x[], int i, int j){
    int temp;

    temp = x[i];
    x[i] = x[j];
    x[j] = temp;
}

void ShowData(int x[], int n){
    int i;

    for (i = 0; i < n; i++){
        printf("%d ", x[i]);
    }
    printf("\n");
}

void main(void){
    int x[] = {6, 3, 1, 7, 0, 4, 8, 5, 9, 2};
    int n = 10;

    printf("Before:\n");
    ShowData(x, n);

    printf("Processing...\n");
    Qsort(x, 0, n - 1);

    printf("After:\n");
    ShowData(x, n);
}
