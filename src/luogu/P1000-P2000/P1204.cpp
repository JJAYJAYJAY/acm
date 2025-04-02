//
// Created by lyh on 2025/4/1.
//
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> PII;
const int N=1e6+10;

vector<PII> segs;

void merge(vector<PII> &segs){
    vector<PII> res;
    sort(segs.begin(),segs.end());
    int st=-2e9,ed=-2e9;
    for(auto seg:segs){
        if(ed<seg.first){
            if(st!=-2e9) res.push_back({st,ed});
            st=seg.first,ed=seg.second;
        }else{
            ed=max(ed,seg.second);
        }
    }
    if(st!=-2e9) res.push_back({st,ed});
    segs=res;
}
int n;
int main(){
    freopen("src/luogu/P1000-P2000/in/P1204.in","r",stdin);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        segs.push_back({l,r});
    }
    merge(segs);

    int max_s=-0x3f3f3f3f,max_n=-0;
    for(int i=0;i<segs.size();i++){
        max_s=max(max_s,segs[i].second-segs[i].first);
        if(i+1<segs.size()){
            max_n=max(max_n,segs[i+1].first-segs[i].second);
        }
    }
    cout<<max_s<<" "<<max_n<<endl;
    fclose(stdin);
}