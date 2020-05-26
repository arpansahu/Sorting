#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

void groupAnangram(string arr[],int size){
    vector<string> words(arr,arr+size);
    for(auto &i : words) sort(i.begin(),i.end());

    map<string,vector<int>> hash;

    for(int i = 0; i  < size ; i++) hash[words[i]].push_back(i);

    for(auto i : hash){
        for(auto j : i.second) cout<<arr[j]<<" ";
        cout<<"\n";
    }

}
int main()

{
    string arr[] =
            {
                    "CARS", "REPAID", "DUES", "NOSE", "SIGNED", "LANE",
                    "PAIRED", "ARCS", "GRAB", "USED", "ONES", "BRAG",
                    "SUED", "LEAN", "SCAR", "DESIGN"
            };
    int size = (*(&arr + 1) - arr);
    groupAnangram(arr,size);


    return 0;
}