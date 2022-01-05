#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    string s; cin>> s;
    stack<int> st;
    int ans=0;
    for(int i=0;i<s.size();i++){
        if(s[i] == '['){
            st.push(-1);
        } 
        else if(s[i] == '('){
            st.push(-2);
        }
        else if(s[i] == ']'){
            int x=0;
            while(!st.empty() && st.top()!= -1 && st.top()!= -2){
                x += st.top();
                st.pop();
            }
            if(st.empty() || st.top() == -2){
                cout << 0;
                return 0;
            }
            else{
                st.pop();
                if(x == 0) st.push(3);
                else st.push(x*3);
            }
        }
        else if(s[i] == ')'){
            int x=0;
            while(!st.empty() && st.top()!= -1 && st.top()!= -2){
                x += st.top();
                st.pop();
            }
            if(st.empty() || st.top() == -1){
                ans = -1;
                break;
            }
            else{
                st.pop();
                if(x == 0) st.push(2);
                else st.push(x*2);
            }
        }
        else{
            ans = -1;
            break;
        }
    }
    if(ans == -1){
        cout << 0;
    }
    else{
        while(!st.empty() && st.top()!= -1 && st.top()!= -2){
            ans += st.top();
            st.pop();
        }
        if(st.size()!=0){
            cout << 0;
        }
        else{
            cout<<ans;
        }
    }
}