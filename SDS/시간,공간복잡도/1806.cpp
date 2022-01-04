#include <iostream>
#include <vector>
using namespace std;

int main(){
    cin.tie(0);
    int N; cin >> N;
    long long S; cin>> S;

    vector<long long> v;
    v.resize(N);
    for(int i=0; i<N;i++) cin >> v[i]; 

    long long sum = v[0];
    int p1=0, p2=0, ans;
    ans = N+1;
    while(p1<N){
        if(sum<S){
            p2++;
            if(p2>=N) break;
            sum += v[p2];
        }
        if(sum>=S){
            ans = min(ans, p2-p1+1);
            sum -= v[p1++];
        }
    }
    cout << (ans != N+1 ? (ans == 0? 1 : ans) : 0);
}
