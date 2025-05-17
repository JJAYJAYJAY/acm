#include <iostream>
#include <queue>

using namespace std;
const int N =1e3+10;

char ans[N][N];

void solve() {
    int h,w;
    cin>>h>>w;
    vector<pair<int,int>> e;
    queue<pair<int,int>> q;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            char c;
            cin>>c;
            if(c=='#') {
                ans[i][j] = '#';
            }
            if(c=='.') {
                ans[i][j] = '.';
            }
            if(c=='E'){
                e.emplace_back(i,j);
                q.emplace(i,j);
                ans[i][j] = 'E';
            }
        }
    }

    int dx[4] = {0, 0, -1, 1},dy[4] = {-1, 1, 0, 0};
    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=1&&nx<=h&&ny>=1&&ny<=w){
                if(ans[nx][ny]=='.'){
                    if(i==0) ans[nx][ny]='>';
                    if(i==1) ans[nx][ny]='<';
                    if(i==2) ans[nx][ny]='v';
                    if(i==3) ans[nx][ny]='^';
                    q.emplace(nx,ny);
                }
            }
        }
    }
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cout<<ans[i][j];
        }
        cout<<endl;
    }
}

int main() {
#ifdef LOCAL
    freopen("src/atCode/BeginerContest405/in/D.in", "r", stdin);
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