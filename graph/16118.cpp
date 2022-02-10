/*
    5 5
    1 2 1
    2 3 1
    1 3 1
    1 4 1
    4 5 10000
    ---------
    0
    https://www.acmicpc.net/board/view/28854
*/


#include <iostream>
#include <vector>
#include  <queue>

using namespace std;

int N, M;
int a, b;
int now, t, speed, nextNode;
long long c, weight;
long long path[2][4001]; // 0: 여우, 1: 늑대
int wolf_chk[4001];

vector<vector<pair<int, long long> > > v(4001);

void Dijkstra(int idx){
    // {time,{node, 0 || 1(늑대의 속도)}}
    priority_queue<pair<long long, pair<int, int>>> pq; 
    int chk = 0;
    pq.push({-1,{1,1}});
    while(!pq.empty()){
        weight = -pq.top().first;
        now = pq.top().second.first;
        speed = pq.top().second.second;
        // cout << weight << " : " << now << " : " << speed << " : "<<wolf_chk[now]<<"\n";
        pq.pop();
        if(idx == 0 && path[idx][now] != 0) continue;
        else if(idx == 0 && path[idx][now] == 0) path[idx][now] = weight;
        else if(idx == 1){
            if(wolf_chk[now] == 3) continue;
            else if(wolf_chk[now] == 0){
                path[idx][now] = weight;
                wolf_chk[now] = speed;
                chk++;
            }
            else if(speed == 2  && wolf_chk[now] == 1) wolf_chk[now] = 3;
            else if(speed == 1 && wolf_chk[now] == 2) wolf_chk[now] = 3;
            else continue;

            if(chk == N) break;
        }    
        

        for(int i=0;i<v[now].size();i++){
            nextNode = v[now][i].first;
            if(idx == 0 && path[idx][nextNode] == 0){ // 여우
                pq.push({-(weight + v[now][i].second * 2),{ nextNode, 1}});
            }
            else if(idx == 1){// 늑대
                // cout << now << ":"<< nextNode<<":"<<speed<<":" << (speed % 2)+1 << ":" << wolf_chk[nextNode];
                if(wolf_chk[nextNode]!=3 && wolf_chk[nextNode] != (speed % 2)+1 ){
                    // cout << " --- yes";
                    if(speed == 1){ // 2배 빠르게 이동
                        pq.push({-(weight + v[now][i].second * 1),{ nextNode, 2}});
                    }
                    else{ // 절반의 속도로 이동
                        pq.push({-(weight + v[now][i].second * 4),{ nextNode, 1}});
                    }
                }
                // cout << "\n";
            }

        }

    }
}

int main(){
    cin >> N >> M;
    while(M--){
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c}); 
    }

    Dijkstra(0);
    Dijkstra(1);

    int cnt = 0;
    for(int i=1;i<=N;i++){
        // cout << path[0][i] << ":" << path[1][i] << "\n";
        if(path[0][i] < path[1][i]) cnt ++;
    }
    cout << cnt;
}