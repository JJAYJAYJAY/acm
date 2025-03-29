//
// Created by lyh on 2025/3/29.
//
#include <iostream>
using namespace std;
int st[100];
int main(){
    int dx[]={2,4,8,1,3,6,1,2,5,1,2,4},
        dy[]={5,2,1,6,3,1,7,3,1,9,4,2};
    int ans = 0;
    for(int i=0;i<12;i++){
        int a = dy[i]*dx[i];
        if(st[a]) continue;
        st[a]=1;
        ans+=a;
    }
    cout<<ans<<endl;
}
