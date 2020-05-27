#include <algorithm>
#include <iostream>

using namespace std;

void maximum(int arr[],int size){
    sort(arr,arr+size);
    int a,b;
    if  ((arr[0] * arr[1]) >  (arr[size - 1] * arr[size - 2])){ a = arr[0]; b = arr[1];}
    else {a = arr[size - 1] ; b =  arr[size - 2];}
    cout <<"Pair is ("<<a<<","<<b<<")";
}

int main()

{
    int arr[] = { -10, -3, 5, 6, -20 };
    int size = (*(&arr + 1) - arr);
    maximum(arr,size);

    return 0;
}