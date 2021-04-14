#include<bits/stdc++.h>
using namespace std;
double findvalue(vector<int> &vec,vector<vector<double>> &dp){
    vector<vector<double>> mysum(vec.size(), vector<double>(vec.size(),0));
    int n = vec.size();
    for(int L=n-1;L>=0;L--){
        for(int R=L+1;R<n;R++){
            double sum = 0;
            for(int i=L;i<R;i++){
                sum += dp[L][i]*(i-L+1) + dp[i+1][R]*(R-i) ;
                mysum[L][R] = mysum[L][R]*(R-L+1) + sum;
            }
            long int freq = ((R-L)*(R-L+1))/2;
            if(R==L) freq = 1;
            dp[L][R] = sum/freq;
            mysum[L][R] = mysum[L][R]/freq;
        }
    }
  
    return mysum[0][n-1];
}
double solve(){
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++)cin>>vec[i];
    vector<vector<double>> dp(n,vector<double>(n,0));
    for(int i=0;i<n;i++){
        dp[i][i] = vec[i];
    }
    double sum = findvalue(vec,dp);
    cout<<sum<<endl;
    return sum;
    
}
int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int i=1;
    while(t--){
        cout<<"Case #"<<i++<<": ";
        cout<<fixed<<setprecision(10)<<solve();
        cout<<endl;
    }
    return 0;
}