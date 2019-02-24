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

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
void selectionSort(int arr[], int n) 
{ 
    int i, j, min_idx; 
    for (i = 0; i < n-1; i++) 
    { 
        min_idx = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min_idx]) 
            min_idx = j; 
  
        swap(&arr[min_idx], &arr[i]); 
    } 
} 

int main() 
{ 
    FILE *fp;
   fp = fopen("O_n^2.txt","w");
   float rata2;
   
   for(size_t i = 0; i < 100; i++)
   {
        int arr_size = 1000 * (i+1);
        int* arr = array_generator(arr_size);

        clock_t t = clock();
        selectionSort(arr,arr_size);
        t = clock() - t;
        
        fprintf(fp,"%i, %f\n", (int)t, ((double)t)/CLOCKS_PER_SEC);
   }
   
   fclose(fp);

    return 0; 
} 
