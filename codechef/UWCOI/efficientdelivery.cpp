#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k)for(int i=j;i<k;i++)
struct travel{
    int64_t srcx;
    int64_t srcy;
    int64_t destx;
    int64_t desty;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k;
    cin>>n>>m>>k;
    vector<travel> data(k);
    int64_t standardcost = 0;
    
    rep(i,0,k){
        cin>>data[i].srcx;
        cin>>data[i].srcy;
        cin>>data[i].destx;
        cin>>data[i].desty;
        data[i].srcx--;
        data[i].srcy--;
        data[i].destx--;
        data[i].desty--;
        // diffx
        standardcost+= 2*abs(data[i].destx - data[i].srcx) +
                        2*abs(data[i].desty - data[i].srcy);
    }

    vector<int> segmentbeg(k);
    vector<int> segmentend(k);
    rep(i,0,k){
        int beg = max((int64_t)0, min(data[i].srcy - abs(data[i].srcx - data[i].destx)/2,
                             data[i].desty - abs(data[i].srcx - data[i].destx)/2));
        int end = min((int64_t)n-1, max(data[i].srcy + abs(data[i].srcx - data[i].destx)/2,
                             data[i].desty + abs(data[i].srcx - data[i].destx)/2));
        segmentbeg[i]=beg;
        segmentend[i] = end;
    }
    
    sort(segmentbeg.begin(),segmentbeg.end());
    sort(segmentend.begin(), segmentend.end());
    for(auto a:segmentbeg){cout<<a<<" ";}cout<<endl;
    for(auto a:segmentend){cout<<a<<" ";}cout<<endl;

    // int bestindex = 0;
    // int gin = 1, mg = 1, index = segmentbeg[0];
    // int i = 1, j = 0;
    // int startindex = segmentbeg[0];
    // int endindex = segmentend[0];
    // while(i<k && j<k){
    //     if(segmentbeg[i]<=segmentend[j]){
    //         gin++;
    //         if(gin>mg){
    //             startindex = segmentbeg[i];
    //             endindex = min(segmentend[j], segmentend[i]);
    //             mg = gin;
    //             index = segmentbeg[i];
    //             // cout<<startindex<<" "<<endindex<<endl;
    //         }
    //         i++;
    //     }else{
    //         gin--;
    //         j++;
    //     }
    // }
    // // cout<<startindex<<" "<<endindex<<endl;
    //selectedindex is startindex
    int64_t newcost = 1e18;
    // for(int j=startindex;j<=endindex;j++){
    //     int64_t tempcost = 0;
    //     for(int i=0;i<k;i++){
    //     int64_t kcost = 0;
    //     kcost = 2*abs(data[i].srcx - data[i].destx) + 2*abs(data[i].srcy - data[i].desty);
    //     int64_t bcost = abs(data[i].srcx - data[i].destx) + 2*abs(data[i].srcy - data[i].desty);
    //     if(j>data[i].srcy && j>data[i].desty){
    //         bcost+=4*abs(j-data[i].desty);
    //     }else if(j<data[i].srcy && j<data[i].desty){
    //         bcost+=4*abs(j-data[i].srcy);
    //     }
    //     // cout<<min(kcost,bcost)<<"\n";
    //     tempcost+= min(kcost, bcost);
    // }
    // newcost = min(newcost, tempcost);
    // }
    
    cout<<newcost<<"\n";


    return 0;
}