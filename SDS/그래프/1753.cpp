#include <iostream>
#include <queue>
#include <vector>

#define INF 987654321

using namespace std;


vector<vector<pair<int,int>>> v(20001); 
priority_queue<pair<int,int> > pq; // weight, node
int dist[20001];
int chk[20001];
int V, E, K, cnt;
int a,b,c;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> V >> E >> K;
    for(int i=0;i<=V;i++){
        v[i].clear();
        dist[i] = INF;
    }


    while(E--){
        cin >> a>> b>> c;
        v[a].push_back({b,c});
        // v[b].push_back({a,c});
    }

    dist[K] = 0;
    pq.push({0,K});

    while(!pq.empty()){
        int node = pq.top().second, weight=-pq.top().first;
        pq.pop();
        if(chk[node]) continue;
        chk[node] = 1;
        for(int i=0;i<v[node].size();i++){
            int next = v[node][i].first;
            int nw = v[node][i].second;
            if(dist[next] > dist[node] + nw){
                dist[next] = dist[node] + nw; 
                pq.push({-dist[next], next});
            }
        }
    }
    for(int i=1;i<=V;i++){
        if(dist[i] == INF) cout << "INF\n";
        else cout << dist[i] <<"\n";
    }
}