#include<bits/stdc++.h>
using namespace std;
const int INF = 1e8;
struct dat{
    int start;
    int end;
    int reward;
};
int bs(vector<dat> &a, int val, int last){
    int start = 0;
    int ans = -1;
    while(start<last){
        int mid = start + (last-start)/2;
        if(a[mid].end<=val){
            ans = mid;
            start = mid+1;
        }else{
            last = mid;
        } 
    }
    return ans;
}
int main(){
   //weighted job scheduling 
   int n;
   cin>>n;
   vector<dat> vec(n);
   for(int i=0;i<n;i++){
       cin>>vec[i].start;
       cin>>vec[i].end;
       cin>>vec[i].reward;
   }
   sort(vec.begin(),vec.end(), [&](const dat a, const dat b){
       if(a.end==b.end){
           if(a.start==b.start){
               return a.reward<b.reward;
           }
           return a.start<b.start;
       }
       return a.end<b.end;
   });
   cout<<endl;
   for(int i=0;i<n;i++){
       cout<<vec[i].start<<" ";
       cout<<vec[i].end<<" ";
       cout<<vec[i].reward<<endl;
   }
    vector<long> rew(n,0);
    rew[0] = vec[0].reward;
    for(int i=1;i<n;i++){
        int index = bs(vec,vec[i].start,i);
        if(index==-1 || (vec[i].start==vec[index].start) && vec[i].end == vec[index].end) rew[i] = max(vec[i].reward ,vec[index].reward);
        else{ rew[i] = vec[i].reward + rew[index];}
    }
    long ans = 0;
    ans = *max_element(rew.begin(), rew.end());
    cout<<ans<<endl;
   return 0;
}