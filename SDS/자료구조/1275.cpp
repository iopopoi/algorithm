#include <iostream>
#define ll long long
using namespace std;

ll seg[2000001];
ll N, Q, seg_size;

void update(int index, int num){
    index = index + seg_size;
    seg[index] = num;
    while(index>1){
        index /= 2;
        seg[index] = seg[index*2] + seg[index*2+1];
    }
}

ll order(long L, ll R, ll vertex, ll nL, ll nR){
    if( nL > R || nR < L ) return 0;
    if( nL >= L && nR <= R ) return seg[vertex];
    ll mid = (nL + nR)/2;
    return order(L, R, vertex*2, nL, mid) + order(L, R, vertex*2+1, mid+1, nR);
}


int main(){
    cin.tie(0);cout.tie(0);
    cin >> N >> Q;
    ll level=1;
    while(seg_size<N){
        seg_size += level;
        level *= 2;
    }
    for(ll i=1;i<=N;i++){
        cin>>seg[i+seg_size];
    }
    for(ll i=seg_size;i>=1;i--){
        seg[i] = seg[i*2] + seg[i*2+1];
    }
    while(Q--){
        ll a[4];
        cin >> a[0] >> a[1] >> a[2] >> a[3];
        if(a[0]>a[1]){
            ll temp;
            temp = a[0]; a[0] = a[1]; a[1]=temp;
        }
        cout << order(a[0], a[1], 1, 1, seg_size+1) << "\n";
        update(a[2], a[3]);
    }
}