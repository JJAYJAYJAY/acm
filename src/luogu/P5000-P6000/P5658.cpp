//
// Created by lyh on 2025/2/26.
//
#include <iostream>
#include "cstring"
using namespace std;

struct node{
    int val;
    node* prev = nullptr;
};

node* front[1000000] = {nullptr};

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int f[n];
    memset(f,0,sizeof(f));
    for(int i = 1;i<n;i++){
        cin>>f[i];
        f[i]--;
    }
    int match[n];
    long long dp[n]; //第i个括号中的合法子串个数
    long long count[n]; //第i个括号中的连续括号串
    memset(match,-1,sizeof(match));
    memset(count,0,sizeof(count));
    memset(dp,0,sizeof(dp));
    for(int i = 0; i < n; i++){
        if(s[i]=='('){
            node *tmp = new node();
            tmp->val = i;
            tmp->prev = front[f[i]];
            front[i] = tmp;
            dp[i] = dp[f[i]];
        } else if(s[i]==')' && front[f[i]]!=nullptr){
            match[i] = front[f[i]]->val;
            dp[i] = dp[f[i]]+1;
            front[i] = front[f[i]]->prev;
            int j = f[match[i]];
            if(count[j]!=0){
                dp[i]+=count[j];
                count[i] = count[j]+1;
            } else{
                count[i] = 1;
            }
        } else{
            dp[i] = dp[f[i]];
        }
    }
    long long res= 0;
    for(int i = 0; i < n; i++){
        res^=(i+1)*dp[i];
//        cout<<dp[i]<<" ";
    }
//    cout<<endl;
    cout<<res;
}