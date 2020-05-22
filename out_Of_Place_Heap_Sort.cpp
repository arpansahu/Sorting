#include <iostream>
using namespace std;
class priorityQueue{
    int * A;
    int size = 0;
    int LEFT(int index){
        return (2 * index + 1) ;
    }
    int RIGHT(int index){
        return (2 * index + 2) ;
    }

    void heapifyDown(int index){
        int smallest = index;
        int left = LEFT(index);
        int right = RIGHT(index);
        if(left <  size && A[smallest] > A[left]) smallest = left;
        if(right <  size && A[smallest] > A[right]) smallest = right;
        if(smallest != index){
            swap(A[index],A[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    priorityQueue(int arr[],int size){
        A = new int[size];
        this->size = size;
        for (int i = 0; i < size; ++i) A[i] = arr[i];
        int index = (size - 2) / 2;
        while(index >= 0) heapifyDown(index--);
    }
    ~priorityQueue(){
        delete [] A;
    }
    bool empty(){
        return size == 0;
    }

    int pop(){
        try{
        if(size  == 0) throw out_of_range("Heap Underflow");
            int data = A[0];
            A[0] = A[size-- - 1];
            heapifyDown(0);
            return data;
        }
        catch (const out_of_range & err){
            cout<<"\n"<<err.what()<<"\n";
        }
    }

};

void heapSort(int arr[],int size){
    priorityQueue pq (arr,size);
    int index = 0;
    while(!pq.empty()) arr[index++] = pq.pop();
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