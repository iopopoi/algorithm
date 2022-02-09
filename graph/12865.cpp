#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N, K;
int dp[101][2]; 
int arr[101][2]; // 번 물건의 무게, 가치

int dfs(int n, int k){
    if(n > N) return 0;
    if(dp[n][1] != -1 ||  )

}

int main(){
    cin >> N >> K;
    for(int i=1;i<=N;i++){
        cin >> arr[i][0] >> arr[i][1];
    }

    memset(dp, -1,sizeof(dp));

    // init
    // dfs(i, K) : i ~ N의 조건을 충족하는 값 반환 
    dfs(1, K); 
}