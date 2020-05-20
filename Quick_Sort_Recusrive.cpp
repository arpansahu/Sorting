#include<iostream>

using namespace std;

int Partition(int arr[], int start, int end)
{
    int pivot = arr[end];
    int pIndex = start;
    for (int i = start; i < end; i++)
    {
        if (arr[i] <= pivot)
        {
            swap(arr[i], arr[pIndex]);
            pIndex++;
        }
    }
    swap (arr[pIndex], arr[end]);
    return pIndex;
}
void QuickSort(int arr[],int start,int end){
    if(start >=  end ) return;
    int pivot  = Partition(arr,start,end);
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
