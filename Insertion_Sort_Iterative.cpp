#include<iostream>
#include "cmath"
using namespace std;

void insertionSort(int arr[],int size){
    for(int i = 1; i <= size; i ++){
        int val = arr[i];
        int j = i;
        while (j > 0 && arr[j - 1] > val){
            arr[j] = arr[j - 1];
            j--;
        }

        arr[j] = val;

    }

}
int main(void)
{
    int arr[] = { 3, 8, 5, 4, 1, 9, -2 };


    insertionSort(arr, (*(&arr + 1) - arr));

    for (int k = 0; k < (*(&arr + 1) - arr); ++k) {
        cout<<arr[k]<<" ";
    }cout<<"\n";

    return 0;
}
