//
// Created by lyh on 2025/4/3.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t;

int main(){
#ifdef LOCAL
    freopen("src/codeforce/Round1013(Div3)/in/B.in","r",stdin);
#endif
    scanf("%d",&t);
    while(t--){
        int n,k;
        scanf("%d%d",&n,&k);
        vector<int> a;
        while(n--){
            int x;
            scanf("%d",&x);
            a.push_back(x);
        }
        sort(a.begin(),a.end(),greater<int>());
        int ans=0;
        int cnt=0;
        int min = -1;
        for(auto item : a){
            min = item;
            cnt++;
            if(cnt*min>=k){
                ans++;
                min=-1;
                cnt=0;
            }
        }
        cout<<ans<<endl;
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}