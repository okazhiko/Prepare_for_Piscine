#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int sort[N];

void quickSort(int bottom, int top, int *data){
// *dataで渡す理由は、配列のデータはそのままでは関数の引数にできないから。先頭の要素へのポインタであらわす必要がある。
    int lower, upper, div, temp;
    if(bottom >= top){
        return;
    }

    div = data[bottom];
    for(lower = bottom, upper = top; lower < upper;){
        while(lower <= upper && data[lower] <= div){
            lower++;
        }
        while(lower <= upper && data[upper] > div){
            upper--;
        }
        if(lower < upper){
            temp = data[lower];
            data[lower] = data[upper];
            data[upper] = temp;
        }
    }

    temp = data[bottom];
    data[bottom]= data[upper];
    data[upper] = temp;

    quickSort(bottom, upper -1, data);
    quickSort(upper + 1, top, data);

}

int main(void){
    int i;

    srand((unsigned int)time(NULL));

    printf("Sort Preparing\n");
    for(i = 0; i < N; i++){
        sort[i] = rand();
        printf("%d ", sort[i]);
    }

    printf("\nSort Start\n");
    quickSort(0, N - 1, sort);
    printf("\nSort Finished\n");

    for(i = 0; i < N; i++){
        printf("%d ", sort[i]);
    }

    return 0;
}