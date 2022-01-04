#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    cin.tie(0);
    vector<int> nums;
    int N, M, x, cnt = 0;
    cin>> N >> M;
    for(int i=0;i<N;i++){
        cin >> x;
        nums.push_back(x);
    }
    int p1=0,p2=0, sum=nums[0];
    while(p1<N){
        if(sum == M){
            cnt ++;
            sum -= nums[p1++];
        }
        else if(sum<M){
            sum += nums[++p2];
        }
        else{
            sum -= nums[p1++];
            if(p2>=N)break;
        }
    }
    cout << cnt;
}