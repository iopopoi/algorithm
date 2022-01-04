#include <iostream>
using namespace std;

int main(){
    long long X, Y, Z; cin>> X >>Y;
    Z = (Y * 100) / X;
    if(Z == 100 || Z == 99) cout << -1;
    else{
        long long s=0, e=1000000001, m, ans=1000000001;
        while(s <= e){
            m = (s+e)/2;
            if(((Y+m)*100)/(X+m) > Z){
                e = m-1;
                ans = min(ans, m);
            }
            else{
                s = m+1;
            }
        }
        // for(int i=0;i<=ans;i++){
        //     // cout << Z << " " << i <<  " " << ((Y+i)*100)/(X+i)<<"\n";
        // }
        cout << ans<<"\n";
    }
}