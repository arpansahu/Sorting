#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;


void permutations(string str){
    sort(str.begin(),str.end());

    while(1){

        cout<<str<<"\n";
        if(! next_permutation(str.begin(),str.end())) return;
    }
}


int main()

{
    string str = "BADC";

    permutations(str);


    return 0;
}