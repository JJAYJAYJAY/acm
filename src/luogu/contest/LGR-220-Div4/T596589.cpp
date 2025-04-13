#include <iostream>

using namespace std;

int n;
int all_a,all_b,all_c;
void solve() {
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int a;
        scanf("%d",&a);
        all_a+=8-a;
        int b;
        scanf("%d",&b);
        all_b+=12-b;
        int c;
        scanf("%d",&c);
        all_c+=1-c;
    }
    cout<<min(min(all_a/8,all_b/12),all_c)<<endl;
}

int main() {
#ifdef LOCAL
    freopen("src/luogu/contest/LGR-220-Div4/in/T596589.in", "r", stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}