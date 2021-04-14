//string pairing
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a;
    cin>>a;
    int charvalue[26];
    for(int i=0;i<n;i++){
        cin>>charvalue[i];
    }
    long prefixsum[a.size()];
    prefixsum[0] = charvalue[a[0] - 'a'];
    for(int i=1;i<s.size();i++){
        prefixsum[i] +=prefixsum[i-1] + charvalue[s[i]-'a'];
    }
    pair<int,int> charmap[26];
    for(int i=0;i<26;i++){
        charmap[i].first=INT_MAX;
        charmap[i].second=INT_MIN;
    }
    for(int i=0;i<s.size();++i){
        char ch = s[i];
        if(charmap[ch-'a'].first>i){
            charmap[ch-'a'] = i;
        }
        if(charmap[ch-'a'].second<i){
            charmap[ch-'a'] = i;
        }
    }
    long sum = 0;
    for(int i=0;i<26;i++){
        if(charmap[i].first==INT_MAX) continue;
        sum = max(sum, prefixsum[charmap[i].second] - (charmap[i].first-1>-1?  
                       prefixsum[charmap[i].first -1]:0));
    }
    return sum;
    return 0;
}