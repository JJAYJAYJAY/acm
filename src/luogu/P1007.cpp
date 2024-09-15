//
// Created by lyh on 2024/9/15.
//
#include "iostream"
using namespace std;

int main(){
    int l,n;
    scanf("%d%d",&l,&n);
    if (!n) {
        cout<<"0 0"<<endl;
        return 0;
    }
    int max=-0x7f7f7f7f,min=0x7f7f7f7f;
    int max_time,min_time=-0x7f7f7f7f;
    int x;
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        max = std::max(max,x);
        min = std::min(min,x);
        min_time = std::max(min_time,std::min(x,l-x+1));
    }
    max_time = std::max(l-min+1,max);
    cout<<min_time<<" "<<max_time;
}