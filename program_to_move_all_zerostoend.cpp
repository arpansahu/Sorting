#include <iostream>
using namespace std;

int main()

{
    int arr[] = { 6, 0, 8, 2, 3, 0, 4, 0, 1 };
    int size = (*(&arr + 1) - arr);
    int k = 0;

    for (int i = 0; i < size ; ++i) if(arr[i] != 0 ) arr[k++] = arr[i];
    for (int j = k; j < size; ++j) arr[j] = 0;

    for (int m = 0; m <size ; ++m) cout<<arr[m]<<" ";
    return 0;
}