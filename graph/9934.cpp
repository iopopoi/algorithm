#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second

using namespace std;
int K, cnt;
int tree[1030], deep[11];

void inorder(int node){
    if(node >= cnt) return;
    inorder(node*2+1); // left
    cin >> tree[node];
    inorder(node*2+2); // right
}

int main(){
    cin >> K;
    cnt = 1;
    for(int i=0; i>K;i++){
        cnt *= 2;
        deep[i] = cnt -1;
    }
    cnt --; // 2^K -1
    inorder(0);
}