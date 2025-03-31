//
// Created by 24223 on 2025/3/31.
//

#include <iostream>

using namespace std;

long long find_1(long long x,long long k){
    long long ans=x;
//找到x二进制下最高位的1
    for(int i=60;i>=0;i--){
        if(ans<=0||k<=0){
            break;
        }
        if(x>>i&1){
            long long tmp=1;
            tmp<<=i;
//            cout<<tmp<<endl;
            ans-=tmp;
            k--;
        }
    }
    if(k>0){
        //找最低位的0，改成1
        for(int i=0;i<=60;i++){
            if(k<=0){
                break;
            }
            if(!(x>>i&1)){
                long long tmp=1;
                tmp<<=i;
                ans+=tmp;
                k--;
            }
        }
    }
    return ans;
}

//long long find_2(long long x,long long k){
//    long long ans=x;
//    while(ans>0&&k>0){
//        for(int i=60;i>=0;i--){
//            if(x>>i&1){
//                long long tmp=1;
//                tmp<<=i;
//                ans=ans&(~tmp);
//                k--;
//            }
//        }
//    }
//    return ans;
//}

void try1(){
    int T;
    cin>>T;
    long long x,k;
    while(T--){
        cin>>x>>k;
        long long ans=find_1(x,k);
        cout<<ans<<endl;
    }
}
int main(){
    freopen("data.in","r",stdin);
    try1();
    fclose(stdin);
    return 0;
}
