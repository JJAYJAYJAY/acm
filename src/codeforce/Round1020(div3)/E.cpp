#include <iostream>
#include <set>
#include "vector"
using namespace std;


void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> p(n);
    vector<int> pos(n+1);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        pos[p[i]] = i;
    }

    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        l--, r--;
        if(pos[k]<l||pos[k]>r){
            cout<<-1<<" ";
            continue;
        }
        int target_idx=pos[k];

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
        int small_cnt=0;
        int big_cnt=0;
        int all_small=0;
        int all_big=0;
        int nee_change=0;
        for(int i=0;i<path.size()-1;i++){
            if(p[path[i]]<k){
                if(path[i+1]<path[i]){
                    all_big++;
                    small_cnt--;
                    nee_change++;
                    big_cnt++;
                }else{
                    all_small++;
                    continue;
                }
            }else{
                if(path[i+1]>path[i]){
                    all_small++;
                    big_cnt--;
                    nee_change++;
                    small_cnt++;
                }else{
                    all_big++;
                    continue;
                }
            }
        }
        if(all_small>k-1||all_big>n-k){
            cout<<-1<<" ";
            continue;
        }else{
            cout<<max(0,big_cnt)+max(0,small_cnt)+nee_change<<" ";
        }
    }
    cout<<endl;
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1020(div3)/in/E.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int work = 1;
    cin>>work;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}