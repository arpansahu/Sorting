#include  <iostream>
using namespace std;

int merge(int arr[],int aux[],int start,int mid,int end,int &inversionCount){

    int k = start, i = start,j = mid + 1;
    while(i <= mid && j <= end){
        if(arr[i] <= arr[j]) aux[k++] = arr[i++];
        else {
            aux[k++] = arr[j++];
            inversionCount++;
        }
    }
    while(i <= mid) aux[k++] = arr[i++];
    for (int l = start; l <=end ; ++l) arr[l] = aux[l];
}

void mergeSort(int arr[],int aux[],int start,int end,int &inversionCount){
    if(start == end) return;
    int mid = start +  ((end - start ) >> 2);
    mergeSort(arr,aux,start,mid,inversionCount);
    mergeSort(arr,aux,mid + 1,end,inversionCount);
    merge(arr,aux,start,mid,end,inversionCount);
}

int main(){
    int arr[] = { 1, 9, 6, 4, 5 };
    int size = (*(&arr + 1) - arr);
    int aux[size];
    for (int i = 0; i < size; ++i) aux[i] = arr[i];
    int inversionCount = 0;
    mergeSort(arr,aux,0,size - 1,inversionCount);
    //for (int i = 0; i < size; ++i) cout << arr[i] <<" ";
    cout <<inversionCount;
    return 0;
}