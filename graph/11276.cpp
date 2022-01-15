#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second

using namespace std;

int main(){
    cin.tie(0); cout.tie(0);
    int T, N; cin >> T;
    priority_queue<int> q;
    while(T--){
        cin >> N;
        if(N==0){
            if(q.empty()){
                cout << "0\n";
            }  
            else{
                cout << q.top()<<"\n";
                q.pop();
            }
        }
        else{
            q.push(N);
        }
    }
}
