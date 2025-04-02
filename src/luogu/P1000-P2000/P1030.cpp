//
// Created by lyh on 2025/4/1.
//
#include <iostream>

using namespace std;

string A,B;
void solve(string stra,string strb){
    if(strb.length()==1) {
        cout<<strb;
        return;
    }
    char now=strb[strb.length() - 1];
    cout<<now;
    for(int i=0;i<stra.length();i++){
        if(stra[i]==now){
//            cout << "向左" << stra.substr(0,i)<<" "<<strb.substr(0, i) << endl;
            if(i!=0) solve(stra.substr(0,i), strb.substr(0, i));
            if(i+1>=stra.length())break;
//            cout << "向右" << stra.substr(i+1)<<" "<<strb.substr(i, strb.length()-i-1) << endl;
            solve(stra.substr(i+1), strb.substr(i, strb.length()-i-1));
            break;
        }
    }
}

int main(){
    freopen("src/luogu/P1000-P2000/in/P1030.in","r",stdin);
    cin>>A>>B;
//    cout<<A<<endl;
//    cout<<B<<endl;
    solve(A,B);
    fclose(stdin);
}