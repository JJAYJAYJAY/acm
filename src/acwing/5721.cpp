//
// Created by lyh on 2025/3/12.
//
#include<iostream>
#include <cstring>
#include <map>

using namespace std;

map<string,int> mp;
const int N= 50;
double g[N][N];
int idx1;
int n;
double eps=1e-6;


void add_g(int i, const char *s, int char_start, int number_start, int j) {
    string str = string(s + char_start, s + number_start);
    int yuansu;
    if(!mp.count(str)){
        yuansu = idx1;
        mp[str]=idx1++;
    }else{
        yuansu = mp[str];
    }
    g[yuansu][i]= stoi(string(s+number_start,s+j));
}

//高斯消元
void gauss(double a[][N],int x,int y){
    for(int j=0;j<y;j++){
        for(int i=j;i<x;i++){
            if(a[i][j]>eps || a[i][j]<-eps){
                if(i!=0){
                    for(int k=0;k<y;k++){
                        swap(a[i][k],a[j][k]);
                    }
                }
                break;
            }
        }
        for(int i=j+1;i<x;i++){
            if(a[i][j]>eps || a[i][j]<-eps){
                double scale = a[i][j]/a[j][j];
                for(int k=0;k<y;k++){
                    a[i][k] -= a[j][k] * scale;
                }
            }
        }
    }
}




int main(){
    scanf("%d",&n);
    while(n--){
        memset(g,0,sizeof g);
        mp.clear();
        idx1=0;
        int m;
        scanf("%d",&m);
        for(int i=0;i<m;i++) {
            char s[1000];
            scanf("%s",s);
            int char_start=0,number_start,j;
            bool in_number=false;
            for(j=0;s[j];j++){
                if(!in_number && s[j]>'0' && s[j]<='9'){
                    number_start=j;
                    in_number=true;
                }
                if(in_number && (s[j]<'0' || s[j]>'9')){
                    in_number=false;
                    add_g(i, s, char_start, number_start, j);
                    char_start=j;
                }
            }
            add_g(i, s, char_start, number_start, j);
        }
        gauss(g,idx1,m);
        for(int i=0;i<idx1;i++){
            for(int j=0;j<m;j++){
                printf("%lf ",g[i][j]);
            }
            printf("\n");
        }
        int rk=0;
        for(int i=0;i<idx1&&i<m;i++){
            if(g[i][i]!=0){
                rk++;
            }
        }
        if(m-rk>0){
            printf("Y\n");
        }else{
            printf("N\n");
        }
    }
}


