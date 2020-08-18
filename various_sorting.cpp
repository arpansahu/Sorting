#include <iostream>
#include <map>
#include <stack>
using namespace std;

void insertionSortRecursive(int arr[],int size,int i){
    int val = arr[i];
    int j = i;
    while(j > 0 && arr[j - 1] > val) {arr[j] = arr[j-1];   j--;}
    arr[j] = val;
    if(i + 1 < size )insertionSortRecursive(arr,size,i+1);
}

void insertionSortIterative(int arr[],int size){
    for (int i = 1; i < size; ++i) {
        int val = arr[i];
        int j = i;
        while(j > 0 && arr[j - 1] > val) {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = val;
    }
}

void selectionSortRecursive(int arr[],int size, int i){
    int min = i;
    for (int j = min + 1; j < size; ++j) {
        if(arr[j] < arr[min]) min = j;
    }
    swap(arr[min],arr[i]);
    if(i + 1 < size) selectionSortRecursive(arr,size,i + 1);
}

void selectionSortIterative(int arr[],int size){
    for (int i = 0; i < size; ++i) {
        int min = i;
        for (int j = min + 1; j < size; ++j) {
            if(arr[j] < arr[min]) min = j;
        }
        swap(arr[min],arr[i]);
    }
}

void bubbleSortRecrsively(int arr[],int size){
    for (int i = 0; i < size - 1; ++i)
        if(arr[i] > arr[i + 1])
            swap(arr[i] ,arr[i+1]);

    if(size - 1 > 1) bubbleSortRecrsively(arr,size - 1);
}

void bubbleSortIteratively(int arr[],int size){
    for (int j = 0; j < size - 1 ; ++j) {
        for (int i = 0; i <  size - 1 - j; ++i) if(arr[i] > arr[i + 1]) swap(arr[i],arr[i + 1]);
    }
}

void merge(int arr[],int aux[],int start,int mid,int end){
    int k = start, i = start , j = mid + 1;
    while(i <= mid && j <= end){
        if(arr[i] <= arr[j]) aux[k++] = arr[i++];
        else aux[k++] = arr[j++];
    }
    while(i <= mid) aux[k++] = arr[i++];
    for (int l = start; l <= end ; ++l) arr[l] = aux[l];
}
void mergeSortRecursively(int arr[],int aux[],int start,int end){
    if( start ==  end ) return;
    int mid = start + ((end - start) >> 1);
    mergeSortRecursively(arr,aux,start,mid);
    mergeSortRecursively(arr,aux,mid + 1,end);
    merge(arr,aux,start,mid,end);
}

void mergeSortIteratively(int arr[],int aux[],int start,int end){
    for (int m = 1; m < end; m = m * 2) {
        for (int i = 0; i < end; i = i + 2 * m) {
            int from = i;
            int mid = i + m - 1;
            int to = i + (2 * m)- 1;
            merge(arr,aux,from,mid,to);
        }
    }
}

int partitionLomuto(int arr[],int start,int end){
    int pivot = arr[end];
    int pIndex = start;
    for (int i = start; i < end ; ++i) {
        if(arr[i] <= pivot) swap(arr[i],arr[pIndex++]);
    }
    swap(arr[pIndex],arr[end]);
    return pIndex;
}
void quickSortLomuto(int arr[],int start,int end){
    if(start >= end) return;
    int pivot = partitionLomuto(arr,start,end);
    quickSortLomuto(arr,start,pivot - 1);
    quickSortLomuto(arr,pivot,end);
}

int partitionHoares(int arr[],int start ,int end){
    int i = start - 1,j = end + 1,pivot =  arr[start];
    while(1){
        do i++; while(arr[i] < pivot) ;
        do j--; while(arr[j] > pivot) ;
        if(i >= j) return j;
        swap(arr[i],arr[j]);
    }
}
void quickSortHoares(int arr[],int start,int end){
    if(start >= end) return ;
    int pivot = partitionHoares(arr,start,end);
    quickSortHoares(arr,start,pivot);
    quickSortHoares(arr,pivot + 1,end);
}

int randomised(int arr[],int start,int end){
    int pivot = rand() % (end - start + 1) + start;
    swap(arr[pivot],arr[end]);
    return partitionLomuto(arr,start,end);
}
void quickSortRandomised(int arr[],int start,int end){
    if(start >=  end) return;
    int pivot = randomised(arr,start,end);
    quickSortRandomised(arr,start,pivot - 1);
    quickSortRandomised(arr,pivot,end);
}

void quickSortTailrecursive(int arr[],int start,int end){
    while(start <= end){
        int pivot = partitionLomuto(arr,start,end);
        if(pivot - start < end - pivot){
            quickSortTailrecursive(arr,start,pivot - 1);
            start =  pivot + 1;
        }
        else{
            quickSortTailrecursive(arr,pivot + 1,end);
            end = pivot - 1;
        }
    }
}

void insertionSortIterativeforHybrid(int arr[],int start,int end){
    for (int i = start; i < end; ++i) {
        int val = arr[i];
        int j = i;
        while(j > 0 && arr[j - 1] > val) {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = val;
    }
}
void quickSortHybrid(int arr[],int start,int end){
    while(start <=  end){
        int pivot = partitionLomuto(arr,start,end);
        if(end - start < 10) {
            insertionSortIterative(arr,end + 1);
            break;
        }
        else{
            if(pivot - start < end - pivot){
                quickSortTailrecursive(arr,start,pivot - 1);
                start =  pivot + 1;
            }
            else{
                quickSortTailrecursive(arr,pivot + 1,end);
                end = pivot - 1;
            }
        }
    }
}

void quickSortDutchNationalFlag(int arr[],int size){
    int start = 0,mid = 0;
    int pivot = 1;
    while(mid <= size){
        if(arr[mid] < pivot) swap(arr[start++],arr[mid++]);
        else if(arr[mid] > pivot) swap(arr[size--],arr[mid]);
        else mid++;
    }
}
void countingSort(int arr[],int size){
    map <int,int> map1;
    for (int i = 0; i < size; ++i) map1[arr[i]]++;
    int index = 0;
    for(auto i: map1){
        while(i.second--) arr[index++] = i.first;
    }
}

void quickSortIterative(int arr[],int size ){
    stack<pair<int,int>> stack1;
    stack1.push({0,size - 1});
    while(!stack1.empty()){
        int start = stack1.top().first,end = stack1.top().second;
        stack1.pop();
        int pivot = partitionLomuto(arr,start,end);
        if(pivot - 1 > start) stack1.push({start,pivot - 1});
        if(pivot  + 1< end) stack1.push({pivot + 1,end});
    }
}

class priorityQueueminHeap{
    int * arr;
    int size ;

    int LEFT(int index){
        return (2 * index + 1);
    }
    int RIGHT(int index){
        return (2 * index + 2);
    }

    void heapifyDown(int index){
        int left = LEFT(index);
        int right = RIGHT(index);
        int minimum = index;
        if(left <  size && arr[left] < arr[minimum]) minimum = left;
        if(right  <  size && arr[right] < arr[minimum]) minimum = right;
        if(minimum != index){
            swap(arr[minimum],arr[index]);
            heapifyDown(minimum);
        }
    }

public:

    priorityQueueminHeap(int arr[],int size){
        this->arr = new int [size];
        this->size = size;
        for (int i = 0; i < size; ++i) this->arr[i] = arr[i];
        int index = (size - 2) / 2;
        while(index >= 0) heapifyDown(index--);
    }
    ~priorityQueueminHeap(){
        delete [] arr;
    }
    bool empty(){
        return size == 0;
    }

    int pop(){
        try{

            if(size <= 0) throw out_of_range("heap under flow");
            int top = arr[0];
            arr[0] = arr[size-- - 1];
            heapifyDown(0);
            return top;
        }
        catch (out_of_range &err){
            cout<<err.what()<<endl;
        }
    }
};

void heapSortoutOfPlace(int arr[],int size){
    priorityQueueminHeap pq(arr,size);
    int index = 0;
    while(!pq.empty()) arr[index++] = pq.pop();
}


class priorityQueueMaxHeap{
    int LEFT(int index){
        return index * 2 + 1;
    }
    int RIGHT(int index){
        return index * 2 + 2;
    }

    void heapifyDown(int arr[],int size,int index){
        int maximum = index;
        int left = LEFT(index);
        int right = RIGHT(index);
        if(left < size && arr[maximum] < arr[left]) maximum =  left;
        if(right < size && arr[maximum] <arr[right]) maximum = right;
        if(maximum != index) {
            swap(arr[maximum],arr[index]);
            heapifyDown(arr,size,maximum);
        }
    }
public:
    priorityQueueMaxHeap(int arr[],int size){
        int index = (size - 2) / 2;
        while(index >= 0 ) heapifyDown(arr,size,index--);
    }
    int pop(int arr[],int size){
        try{
            if(size <= 0) throw out_of_range("Heap underflow");
            int top = arr[0];
            arr[0] = arr[size - 1];
            heapifyDown(arr,size - 1,0);
            return top;
        }
        catch (out_of_range & err){
            cout <<err.what()<<endl;
        }
    }
};

void heapSortInPlace(int arr[],int size){
    priorityQueueMaxHeap pq (arr,size);
    while(size > 0) {arr[size - 1] =  pq.pop(arr,size); size--;}
}


int main()
{
    int arr[] = { 3, 8, 5, 4, 1,1, 9, -2 ,-1,-3,-10,-11,-12,-13};
    int size = (*(&arr + 1) - arr);
    //insertionSortRecursive(arr,size,1);
    //insertionSortIterative(arr,size);
    //selectionSortRecursive(arr,size,0);
    //selectionSortIterative(arr,size);
    //bubbleSortRecrsively(arr,size);
    //bubbleSortIteratively(arr,size);

    int aux[size];
    for (int i = 0; i < size; ++i) aux[i] = arr[i];
    //mergeSortRecursively(arr,aux,0,size - 1);
    //mergeSortIteratively(arr,aux,0,size - 1);

    //quickSortLomuto(arr,0,size - 1);
    //quickSortHoares(arr,0,size - 1);
    //quickSortRandomised(arr,0,size-1);
    //quickSortTailrecursive(arr,0,size - 1);
    //quickSortHybrid(arr,0,size-1);
    //quickSortIterative(arr,size);

    int dqa[] = { 0, 1, 2, 2, 1, 0, 0, 2, 0, 1, 1, 0 };
    //quickSortDutchNationalFlag(dqa,(*(&dqa +  1) - dqa));
    //for (int j = 0; j < (*(&dqa +  1) - dqa); ++j) cout<<dqa[j] <<" ";cout<<"\n";

    //countingSort(arr,size);

    //heapSortoutOfPlace(arr,size);
    heapSortInPlace(arr,size);

    for (int k = 0; k < (*(&arr + 1) - arr); ++k) {
        cout<<arr[k]<<" ";
    }cout<<"\n";

    return 0;

}