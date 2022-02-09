// BOJ.3015 오아시스 결합
/*
    1. stack을 이용한다.
    2. i번 사람의 키가 들어오면 바로 바로 ans(쌍의 개수)를 갱신한다.
    3. stack의 top값에 저장된 높이는 항상 가장 작은 값이다.
    4. i번 사람은 0 ~ (i-1)번 사람중 서로 바라볼 수 있는 사람의수를 찾는다.
    5. stack이 비어 있다면?
    6. stack의 top값이 i번 사람보다 크다면?
    7. stack의 top값이 i번 사람보다 작다면?
    8. 같다면?
    9. stack에 사람의 키만 저장해도 될까? 같은 키의 사람이 연속하여 있다면?

    주의할 점!
    1. 키가 같은 사람은?
    2. 키가 같은 사람이 연속으로 있다면 다음에 들어온 사람이 이보다 클때 어떠한가?
    3. 반대로 다음에 들어온 사람이 더 작다면?
    4. 정답의 범위는?  
*/

#include <iostream>
#include <stack>

using namespace std;

int N, x;
stack<pair<long long, int> > s; // cnt, height
// stack에는 top값의 키가 가장 작도록 하여 값을 넣는다
// stack에는 사람의 키뿐 아니라 키가 같은 경우 해당 키의 사람 수를 함께 저장한다.
long long ans;

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    // 사람의 수
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> x;
        if(s.empty()){ // stack이 비어 있다면 stack에 x값을 넣어준다.
            s.push({1, x});
        }
        else{
            if(s.top().second > x){ // 6. stack의 top값이 i번 사람보다 크다면?
                // i번 째 사람은 바로 앞의 한 사람을 볼 수 있다.
                ans += 1;
                // stack에 i번째 사람 정보를 넣는다.
                s.push({1, x});
            }
            else{
                // 7. stack의 top값이 i번 사람보다 작다면?
                //    해당되는 사람들을 모두 볼 수 있다.
                while(!s.empty() && s.top().second < x){
                    ans += s.top().first;
                    s.pop();
                }
                // 8. 같다면?
                // 정보를 갱싢ㄴ다.
                if(!s.empty() && s.top().second == x){
                    ans += s.top().first;
                    s.top().first++;
                    // i번째 사람보다 커도 한명은 볼 수 있다.
                    if(s.size()>1) ans += 1;
                }
                else if(!s.empty()){ // stack의 모든 키정보가 x보다 작을 때
                    ans += 1;
                    s.push({1, x});
                }
                else{ 
                    s.push({1, x});
                }
            }
        }
        // cout << i << " " << x << " " << ans << "\n";

    }
    cout << ans;
}