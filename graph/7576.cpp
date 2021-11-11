/*
    7576번 토마토

*/


#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second

using namespace std;

int N, M, cnt;
int t;
int arr[1001][1001];
int dir[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
queue<vector<int> >  q; // {x, y, time}

int main(){
    cin >> M >> N;
    for(int i=0;i<N;i++){
        for(int j = 0; j < M; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1){
                q.push({i,j,0});
            }
            else if(arr[i][j] == -1) cnt ++;
        }
    }
    
    while(!q.empty()){
        int y = q.front()[0], x = q.front()[1], time = q.front()[2];
        cnt ++;
        t = max(t, time);
        q.pop();
        for(int i=0;i<4;i++){
            int yy = y + dir[i][0], xx = x + dir[i][1];
            if(yy>=N || xx >= M || yy<0||xx<0) continue;
            if(arr[yy][xx] == 0){
                q.push({yy,xx, time +1});
                arr[yy][xx] = 1;
            }
        }
    }

    // for(int i=0;i<N;i++){
    //     for(int j = 0; j < M; j++){
    //         if(arr[i][j] == 0){
    //             cout << -1;
    //             return 0;
    //         }
    //     }
    // }
    if(cnt == N*M) cout << t;
    else cout << -1;

    return 0;
}