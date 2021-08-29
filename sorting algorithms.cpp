#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
int i,j,temp,data;
void insertion_sort(int arr[],int n){
	for (i = 1; i < n; i++){         //This for loop for making the second element of the all comparisons as a temporary element
		temp = arr[i];
		j = i - 1;
		
		while(j >= 0 && arr[j] > temp){     //This while loop is for pushing the grater number one position forward thier position   
			arr[j + 1] = arr[j];
            j = j - 1;
		}
		arr[j+1]=temp;            //This single line is to update the value of the temporary element
	}
}

void quick_sort_swap(int *a,int*b){
	int t = *a;
    *a = *b;
    *b = t;
}

int quick_sort_pivot(int array[], int low, int high) {
  
  int pivot = array[high];
  
  int i = (low - 1);

  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {

      i++;
      
      quick_sort_swap(&array[i], &array[j]);
    }
  }

  quick_sort_swap(&array[i + 1], &array[high]);
  
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    int pi = quick_sort_pivot(array, low, high);

    quickSort(array, low, pi - 1);

    quickSort(array, pi + 1, high);
  }
  
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
	int x;
	int arr[100000];
	for (int f = 0; f < 10 ;f++) {
    arr[f] = rand()%10000;
    }
    int n = sizeof(arr) / sizeof(arr[0]); //To give the function the size of the array
    printf("Array of 100000 random number in initialized \n");
    
    clock_t begin = clock();
     insertion_sort(arr,n);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("The time that spended in insertion sort is %f seconds\n",time_spent);
    
    clock_t begin2 = clock();
	quickSort(arr, 0, n - 1);
    clock_t end2 = clock();
    double time_spent2 = (double)(end2 - begin2) / CLOCKS_PER_SEC;
    printf("The time that spended in quick sort is %f seconds\n",time_spent2);
    
	return 0;
}
