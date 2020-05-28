#include <algorithm>
#include <iostream>
#include <climits>
using namespace std;

void minimumProductTriplet(int arr[],int size){
    int min1 = INT_MAX;
    int min2 = INT_MAX - 1;
    int min3 = INT_MAX - 2;
    int max1 = INT_MIN + 1;
    int max2 = INT_MIN;
    for(int i = 0; i < size  ; i++)
    {
        if(arr[i] > max1 && arr[i] <= max2) {
            max2 = max1;
            max1 = arr[i];
        }
        else if(arr[i] > max2) max2 = arr[i];

        if(min1 > arr[i]){
            min3 = min2;
            min2 = min1;
            min1 = arr[i];
        }
        else if (min2 > arr[i]){
            min3 = min2;
            min2 = arr[i];
        }
        else if(min3 > arr[i]) min3 = arr[i];

    }
    int a,b,c;
    if((min1*min2*min3) < (min1*max1*max2)){
        a = min1;b=min2;c=min3;
    }
    else{
        a= min1;b=max2;c = max1;
    }
    cout<<"Minimum Triplet is ("<<a<<","<<b<<","<<c<<")";
}

int main()

{
    int arr[] = { -10, -3, 5, 6, -20 };
    int size = (*(&arr + 1) - arr);
    minimumProductTriplet(arr,size);

    return 0;
}