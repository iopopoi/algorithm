/*
    BOJ.16118 달빛 여우

    이용한 알고리즘 
    - 다익스트라

    구현
    1. 여우와 늑대 각각 다익스트라를 돌려 각 그루터기에 가는데 걸리는 시간을 구한다.
    2. 여우는 오솔길을 다니는 데 걸리는 시간 (* 2)
    3. 늑대는 (* 1) 과  (* 4)을 돌아가며 적용한다
    4. 늑대는 한 그루터기를 두번 방문 할 수 있다.
       ( 1 - 4 - 5 ) 보다 (1 - 2 - 3 - 4 - 5 )가 더 빠를 수 있다. .... ( 4 - 5 )의 오솔길이 긴 경우를 고려한다.
    5. 4번을 고려하여 늑대가 각 그루터기에서 출발하는 속도가 다른 경우 다시 해당 그루터기를 방문할 수 있도록한다. 

    예제 입력
    5 5
    1 2 1
    2 3 1
    1 3 1
    1 4 1
    4 5 10000
    ---------
    0
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
int wolf_chk[4001]; // 늑대가 i번 그루터기에서 출발하는 속도를 기록한다.

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
            // 모든 그루터가 까지의 최속 시간을 기록하면 탐색을 종료한다.
            if(chk == N) break;
        }    
        
        for(int i=0;i<v[now].size();i++){
            nextNode = v[now][i].first;
            if(idx == 0 && path[idx][nextNode] == 0){ // 여우
                pq.push({-(weight + v[now][i].second * 2),{ nextNode, 1}});
            }
            else if(idx == 1){// 늑대
                if(wolf_chk[nextNode]!=3 && wolf_chk[nextNode] != (speed % 2)+1 ){
                    if(speed == 1){ // 2배 빠르게 이동
                        pq.push({-(weight + v[now][i].second * 1),{ nextNode, 2}});
                    }
                    else{ // 절반의 속도로 이동
                        pq.push({-(weight + v[now][i].second * 4),{ nextNode, 1}});
                    }
                }
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
        if(path[0][i] < path[1][i]) cnt ++;
    }
    cout << cnt;
}