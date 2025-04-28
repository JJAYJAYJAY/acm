#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
const int N = 1000010;
int nxt[N][26];
int f[N];

void solve() {
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    s.insert(0," ");

    for(int c = 0; c < k; c++){
        nxt[n+1][c] = n+1;
    }
    for(int i = n; i >= 1; i--){
        for(int c = 0; c < k; c++)
            nxt[i][c] = nxt[i+1][c];
        nxt[i][ s[i] - 'a' ] = i;
    }

    f[n+1] = 1;
    for(int i = n; i >= 1; i--){
        int best = INT_MAX;
        for(int c = 0; c < k; c++){
            int j = nxt[i][c];
            if(j == n+1){
                best = 1;
                break;
            } else {
                best = min(best, 1 + f[j+1]);
            }
        }
        f[i] = best;
    }

    int q;
    cin>>q;
    while(q--){
        string t;
        cin>>t;
        int now=1;
        int flag=true;
        for(char ch:t){
            int c = ch - 'a';
            if(nxt[now][c] == n+1){
                cout << 0 << "\n";
                flag = false;
                break;
            }
            now = nxt[now][c] + 1;
        }
        if(!flag) continue;
        cout<<f[now]<<endl;
    }
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/EduRound178(div2)/in/E.in", "r", stdin);
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