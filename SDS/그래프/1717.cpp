// BOJ - 1717. 집합의 표현
/*
    Union find
    각 노드마다 연결된 1개의 노드가 주어질 때 트리를 구성하여 
    최상위 노드가 서로 같은 경우 같은 집합에 속함을 파악할 수 있다.

    처음에는 모든 부모 노드를 자기 자신으로 초기화하고, 
    연결관계가 주어질 때 마다 union 함수를 이용하여 트리를 구성한다.

    find 함수를 이용하여 최상단 노드를 찾아주고, 
    경로 압축을 진행하여 수행 시간을 단축시켜 줍니다.


*/

#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[1000001];

// find 함수를 이용하여 최상단 노드를 찾는다.
int find(int A){
    int topA = A;
    while(arr[topA] != topA){
        topA = arr[topA];
    }
    arr[A] = topA;
    return topA;
}

// A U B - 연결관계가 주어지면 union 함수를 이용하여 트리를 구성한다
void Union(int A, int B){
    arr[find(A)] = find(B);
}

int main(){
    cin.tie(0); cout.tie(0); 
    ios_base::sync_with_stdio(0);
    cin >> N >> M;

    // 처음에는 모든 부모노드를 자기 자신으로 초기화한다.
    for(int i=1;i<=N;i++) arr[i] = i; 

    int a, b, c;
    while(M--){
        cin >>a >> b  >> c;
        if(a == 0){
            // 연결관계가 주어질 때 마다 union 함수를 이용하여 트리를 구성한다
            Union(b,c);
        } 
        else{
            if(find(b) == find(c)) cout<<"YES\n";
            else cout << "NO\n";
        }
    }
}