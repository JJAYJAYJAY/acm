#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int t;
int n,m;
const int N=2e5+5;
int st[N],cnt[N];
vector<string> a;
void solve() {
    scanf("%d", &t);
    while(t--) {
        a.clear();
        memset(st,0,sizeof(st));
        memset(cnt,0,sizeof(cnt));
        scanf("%d%d", &n, &m);
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            a.push_back(s);
        }
        int maxx =0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                string s;
                cin>>s;
                if(a[j]==s){
                    st[j]=1;
                    cnt[i]++;
                }
            }
            maxx = max(maxx,cnt[i]);
        }
        for(int i=0;i<n;i++){
            if(st[i]==0){
                cout<<-1<<endl;
                break;
            }
            if(i==n-1){
                cout<<n+(n-maxx)*2<<endl;
            }
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1016(Div3)/in/F.in", "r", stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}