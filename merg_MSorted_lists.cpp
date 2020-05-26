#include <vector>
#include <queue>
#include <iostream>

using namespace std;


struct Node{
    int val,listNumber,index;
};

struct  compare{
    bool operator()(struct Node lhs,struct Node rhs){
        return lhs.val > rhs.val;
    }
};
void mergeSortedList(vector<int> arr[],int size){
    priority_queue <Node,vector<Node>,compare> pq;
    for (int i = 0; i < size; ++i) pq.push({arr[i][0],i,0});

    while(!pq.empty()){
        struct Node temp = pq.top();
        pq.pop();
        cout<<temp.val<<" ";
        if(temp.index + 1 < arr[temp.listNumber].size())pq.push({arr[temp.listNumber][temp.index + 1],temp.listNumber,temp.index +1});
    }

}


int main()

{
    vector<int> arr[] =
            {
                    { 10, 20, 30, 40 },
                    { 15, 25, 35 },
                    { 27, 29, 37, 48, 93 },
                    { 32, 33 }
            };
    int size = (*(&arr + 1) - arr);
    mergeSortedList(arr,size);


    return 0;
}