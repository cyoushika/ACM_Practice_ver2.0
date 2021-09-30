#include<stdio.h>

int partitation(int* arr, int low, int high){
    int pivot = arr[low];
    while(low<high){
        while(low<high&&arr[high]>=pivot){
            high--;
        }
        arr[low]=arr[high];
        while(low<high&&arr[low]<=pivot){
            low++;
        }
        arr[high] = arr[low];
    }
    arr[low]=pivot;
    return low;
}

void qsort(int* A,int low,int high){
    if(low<high){
        int pivot = partitation(A,low,high);
        qsort(A,low,pivot-1);
        qsort(A,pivot+1,high);
    }
}
