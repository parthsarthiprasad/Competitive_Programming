#include<bits/stdc++.h>
#define forn(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
    const int mod = 998244353;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long int answer = 0;
        vector<long long int> vec(2*n);
        forn(i,2*n)cin>>vec[i];
        sort(vec.begin(), vec.end());
        // vector<int> prod;
        map<int,int> prod;
        for(int i=0;i<2*n;i++){
            int count = 0;
            int j =i;
            while(j<2*n && vec[i]==vec[j]){
                j++;
                count++;
            }
            prod[vec[i]] = count;
            i=max(i,j-1);
        }
        for(int i=0;i<2*n;i++){
            long long int tempval = 0;
            for(int j=i+1, count=0;count<n-i && j<2*n;j++){
                if((j-i)&1&(i+1) ){
                tempval+=(vec[j]-vec[i]);
                tempval%=mod;
                count++;
                }
            }
            for(auto a:prod){
                tempval*=a.second;
                tempval%=mod;
            }
            
            tempval%=mod;
            answer+=tempval;
            answer%=mod;
            while(i+1<n && vec[i]==vec[i+1]){
                i++;
            }
        }
        // for(auto a:prod){
        //     answer*=a;
        //     answer%=mod;
        // }
        answer*=2;
        answer%=mod;
        cout<<answer<<endl;


    }
}