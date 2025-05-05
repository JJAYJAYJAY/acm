#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n+1);
    vector<int> p(n+1);
    unordered_map<int,vector<int>> pos;
    int mx=0;
    int target_idx=-1;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        mx=max(mx,x);
        a[i]=x;
        if(x==-1){
            target_idx=i;
        }
        pos[x].push_back(i);
    }
    int x=1,y=n;

    for(int i=1;i<=mx;i++){
        if(i%2==1){
            //左边倒着填右边正着填
            int a=y-pos[i].size()+1;
            int b=y;
            for(int j=pos[i].size()-1;j>=0;j--){
                if(pos[i][j]<target_idx){
                    p[pos[i][j]]=a++;
                }else{
                    p[pos[i][j]]=b--;
                }
            }
            y-=pos[i].size();
        }else{
            //左边正着填右边倒着填
            int a=x;
            int b=x+pos[i].size()-1;
            for(int j=0;j<pos[i].size();j++){
                if(pos[i][j]<target_idx){
                    p[pos[i][j]]=a++;
                }else{
                    p[pos[i][j]]=b--;
                }
            }
            x+=pos[i].size();
        }
    }

    p[pos[-1][0]]=x;
    for(int i=0;i<n;i++){
        cout<<p[i]<<" ";
    }
    cout<<endl;
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1019(div2)/in/D.in", "r", stdin);
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