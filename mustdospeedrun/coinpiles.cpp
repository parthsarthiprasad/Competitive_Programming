//https://practice.geeksforgeeks.org/problems/coin-piles/0
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> ptr(n), temp(n);
        for(int i=0;i<n;++i)cin>>ptr[i];
        temp = ptr;
        int count = INT_MAX;
        int numcost = 0;
        int currval = ptr[0];
        for(int i=1;i<n;i++){
            if(currval+k <ptr[i]){
                numcost+= ptr[i] - (currval + k);
                currval+=k;
            }else if(currval-k>ptr[i]){
                numcost+= currval-k-ptr[i];
                currval=ptr[i];
            }else currval = ptr[i];
        }
        count = min(count, numcost);
        currval = ptr[n-1];
        for(int i=n-2;i>-1;i--){
            if(currval+k <ptr[i]){
                numcost+= ptr[i] - (currval + k);
                currval+=k;
            }else if(currval-k>ptr[i]){
                numcost+= currval-k-ptr[i];
                currval=ptr[i];
            }else currval = ptr[i];
        }
        count = min(count,numcost);
        cout<<count<<endl;
    }
}