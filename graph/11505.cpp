#include <iostream>
#include <algorithm>

using namespace std;
int N, M, K;
int a, b, c;
int inner_size, level;
long long arr[4000000];

void CHAN(int b, int c){
    b = b + inner_size;
    arr[b] = c;
    while(b>1){
        b /= 2;
        arr[b] = ((arr[b*2] % 1000000007) * (arr[b*2+1] % 1000000007)) % 1000000007;
    }
}

long long MUL(int L, int R){
    long long ans = 1;
    L += inner_size;
    R += inner_size;

    while(L <= R){
        if(L % 2 == 1) ans = (ans * arr[L]) % 1000000007;
        if(R % 2 == 0) ans = (ans * arr[R]) % 1000000007;

        L = (L + 1) / 2;
        R = (R - 1) / 2;
    }
    return ans;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M >> K;
    level = 1;
    while (inner_size < N)
    {
        inner_size += level;
        level *= 2;
    }
    for(int i=1;i<=N;i++) 
        cin >> arr[inner_size + i];

    for(int i = inner_size; i > 0; i--)
        arr[i] = ((arr[i*2] % 1000000007) * (arr[i*2+1] % 1000000007)) % 1000000007;

    K += M;
    for(int i=0;i < K;i++){
        cin >> a >> b >> c;
        if(a == 1){
            CHAN(b, c);
        }   
        else{
            cout << MUL(b, c) << "\n";
        }

    }
}   