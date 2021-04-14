#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        char start = s[0];
        char end = s[s.size()-1];
        char otc;
        if(start==end){
            cout<<"NO\n";
            continue;
        }
        int countstart =0 ;
        int countend = 0;
        int left = 0;
        for(auto a:s){
            if(a==start)countstart++;
            else if(a==end) countend++;
            else left++;
        }
        if(countstart>countend) otc = end;
        else otc = start;
        int count =0;
        bool possible = true;
        for(auto a:s){
            if(a==start) count++;
            else if(a==end) count--;
            else if(otc ==start) count++;
            else count--;
            if(count<0) possible = false;
        }
        if(count!=0) possible = false;
        if(possible)cout<<"YES\n";
        else cout<<"NO\n";
    }
}