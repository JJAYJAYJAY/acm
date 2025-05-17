#include<iostream>
#include <queue>

using namespace std;

void solve() {
    priority_queue<int> a;
    for(int i=0;i<13;i++){
        int x;
        cin>>x;
        if(x>0){
            a.push(x);
        }
    }
    int ans =0;
    while(a.size()>=2){
        int x = a.top(); a.pop();
        int y = a.top(); a.pop();
        x--; y--;
        if(x>0) a.push(x);
        if(y>0) a.push(y);
        ans++;
    }
    cout<<ans<<endl;
}

int main() {
#ifdef LOCAL
    freopen("src/2024/in/A.in","r",stdin);
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