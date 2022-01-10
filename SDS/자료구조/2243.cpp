#include <iostream>
#include <vector>

using namespace std;

int segT[4000000];
int n, level, segT_size;
void update(int candy,int num){
    candy = candy + segT_size;
    segT[candy] += num;
    while(candy > 1){
        candy /= 2;
        segT[candy] = segT[candy * 2] + segT[candy * 2 + 1];
    }
}

int order(int num){
    int p = 1;
    while(p<segT_size){
        p<<=1;
        if(segT[p]<num){
            num-=segT[p];
            p += 1;
        }
    }
    return p - segT_size;
}

int main(){
    cin.tie(0); cout.tie(0);
    level = 1;

    while(segT_size<1000000){
        segT_size += level;
        level *= 2;
    }

    cin >> n;
    int x;
    while(n--){
        cin>>x;
        if(x==1){
            int a, c; cin>> a;
            c = order(a);
            update(c, -1);
            cout<< c << "\n";
        }
        else if(x==2){
            int a,b; cin>>a>>b;
            update(a, b);
        }
    }

}