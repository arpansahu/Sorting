#include <iostream>
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


void QuickSort(int a[], int low, int high)
{
    if(low >= high)return ;
    int pivot = Partition(a, low, high);
    QuickSort(a, low, pivot);
    QuickSort(a, pivot + 1, high);
}

int main()
{
    int arr[] = { 3, 8, 5, 4, 1, 9, -2 };
    int size = (*(&arr + 1) - arr);


    QuickSort(arr, 0, size - 1);

    for (int i = 0 ; i < size; i++)
        cout << arr[i] << " ";

    return 0;
}
