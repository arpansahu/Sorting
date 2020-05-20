#include<iostream>

using namespace std;

int Partition(int a[], int start, int end)
{
    int pivot = a[end];
    int pIndex = start;

    for (int i = start; i < end; i++)
    {
        if (a[i] <= pivot)
        {
            swap(a[i], a[pIndex]);
            pIndex++;
        }
    }
    swap (a[pIndex], a[end]);
    return pIndex;
}

int RandomizedPartition(int arr[],int start ,int end ){
    int pivotIndex = rand() %  (end - start + 1) + start;
    swap(arr[end],arr[pivotIndex]);
    return Partition(arr,start,end);
}

void QuickSort(int arr[],int start,int end){
    if(start >=  end ) return;
    int pivot  = RandomizedPartition(arr,start,end);
    QuickSort(arr,start,pivot -  1);
    QuickSort(arr,pivot,end);
}
int main()
{
    int arr[] = { 3, 8, 5, 4, 1, 9, -2 };
    int size = (*(&arr + 1) - arr);

    QuickSort(arr, 0,size - 1);

    for (int k = 0; k < (*(&arr + 1) - arr); ++k) {
        cout<<arr[k]<<" ";
    }cout<<"\n";

    return 0;
}
