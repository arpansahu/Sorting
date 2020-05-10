#include<iostream>
#include "map"
using namespace std;
void countSort(int arr[],int n){
    map<int,int> mapFreq;
    for (int i = 0; i < n ; ++i) mapFreq[arr[i]]++;
    int index = 0;
    for(auto i : mapFreq) {
        for (int j = 0; j < i.second ; ++j) {
            arr[index++] = i.first;
        }
    }

}
int main()
{
    int arr[] = { 3, 8, 5, 4, 1, 9, -1 };
    int size = (*(&arr + 1) - arr);

    countSort(arr,size);

    for (int k = 0; k < (*(&arr + 1) - arr); ++k) {
        cout<<arr[k]<<" ";
    }cout<<"\n";

    return 0;
}
