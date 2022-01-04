#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long trees[1000001]; 
int main(){
    int N; cin >>N; 
    long long M, sum, s,e,m, ans;
    cin >> M;
    for(int i=0; i<N;i++) cin >> trees[i];
    sort(trees, trees+N);
    s = 0;
    e = trees[N-1];
    ans = 0;
    while(s <= e){
        m = (s+e)/2;
        sum = 0;
        for(int i=0;i<N;i++){
            sum += max( trees[i] - m , (long long) 0);
        }
        if(sum < M){
            e = m - 1;
        }
        else if(sum >= M){
            ans = max(ans, m);
            s = m+1;
        }
    }

    cout << ans;
}
