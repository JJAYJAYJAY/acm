//
// Created by lyh on 2024/9/15.
//
#include "iostream"
#include <cstdio>
#include <cstring>
using namespace std;

//高精度
const int MAXN = 85, Mod = 10000;
struct HP {
    int p[505], len;
    HP() {
        memset(p, 0, sizeof p);
        len = 0;
    } //这是构造函数，用于直接创建一个高精度变量
    void print() {
        printf("%d", p[len]);
        for (int i = len - 1; i > 0; i--) {
            if (p[i] == 0) {
                printf("0000");
                continue;
            }
            for (int k = 10; k * p[i] < Mod; k *= 10)
                printf("0");
            printf("%d", p[i]);
        }
    } //四位压缩的输出
} f[MAXN][MAXN], base[MAXN], ans;

HP operator + (const HP &a, const HP &b) {
    HP c; c.len = max(a.len, b.len); int x = 0;
    for (int i = 1; i <= c.len; i++) {
        c.p[i] = a.p[i] + b.p[i] + x;
        x = c.p[i] / Mod;
        c.p[i] %= Mod;
    }
    if (x > 0)
        c.p[++c.len] = x;
    return c;
} //高精+高精

HP operator * (const HP &a, const int &b) {
    HP c; c.len = a.len; int x = 0;
    for (int i = 1; i <= c.len; i++) {
        c.p[i] = a.p[i] * b + x;
        x = c.p[i] / Mod;
        c.p[i] %= Mod;
    }
    while (x > 0)
        c.p[++c.len] = x % Mod, x /= Mod;
    return c;
} //高精*单精

HP max(const HP &a, const HP &b) {
    if (a.len > b.len)
        return a;
    else if (a.len < b.len)
        return b;
    for (int i = a.len; i > 0; i--)
        if (a.p[i] > b.p[i])
            return a;
        else if (a.p[i] < b.p[i])
            return b;
    return a;
} //比较取最大值

int n,m;
void BaseTwo() {
    base[0].p[1] = 1, base[0].len = 1;
    for (int i = 1; i <= m + 2; i++){
        base[i] = base[i - 1] * 2;
    }
} //预处理出2的幂

int main(){
    scanf("%d%d", &n, &m);
    BaseTwo();
    int ar[m+2];
    memset(ar, 0, sizeof ar);
    while(n--){
        memset(f, 0, sizeof f);
        for (int i = 1; i <= m; i++)
            scanf("%d", &ar[i]);
        for (int i=1;i<=m;i++){
            for(int j=m;j>=i;j--){
                f[i][j]=max(f[i][j],f[i-1][j]+base[m-j+i-1]*ar[i-1]);
                f[i][j]=max(f[i][j],f[i][j+1]+base[m-j+i-1]*ar[j+1]);
            }
        }
        HP Max;
        for (int i = 1; i <= m; i++)
            Max = max(Max, f[i][i] + base[m] * ar[i]);
        ans = ans + Max;
    }
    ans.print();
    return 0;
}