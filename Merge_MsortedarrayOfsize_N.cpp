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
void mergeSortedList(vector<int> arr[],int size,int n){
    priority_queue <Node,vector<Node>,compare> pq;
    for (int i = 0; i < size; ++i) pq.push({arr[i][0],i,0});

    while(!pq.empty()){
        struct Node temp = pq.top();
        pq.pop();
        cout<<temp.val<<" ";
        if(temp.index + 1 < n )pq.push({arr[temp.listNumber][temp.index + 1],temp.listNumber,temp.index +1});
    }

}


int main()

{
    vector<int> arr[] =
            {
                    { 10, 20, 30, 40 },
                    { 15, 25, 35, 45 },
                    { 27, 29, 37, 48 },
                    { 32, 33, 39, 50 },
                    { 16, 18, 22, 28 }
            };
    int size = (*(&arr + 1) - arr);
    mergeSortedList(arr,size,4);


    return 0;
}