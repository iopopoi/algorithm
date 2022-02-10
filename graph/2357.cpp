#include <iostream>
#include <algorithm>

using namespace std;

int N, M, inner_size, level;
int a, b; 
int maxtree[400001], mintree[400001];
int ans[2]; // max, min

void construct(){
    for(int i = inner_size; i > 0 ; i--){
        maxtree[i] = max(maxtree[i * 2], maxtree[i * 2 + 1]);
        mintree[i] = min(mintree[i * 2], mintree[i * 2 + 1]);
    }
}

void find_ans(int L, int R){
    L += inner_size;
    R += inner_size;

    ans[0] = 0;
    ans[1] = 1000000001;

    while(L <= R){
        // left가 홀수 이면 오른쪽 자식이면 갱신한다.
        // right가 짝수 이면 왼쪽 자식이면 갱신한다.
        if(L % 2 == 1){
            ans[0] = max(ans[0], maxtree[L]);
            ans[1] = min(ans[1], mintree[L]);
        }
        if(R % 2 == 0){
            ans[0] = max(ans[0], maxtree[R]);
            ans[1] = min(ans[1], mintree[R]);
        }
        L = (L + 1)/2;
        R = (R - 1)/2;
    }
}


int main(){
    cin.tie(0); ios_base:: sync_with_stdio(0);

    cin >> N >> M;

    level = 1;
    while( inner_size < N){
        inner_size += level;
        level *= 2 ;
    }

    for(int i=1;i<= N;i++){
        cin >> maxtree[inner_size + i];
        mintree[inner_size + i] = maxtree[inner_size + i];
    }
    construct();
    for(int i=0;i<M;i++){
        cin >> a >> b;
        if(b < a){
            int temp = a; a = b; b = temp;   
        }
        find_ans(a, b);
        cout << ans[1] << " " << ans[0] << "\n";
    }
}