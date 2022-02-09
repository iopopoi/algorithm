/*
    BOJ. 4803 트리
    각 테스트 케이스마다 주어진 그래프에서 트리의 개수를 파악하는 문제이다.

    사용한 알고리즘
    - 유니온 파인드
    - 트리: 순회가 있으면 트리가 아니다.

    문제 풀이
    1. 간선의 정보(A, B)가 들어오면 A와 B각 속한 tree의 root를 구한다.
    2. 같은 간선의 정보가 들어오지 않기 때문에 A와 B의 root가 같은 경우이는 순환이 생김을 의미한다.
       (A-root-B의 경로와 A-B 경로가 존재하기 때문에 순환발생)
    3. A, B의 연결로 순환이 발생하는 경우 이들의 parent정보를 -1로 표기하여 해당 노드의 그래프는 트리가 아님을 나타낸디.
    4. 모든 간선의 정보를 입력받은후 각 노드각 속한 tree의 root를 확인하여 root의 개수를 구해 반환한다.
*/

#include <iostream>
#include <vector>

using namespace std;

int arr[501], chk[501];
int N, M, t=1, cnt;
int a, b;

// 해당 node가 속한 tree의 root를 구한다. 
// root를 구할 수 없는 경우(tree에 속한 node가 아닌경우) 노드의 root는 -1이 되도록한다.
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

// 두 노드 A와 B가 속한 tree, graph를 연결한다.
// 둘의 연결로 순환이 발생하면 이 둘이 속한 그래프는 트리가 아니다.
void Union(int A, int B){
    int topA = Find(A);
    int topB = Find(B);

    // A와 B가 속한 트리의 root가 같으면 
    // A와 B를 연결하는 간선이 있는 경우 트리의 순회가 생긴다.
    if(topA == topB || topA == -1 || topB == -1){
        arr[topA] = -1; // A, B가 속한 그래프는 트리가 아니다.
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

        // tree의 root의 개수(트리의 개수)를 구한다.
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