#include <bits/stdc++.h>
using namespace std;

int dist[105][105];
int N,M;
int a,b,c;

int main(){
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> N >> M;

    fill(&dist[0][0],&dist[104][104],1e8);

    for(int i=0;i<M;i++){
        cin>>a>>b>>c;
        dist[a][b]=min(dist[a][b],c);
    }

    for(int i=1;i<=N;i++)dist[i][i]=0;
    
    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    for(int i=1;i<=N;i++,cout<<"\n"){
        for(int j=1;j<=N;j++){
            cout<<(dist[i][j]==1e8?0:dist[i][j])<<" ";
        }
    }
}