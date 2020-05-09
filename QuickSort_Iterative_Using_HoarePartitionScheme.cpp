#include<iostream>
#include "stack"
using namespace std;

int Partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low - 1;
    int j = high + 1;
    while(1)
    {
        do {
            i++;
        } while (a[i] < pivot);

        do {
            j--;
        } while (a[j] > pivot);

        if(i >= j)
            return j;

        swap(a[i], a[j]);
    }
}
void QuickSort(int arr[],int size){
    stack<pair<int,int>> stack1;
    stack1.push({0,size-1});
    int start ,end;
    while(!stack1.empty()){
        start = stack1.top().first ,  end = stack1.top().second;
        stack1.pop();

        int pivot  = Partition(arr,start,end);
        if(pivot - 1 > start) stack1.push({start,pivot });
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
#include<iostream>
#include "stack"
using namespace std;

int Partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low - 1;
    int j = high + 1;
    while(1)
    {
        do {
            i++;
        } while (a[i] < pivot);

        do {
            j--;
        } while (a[j] > pivot);

        if(i >= j)
            return j;

        swap(a[i], a[j]);
    }
}
void QuickSort(int arr[],int size){
    stack<pair<int,int>> stack1;
    stack1.push({0,size-1});
    int start ,end;
    while(!stack1.empty()){
        start = stack1.top().first ,  end = stack1.top().second;
        stack1.pop();

        int pivot  = Partition(arr,start,end);
        if(pivot - 1 > start) stack1.push({start,pivot });
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
