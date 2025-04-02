//
// Created by 24223 on 2025/3/31.
//

#include <iostream>

using namespace std;

int main(){
    freopen("src/luogu/P10000+/in/P11968.in","r",stdin);
    int T;
    cin>>T;
    long long x,k;
    while(T--){
        cin>>x>>k;
        long long les=k;
        long long n=0;
        long long up_mn=2e18,low_mx=-2e18;
        int cnt=0;
        for(int i=60;i>=0;i--){
            if(x>>i&1) {
                cnt++;
            }
        }
        if(cnt==k){
            cout<<0<<endl;
            continue;
        }
        for(int i=60;i>=0;i--){
            if(i+1<les)break;
//            cout<<n<<endl;
            if(x>>i&1){
                //填0的情况
                long long tmp=0;
                if(les<=i){
                    for(int j=i-1;j>i-1-les;j--){
                        tmp += 1ll<<j;
                    }
                    low_mx=max(low_mx,n+tmp);
                }
                if(les==0) break;
                n+=1ll<<i;
//                cout<<n<<endl;
                les--;
            }else{
                if(les>=1&&les<=i+1){
                    long long tmp=1ll<<i;
                    for(int j=0;j<les-1;j++){
                        tmp+=1ll<<j;
                    }
                    up_mn=min(up_mn,n+tmp);
                }
            }
        }
        cout<<min(up_mn-x,x-low_mx)<<endl;
    }
    fclose(stdin);
    return 0;
}
