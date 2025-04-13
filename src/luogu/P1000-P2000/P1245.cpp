#include <iostream>
#include <vector>
using namespace std;
const int N =1e6+10;


int char_map[26] = {1,1,1,2,2,2,3,3,3,4,4,4,5,5,6,6,6,7,7,7,8,8,8,9,9,9,};
int n;
int tr[N][15],idx;
string val[N];

void insert(string s){
    int p = 0;
    for(int i = 0; i < s.size(); i++){
        int id =  char_map[s[i]-'a'];
        if(tr[p][id] == 0){
            tr[p][id] = ++idx;
        }
        p = tr[p][id];
    }
    val[p] = s;
}

vector<string> ans;

bool dfs_find(string s,int p,int i){
    if(i == s.size()){
        return true;
    }
    int id = s[i]-'0';
    if(tr[p][id] == 0){
        return false;
    }else{
        if(!val[tr[p][id]].empty()){
            ans.push_back(val[tr[p][id]]);
            if(dfs_find(s,0,i+1)){
                return true;
            }
            ans.pop_back();
        }
        if(i==s.size()-1){
            return false;
        }
        return dfs_find(s,tr[p][id],i+1);
    }
}


void solve() {
    scanf("%d", &n);
    string s;
    cin>>s;
    for(int i=1;i<=n;i++){
        string t;
        cin>>t;
        insert(t);
    }
    if(!dfs_find(s,0,0) || ans.empty()) {
        printf("No Solutions!");
    }
    else {
        //最后一个不输出空格
        for(int i=0;i<ans.size();i++){
            if(i == ans.size()-1){
                cout<<ans[i];
            }else{
                cout<<ans[i]<<" ";
            }
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("src/luogu/P1000-P2000/in/P1245.in","r",stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}