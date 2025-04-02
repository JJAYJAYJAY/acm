//
// Created by lyh on 2024/9/15.
//
#include "iostream"
#include <math.h>

using namespace std;

int const N = 410;

struct point{
    double x,y;
    double T;
}p[410];

int idx=0;
int S,t,A,B;
double g[N][N];

double get_dis(point p1,point p2){
    return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
}

point get_point(int i){
    point p1,p2,p3;
    p1 = p[i*4];
    p2 = p[i*4+1];
    p3 = p[i*4+2];
    double p1p2 = get_dis(p1,p2);
    double p1p3 = get_dis(p1,p3);
    double p2p3 = get_dis(p2,p3);
    if(p1p2+p1p3==p2p3){
        return {p2.x+p3.x-p1.x,p2.y+p3.y - p1.y,p1.T};
    }else if(p1p2+p2p3==p1p3){
        return {p1.x+p3.x-p2.x,p1.y+p3.y - p2.y,p2.T};
    }else{
        return {p1.x+p2.x-p3.x,p1.y+p2.y - p3.y,p3.T};
    }
}

void floyd(){
    for(int k=0;k<4*S;k++){
        for(int i=0;i<4*S;i++){
            for(int j=0;j<4*S;j++){
                g[i][j] = min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }
}
int n;
int main(){
    freopen("src/luogu/P1000-P2000/in/P1027.in","r",stdin);
    scanf("%d",&n);
    while(n--){
        idx=0;
        scanf("%d%d%d%d",&S,&t,&A,&B);
        for(int i=0;i<S;i++){
            double x1,y1,x2,y2,x3,y3,T;
            scanf("%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3,&T);
            p[idx++] = {x1,y1,T};
            p[idx++] = {x2,y2,T};
            p[idx++] = {x3,y3,T};
            p[idx++] = get_point(i);
        }
        for(int i=0;i<4*S;i++){
            for(int j=0;j<4*S;j++){
                if(i/4==j/4){
                    g[i][j] = sqrt(get_dis(p[i],p[j]))*p[i].T;
                }else{
                    g[i][j] = sqrt(get_dis(p[i],p[j]))*t;
                }
//                cout<<g[i][j]<<" ";
            }
//            cout<<endl;
        }
        floyd();
        double min_ans = 1e18;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                min_ans =min(min_ans,g[(A-1)*4+i][(B-1)*4+j]);
            }
        }
        printf("%.1lf\n",min_ans);
    }
    fclose(stdin);
}