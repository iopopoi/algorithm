#include <bits/stdc++.h>
using namespace std;

int ind[501], Time[501], ans[501];
vector <vector<int> > v(501);
int N;

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    for(int i=1;i<=N;i++){
        int a, b; cin >> a >> b;
        Time[i] = a;
        while(b!=-1){
            v[b].push_back(i);
            ind[i]++;
            cin >> b;
        }
    }

    queue<int> q;
    for(int i=1;i<=N;i++){
        if(ind[i]==0) q.push(i);
    }
    while(!q.empty()){
        int f = q.front();
        q.pop();
        for(int i=0;i<v[f].size();i++){
            int next = v[f][i];
            if(ind[next]>0)
                ans[next] = max(ans[next], Time[f]);
            if(--ind[next]==0){
                Time[next] += ans[next];
                q.push(next);
            }
        }
    }
    for(int i=1;i<=N;i++) cout << Time[i]<<"\n";
}