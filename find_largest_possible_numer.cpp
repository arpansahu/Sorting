#include  <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct {
    bool operator()(string a,string b){
        string value1 = a + b;
        string value2 = b + a;
        return value1 > value2;
    }
}customcompare ;

int main(){
    vector <string> arr = { "10", "68", "97", "9", "21", "12" };
    sort(begin(arr),end(arr),customcompare);

    for (auto i : arr) cout << i ;
    return 0;
}