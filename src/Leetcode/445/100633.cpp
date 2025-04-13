#include <iostream>

using namespace std;

void solve() {
    int x,y,z;
    cin>>x>>y>>z;
    if(abs(z-x)>abs(z-y)){
        cout<<2<<endl;
    }
    else if(abs(z-x)<abs(z-y)){
        cout<<1<<endl;
    }
    else if(abs(z-x)==abs(z-y)){
        cout<<0<<endl;
    }
}

int main() {
#ifdef LOCAL
    freopen("src/Leetcode/445/in/100633.in","r",stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}