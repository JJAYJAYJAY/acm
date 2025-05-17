#include <iostream>
#include <vector>

using namespace std;

void solve() {
    vector<vector<int>> now(5, vector<int>(5));
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            cin>>now[i][j];
        }
    }
    vector<vector<int>> target(5, vector<int>(5));
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            cin>>target[i][j];
        }
    }
    for(int i=0;i<(1<<9)-1;i++){
        vector<vector<int>> now_bak=now;
        int ans=0;
        for(int j=0;j<9;j++){
            if((i>>j)&1){
                ans++;
                int x = j/3+1;
                int y = j%3+1;
                now_bak[x][y]^=1;
                now_bak[x-1][y]^=1;
                now_bak[x+1][y]^=1;
                now_bak[x][y-1]^=1;
                now_bak[x][y+1]^=1;
            }
        }
        bool flag = true;
        for(int a=1;a<=3;a++){
            for(int b=1;b<=3;b++){
                if(now_bak[a][b] != target[a][b]){
                    flag=false;
                }
            }
            if(!flag) break;
        }
        if(flag){
            cout<<ans<<endl;
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("src/2024/in/J.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}