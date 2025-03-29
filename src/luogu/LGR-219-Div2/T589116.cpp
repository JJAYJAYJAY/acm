//
// Created by lyh on 2025/3/29.
//

#include <iostream>

using namespace std;

int main(){
    int cnt=0;
    for(int i=2026;i<2116;i++){
        if(i%100==0){
            if(i%400==0){
                cout<<i<<endl;
                cnt++;
            }
        }
        else{
            if(i%4==0){
                cout<<i<<endl;
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    cout<<2+30+31+30+31+31+30+31+30+31+cnt+365*(2116-2026)<<endl;
    cout<<cnt+365*(2116-2026)<<endl;
    cout<<2+30+31+30+31+31+30+31+30+31<<endl;
}