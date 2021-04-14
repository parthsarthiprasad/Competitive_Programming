#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<k;i++)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> permut(n);
        rep(i,0,n){
            cin>>permut[i];
        } 
        int mostrequired = 0;
        for(int i=n-1;i>=0;i--){
             if(permut[i]!=i+1) {
                 mostrequired = i+1;
                 break;
             }
             
        }
        //  cout<<mostrequired<<" ";
        // double permutation = 0;
        // vector<vector<double>> vec(n, vector<double> (2,(double)0));
        double allmulti = mostrequired>0?(double)1:(double)0;
        rep(i,0,m){
            int a; double p;
            cin>>a>>p;
            if(a>=mostrequired) allmulti*=(1-p);
            // vec[a-1][0] = 1-p;
            // vec[a-1][1] = p;
        }
        
        
        // rep(i,max(0,mostrequired-1),n){
        //     allmulti*=vec[i][0];
        // }

        // rep(i,mostrequired-1,n){
        //     if(vec[i][0]!=0)
        //     permutation+= vec[i][1]* allmulti / vec[i][0];
        // }
        cout.precision(6);
        // if(mostrequired==INT_MAX) cout<<fixed<<(double)1<<endl;
        cout<<fixed<<1 - allmulti<<endl;
        // cout<<fixed<<permutation<<endl;
    }
    return 0;
}