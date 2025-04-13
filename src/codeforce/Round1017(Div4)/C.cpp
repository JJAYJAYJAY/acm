#include <iostream>
#include<unordered_set>
#include<cstring>
using namespace std;

const int N = 805;
int g[N][N];
int st[2*N];

void solve() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        memset(st, 0, sizeof(st));
        unordered_set<int> elements;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin >> g[i][j];
                elements.insert(g[i][j]);
            }
        }
        int k=1;
        while(elements.count(k)){
            k++;
        }
        cout<<k<<" ";
        int i=1,j=1;
        while(i+j<=2*n){
            if(!st[i+j]) {
                cout<<g[i][j]<<" ";
                st[i+j]=1;
            }
            if(j==n){
                i++;
                j=1;
            }else{
                j++;
            }
        }
        cout<<endl;
    }
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1017(Div4)/in/C.in", "r", stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}