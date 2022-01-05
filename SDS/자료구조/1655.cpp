#include <iostream>
#include <queue>
using namespace std;

int main(){
    cin.tie(0); cout.tie(0);
    priority_queue<int> smaller, bigger;
    int N; cin>> N;
    while(N--){
        int x; cin >> x;
        if(smaller.size()==bigger.size()){
            if( !bigger.empty() && -bigger.top() < x){
                smaller.push(-bigger.top());
                bigger.pop();
                bigger.push(-x);
            }
            else{
                smaller.push(x);
            }
        }
        else{
            if( !smaller.empty() && smaller.top() > x){
                bigger.push(-smaller.top());
                smaller.pop();
                smaller.push(x);
            }
            else{
                bigger.push(-x);
            }
        }
        cout<< smaller.top() <<"\n";
    }
}