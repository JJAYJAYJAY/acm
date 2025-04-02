//
// Created by lyh on 2025/3/31.
//
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    freopen("src/luogu/P10000+/in/P11968.in","r",stdin);

    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        ll x,k;
        cin>>x>>k;
        ll pre=0;int les=k;
        ll up_mn=2e18,low_mx=-2e18;
        //2进制下判断两个数大小只需要看最高的不同位
        for(int i=60;i>=0;i--){//枚举和x在i位不同
            if(i+1<les)break;
            if(x>>i&1){//如果x在i位为1,可以构造比它小的low_mx
                if(les<=i){//要放的1个数必须小于等于没放的位置
                    ll add=0;
                    for(int j=i-1;j>i-1-les;j--){//尽可能放大的位置(i位不放是为了保证比x小)
                        add+=1ll<<j;
                    }
                    low_mx=max(low_mx,pre+add);//更新值
                }
                if(les==0)break;//更新pre,比i位高的位置和x保持相同，因为枚举的是第一个和x不同的位置，如果1用完了就提前结束
                pre+=1ll<<i;
                les--;
            }else{//同理构造比它大的up_min
                if(les>=1&&les<=i+1){//i位放1,其它尽可能放小的位置，同样需要检查个数
                    ll add=1ll<<i;
                    for(int j=0;j<les-1;j++){
                        add+=1ll<<j;
                    }
                    up_mn=min(up_mn,pre+add);
                }
            }
        }
        //检验是否能够完全相同
        int cnt=0;
        for(int i=60;i>=0;i--){
            if(x>>i&1)cnt++;
        }
        if(cnt==k){
            cout<<0<<"\n";
        }else{
            cout<<min(up_mn-x,x-low_mx)<<"\n";
        }
    }
    fclose(stdin);
    return 0;
}

//6
//2
//2
//9
//0
//163952066559
//1