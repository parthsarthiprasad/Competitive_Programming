/*
https://practice.geeksforgeeks.org/problems/form-a-palindrome/0
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        string s,k;
        cin>>s;
        k = s;
        reverse(k.begin(), k.end());
        //finding longest palindroming subsequence for this set
        int n = s.size();
        int lps[n+1][n+1];
        for(int i=0;i<=n;i++){
            lps[i][0] = lps[0][i]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==k[j-1]){
                    lps[i][j] = lps[i-1][j-1]+1;
                }else{
                    lps[i][j] = max(lps[i-1][j], lps[i][j-1]);
                }
            }
        }
        cout<<max(n - lps[n][n],0)<<endl;


    }
}