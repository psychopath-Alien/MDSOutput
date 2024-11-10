#include <stdlib.h>
#include <stdio.h>

int mean(int dataset[]){
    int sum = 0;
    int dataset_length = sizeof(dataset);
    for(int i = 0; i < dataset_length; i++){
        sum += i;
    }
    return sum/dataset_length;
}
int dataSorter(int dataset[], int low, int high){
    if(low < high) {
        int pi = sort_partition(dataset, low, high);
        dataSorter(dataset, low, pi - 1);
        dataSorter(dataset, pi + 1, high);
    }
}
void swapVariable(int *a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int sort_partition(int data[], int low, int high){
    int pivot = data[high];
    int i = (low - 1);

    for(int j = low; j < high; j++){
        if(data[j] < pivot){
            i++;
            swapVariable(&data[i], &data[j]);
        }
    }
    swapVariable(&data[i + 1], &data[high]);
    return (i + 1);
}


int median(int dataset[]){

    int middle = sizeof(dataset);
    int median = 0;
    
    if (middle % 2 == 0){
        median = (dataset[middle] + dataset[middle-1]) / 2;
    }else {
        median = middle + 1;
    }
    return median;
}
int mode(int dataset[]){
    int max_freq = 1, elem_freq = 1;
    int max_elem = dataset[0];

    for(int i = 1; i < sizeof(dataset); i++){
        if(dataset[i] == dataset[i - 1]){
            elem_freq++;
        }else{
            if(elem_freq > max_freq){
                max_freq = elem_freq;
                max_elem = dataset[i - 1];
            }
            elem_freq = 1;
        }
    }
    if (elem_freq> max_freq) {
        max_freq = elem_freq;
        max_elem = dataset[sizeof(dataset) - 1];
    }

    return max_elem;
}
int userImput{
     int *arr = NULL;
    int capacity = 10;
    int size  = 0;
    int input;

    arr = (int*) malloc(capacity * sizeof(int));
    if (arr == NULL){
        printf("Memory Allocation failed.\n");
        return 1;
    }
    printf("=== ENTER INTEGERS (enter -1 to stop)\n");

    while(1){
        printf("Element %d: ", size + 1);
        scanf("%d", &input);

        if(input == -1){
            break;
        }

        if(size == capacity){
            capacity *= 2;
            arr = (int*)realloc(arr, capacity*sizeof(int));
            if(arr == NULL){
                printf("Memory allocation failed.\n");
                return 1;
            }
        }
        arr[size] = input;
        size ++;
    }
    free(arr);
    return  dataSorter(arr, 0, size -1);

}

