//
// Created by lyh on 2024/9/14.
//
#include "iostream"
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[4][n+1];
    for(int i=1;i<n+1;i++){
        cin>>a[0][i]>>a[1][i]>>a[2][i]>>a[3][i];
    }
    int target_x,target_y;
    int res=-1;
    cin>>target_x>>target_y;
    for(int i=1;i<n+1;i++){
        int x = a[0][i],y = a[1][i],x1 = a[2][i],y1 = a[3][i];
        if(target_x>=x&&target_x<=x+x1&&target_y>=y&&target_y<=y+y1){
            res=i;
        }
    }
    cout<<res;
}