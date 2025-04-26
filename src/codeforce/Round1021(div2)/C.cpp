#include <iostream>
#include <vector>
#include<algorithm>
#include <set>
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a[i]=x;
    }
    sort(a.begin(), a.end());
    int last=0;
    bool flag= false;
    for(int i=0;i<n;i++){
        if(i-1>=0&&a[i]-a[i-1]==1&&flag){
            int cnt=1;
            while(i+1<n&&a[i]==a[i+1]){
                cnt++;
                if(cnt>=2){
                    cout<<"YES"<<endl;
                    return;
                }
                i++;
            }
        }else{
            int cnt=1;
            while(i+1<n&&a[i]==a[i+1]){
                cnt++;
                if(cnt>=4){
                    cout<<"YES"<<endl;
                    return;
                }
                i++;
            }
            if(cnt>=2){
                flag=true;
            }else{
                flag=false;
            }
        }
    }
    cout<<"NO"<<endl;
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1021(div2)/in/C.in", "r", stdin);
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