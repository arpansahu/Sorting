#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;


void palindromicPermutations(string str){
    unordered_map<char,int> map1;

    for(auto i : str) map1[i]++;
    int odd = 0; string mid;
    string left,right;

    for(auto i : map1){
        char ch = i.first;
        int count = i.second;

        if(count == 1){
            if(++odd > 1) return;
            count--;
            mid = ch;
        }

        count = count / 2;
        while(count--) left = left + ch;

    }

    sort(left.begin(),left.end());

    while(1){
        right = left;
        reverse(right.begin(),right.end());

        cout<<left + mid + right <<"\n";

        if(! next_permutation(left.begin(),left.end())) return;
    }
}


int main()

{
    string str = "xyxzwxxyz";

    palindromicPermutations(str);


    return 0;
}