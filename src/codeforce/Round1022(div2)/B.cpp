#include <iostream>
#include<bitset>
using namespace std;

void solve() {
    int n,x;
    cin>>n>>x;
    //将x转为二进制
    bitset<32> b(x);
    //输出b
//    cout<<b<<endl;
    int cnt = b.count();
//    cout<<cnt<<" ";
    if(x==0){
        if(n==1){
            cout<<-1<<endl;
            return;
        }
        if(n%2==0){
            cout<<n<<endl;
            return;
        }else{
            cout<<n+3<<endl;
            return;
        }
    }
    if(x==1){
        if(n%2==1){
            cout<<n<<endl;
            return;
        }else{
            cout<<n+3<<endl;
            return;
        }
    }
    if(n<=cnt){
        cout<<x<<endl;
        return;
    }
    if(x%2==1){
        if((n-cnt)%2==0){
            cout<<x+n-cnt<<endl;
            return;
        }else{
            cout<<x+n-cnt+1<<endl;
            return;
        }
    }else{
        if((n-cnt)%2==0) {
            cout << x + n - cnt << endl;
            return;
        }else{
            cout<<x+n-cnt+1<<endl;
            return;
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1022(div2)/in/B.in","r",stdin);
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