/*
    132 392 311 351 231
    392 351 132 311 231

    1 2 3 4 5
    2 4 1 3 5 

    (5, 5) (3, 4) (1, 3) (4, 2) (2, 1)  
*/


#include <iostream>
#include <queue>
using namespace std;

int N, S, level;
priority_queue<pair<int,int> >A, B, pq;
long tree[2000001];

void update(int index){
    index += S;
    while (index > 0)
    {   
        tree[index] += 1;
        index/=2;
    }
}

long sum(int node){
    int left = S+1;
    int right = node + S;

    long value = 0;

    while(left <= right ){
        if(left % 2 == 1){
            value += tree[left];
            left ++;
        }
        if(right % 2 == 0){
            value += tree[right];
            right--;
        }
        left /= 2;
        right /= 2;
    }

    return value;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> N;
    level = 1;
    while(S<N){
        S+= level;
        level *= 2;
    }

    int a;
    for(int i=1;i<=N;i++){
        cin >> a;
        A.push({a, i});
    }
    for(int i=1;i<=N;i++){
        cin >> a;
        B.push({a, i});
    }

    int px, py;
    long ans = 0;
    while(true){
        if(A.empty()|| B.empty()) break;
        px = A.top().second;
        py = B.top().second;
        A.pop();
        B.pop();
        pq.push({py, px});
    }
    while(!pq.empty()){
        px = pq.top().second;
        pq.pop();
        ans += sum(px);
        update(px);
    }
    cout << ans;
    return 0;
}
