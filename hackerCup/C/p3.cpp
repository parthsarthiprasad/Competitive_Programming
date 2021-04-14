#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair

using namespace std;
bool comp(const pair<int,int> &a, const pair<int,int> &b){
    if(a.first == b.first){
        return a.second<b.second;
    }
    return a.first<b.first;
}
map<int,int> dp;
ll findlen(vector<pair<int,int> >&vec, int start, int pos, int end){
    
    if(dp.find(pos)!=dp.end()) return dp[pos];
    ll len =0;
    int i=start;
    while(i<end && vec[i].first<pos){i++;}
    if(i==end) return 0;
    if(vec[i].first!=pos) return 0;
    while(vec[i].first==pos){
        len =max(len, findlen(vec,i+1,vec[i].second,end) + vec[i].second-vec[i].first);
        i++;
    }
    dp[pos]=len;
    return len;
}
ll solve(){
    int n;
    cin>>n;
    vector<pair<int,int> > leftsegment(n), rightsegment(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        leftsegment[i]=mp(a-b,a);
        rightsegment[i]=mp(a,a+b);
    }
  
    sort(leftsegment.begin(),leftsegment.end(), comp);
    sort(rightsegment.begin(), rightsegment.end(),comp);

    for(int i=0;i<n;i++){
        cout<<leftsegment[i].first<<" "<<leftsegment[i].second<<endl;
    }
    for(int i=0;i<n;i++){
        cout<<rightsegment[i].first<<" "<<rightsegment[i].second<<endl;
    }
    long long maxlen=0;
    maxlen = findlen(leftsegment,0, leftsegment[0].first,n);
    dp.clear();
    maxlen = max(maxlen,findlen(rightsegment,0,rightsegment[0].first,n));
    dp.clear();
    return maxlen;
    //return maxlen;

}
int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t;
    cin>>t;
    int i=1;
    while(t--){
        cout<<"Case #"<<i++<<": "<<solve()<<"\n";
    }
}