#include <stdio.h>

#define PEOPLE_NUM 5

/*
参照：https://www.cc.kyoto-su.ac.jp/~yamada/programming/struct.html
*/

typedef struct {
    char name[20];
    char sex;
    int age;
    double height;
    double weight;
} person_t;

/*構造体の配列*/
int main(){
    person_t p[PEOPLE_NUM] = {
        {"Bob", 'M', 19, 165.4, 72.5},
        {"Alice", 'F', 19, 161.7, 44.2},
        {"Tom", 'M', 20, 175.2, 66.3},
        {"Stefany", 'F', 18, 159.3, 48.5},
        {"Leonardo", 'M', 19, 172.8, 67.2}
    };
    
    int i, j;
    double height_sum, weight_sum, height_ave, weight_ave, height_sumF, height_aveF;

    height_sum = weight_sum = height_sumF = 0.0;
    j = 0;
    for(i = 0; i < PEOPLE_NUM; i++){
        height_sum += p[i].height;
        weight_sum += p[i].weight;
        if(p[i].sex == 'F'){
            height_sumF += p[i].height;
            j ++;
        }
    }

    height_ave = height_sum / PEOPLE_NUM;
    weight_ave = weight_sum / PEOPLE_NUM;
    height_aveF = height_sumF / j;

    printf("Height average: %f\n", height_ave);
    printf("Weight average: %f\n", weight_ave);
    printf("Female height average: %f\n", height_aveF);

}