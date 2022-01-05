#include <iostream>
#include <vector>
#include <queue>
#define pb push_back

using namespace std;

int main(){
    cin.tie(0);
    int a,b; cin >> a>> b;
    int k =1;
    while(a!=-1 && b!=-1){
        vector <vector<int> >v(14);
        int s = a;
        int node[15] ={0,};
        int parent[15] = {0,};
        int cnt=0, check=0;
        while(a!=0&&b!=0){
            v[a].pb(b);
            v[b].pb(a);
            if(parent[b] == 0){
                parent[b] = a;
            }
            else{
                check = -1;
            }
            if(node[a] == 0){
                cnt++;
                node[a]=1;
            }
            if(node[b] == 0){
                cnt++;
                node[b]=1;
            }
            cin>>a>>b;
        }
        if(check == -1){
            cout <<"Case " << k <<" is not a tree.\n";
            cin>>a>>b;
            k++;
            continue;
        }
        if(cnt == 0){
            cout <<"Case " << k <<" is a tree.\n";
            cin>>a>>b;
            k++;
            continue;
        }
        int chk[15] = {0,};
        queue<pair<int,int>> q;// from , now
        q.push({-1,s});
        chk[s] = 1;
        while(!q.empty()){
            int fr = q.front().second;
            int from = q.front().first; 
            q.pop();

            for(int i=0;i<v[fr].size();i++){
                if(v[fr][i] == from) continue;
                else{
                    if(chk[v[fr][i]]==0){
                        q.push({fr, v[fr][i]});
                        chk[v[fr][i]]=1;
                        cnt--;
                    }
                    else{
                        cnt = -1;
                        break;
                    }
                }
            }
            if(cnt == -1) break;
        }
        if(cnt == 1) cout <<"Case " << k <<" is a tree.\n";
        else cout <<"Case " << k <<" is not a tree.\n";
        k++;
        cin>>a>>b;
    }

}