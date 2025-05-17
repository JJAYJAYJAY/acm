#include <iostream>
#include <vector>
#include "algorithm"
using namespace std;
using ll = long long;
void solve() {
    int n;
    cin>>n;
    int x = (n-1)/2, y = (n-1)/2;
    static int dx[4] = {0, 1, 0, -1};
    static int dy[4] = {1, 0, -1, 0};

    int num = 0;
    vector<vector<int>> a(n, vector<int>(n, 0));
    a[x][y] = num++;

    int step = 1, dir = 0;
    while(num < n*n){
        for(int repeat = 0; repeat < 2; repeat++){
            for(int s = 0; s < step && num < n*n; s++){
                x += dx[dir];
                y += dy[dir];
                if(x>=0 && x<n && y>=0 && y<n){
                    a[x][y] = num++;
                }
            }
            dir = (dir + 1) % 4;
        }
        step++;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << a[i][j] <<' ';
        }
        cout << endl;
    }
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1024(Div2)/in/C.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int work = 1;
    cin>>work;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}