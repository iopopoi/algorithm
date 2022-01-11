//  x -> y가 불가능하다 : 둘 사이의 경로가 없다.
// 플로이드 와셜로 최단 경로를 구할 수 없다. -> INF로 남는다.
// 비교가 불가능하다 == 이동이 불가능하다.

#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int N, M, a,b;
int cnt;
int student[501][501]; 
int main(){
    cin >> N >> M;

    for(int i=0;i<=N;i++){
        for(int j=0;j<=N; j++){
            student[i][j] = INF;
        }
    }

    for(int i=0;i<M;i++){
        cin >> a>> b;
        student[a][b] = 0;
        // student[b][a] = 0;
    }

    for(int k=1;k<=N;k++){
        for(int i=1; i<=N;i++){
            for(int j=1;j<=N;j++){
                if(i==j) student[i][j] = 0;
                if(student[i][k] == INF|| student[k][j] == INF) continue;
                if(student[i][j] > student[i][k]+student[k][j])student[i][j] = 0;
            }
        }
    }
    int cnt, ans=0;
    for(int i=1;i<=N;i++){
        cnt =0;
        for(int j=1;j<=N;j++){
            if(student[i][j]==0|| student[j][i]==0){
                cnt ++;
            }
        }
        if(cnt>=N) ans++; 
    }
    cout << ans;
}