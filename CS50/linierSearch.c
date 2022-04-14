/*
Pseudo cord
For each door from left to right
    If number is behind door
        Return true
return false


#include <stdio.h>

int door[7] = {4, 6, 2, 8, 9, 5, 1};
int request = 0;

int main(){
    for (int i = 0; i < 7; i++){
        if(door[i] == request){
            printf("True");
            break;
        }
    }
}

*/

#include <stdio.h>
#include <string.h>

int main(void){
    char *names[] = {"Bill",
                     "Charlie",
                     "Fred",
                     "George",
                     "Ginny",
                     "Percy",
                     "Ron"};

    for (int i = 0; i < 7; i++){
        if(strcmp(names[i], "Ron") == 0){
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}