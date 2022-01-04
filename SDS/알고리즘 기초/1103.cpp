#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N,M, ans;
int cards[51][51];

// 카드를 뒤집을 때 이전에 카드를 확인한 장소이면 무한하게 움직일 수 있다.
int chk[51][51]; // 무한하게 반복가능한지 판단한다. 
int dp[51][51];

int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

bool move(int y, int x, int time){
    // cout<<y<<" : " << x << " : " << time << "\n";
    if(ans == -1 ) return true;
    ans = max(ans, time);
    chk[y][x] = 1;
    dp[y][x] = time;

    for(int i=0;i<4;i++){
        int yy = y, xx= x;
        yy = yy + dir[i][0] * cards[y][x];
        xx = xx + dir[i][1] * cards[y][x];
        if(yy >= N || xx >= M || yy <0 || xx < 0 || cards[yy][xx] == -1 ) continue;

        if(chk[yy][xx]){
            ans = -1;
            return true;
        }
        if(dp[yy][xx] > 0 && time<dp[yy][xx]) continue;
        if(move(yy,xx, time+1)) return true;
    }

    chk[y][x] = 0;
    return false;
}

int main(){
    cin >> N >> M;
    for(int i=0;i<N;i++){
        string s; cin >> s;
        for(int j=0;j<M;j++){
            if(s[j] == 'H') cards[i][j] = -1;
            else cards[i][j] = s[j] - '0';
        }
    }

    move(0, 0, 1);
    cout << ans;

}