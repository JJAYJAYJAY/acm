#include <iostream>
#include <vector>
#include "unordered_map"
#include "algorithm"
using namespace std;
int n;
string s;

char get_char(int i){
    char a[]={'T','L','I'};
    if(s[i]==s[i+1]) return 'N';
    for(auto u:a){
        if(s[i]!=u&&s[i+1]!=u) return u;
    }
    return 'N';
}

void solve() {
    int t;
    cin>>t;
    while(t--){
        unordered_map<char,int> mp;
        cin>>n>>s;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        if(mp['I']==mp['L']&&mp['L']==mp['T']){
            cout<<0<<endl;
            continue;
        }
        if(n==1){
            cout<<-1<<endl;
            continue;
        }
        vector<int> ans;
        int lock;
        while(max({mp['I'],mp['L'],mp['T']})!=min({mp['I'],mp['L'],mp['T']})){
            int mx=max({mp['I'],mp['L'],mp['T']});
            lock = 1;
            for(int i=0;i<s.size()-1;i++){
                char j = get_char(i);
                if(j!='N'&&mp[j]<mx){
                    mp[j]++;
                    s.insert(s.begin()+i+1, j);
                    ans.push_back(i+1);
                    lock = 0;
                }
            }
            if(lock){
                for(int i=0;i<s.size()-1;i++){
                    char j = get_char(i);
                    if(j!='N'&&mp[j]==mx){
                        mp[j]++;
                        s.insert(s.begin()+i+1, j);
                        ans.push_back(i+1);
                        lock = 2;
                        break;
                    }
                }
            }
            if(lock ==1){
                break;
            }
        }
        if(lock ==1){
            cout<<-1<<endl;
            continue;
        }
        if(ans.size()>2*n){
            cout<<-1<<endl;
        }else{
            cout<<ans.size()<<endl;
            for(auto u:ans){
                cout<<u<<" "<<endl;
            }
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1014(Div2)/in/D.in","r",stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}