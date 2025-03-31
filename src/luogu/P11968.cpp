//
// Created by 24223 on 2025/3/31.
//

#include <iostream>

using namespace std;


void try1(){
    int T;
    cin>>T;
    long long x,k;
    while(T--){
        cin>>x>>k;
        long long ans=x;
        long long t=1;
        //找到x二进制下最高位的1
        while(t<=x){
            t<<=1;
        }
        t>>=1;

        while(ans>0&&k>0){
            //找到x二进制下最高位的1
//            cout<<ans<<endl;
//            cout<<"t:"<<t<<endl;
            ans=ans&(~t);
//            cout<<"ans:"<<ans<<endl;
            while(!(t&x)){
                t>>=1;
            }
            t>>=1;
            k--;
        }
        t=1;
//        cout<<k<<endl;
        if(k>0){
            while(k>0){
                //找最低位的0，改成1
                while(t&x){
                    t<<=1;
                }
//                cout<<k<<endl;
                ans|=t;
                t<<=1;
                k--;
            }
        }
        cout<<ans<<endl;
    }
}
int main(){
    freopen("data.in","r",stdin);

    fclose(stdin);
    return 0;
}
