#include <algorithm>
#include <iostream>

using namespace std;

void ditinctComboOfLenghtK(int arr[],string str,int i,int size,int k){
    if ( k > size) return;
    if(k == 0){
        cout<<str<<endl;
        return;
    }
    for (int j = i; j < size ; ++j) ditinctComboOfLenghtK(arr,str+" "+to_string(arr[j]),j+1,size,k -1);

}

int main()

{
    int arr[] = { 1, 2, 3 };
    int k = 2;
    int size = (*(&arr + 1) - arr);
    ditinctComboOfLenghtK(arr,"",0,size,k);

    return 0;
}