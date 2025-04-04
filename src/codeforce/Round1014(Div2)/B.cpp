//
// Created by lyh on 2025/4/3.
//

#include <iostream>

using namespace std;

void solve(string a,string b,int n){
    int sum1=0,sum2=0;//sum1和sum2是两条路线上1的总数
    for (int i = 0; i < n; i++){
        if((i + 1) % 2 == 0){
            if(b[i]=='1')sum1++;
            if(a[i]=='1')sum2++;
        }else{
            if(b[i]=='1')sum2++;
            if(a[i]=='1')sum1++;
        }
    }
    //和两个sum进行比较的分别是两条路径上能够存的1的个数
    if (n % 2 == 0){//是偶数直接除以2
        if (sum1 > n / 2 || sum2 > n / 2)puts("NO");
        else puts("YES");
    }else{
        if (sum1 > (n - 1) / 2 || sum2 > n - (n - 1) / 2)puts("NO");
        else puts("YES");
    }
}

int n;
int main(){
#ifdef LOCAL
    freopen("src/codeforce/Round1014(Div2)/in/B.in","r",stdin);
#endif
    scanf("%d",&n);
    while(n--){
        int m;
        scanf("%d",&m);
        string a,b;
        cin>>a>>b;
        solve(a,b,m);
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}