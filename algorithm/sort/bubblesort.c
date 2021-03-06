#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int sort[N];

void BubbleSort(void){
    /*
    最初のバージョン
    int i, j, flag;

    do{
        flag = 0;
        for (i = 0; i < N - 1; i++){
            if(sort[i] > sort[i + 1]){
                flag = 1;
                j = sort[i];
                sort[i] = sort[i + 1];
                sort[i+ 1] = j;
            }
        }
    } while(flag == 1);
    */

    //改良版
    int i, j, flag, k;

    k = 0;
    do {
        flag = 0;
        for (i = 0; i < N -1 -k; i++){
            if(sort[i] > sort[i + 1]){
                flag = 1;
                j = sort[i];
                sort[i] = sort[i + 1];
                sort[i + 1] = j;
            }
        }
        k++;
    }while(flag == 1);
}

int main(void){
    int i;

    srand((unsigned int)time(NULL));

    printf("Sort Preparing\n");
    for (i = 0; i < N; i++){
        sort[i] = rand();
        printf("%d ", sort[i]);
    }
    printf("\nStart sorting\n...\n");
    BubbleSort();

    printf("Finished\n");
    for (i = 0; i < N; i++){
        printf("%d ", sort[i]);
    }

    return 0;
}