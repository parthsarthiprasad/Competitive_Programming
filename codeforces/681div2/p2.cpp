#include<bits/stdc++.h>
#define forn(i,n) for(int i=0;i<n;i++)
using namespace std;
int a,b;
long long int findans(vector<int> &tempseg,int i, int n, vector<vector<int>> &dp){
    if(i==n) return a;
    if(i==n || i<0 || i>n) return 0;
    if(dp[i][n]!=-1) return dp[i][n];
    long long int count = 0;
    count = min(a + findans(tempseg,0,i-1,dp) + findans(tempseg,i+1,n,dp),
            min(findans(tempseg,0,i-1,dp)+ b*tempseg[i] + findans(tempseg,i+1,n,dp),
                findans(tempseg,0,i,dp)+ i+1<n?b*tempseg[i+1]:a +findans(tempseg,i+1,n,dp) ));
    return dp[i][n] = count;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        
        cin>>a>>b;
        string s;
        cin>>s;
        vector<int> segments;
        for(int i=0;i<s.size();i++){
            int j = i;
            int count = 0;
            while(j<s.size() && s[j]=='0'){
                count++;
                j++;
            }
            if(count){
                segments.push_back(count);
            }
            i = max(i,j-1);
        }
        vector<int> tempseg;
        if(s[0]=='0' && s[s.size()-1]=='0'){
            for(int i=1;i<segments.size()-1;i++){
                tempseg.push_back(segments[i]);
            }
        }else if(s[0]=='0' && s[s.size()-1]!='0'){
            for(int i=1;i<segments.size();i++){
                tempseg.push_back(segments[i]);
            }
        }else if(s[s.size()-1]=='0' && s[0]!='0'){
            for(int i=0;i<segments.size()-1;i++){
                tempseg.push_back(segments[i]);
            }
        }else{
            for(int i=0;i<segments.size();i++){
                tempseg.push_back(segments[i]);
            }
        }
        if(tempseg.size()==0){
            cout<<0<<endl;
            continue;
        }else{
            long long int totcount = a;
            // for(int i=0;i<tempseg.size();i++){
            //     cout<<tempseg[i]<<" ";
            // }
            // cout<<endl;
            vector<vector<int>> dp(tempseg.size()+1, vector<int> (tempseg.size()+1,-1));
            // dp[0][0] = a;
            long long int ttempcount = findans(tempseg,0, tempseg.size(),dp);
            // for(auto a:dp){
            //     for(auto b:a){
            //         cout<<b<<" ";
            //     }
            //     cout<<endl;
            // }
            cout<<ttempcount<<endl;
        }
    }
    return 0;
}