#include <stdio.h>

/*
typedefで int * をintPtr_tで宣伝できるようにしている。
参照：https://www.cc.kyoto-su.ac.jp/~yamada/programming/struct.html
*/

typedef int * intPtr_t;
intPtr_t foo(intPtr_t p){
    return p + 3;
}


int main(void){
    int a[10];
    intPtr_t p;

    p = foo(a);
    printf("%p", p);
}