/*
    BOJ.12865 평범함 배낭

    사용한 알고리즘
    - DP, 분할정복
*/
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N, K;
int dp[101][100001]; // j의 무게로 i ~ N까지 물건을 들으려 할때 최대 가중치
int arr[101][2]; // i번 물건의 무게, 가치

// n ~ N까지 k의 무게로 들수 있는 max값 반환
int dfs(int n, int k){
    if(n == N){
        if(arr[N][0] <= k) return dp[n][k] = arr[n][1];
        else return dp[n][k] = 0;
    }
    if(dp[n][k] != -1 ) return dp[n][k];
    
    if(arr[n][0] <= k) return dp[n][k] = max(dfs(n+1,k), dfs(n+1, k - arr[n][0]) + arr[n][1] );
    else return dp[n][k] = dfs(n+1, k);
}

int main(){
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> N >> K;
    for(int i=1;i<=N;i++){
        cin >> arr[i][0] >> arr[i][1];
    }

    memset(dp, -1,sizeof(dp));

    // dfs(i, K) : K개의 무개로 i ~ N의 물건을 담으려할때 최대 가중치
    cout << dfs(1, K); 
}