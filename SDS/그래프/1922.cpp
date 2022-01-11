//  BOJ 2252 - 네트워크 연결
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int uni[1001];
// priority_queue<pair<int, pair<int, int>>> pq;
vector<pair<int, pair<int, int>>> v;

int find(int A){
    int topA = A;
    while(topA!=uni[topA]){
        topA = uni[topA];
    }
    uni[A] = topA;
    return topA;
}

void Union(int A, int B){
    uni[find(A)] = find(B);
}


int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N >> M;
    for(int i=1;i<=N;i++) uni[i] = i;

    int a, b, c;
    while(M--){
        cin >> a>> b>> c;
        // pq.push({-c,{a, b}});
        v.push_back({c,{a, b}});
    }
    sort(v.begin(), v.end());

    int cnt = 0, ans = 0;
    int q=0;
    while(cnt != N-1){
        // int weight = pq.top().first;
        // int n1 = pq.top().second.first, n2 = pq.top().second.second;
        int weight = v[q].first;
        int n1 = v[q].second.first, n2 = v[q].second.second;
        q++;
        // pq.pop();
        if(find(n1) != find(n2)){
            Union(n1, n2);
            cnt++;
            ans += weight;
        }
    }
    cout << ans;
    return 0;
}