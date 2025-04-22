#include <iostream>
#include <vector>

using namespace std;


void solve() {
    int t;
    cin>>t;
    while(t--){
        int n;
        string s;
        cin>>n>>s;
        int i =1;
        vector<int> ans;
        int cnt = 1;
        for(int j=0;j<s.length();j++){
            if(s[j]=='<'){
                cnt++;
            }
        }
        i = cnt-1;
        int first =cnt;
        cnt++;
        for(int j=0;j<s.length();j++){
            if(s[j]=='<'){
                ans.push_back(i);
                i--;
            }else{
                ans.push_back(cnt);
                cnt++;
            }
        }
        ans.insert(ans.begin(),first);
        for(int j=0;j<ans.size();j++){
            cout<<ans[j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1018(Div1+Div2)/in/A.in","r",stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}