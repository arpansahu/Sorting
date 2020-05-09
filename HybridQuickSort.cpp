#include<iostream>

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
void OptimizedQuicksort(int arr[],int start,int end){
    while(start < end){
        int pivot = Partition(arr,start,end);
        if(end - start < 10){
            insertionSort(arr,end + 1);
            break;
        }
        else{
            if(pivot - start < end - pivot ){
                OptimizedQuicksort(arr,start,pivot - 1);
                start = pivot + 1;
            }
            else{
                OptimizedQuicksort(arr,pivot + 1,end);
                end = pivot - 1;
            }
        }

    }
}
int main()
{
    int arr[] = { 3, 8, 5, 4, 1, 9, -2 };
    int size = (*(&arr + 1) - arr);

    OptimizedQuicksort(arr, 0,size - 1);

    for (int k = 0; k < (*(&arr + 1) - arr); ++k) {
        cout<<arr[k]<<" ";
    }cout<<"\n";

    return 0;
}
