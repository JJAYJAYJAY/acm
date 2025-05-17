#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> match(n+1,-1);
    vector<int> a(n+1),b(n+1);
    vector<int> pos_a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pos_a[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    int cnt=0;
    int pos=-1;
    for(int i=1;i<=n;i++){
        if(match[a[i]]!=-1&&match[a[i]]!=b[i]){
            cout<<-1<<endl;
            return;
        }
        match[a[i]]=b[i];
        match[b[i]]=a[i];
        if(a[i]==b[i]){
            cnt++;
            pos=i;
        }
    }
    if(n%2==0&&cnt>0) {
        cout << -1 << endl;
        return;
    }
    if(n%2==1&&cnt!=1){
        cout<<-1<<endl;
        return;
    }
    vector<pair<int,int>> ans;
    if(n%2==1){
        if(pos!=(n+1)/2){
            int mid = (n+1)/2;
            ans.emplace_back(pos, mid);
            swap(a[pos], a[mid]);
            swap(b[pos], b[mid]);
            pos_a[ a[pos] ] = pos;
            pos_a[ a[mid] ] = mid;
        }
    }
    for(int i=1;i<=n/2;i++){
        if(a[i]!=b[n-i+1]){
            int j = pos_a[ match[a[i]] ];
            int k = n - i + 1;
            ans.emplace_back(j, k);

            swap(a[j], a[k]);
            swap(b[j], b[k]);

            pos_a[ a[j] ] = j;
            pos_a[ a[k] ] = k;
        }
    }
    cout<<ans.size()<<endl;
    for(auto item:ans){
        cout<<item.first<<" "<<item.second<<endl;
    }
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1015(Div1+Div2)/in/C.in", "r", stdin);
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