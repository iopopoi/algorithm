/*
    백준 2644번 - 촌수계산
    두 사람 사이의 촌수를 계산하는 문제이다.
    분야 - graph, dfs, bfs

    문제에서 주어진 부모, 자식사이의 관계를 graph(인접리스트)에 저장하고
    bfs를 통해 graph를 탐색하여 서로 다른 두 사람 사이의 촌수를 구하였다.
*/
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second

using namespace std;

int N, S, F; // 정점의 수, 서로 다른 두 사람의 번호
int chk[101]; // 탐색을 반복하지 않기 위한 배열
vector<vector<int>> graph(101); // 부모 자식정보를 저장하는 그래프

int order(){
    queue < pair<int,int> > q; // index, time
    q.push({S,0});
    chk[S] = 1;
    while(!q.empty()){
        int index = q.front().fst, time = q.front().snd;
        q.pop();
        for(int i=0;i<graph[index].size();i++){
            int next = graph[index][i];
            if(next == F) return time + 1;
            if(chk[next]==0){
                q.push({next, time+1 });
                chk[next] = 1;
            }
        }
    }
    return -1;
}

int main(){
    int edge, p,c;
    cin >> N >> S >> F >> edge;
    while(edge--){
        cin >> p >> c;
        graph[p].pb(c);
        graph[c].pb(p);
    }
    cout << order();
}