#include <iostream>
#include <vector>

using namespace std;

int arr[501], chk[501];
int N, M, t=1, cnt;
int a, b;

int Find(int node){
    int top = node;
    while(arr[top] != top && top != -1){
        top = arr[top];
        if(top == node){
            arr[node] = -1; // tree가 아니다 : 순회가 있다.
            return -1;
        }
    }
    arr[node] = top;
    return top;
}

void Union(int A, int B){
    int topA = Find(A);
    int topB = Find(B);

    if(topA == topB || topA == -1 || topB == -1){
        arr[topA] = -1;
        arr[topB] = -1;
        arr[A] = -1;
        arr[B] = -1;
    }
    else{
        arr[topA] = arr[topB];
    }
}

int main(){
    while(true){
        cin >> N >> M;
        if(N==0&&M==0) break;

        for(int i=1;i<=N;i++){
            arr[i] = i;
            chk[i] = 0;
        } 
        cnt = 0;

        while(M--){
            cin >> a>> b;
            Union(a, b);
        }
        int f;
        for(int i=1;i<=N;i++){
            f = Find(i);
            if( f != -1 && chk[f] == 0){
                cnt ++;
                chk[f] = 1;
            }
        }

        cout << "Case " << t << ": ";
        if( cnt == 0){
            cout << "No trees.\n";
        }
        else if(cnt == 1){
            cout << "There is one tree.\n";
        }
        else{
            cout << "A forest of " << cnt << " trees.\n";
        }
        t++;
    }


}