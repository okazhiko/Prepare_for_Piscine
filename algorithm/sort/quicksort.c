#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int sort[N];

void quickSort(int bottom, int top, int *data){
/* 
*dataで渡す理由は、配列のデータはそのままでは関数の引数にできないから。先頭の要素へのポインタであらわす必要がある。
bottom: 配列の先頭。多くの場合0
top: 配列の一番最後。N個の配列ならN-1
なので、配列数がグローバルで規定されているので、引数にする必要はないのでは？
→再帰する時にbottom,topともに変更になるので必要。
*/
    int lower, upper, div, temp;
    //
    if(bottom >= top){
        return;
    }

    div = data[bottom];
    for(lower = bottom, upper = top; lower < upper;){
    //比較する二つの項目を初期化している。それぞれ配列の先頭と一番最後
        while(lower <= upper && data[lower] <= div){
            lower++;
        //配列の先頭（分水嶺の数字）よりもlowerが小さいもしくは同等である限り、lowerを後ろの項目にずらしていく。最初の段階ではdata[lower] = divなので、<=であることに注意。
        }
        while(lower <= upper && data[upper] > div){
            upper--;
        //上記の逆。
        }
        if(lower < upper){
            temp = data[lower];
            data[lower] = data[upper];
            data[upper] = temp;
        //上のwhile2つを行った結果、data[lower]はdivより大きく、data[upper]はdivより小さくなっているので、それを並び変える。ただし、upper <lowerになっている場合は並び替えは不要。
        }
    }

    temp = data[bottom];
    data[bottom]= data[upper];
    data[upper] = temp;
    //upperの位置にdiv（先頭の項目）をおき、代わりに先頭には

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