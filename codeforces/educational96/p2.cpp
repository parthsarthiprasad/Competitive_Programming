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
        vector<int> vec(n);
        for(int i=0;i<n;++i)cin>>vec[i];
        if(n==1){
            cout<<0<<endl;
            continue;
        }
        sort(vec.begin(),vec.end());
        unsigned long long sum = vec[n-1];
        for(int i=n-2,count=0;count<k && i>-1;count++,i--){
            sum+=vec[i];
        }
        cout<<sum<<endl;
    }
    return 0;
}