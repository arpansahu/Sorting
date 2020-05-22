#include <iostream>
using namespace std;

class priorityQueue{
    int LEFT(int index){
        return index * 2 + 1;
    }
    int RIGHT(int index){
        return index * 2 + 2;
    }

    void heapifyDown(int arr[],int size,int index){
        int left = LEFT(index);
        int right = RIGHT(index);
        int maximum  = index;
        if(left <  size && arr[maximum] < arr[left]) maximum = left;
        if(right < size && arr[maximum] < arr[right]) maximum = right;
        if(maximum != index){
            swap(arr[maximum],arr[index]);
            heapifyDown(arr,size,maximum);
        }
    }
public:
    priorityQueue(int arr[],int size){
        int index = (size - 2) / 2;
        while(index >= 0) heapifyDown(arr,size,index--);
    }
    int pop(int arr[],int size){
        if( size <= 0 ) return -1;
        int top = arr[0];
        arr[0] = arr[size - 1];
        heapifyDown(arr,size- 1,0);
        return top;
    }
};

void heapSort(int arr[],int size){
    priorityQueue pq(arr,size);
    while(size > 0){
        arr[size - 1] = pq.pop(arr,size);
        size--;
    }
}
int main(){
    int arr[] = { 3, 8, 5, 4, 1,1, 9, -2 ,-1,-3,-10,-11,-12,-13};
    int size = (*(&arr + 1) - arr);
    heapSort(arr,size);
    for (int k = 0; k < (*(&arr + 1) - arr); ++k) {
        cout<<arr[k]<<" ";
    }cout<<"\n";
    return 0;
}