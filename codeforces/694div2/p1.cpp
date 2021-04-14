#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        vector<int> vec(n);
        for(int i=0;i<n;i++)cin>>vec[i];
        int64_t minval = 0, maxval = 0;
        for(int i=0;i<n;i++){
            maxval+=vec[i];
            minval+= ((vec[i] + x -1)/x);
        }
        maxval = (maxval + x - 1)/x;
        cout<<maxval<<" "<<minval<<endl;

        
    }
    return 0;
}