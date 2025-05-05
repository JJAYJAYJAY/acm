#include <iostream>

using namespace std;

void solve() {
    int n;
    cin>>n;
    long long odd_sum=0;
    long long even_sum=0;
    int all_mx=INT_MIN;
    int cnt=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x%2==0) {
            even_sum += x;
        }
        else {
            odd_sum += x;
            cnt++;
        }
        all_mx=max(all_mx,x);
    }
    if(odd_sum==0||even_sum==0){
        cout<<all_mx<<endl;
    }else{
        cout<<even_sum+odd_sum-cnt+1<<endl;
    }
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1014(Div2)/in/C.in", "r", stdin);
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