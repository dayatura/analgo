#include <stdio.h>
#include <time.h>

#include "arrayGen.h"

float mean(int* numbers, int length){

    int sum = 0;

    for(int i=0; i<length; i++){
        sum += numbers[i];
    }

    return sum/(float)length;
}

int main() {

//    int arr[] = {12, 11, 13, 5, 6, 7}; 
//    int arr_size = sizeof(arr)/sizeof(arr[0]); 
   float rata2;

   int number = 5;
   int* array = array_generator(number);
   int array_size = sizeof(array)/sizeof(array[0]);
   
   clock_t t = clock();
   rata2 = mean(array,array_size);
   t = clock() - t;
   
   printf("Time = %f ", ((double)t)/CLOCKS_PER_SEC);

   return 0;
}