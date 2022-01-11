#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int N, M, S, D;
int u, v, p;
vector<pair<int,int> > path[501];
int dist[501];
bool isPath[501][501];
vector<int> par[501];

void dijkstra(int seq){
    priority_queue<pair<int,int>> pq;
    pq.push({0, S});
    dist[S] = 0;
    while(!pq.empty()){
        int node = pq.top().second, w = -pq.top().first;
        pq.pop();

        int next, nw;
        for(int i=0;i<path[node].size();i++){
            next = path[node][i].first;
            nw = path[node][i].second;

            // removePath에서 최단경로는 true로 설정하기 때문에 skip한다.
            if(isPath[node][next]) continue;
            if(dist[next]>dist[node]+nw){
                dist[next] = dist[node] + nw;
                pq.push({-dist[next], next});
                if(seq == 1){
                    // 최솟값으로 next를 갈 수 있으면 next의 parent로 node를 저장한다.
                    par[next].clear();
                    par[next].push_back(node);
                }
            }
            else{
                if(seq==1){
                    // 최솟값으로 next를 갈 수 있으면 next의 parent로 node를 저장한다.
                    // 이미 저장된 최솟값과 같다면 또 다른 최소경로 이므로 clear없이 
                    // node를 parent정보로 추가한다.
                    if(dist[next] == dist[node]+nw){
                        par[next].push_back(node);
                    }
                }
            }
        }
    }
}

void removePath(int start, int node){
    if(node == start) return;
    for(int i=0;i<par[node].size();i++){
        if(isPath[par[node][i]][node]) continue;
        isPath[par[node][i]][node] = true; // 최단경로에 포함된 경우 true로 표현한다.
        removePath(start, par[node][i]);
    }
}

int main(){
    cin.tie(0); ios_base::sync_with_stdio(0);
    while(true){
        cin >> N >> M;
        if(N==0 && M==0) break;
        cin>> S >> D;
        
        for(int i=0;i<=N;i++){
            dist[i] = INF;
            path[i].clear();
            for(int j=0;j<=N;j++) isPath[i][j] = false;
        }

        while(M--){
            cin >> u >>v >>p;
            path[u].push_back({v,p});
        }

        dijkstra(1);

        if(dist[D]==INF){
            cout << "-1\n";
            continue;
        }
        removePath(S, D);
        for(int i=0;i<+N;i++) dist[i] = INF;
        dijkstra(2);
        if (dist[D] == INF) {
            cout << "-1\n";
        }
        else {
            cout << dist[D] << "\n";
        }
    }
    return 0;
}