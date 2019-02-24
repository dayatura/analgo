#include "arrayGen.h"

int* array_generator(int number){
    int* array = malloc(sizeof(number) * number);

    for(int i = 0; i < number; i++)
    {
        array[i] = rand() % number + 1;
    }
    
    return array;
}