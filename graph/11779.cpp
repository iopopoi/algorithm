#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int S, F;
int a, b;
long long w;
int path[1001];

long long weight;
int be, now, next_node;

vector< vector <pair<int,long long> > > v(1001);
vector<int> paths;
priority_queue<pair< long long, pair<int, int> > > pq; // - weight, node, node_now;


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;
    
    while(M--){
        cin >> a >> b >> w;
        v[a].push_back({b, w});
    }

    cin >> S >> F;

    pq.push({0, {-1, S}});

    while(!pq.empty()){
        weight = pq.top().first; 
        be = pq.top().second.first;
        now = pq.top().second.second;
        pq.pop();
        if(path[now] != 0) continue;
        path[now] = be;
        if(now == F) {
            cout << -weight << "\n";
            break;
        }

        for(int i = 0; i< v[now].size(); i++){
            next_node = v[now][i].first;
            if(path[next_node] == 0){
                pq.push({ weight - v[now][i].second, {now, next_node}});
            }
        }
    }

    while(F != -1){
        paths.push_back(F);
        F = path[F];
    }
    cout << paths.size()<< "\n";
    for(int i= paths.size()-1; i >= 0 ;i--){
        cout << paths[i] <<" ";
    }

}
