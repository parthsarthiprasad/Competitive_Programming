#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<k;i++)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k,sz;
        cin>>n>>k;
        sz = n*k;
        vector<int> vec(sz);
        rep(i,0,sz)cin>>vec[i];
        sort(vec.begin(), vec.end());
        long long int sum =0;
        int start = k;
        for(int i = start,count=0;count<k && i<sz;i+=n,count++){
            cout<<vec[i]<<" ";
            sum+=vec[i];
        }
        cout<<sum<<endl;
    }
}