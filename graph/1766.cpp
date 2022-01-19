#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int a, b;
int deg[32001];
vector<vector<int> > v(32001);
priority_queue<int> q;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;
    while(M--){
        cin >> a >> b;
        v[a].push_back(b);
        deg[b]++;
    }
    for(int i=1;i<=N;i++){
        if(deg[i]==0){
            q.push(-i);
        }
    }

    int node, next;
    while (!q.empty())
    {
        node = -q.top();
        q.pop();
        cout << node << " ";
        for(int i=0; i<v[node].size();i++){
            next =v[node][i];
            deg[next]--;
            if(deg[next]==0){
                q.push(-next);
            }
        }
    }
    
}