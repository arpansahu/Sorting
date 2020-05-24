#include  <iostream>
using namespace std;

void partition(int arr[],int start,int end){
    int pivot = 0;
    int pIndex = start;
    for (int i = start; i <= end ; ++i) if(arr[i] < pivot) swap(arr[pIndex++],arr[i]);

}

int main(){
    int arr[] = { 9, -3, 5, -2, -8, -6, 1, 3 };
    int size = (*(&arr + 1) - arr);
    partition(arr,0,size-1);

    for (int i = 0; i < size; ++i) cout << arr[i] <<" ";

    return 0;
}