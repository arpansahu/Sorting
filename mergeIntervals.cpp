#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct interval{
    int begin,end;
    bool operator <(interval const &i){
        return (begin < i.begin);
    }
};
void mergeIntervals(vector<interval> arr){
    sort(arr.begin(),arr.end());
    stack<interval> stack1;
    for(auto i :arr){
        if(stack1.empty() || stack1.top().end < i.begin) stack1.push(i);
        if(stack1.top().end < i.end) stack1.top().end = i.end;
    }
    while(!stack1.empty()){
        cout  << '{' << stack1.top().begin << ',' << stack1.top().end << "}\n";
        stack1.pop();
    }
}

int main()

{
    vector<interval> arr = { { 1, 5 }, { 2, 3 }, { 4, 6 }, { 7, 8 },
                             { 8, 10 },  {12, 15} };

    mergeIntervals(arr);
    return 0;
}