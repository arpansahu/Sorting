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
    if(high == low) return ;
    int mid = (low + ((high - low) >> 1));
    MergeSort(arr,aux,low,mid);
    MergeSort(arr,aux,mid + 1,high);
 //   cout <<"Merge of : "<<low<<"-"<<high <<" ";
    Merge(arr,aux,low,mid,high);
 //   for (int i = low; i <= high; ++i) cout <<arr[i]<<" ";cout<<"\n";
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
