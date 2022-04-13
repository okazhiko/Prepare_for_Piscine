#include <stdio.h>
#include <stdlib.h>

int array[10] = {5, 4, 6, 1, 9, 2, 7, 3, 8, 0};

void devide(int x[], int first, int last){
    int mid = (first + last ) / 2;
    int fHalf[mid + 1], lHalf[last - mid];
    /*
    mid = 4
    fHalf[5], lHalf[5]
    */
    while(last > 0){
        printf("First Half:\n");
        for (int i = 0; i <= mid; i++){
            fHalf[i] = x[i];
            printf("%d ", fHalf[i]);
        }

        printf("\nLast Half:\n");
        for (int j = 0; j <= (last - mid-1); j++){
            lHalf[j] = x[mid + 1 + j];
            printf("%d ", lHalf[j]);
        }
        devide(fHalf, 0, mid);
        devide(lHalf, 0, last - mid - 1);
    }

}

int main(void){
    devide(array, 0, 9);
}