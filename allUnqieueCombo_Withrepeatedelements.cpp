#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void allUnqieueCombo(int arr[],vector<int>&out,int curr,int size,int k){

    if(out.size() == k){
        cout <<"{ ";
        for(auto i : out) cout <<i<<",";
        cout<<" }"<<endl;
        return;
    }

    for (int j = curr; j < size ; ++j) {
        out.push_back(arr[j]);
        allUnqieueCombo(arr,out,j,size,k);

        out.pop_back();
        while(j < size -1 && arr[j] == arr[j+1]) j++;
    }
}

int main()

{
    int arr[] = { 1, 2, 1 };
    int k = 2;
    int size = (*(&arr + 1) - arr);
    sort(arr,arr + size);
    vector<int> out;
    allUnqieueCombo(arr,out,0,size,k);

    return 0;
}