#include<iostream>
#include "cmath"
using namespace std;

void BubbleSort(int arr[],int size){

    int count = 0;
    for (int i = 0; i < size - 1 ; i++) {
        if (arr[i] > arr[i + 1]) {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
            count++;
        }
    }
    if(size - 1 > 1 ) BubbleSort(arr,size -  1);

}
int main()
{
    int arr[] = { 3, 8, 5, 4, 1, 9, -2 };


    BubbleSort(arr, (*(&arr + 1) - arr));

    for (int k = 0; k < (*(&arr + 1) - arr); ++k) {
        cout<<arr[k]<<" ";
    }cout<<"\n";

    return 0;
}
