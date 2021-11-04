/*
    1260번 DFS와 BFS
    주어진 정점으로 부터 DFS와 BFS를 돌아 탐색하는 정점의 순서를 출력한다.
    
    분야 : graph, dfs, bfs
    인접리스트(이중벡터)를 이용하여 graph정보를 저장하고 dfs와 bfs를 통해 이를 탐색하였습니다.
*/


#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second

using namespace std;

int N, E, S; // 정점의 개수, 간선의 개수, 탐색의 시작위치
vector<vector <int> > v(1001); // 인접리스트
int arr[1001][1001];

// 탐색한 정점을 check하는 배열
int chk_dfs[1001];
int chk_bfs[1001];

int dfs(int index){
    cout << index << " ";
    chk_dfs[index] = 1;
    // v[index]에 저장된 정점을 모두 확인한다.
    // (=index정점과 연결된 모든 점점을 확인한다.)
    for(int i=0; i<v[index].size();i++){
        int next = v[index][i];
        if(chk_dfs[next]==0){
            return dfs(next);
        }
    }
    return 0;
}

void bfs(){
    queue <int> q; // 앞으로 탐색해야할 정점들의 정보를 저장한다.
    q.push(S);
    chk_bfs[S] = 1;
    while(!q.empty()){
        int index = q.front();
        cout << index << " ";
        // v[index]에 저장된 정점을 모두 확인한다.
        // (=index정점과 연결된 모든 점점을 확인한다.)
        for(int i=0;i< v[index].size();i++){
            int next = v[index][i];
            if(chk_bfs[next]==0){
                q.push(next);
                chk_bfs[next] = 1;
            }
        }
        q.pop();
    }
}

int main(){
    cin >> N >> E >> S;
    // 정보를 입력받아 인접리스트에 정보를 추가한다.
    while(E--){
        int s,f;
        cin >> s >> f; 
        // 양방향 그래프이다.
        v[s].pb(f);
        v[f].pb(s);
    }
    // 탐색가능한 정점이 여러개인 경우 정점의 번호가 작은것부터 방문하므로 모든 v[i]를 정렬한다.
    for(int i=1;i<=N;i++){
        sort(v[i].begin(), v[i].end());
    }

    dfs(S); 
    cout << "\n";
    bfs();
}