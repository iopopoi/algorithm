#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second

using namespace std;

int N;
vector < pair<int,int> > v(100);

void preorder(char root){
    cout << root ; // root
    if(v[root].fst != '.')  preorder(v[root].fst); // left subtree
    if(v[root].snd != '.')  preorder(v[root].snd); // right subtree
}
void inorder(char root){
    if(v[root].fst != '.')  inorder(v[root].fst); // left subtree
    cout << root ; // root
    if(v[root].snd != '.')  inorder(v[root].snd); // right subtree
}
void postorder(char root){
    if(v[root].fst != '.')  postorder(v[root].fst); // left subtree
    if(v[root].snd != '.')  postorder(v[root].snd); // right subtree
    cout << root ; // root
}

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        char P, L, R;
        cin >> P >> L >> R; 
        v[P]={L, R};
    }
    preorder('A'); 
    cout << "\n";
    inorder('A'); 
    cout << "\n";
    postorder('A'); 
}