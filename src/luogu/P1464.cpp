//
// Created by lyh on 2024/9/20.
//
#include "iostream"
#include "cstring"
long long note[25][25][25]={0};
using namespace std;
int w(long long a,long long b,long long c){
    if(a<=0||b<=0||c<=0){
        return 1;
    } else if(a>20||b>20||c>20){
        if (note[20][20][20]==0) note[20][20][20]=w(20,20,20);
        return note[20][20][20];
    }
    if(note[a][b][c]==0){
        if(a<b&&b<c){
            note[a][b][c-1]=w(a,b,c-1);
            note[a][b-1][c-1]=w(a,b-1,c-1);
            note[a][b-1][c]=w(a,b-1,c);
            note[a][b][c]=note[a][b][c-1]+note[a][b-1][c-1]-note[a][b-1][c];
            return note[a][b][c];
        } else{
            note[a-1][b][c]=w(a-1,b,c);
            note[a-1][b-1][c]=w(a-1,b-1,c);
            note[a-1][b][c-1]=w(a-1,b,c-1);
            note[a-1][b-1][c-1]=w(a-1,b-1,c-1);
            note[a][b][c]=note[a-1][b][c]+note[a-1][b-1][c]+note[a-1][b][c-1]-note[a-1][b-1][c-1];
            return note[a][b][c];
        }
    } else{
        return note[a][b][c];
    }
}

int main(){
    long long a,b,c;
    while(1){
        cin>>a>>b>>c;
        if(a==-1&&b==-1&&c==-1) return 0;
        cout<<"w("<<a<<", "<<b<<", "<<c<<')'<<" = "<<w(a,b,c)<<endl;
    }
}