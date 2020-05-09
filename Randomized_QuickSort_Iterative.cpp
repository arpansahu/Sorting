#include<iostream>
#include "stack"
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
    int temp = arr[pivotIndex]; arr[pivotIndex] =  arr[end];  arr[end] = temp;
    return Partition(arr,start,end);
}

void QuickSort(int arr[],int size){
    stack<pair<int,int>> stack1;
    stack1.push({0,size-1});
    int start ,end;
    while(!stack1.empty()){
        start = stack1.top().first ,  end = stack1.top().second;
        stack1.pop();

        int pivot  = RandomizedPartition(arr,start,end);
        if(pivot - 1 > start) stack1.push({start,pivot - 1});
        if(pivot + 1 < end) stack1.push({pivot + 1, end });
    }
}
int main()
{
    int arr[] = { 3, 8, 5, 4, 1, 9, -2 };
    int size = (*(&arr + 1) - arr);

    QuickSort(arr, size );

    for (int k = 0; k < (*(&arr + 1) - arr); ++k) {
        cout<<arr[k]<<" ";
    }cout<<"\n";

    return 0;
}
