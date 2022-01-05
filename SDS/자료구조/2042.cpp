#include <iostream>
using namespace std;

long long tree[4000000];
long long ss = 0;

void construct(){ // make segment tree
    for(long long i= ss;i>=1;i--)
        tree[i] = tree[i*2] + tree[i*2+1];

}

void update(long long index, long long value){
    index = index + ss;
    tree[index] = value;
    while(index>1){
        index/=2;
        tree[index] = tree[index*2] + tree[index*2+1];
    }
}

long long solve(long long L, long long R, long long vertex, long long nL, long long nR){
    if(nL>R || nR<L) return 0;
    if( L<=nL && nR<=R ) return tree[vertex];
    long long mid = (nL+nR)/2;
    return solve(L, R, vertex*2, nL, mid) + solve(L, R, vertex*2+1, mid+1, nR);
}

int main(){
    cin.tie(0); cout.tie(0);
    long long N, M, K;
    cin >> N >> M >> K;
    long long level = 1;
    while(ss<N){
        ss += level;
        level *= 2;
    }
    for(int i=1;i<=N;i++){
        cin>>tree[ss+i];
    }
    construct();
    for(int i=0;i<M+K;i++){
        long long a,b,c;
        cin>> a>> b>> c;
        if(a==1){
            update(b,c);
        }
        else{
            cout << solve(b,c,1,1,ss+1)<<"\n";
        }
    }
}