#include  <iostream>
#include <map>
using namespace std;

void countSort(int arr[],int end){
   map <int,int> map1;
    for (int i = 0; i < end; ++i) map1[arr[i]]++;
    int index = 0;
    for(auto i : map1) while(i.second--) arr[index++] = i.first;
}

int main(){
    int arr[] = { 4, 2, 40, 10, 10, 1, 4, 2, 1, 10, 40 };
    int size = (*(&arr + 1) - arr);
    countSort(arr,size);

    for (int i = 0; i < size; ++i) cout << arr[i] <<" ";

    return 0;
}