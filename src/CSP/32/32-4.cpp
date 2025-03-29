//
// Created by lyh on 2025/3/28.
//
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
const int N= 1e6+10;

int n,m;

int main() {
    freopen("input.txt", "r", stdin);  // 让 stdin 从文件读取
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int v;
        double a,b,c,d;
        scanf("%d",&v);
        if(v==1){
            scanf("%lf%lf%lf%lf",&a,&b,&c,&d);

        }
        if(v==2){
            scanf("%lf%lf%lf%lf",&a,&b,&c,&d);

        }
        if(v==3) {

        }

    }
    fclose(stdin);  // 恢复标准输入（可选）
    return 0;
}
