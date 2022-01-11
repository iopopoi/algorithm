#include <bits/stdc++.h>
#define INF 9876543210
using namespace std;

long long N, M, a, b, c;
vector<vector<long long> > bus; // 출발지, 도착지, 시간
long long dist[501];

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> N >> M;

    for(int i=0;i<=N;i++) dist[i] = INF;

    while(M--){
        cin >> a >> b >> c;
        bus.push_back({a,b,c});
    }

    dist[1] = 0;
    for(int t=1; t<N;t++){
        for(int i=0;i<bus.size();i++){ // 모든 간선을 본다 -> 모든 간선을 한번씩 다 보는 것이 1순환이다.
            if(dist[bus[i][0]]==INF) continue;
            if(dist[bus[i][1]] > dist[bus[i][0]] + bus[i][2]){
                dist[bus[i][1]] = dist[bus[i][0]] + bus[i][2];
            } 
        }
    }

    bool isCycle = false;
    for(int i=0; i<bus.size();i++){
        if(dist[bus[i][0]]==INF) continue;
        if(dist[bus[i][1]] > dist[bus[i][0]] + bus[i][2]){
            isCycle = true;
            break;
        } 
    }
    if(isCycle){
        cout << -1 << endl;
    }
    else {
        for (int i = 2; i <= N; i++) {
            if (dist[i] == INF) {
                cout << -1 << "\n";
            }
            else {
                cout << dist[i] << "\n";
            }
        }
    }
    return 0;   
}