#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M, st, fi, a, b, c;
vector<vector<pair<int,int>>> v(1001); // node, weight
priority_queue<pair<int, int> > pq; // -weight, node
int dist[1001];
bool chk[1001];


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> N >> M;
    int inf; inf = N * 100000;
    for(int i=0;i<=N;i++){
        chk[i] = false;
        dist[i] = inf;
    }

    while(M--){
        cin >> a>> b>> c;
        v[a].push_back({b,c});
    }
    
    cin >> st >> fi;
    
    pq.push({0, st});
    dist[st] = 0;

    while(!pq.empty()){
        int node = pq.top().second, weight = -pq.top().first;
        pq.pop();
        if(chk[node]) continue;
        chk[node] = true;
        if(node == fi) break;
        for(int i=0;i< v[node].size();i++){
            int next = v[node][i].first;
            int nw = v[node][i].second;

            if(dist[next] > dist[node] + nw){
                dist[next] = dist[node] + nw;
                pq.push({-dist[next], next});
            }
        }

    }
    cout << dist[fi];
}