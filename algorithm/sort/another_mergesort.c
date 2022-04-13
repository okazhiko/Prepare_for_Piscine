//https://qiita.com/omu58n/items/2aa3c751cfb10cdbbb43

#include <stdio.h>

//マージソート
void merge_sort(int array[], int left, int right){      //引数は①配列、②配列の最初の添字、③配列の最後の添字
    int i, j, k, mid;  
    int work[10];                                       //作業用配列
    if(left < right){
        mid = (left + right) / 2;                       //midを配列の中央の添字として初期化
        merge_sort(array, left, mid);                   //leftからmidまでの配列でマージソート
        merge_sort(array, mid + 1, right);              //mid+1からrightまでの配列でマージソート
        for (i = mid; i >= left; i--){
            work[i] = array[i];                         //array[]の左側をwork[i]に保管
        }
        for (j = mid + 1; j <= right; j++){
            work[right - (j - (mid + 1))] = array[j];   //array[]の右側を逆にしてwork[]に保管
        }
        i = left;                                       //
        j = right;                                      //
        for (k = left; k <= right; k++){                //
            if(work[i] < work[j]){                      //work[]の最初と最後を比較し、最後が大きいのであれば
                array[k] = work[i++]; 
            }                                           //array[]の最初はwork[i + 1]となる            }
            else{
                array[k] = work[j--]; 
            }                  
        }
    }
}

int main(void){
    int array[10] = {2, 1, 8, 5, 4, 7, 9, 0, 6, 3};
    int i;

    printf("Before sort\n");
    for (i = 0; i < 10; i++){
        printf("%d ", array[i]);
    }
    printf("\n");

    merge_sort(array, 0, 9);

    printf("After sort\n");
    for (i = 0; i < 10; i++){
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}