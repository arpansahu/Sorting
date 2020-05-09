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
void tailRecursiveQuicksort(int arr[],int start,int end){
    while(start < end){
        int pivot = Partition(arr,start,end);
        //recur on smaller arry
        if(pivot - start < end - pivot ){
            tailRecursiveQuicksort(arr,start,pivot - 1);
            start = pivot + 1;
        }
        else{
            tailRecursiveQuicksort(arr,pivot + 1,end);
            end = pivot - 1;
        }
    }
}
int main()
{
    int arr[] = { 3, 8, 5, 4, 1, 9, -2 };
    int size = (*(&arr + 1) - arr);

    tailRecursiveQuicksort(arr, 0,size - 1);

    for (int k = 0; k < (*(&arr + 1) - arr); ++k) {
        cout<<arr[k]<<" ";
    }cout<<"\n";

    return 0;
}
