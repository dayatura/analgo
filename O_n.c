#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int* array_generator(int number){
    int* array = malloc(sizeof(number) * number);

    for(int i = 0; i < number; i++)
    {
        array[i] = rand() % number + 1;
    }
    
    return array;
}

float mean(int* numbers, int length){

    int sum = 0;

    for(int i=0; i<length; i++){
        sum += numbers[i];
    }

    return sum/(float)length;
}

int main() {

   FILE *fp;
   fp = fopen("O_n.txt","w");
   float rata2;
   
   for(size_t i = 0; i < 100; i++)
   {
        int arr_size = 1000 * (i+1);
        int* arr = array_generator(arr_size);

        clock_t t = clock();
        rata2 = mean(arr,arr_size);
        t = clock() - t;
        
        fprintf(fp,"%i, %f\n", (int)t, ((double)t)/CLOCKS_PER_SEC);
   }
   
   fclose(fp);

   return 0;
}