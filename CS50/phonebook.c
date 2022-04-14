#include <stdio.h>
#include <string.h>

int main(void){
    typedef struct {
        char name[20];
        char number[20];
    } person;


    person p[2] = {
        {"Carter", "+1-617-495-1000"},
        {"David", "+1-949-468-2750"},
    };

    for (int i = 0; i < 2; i++){
        if(strcmp(p[i].name, "David") == 0){
            printf("Found %s\n", p[i].number);
            return 0;
        }
    }

    printf("Not found\n");
}