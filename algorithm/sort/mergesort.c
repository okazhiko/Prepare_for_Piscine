#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int sort[N];
int buffer[N];

void mergesort(int n, int *x){
    int i, j, k, m;
    if(n <= 1){
        return;
    }
    m = n / 2;

    //ブロックを2分割する
    mergesort(m, x);
    mergesort(n - m, x + m);

    //マージ
    for (i = 0; i < m; i++){
        buffer[i] = x[i];
    }

    j = m;
    i = k = 0;

    while(i < m && j < n){
        if(buffer[i] <= x[j]){
            x[k++] = buffer[i++];
        }
        else{
            x[k++] = x[j++];
        }
    }
    while(i , m){
        x[k++] = buffer[i++];
    }
}

int main(void){
    int i;

    srand((unsigned int)time(NULL));

    printf("Before\n");
    for (i = 0; i < N; i++){
        sort[i] = rand();
        printf("%d ", sort[i]);
    }

    printf("\nProcessing\n");
    mergesort(N, *sort);

    printf("\nFinished\n");

    for (i = 0; i < N; i++){
    printf("%d ", sort[i]);
    }

    return 0;
}