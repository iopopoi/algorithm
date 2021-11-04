/*
    백준 2644번 - 촌수계산
    두 사람 사이의 촌수를 계산하는 문제이다.
    분야 - graph, dfs, bfs
*/
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second

using namespace std;

int N, S, F;
int chk[101];
vector<vector<int>> tree(101);

int order(){
    queue < pair<int,int> > q; // index, time
    q.push({S,0});
    chk[S] = 1;
    while(!q.empty()){
        int index = q.front().fst, time = q.front().snd;
        q.pop();
        for(int i=0;i<tree[index].size();i++){
            int next = tree[index][i];
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
        tree[p].pb(c);
        tree[c].pb(p);
    }
    cout << order();
}