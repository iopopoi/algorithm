#include <iostream>
#include <vector>
#include <queue>
using namespace  std;

int main() {
    int T; cin>> T;
    int N, M, a, b, A, B;
    for(int t=1; t<=T; t++){
        vector<int> status, time; 
        vector<vector<int> >map(1001);
        
        cin>> N >> M >> A >> B;
        while(M--){
            cin>> a>> b;
            map[a].push_back(b);
            map[b].push_back(a);
        }

        queue<vector<int> > q[2]; // spot, team, time
        status.resize(N+1,0);
        time.resize(N+1,0);

        status[A] = 1;
        status[B] = 2;
        time[A] = 1;
        time[B] = 1;

        int now=0;
        q[0].push({A,1,1}); // 1은 A팀지역
        q[0].push({B,2,1}); // 2는 B팀지역

        while( !q[0].empty() || !q[1].empty()){
            while(!q[now].empty()){
                int spot = q[now].front()[0], team=q[now].front()[1], spot_time=q[now].front()[2];
                q[now].pop();
                if(status[spot] == 3) continue;
                for(int i=0; i<map[spot].size(); i++){
                    if(time[map[spot][i]]==0){
                        q[(now+1)%2].push({map[spot][i],team, spot_time+1});
                        status[map[spot][i]] = team;
                        time[map[spot][i]] = spot_time + 1;
                    }
                    else if(time[map[spot][i]] == spot_time+1 &&  status[map[spot][i]] != team &&  status[map[spot][i]] < 3){
                        status[map[spot][i]] = 3;
                    }
                    else if(status[map[spot][i]]==3 && time[map[spot][i]] < spot_time){
                        status[map[spot][i]] = team;
                        q[(now+1)%2].push({map[spot][i],team, spot_time+1});
                    }
                }
            }

            now = (now+1)%2;
        }
        int cnt[3]={0,0,0}, result, D=0; //A, B, N
        for(int i=1;i<=N;i++){
            cnt[status[i]%3]++;
            if(status[i]==3) D++;
        }
        if(cnt[1]>cnt[2]) result = 0;
        else if(cnt[1]+cnt[0]>cnt[2]) result = cnt[2]-cnt[1]+1;
        else result = -1;

        cout << "#"<<t<<" "<<D<<" "<<result<<"\n";
    }


    return 0;
}