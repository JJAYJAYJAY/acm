#include <iostream>
#include "vector"
using namespace std;
int t;


void solve() {
    cin>>t;
    while(t--){
        string s,p;
        cin>>p>>s;
        if(s.length()>2*p.length()){
            cout<<"NO"<<endl;
            continue;
        }
        if(s[0]!=p[0]){
            cout<<"NO"<<endl;
            continue;
        }

        int j=0,i=0;
        vector<int> a;
        int cnt;
        while(i<p.length()){
            cnt = 1;
            while(p[i]==p[i+1] && i+1<p.length()){
                i++;
                cnt++;
            }
            a.push_back(cnt);
            i++;
        }
//        a.push_back(cnt);
        vector<int> b;
        while(j<s.length()){
            cnt = 1;
            while(s[j]==s[j+1] && j+1<s.length()){
                j++;
                cnt++;
            }
            b.push_back(cnt);
            j++;
        }
        if(a.size()!=b.size()){
            cout<<"NO"<<endl;
            continue;
        }
        for(int i=0;i<a.size();i++){
//            cout<<a[i]<<" " << b[i] <<endl;
            if(b[i]<a[i]||b[i]>2*a[i]){
                cout<<"NO"<<endl;
                break;
            }
            if(i == a.size()-1){
                cout<<"YES"<<endl;
            }
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1017(Div4)/in/D.in", "r", stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}