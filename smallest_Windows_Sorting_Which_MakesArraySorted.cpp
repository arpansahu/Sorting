#include  <iostream>
#include <climits>
using namespace std;

void findsubarray(int arr[],int end){

    int left = -1,right = -1;
    int max = INT_MIN,min = INT_MAX;

    for (int i = 0; i < end; ++i) {
        if(max < arr[i]) max = arr[i];    
        if(arr[i] < max)  right = i;
    }
    for (int j = end - 1; j >= 0 ; j--) {
        if(min > arr[j]) min = arr[j];
        if(arr[j] > min) left = j;
    }
    cout<< left<<"-"<<right;

}

int main(){
    int arr[] = {1, 3, 2, 7, 5, 6, 4, 8  };
    int size = (*(&arr + 1) - arr);
    findsubarray(arr,size);

    // for (int i = 0; i < size; ++i) cout << arr[i] <<" ";
    return 0;
}