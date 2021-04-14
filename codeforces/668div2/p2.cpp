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
    vector<long> ptr(n);
    for(int i=0;i<n;i++){
        cin>>temp;
        ptr[i] = temp;
    }
    long sum = 0;
    long totcost = 0;
    for(int i=0;i<n;i++){
        sum+=ptr[i];
        if(sum<0){
            totcost += abs(sum);
            sum=0;
        }
    }
    cout<<to_string(totcost)<<"\n";
    }
    return 0;
}