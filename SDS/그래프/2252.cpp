//  BOJ 2252 - 네트워크 연결
#include <bits/stdc++.h>
using namespace std;

int ind[32001];
vector<vector<int> > v(32001);
queue<int> q;
int N, M;

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> N >> M;
    int a, b;
    while(M--){
        cin >> a>> b;
        v[a].push_back(b);
        ind[b]++;
    }
    for(int i=1;i<=N;i++){
        if(ind[i]==0) q.push(i);
    }
    while(!q.empty()){
        int f = q.front();
        q.pop();
        cout << f <<" ";
        for(int i=0;i<v[f].size();i++){
            int next = v[f][i];
            if(--ind[next] == 0) q.push(next);
        }
    }
}