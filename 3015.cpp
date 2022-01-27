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
            if(s.top().second > x){
                ans += 1;
                s.push({1, x});
            }
            else{
                while(!s.empty() && s.top().second < x){
                    ans += s.top().first;
                    s.pop();
                }
                if(!s.empty() && s.top().second == x){
                    ans += s.top().first;
                    s.top().first++;
                    if(s.size()>1) ans += 1;
                }
                else if(!s.empty()){
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