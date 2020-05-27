#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

bool next_permutation(string &str,int n){
    int i = n - 1;
    while(str[i - 1] >= str[i]) if(--i == 0) return false;

    int j = n - 1;
    while(j > i && str[j] <= str[i - 1]) j--;

    swap(str[i - 1],str[j]);
    reverse(str.begin() + i,str.end());

    return true;
}

void permutations(string str){
    sort(str.begin(),str.end());

    while(1){

        cout<<str<<"\n";
        if(! next_permutation(str,str.length())) return;
    }
}


int main()

{
    string str = "BADC";


    permutations(str);


    return 0;
}