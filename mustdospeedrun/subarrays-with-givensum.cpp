//subarray with given sum
/*
https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int ptr[n];
        for(int i=0;i<n;++i)cin>>ptr[i];
        //let's do find all subarrays
        vector<pair<int,int>> pos;
        int start = 0;
        int end = 0;
        int sum = 0;
        for(;end<n;){
            if(sum==k){
                pos.push_back({start,end});
                sum+=ptr[end++];
            }
            else if(sum<k){
                sum+=ptr[end++];
            }else{
                sum-=ptr[start++];
            }
        }
        while(start<n){
            if(sum==k){
                pos.push_back({start,end});
            }
            sum-=ptr[start++];
        } 
        //cout<<(int) pos.size()<<endl;
        //for 1 indexing
        if(pos.size()==0){
            cout<<-1<<endl;
        }else{
            for(int i=0;i<1;i++){
                cout<<1+ pos[i].first<<" "<<pos[i].second<<endl;
            }
        }
    }
    return 0;
}