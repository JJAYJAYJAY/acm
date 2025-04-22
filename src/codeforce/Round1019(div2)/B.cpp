#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cnt = 1;
    for(int i=1;i<n;i++){
        if(s[i] != s[i-1]) {
            cnt++;
        }
    }
    int res=n;
    if(s[0]=='1'){
        res+=1;
    }
    if(cnt==1){
    }else if(cnt == 2){
        res += 1;
        if(s[0] == '1'){
            res--;
        }
    }else{
        res += cnt-1-2;
        if(cnt ==3){
            if(s[0] == '0'){
                res++;
            }
        }
    }
    cout<<res<<endl;
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1019(div2)/in/B.in", "r", stdin);
#endif
    int work = 1;
    cin>>work;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}