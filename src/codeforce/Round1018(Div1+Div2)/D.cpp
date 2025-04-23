#include <iostream>
#include <vector>
#include<map>
#include<set>
using namespace std;

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1018(Div1+Div2)/in/D.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int,set<int>> mp;
        map<int,set<int>> mp2;
        vector<pair<int, int>> points(n);
        for (int i = 0; i < n; ++i) {
            int x,y;
            cin>>x>>y;
            mp[x].insert(y);
            mp2[x+y].insert(x);
        }
        int ans_x;
        for(auto item:mp){
            if(item.second.size()%2==1){
                ans_x=item.first;
                break;
            }
        }
        int ans_b;
        for(auto item:mp2){
            if(item.second.size()%2==1){
                ans_b=item.first;
                break;
            }
        }

        cout<<ans_x<<" "<<-ans_x+ans_b<<endl;
    }

    return 0;
}