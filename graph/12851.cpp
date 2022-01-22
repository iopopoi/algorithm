#include <iostream>
#include <queue>
using namespace std;

int N, K;
int ans, cnt;

int chk[200001];
priority_queue<pair<int,int>> pq; // time, spot

int main(){
    cin >> N >> K;
    ans = -1;
    pq.push({0, N});
    chk[N] == 1;
    int spot, time;
    while(!pq.empty()){
        time = -pq.top().first; spot = pq.top().second;
        chk[spot] = 1;
        pq.pop();
        if(spot == K){
            if(ans== -1 || ans == time){
                cnt ++;
                ans = time;
            }
            else break;
        }
        if(spot*2<=2*K && chk[spot*2]==0){
            pq.push({-(time+1), spot*2});
        }
        if(spot+1<=100000 && chk[spot+1] == 0){
            pq.push({-(time+1), spot+1});
        }
        if(spot-1>=0 && chk[spot-1] == 0){
            pq.push({-(time+1), spot-1});
        }
    }
    cout << ans << "\n" << cnt;

}