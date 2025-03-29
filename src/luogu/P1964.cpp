//
// Created by lyh on 2024/11/3.
//
#include "iostream"
#include "cstring"
#include "map"

using namespace std;
struct Object{
    int value;
    int maxNum;
    int num;
};
int main(){
    int m,n;
    cin>>m>>n;
    map<string,Object> objects;
    for(int i=1;i<=n;i++){
        string name;
        int value,num,maxNum;
        cin>>num>>value>>maxNum>>name;
        if(objects.find(name)!=objects.end()){
            objects[name].num+=num;
            continue;
        }
        objects[name]={value,maxNum,num};
    }

    int arr[2000]={0};
    int cnt=0;
    //遍历map
    for(auto it=objects.begin();it!=objects.end();it++){
        int x = it->second.num/it->second.maxNum;
        for(int i=0;i<x;i++){
            arr[++cnt]=it->second.value*it->second.maxNum;
        }
        arr[++cnt]=it->second.value*(it->second.num%it->second.maxNum);
    }
    int dp[cnt+1][21-m+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=cnt;i++){
        for(int j=1;j<=21-m;j++){
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]+arr[i]);
        }
    }
    cout<<dp[cnt][21-m];
}