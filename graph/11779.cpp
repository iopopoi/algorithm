/*
    BOJ.11779 최소비용구하기2

    사용한 알고리즘
    - 다익스트라
    - 그래프

    구현
    1. 우선순위큐를 이용하여 다익스트라를 진행한다.
    2. pq의 top을 확인하며 처음 해당 node를 확인한 경우 path[node]에 node에 오기 직전에 거치는 node의 정보를 저장한다.
    3. pq의 정보는 { - weight, { 이전 노드(방문지), 현재 노드 }} 가 저장되어 있다.
    4. 목적지가 top에 오면 목적지까지의 최단경로를 찾은 것으로 이때의 weight를 출력한다.
    5. path의 정보를 목적지부터 역으로 탐색하여 경로 정보를 얻고 이를 출력한다.
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int S, F;
int a, b;
long long w;
int path[1001]; // i번 node의 이전 방문 node를 저장한다
 
long long weight;
int be, now, next_node;

vector< vector <pair<int,long long> > > v(1001); // graph정보
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


    // 다익스트라
    pq.push({0, {-1, S}});

    while(!pq.empty()){
        weight = pq.top().first; 
        be = pq.top().second.first;
        now = pq.top().second.second;
        pq.pop();
        
        // 이전에 방문한 node는 pass한다.
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
