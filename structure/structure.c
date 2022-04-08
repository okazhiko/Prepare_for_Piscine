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

/*サンプルプログラム1とメモリサイズ確認*/
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



