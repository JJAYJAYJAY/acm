#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

const int N =550;
double d1,c,d2,p;
int n;


pair<double,double> Nodes[N];
void solve() {
    scanf("%lf%lf%lf%lf%d",&d1,&c,&d2,&p,&n);
    vector<pair<double,double>> oil;
    double ans = c*p;
    double total = c;
    oil.push_back({c,p});
    for(int i=0;i<n;i++){
        scanf("%lf%lf",&Nodes[i].first,&Nodes[i].second);
    }
    Nodes[n].first = d1;
    Nodes[n].second = 0;
    sort(Nodes,Nodes+n);
    double now = 0;
    for(int i=0;i<=n;i++){
        pair<double,double> node = Nodes[i];
        if(node.first - now > total*d2){
            cout<<"No Solution"<<endl;
            return;
        }

        double oil_cost = (node.first - now)/d2;
        total -= oil_cost;
        //计算油耗
        while(oil_cost){
            pair<double,double>& top = oil.front();
            if(top.first>oil_cost){
                top.first -= oil_cost;
                oil_cost = 0;
            }else{
                oil_cost -= top.first;
                oil.erase(oil.begin());
            }
        }
        //计算是否换油
        while(!oil.empty()){
            pair<double,double>& top = oil.back();
            if(top.second > node.second){
                ans -= top.first*top.second;
                total -= top.first;
                oil.pop_back();
            }else{
                break;
            }
        }
        double add = c - total;
        if(add > 0){
            ans += add*node.second;
            total += add;
            oil.push_back({add,node.second});
        }
        now = node.first;
    }
    printf("%.2lf\n",ans);
}

int main() {
#ifdef LOCAL
    freopen("src/luogu/P1000-P2000/in/P1016.in","r",stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}