#include <iostream>

using namespace std;

int N, M;
char a;
int b, c;
long long d;
long long tree[100001][2]; // node, gap

int Find(int x){
    // int xTop = x;
    // while(xTop !=tree[xTop][0]){
    //     tree[x][1] += tree[xTop][1];
    //     xTop = tree[xTop][0];
    // }
    // return tree[x][0] = xTop;
    if(x == tree[x][0]) return x;
    int par = Find(tree[x][0]);
    tree[x][1] += tree[tree[x][0]][1];
    return tree[x][0] = par;
}

void Union(int A, int B, long long gap){
    int TopA = Find(A);
    int TopB = Find(B);
    if(TopA!=TopB){
        tree[TopA][0] = TopB;
        tree[TopA][1] = tree[B][1] - tree[A][1] + gap;
    }
}


int main(){
    cin.tie(0); ios_base::sync_with_stdio(0);
    while(true){
        cin >> N >> M;
        if(N==0 && M==0) break;
        for(int i=0;i<=N;i++){
            tree[i][0] = i;
            tree[i][1] = 0;
        }  
        while(M--){
            cin >> a;
            if(a=='!'){
                cin >> b >> c>> d;
                Union(b, c, d);
            }
            else {
                cin >> b>> c;
                if(Find(b) == Find(c)) cout << tree[b][1]-tree[c][1] <<"\n";
                else cout << "UNKNOWN\n";
            }
        }
    }
    return 0;
}