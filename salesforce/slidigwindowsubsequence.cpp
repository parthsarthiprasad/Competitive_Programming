#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a,b;
    cin>>a>>b;
    int count = 0;
    int windowlength = INT_MAX;
    a+=a;
    unorded_map<char,int> mp;
    for(int i=0;i<n;i++){
        mp[a[i]]++;
        if(find(b.begin(), b.end(), s[i]) !=b.end()){
            count++;
        }
    
        while(count==b.size()){
            mp[a[index]]--;
            if(find(b.begin(),b.end(), a[index++])!= b.end()){
                count--;
                windowlength=min(windowlength,i-index-1);
            }
        }
    
    }
}