#include<stdio.h>

typedef struct{
    double re;
    double im;
} complex_t;

void printComplex(complex_t c){
    printf("%f + %f i\n", c.re, c.im);
}

/*構造体型は関数の戻り値の型にできる
complex_t addComplex(complex_t a, complex_t b){
    complex_t c;

    c.re = a.re + b.re;
    c.im = a.im + b.im;

    return c;
}

int main(){
    complex_t a = {1.2, 3.4};
    complex_t b = {5.6, 7.8};
    complex_t c;

    c = addComplex(a,b);
    printComplex(c);

    return 0;
}
*/

/*ポインタ型で上記と同じことも可能*/
void addComplexPtr(complex_t * a, complex_t *b, complex_t *c){
    (*c).re = (*a).re + (*b).re;
    (*c).re = (*a).re + (*b).re;
}

int main(){
    complex_t x = {1.2, 3.4};
    complex_t y = {5.6, 7.8};
    complex_t z;

    addComplexPtr(&x, &y, &z);
    printComplex(z);

    return 0;
}