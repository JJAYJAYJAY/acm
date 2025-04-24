#include <iostream>
#include <set>
#include "vector"
using namespace std;

//找到数组中第一个比他小的数字
int find_min(vector<int> &p,int x){
    int l=0,r=p.size()-1;


    return l;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> p(n);
    set<pair<int,int>> s;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        l--, r--;
        int target_idx=-1;
        for(int i=l;i<=r;i++){
            if(p[i]==k){
                target_idx=i;
            }
        }
        if(target_idx==-1){
            cout<<-1<<" ";
            continue;
        }

        //构造路径
        vector<int> path;
        while(l<=r){
            int mid = (l+r)/2;
            path.push_back(mid);
            if(mid == target_idx){
                break;
            }else{
                if(mid<target_idx){
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }
        }
        int ans = -1e9;
        int small_cnt=0;
        int big_cnt=0;
        for(int i=0;i<path.size()-1;i++){
            if(p[path[i]]<k){
                if(path[i+1]<path[i]){
                   ans = max(ans,path[i]);
                   big_cnt++;
                }else{
                    continue;
                }
            }else{
                if(path[i+1]>path[i]){
                    ans = max(ans,path[i]);
                    small_cnt++;
                }else{
                    continue;
                }
            }
        }
        if(ans==-1e9){
            cout<<0<<" ";
        }else{
            cout<<ans<<" ";
        }
    }
    cout<<endl;
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1020(div3)/in/E.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int work = 1;
    cin>>work;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}