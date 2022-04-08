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

/*サンプルプログラム1とメモリサイズ確認
int memory_size() {
    person_t p;
    printf("[MemorySize]Name: %d\tSex: %d\tAge: %d\tHeight: %d\tWeight: %d\n", sizeof(p.name), sizeof(p.sex), sizeof(p.age), sizeof(p.height), sizeof(p.weight));
    printf("person_t: %d\n", sizeof(p));
}

int main() {
    person_t p1 = {"Tom", 'M', 20, 175.2, 66.5};
    printf("[Person1]Name: %s\tSex: %c\tAge: %d\tHeight: %f\tWeight: %f\n", p1.name, p1.sex, p1.age, p1.height, p1.weight);
    person_t p2;
    p2 = p1;
    p2.age ++;
    p2.height += 0.7;
    p2.weight -= 1.5;
    printf("[Person2]Name: %s\tSex: %c\tAge: %d\tHeight: %f\tWeight: %f\n", p2.name, p2.sex, p2.age, p2.height, p2.weight);

    memory_size();

    return 0;
}

*/

/*構造体の配列*/

/*
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
*/

/*構造体をメンバにする構造体*/

typedef struct {
    person_t boy;
    person_t girl;
    int month;
} couple_t;

int main(){
    couple_t cpl = {
        {"Tom", 'M', 20, 175.2, 66.3},
        {"Stefany", 'F', 18, 159.3, 48.5},
        8
    };

    printf("%s and %s are going together for %d months.\n", cpl.boy.name, cpl.girl.name, cpl.month);

    person_t newboy = {"Leonardo", 'M', 19, 172.8, 67.2};
    cpl.boy = newboy;
    cpl.month = 2;
    printf("%s and %s are going together for %d months.\n", cpl.boy.name, cpl.girl.name, cpl.month);

    return 0;
}
