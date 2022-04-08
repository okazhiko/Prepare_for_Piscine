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


