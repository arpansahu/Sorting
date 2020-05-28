#include <algorithm>
#include <iostream>

using namespace std;
void quadTupleWithSumk(int arr[],int size,int k){
    sort(arr,arr+size);
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            int remsum = k - (arr[i] + arr[j]);

            int low  = j + 1,high = size -1;
            while(low < high){
                if(arr[low] + arr[high] < remsum) low++;
                else if (arr[low] + arr[high] > remsum) high--;
                else
                {
                    cout << "(" << arr[i] << " " << arr[j] << " " <<
                         arr[low] << " " << arr[high] << ")\n";

                    low++, high--;
                }
            }
        }
    }
}

int main()

{
    int arr[] = { 2, 7, 4, 0, 9, 5, 1, 3 };
    int sum = 20;
    int size=  (*(&arr + 1) -  arr);
    quadTupleWithSumk(arr,size,sum);
    return 0;
}