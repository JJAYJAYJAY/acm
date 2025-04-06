#include <iostream>
#include "vector"
#include "algorithm"
using namespace std;
int n;

void solve() {
    scanf("%d", &n);
    vector<int>a;
    for(int i=1,x;i<=n;i++)
    {
        scanf("%d",&x);
        a.insert(upper_bound(a.begin(),a.end(),x),x);//二分插入保证单调性
        if(i%2==1)
        {
            printf("%d\n",a[(i-1)/2]);//是奇数个就输出
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("src/luogu/P1000-P2000/in/P1168.in","r",stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}