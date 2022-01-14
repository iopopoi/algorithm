//  BOJ.2517  달리기 - index tree

// i번 선수보다 앞서 달리고 있는 더 실력이 좋은 선수의 수를 구해야한다.

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, S;
int arr[2000000];
int ans[500001];
vector<pair<int,int> > v;

void update(int index){ // index번 선수 정보 갱신
    index += S;
    arr[index] = 1;
    while(index>1){
        index /= 2;
        arr[index] = arr[index*2] + arr[index*2+1];
    }
}

// r번 선수의 등수를 찾는다.
// 현재 arr에는(index tree에는) r번 선수보다 실력이 좋은 사람이 표시되어 있으므로
// 1 ~ r을 확인하여 count하면 r번 선수보다 실력이 좋고 먼저 ~r-1번으로 달리고 있는 
// 선수의 수를 구할 수 있다.
int Find(int l, int r){
    l += S; r += S;
    int cnt=0;
    while(l<=r){
        // left가 홀수 이면 오른쪽 자식이면 갱신한다.
        // right가 짝수 이면 왼쪽 자식이면 갱신한다.
        if((l&1)==1) cnt += arr[l];
        if((r&1)==0) cnt += arr[r];
        l = (l+1) >> 1;
        r = (r-1) >> 1;
    }
    return cnt;
}

int main(){
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> N;
    int level = 1;
    while(S < N){
        S += level;
        level *= 2;
    }
    for(int i=1;i<=N;i++){
        cin >>  level;
        v.push_back({-level,i}); // 선수의 속도가 빠른 순서로 정렬한다.
    }
    sort(v.begin(), v.end());


    for(int i=0;i<v.size();i++){
        update(v[i].second);
        ans[v[i].second] = Find(1, v[i].second);
    }
    for(int i=1;i<=N;i++) cout << ans[i] << "\n";
}