#include <iostream>
#include "vector"
using namespace std;

bool isPrime(int x){
    if(x <= 1)
        return 0;
    for(int i = 2 ; i * i <= x ; ++i)
        if(x % i == 0)
            return 0;
    return 1;
}

void solve() {
    int n;
    cin>>n;
    vector<int> ans;
    for(int x = 0 ; ; x++){
        if(isPrime(n / 2 - x)){
            int p = n / 2 - x;
            ans.push_back(p);
            for(int i = 1 ; i <= n ; ++i){
                if(p - i > 0)
                    ans.push_back(p - i);
                if(p + i <= n)
                    ans.push_back(p + i);
            }
            break;
        }
        if(isPrime(n / 2 + x)){
            int p = n / 2 + x;
            ans.push_back(p);
            for(int i = 1 ; i <= n ; ++i){
                if(p - i > 0)
                    ans.push_back(p - i);
                if(p + i <= n)
                    ans.push_back(p + i);
            }
            break;
        }
    }
    for(int i = 0 ; i < ans.size() ; ++i){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1012(Div2)/in/D.in", "r", stdin);
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