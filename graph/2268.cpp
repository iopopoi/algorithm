#include <iostream>
#include <algorithm>

using namespace std;

int inner_size, level;
int N, M;
int a, b, c;
long long k;
long long arr[4000000];

void modify(int idx, long long val){
    idx += inner_size;
    arr[idx] = val;
    while(idx>1){
        idx /= 2;
        arr[idx] = arr[idx * 2] + arr[idx * 2 + 1];
    }
}

long long SUM(int L, int R){
    L += inner_size;
    R += inner_size;

    long long ans = 0;
    while(L <= R){
        if(L % 2 == 1) ans += arr[L];
        if(R % 2 == 0) ans += arr[R];

        L = (L + 1)/2;
        R = (R - 1)/2; 
    }
    return ans;
}



int main(){
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> N >> M;

    level = 1;
    while(inner_size<N){
        inner_size += level;
        level *= 2;
    }

    while(M--){
        cin >> a >> b;
        if(a == 0){
            cin >> c;
            if(c<b){
                int temp = b; b = c; c= temp;
            }
            cout << SUM(b, c) << "\n";
        }
        else{
            cin >> k;
            modify(b, k);
        }
    }
}