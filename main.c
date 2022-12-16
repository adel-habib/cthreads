#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<time.h>


void* rollDice(){
    int value = (rand() % 6) +1;
    int* result = malloc(sizeof(int));
    *result = value;
    printf("VALUE IS: %d\n",value);
    return (void*) result;
}

int main(int argc, char* argv[]){
    srand(time(NULL));
    int *res;
    pthread_t th;
    if(pthread_create(&th,NULL,&rollDice,NULL) != 0) {
        return 1;
    }

    if(pthread_join(th,(void **) &res) != 0) {
        return 2;
    }

    printf("VAL IS: %d",*res);
    free(res);

    return 0;
}