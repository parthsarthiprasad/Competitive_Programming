#include<bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i=0;i<n;i++)
const int  nax = 2e5+2;
vector<int> G[nax];


void dfs2(int src, vector<int> &cities, vector<pair<long long int,long long int>> &answers){
   bool leaf= true;
   for(auto a:G[src]){
       leaf = false;
       dfs2(a,cities,answers);
   }
   if(leaf){
       answers[src]={cities[src],0};
       return;
   }
   long long int num = 0;
   long long int diff = 0;
   long long int  count = 0;
   for(auto a:G[src]){
       num = max(num, answers[a].first);
       count++;
   }
   for(auto a:G[src]){
       diff += num-(answers[a].first - answers[a].second);
   }
   long long int tempval1 = cities[src], tempval2 = cities[src];
   tempval1 = max(0LL,tempval1-diff);
   diff = max(0LL,diff-tempval2);
   
    answers[src] = {num+((tempval1+count-1)/count ), diff + count - tempval1%count};
    return;
}
int main(){
    int n,temp;
    cin>>n;
    forn(i,n)G[i].clear();
    forn(i,n-1){
        cin>>temp;
        temp--;
        G[temp].push_back(i+1);
    }
    vector<int> cities(n);
    forn(i,n)cin>>cities[i];

    vector<pair<long long int,long long int>> answers(n,{0,0});
    dfs2(0,cities,answers);
    cout<<answers[0].first<<"\n";
    return 0;

}