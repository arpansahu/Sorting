#include<iostream>
#include "cmath"
using namespace std;

void SelectionSort(int arr[],int size){
    for(int i = 0; i < size; i ++){
        int min  = i;
        for (int j = min + 1 ; j < size; ++j) {
            if(arr[j] < arr[min]) min = j;
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}
int main()
{
    int arr[] = { 3, 8, 5, 4, 1, 9, -2 };


    SelectionSort(arr, (*(&arr + 1) - arr));

    for (int k = 0; k < (*(&arr + 1) - arr); ++k) {
        cout<<arr[k]<<" ";
    }cout<<"\n";

    return 0;
}
