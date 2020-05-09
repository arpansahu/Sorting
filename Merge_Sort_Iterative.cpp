#include<iostream>

using namespace std;

void Merge(int arr[],int aux[],int low,int mid ,int high){
    int k = low,i = low,j = mid + 1;
    while(i <= mid && j <= high){
        if(arr[i] <= arr[j]) aux[k++] = arr[i++];
        else aux[k++] = arr[j++];
    }
    while(i <= mid) aux[k++] = arr[i++];
    for (int l = low; l <= high ; ++l) arr[l] = aux[l];
}
void MergeSort(int arr[],int aux[],int low,int high){
    // divide the array into blocks of size m
    // m = [1, 2, 4, 8, 16...]
    for (int m = 1; m <= high - low; m = 2*m)
    {
        // for m = 1, i = 0, 2, 4, 6, 8
        // for m = 2, i = 0, 4, 8
        // for m = 4, i = 0, 8
        // ...
        for (int i = low; i < high; i += 2*m)
        {
            int from = i;
            int mid = i + m - 1;
            int to = min(i + 2*m - 1, high);

            Merge(arr, aux, from, mid, to);
        }
    }
}
int main()
{
    int arr[] = { 3, 8, 5, 4, 1, 9, -2 };
    int size = (*(&arr + 1) - arr);
    int aux[size] ;
    for (int i = 0; i < size; ++i) aux[i] = arr[i];

    MergeSort(arr, aux,0,size - 1);


    for (int k = 0; k < (*(&arr + 1) - arr); ++k) {
        cout<<arr[k]<<" ";
    }cout<<"\n";

    return 0;
}
