//
// Created by lyh on 2025/3/28.
//
#include<iostream>

using namespace std;
int a[1010][11];
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
        }
    }

    for(int i=1;i<=n;i++){
        int ans=0;
        for(int j=0;j<=n;j++){
            for(int k=1;k<=m;k++){
                if(a[j][k]<=a[i][k]){
                    break;
                }
                if(k==m){
                    ans = j;
                }
            }
            if(ans!=0){
                break;
            }
        }
        printf("%d\n",ans);
    }
}