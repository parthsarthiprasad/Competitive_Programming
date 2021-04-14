#include<bits/stdc++.h>
 
using namespace std;
int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t,temp;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long> ptr;
        for(int i=0;i<n;i++){
        cin>>temp;
        ptr.push_back(temp);
    }
    // for(int i=0;i<n;i++) cout<<ptr[i]<<" ";
    // cout<<endl; 
    long sum = 0;
    long totcost = 0;
    for(int i=0;i<n;i++){
        sum+=ptr[i];
        if(sum+1<1){
            totcost += abs(sum);
            sum=0;
        }
    }
    cout<<totcost<<"\n";
    }
    
    return 0;
}