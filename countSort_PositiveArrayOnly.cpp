#include<iostream>
#include "string.h"
using namespace std;
void countSort(int arr[],int n,int k){
    int freq[k];
    memset(freq,0,sizeof freq);
    for(int i = 0; i < n ; i ++) freq[arr[i]]++;
    int index = 0;
    for (int j = 0; j < k; ++j) while(freq[j]--) arr[index++] = j;
}
int main()
{
    int arr[] = { 3, 8, 5, 4, 1, 9, 5 };
    int size = (*(&arr + 1) - arr);

    countSort(arr, size,10);

    for (int k = 0; k < (*(&arr + 1) - arr); ++k) {
        cout<<arr[k]<<" ";
    }cout<<"\n";

    return 0;
}
