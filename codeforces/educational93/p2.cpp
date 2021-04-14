//last round went bad due to sprinklr mood
//keepcalm and do well, microsoft is ahead;
#include<bits/stdc++.h>
#define ll long long 
const int mod = 1e9+1;
const int nax = 2e5+5;
#define pb push_back
#define mp make_pair
using namespace std;
// int findans(int i, int n, string &s){
//     if(i>=n) return 0;
//     int k=1,l=1;
//     int index = i;
//     while(index<= n && s[index]==s[index+1]){
//         k++;
//         index++;
//     }
//     index = n;
//     while(index>=i &&  s[index-1]==s[index]){
//         l++;
//         index--;
//     }
//     return max( findans(i+k,n,s) +k , findans(i,n-l,s) + l);
// }


ll solve(){
    string s;
    cin>>s;
    vector<int> vec1;
    vector<int> vec0;
    for(int i=0;i<s.size(); i++){
        int count =1;
        while( i+1 < s.size() && s[i]==s[i+1]){
            i++;
            count++;
        }
        if(s[i]=='0')
        vec0.pb(count);
        else vec1.pb(count);
    }

    if(vec1.size()==0) return 0;
    else {
        int count =0;
        sort(vec1.rbegin(), vec1.rend());
        for(int i=0;i<vec1.size(); i+=2){
            count+=vec1[i];
        }
        return count;

    }

    //cout<<s<<endl;
    // return max(findans(0,s.size()-1, s), findans(0,s.size()-1, s));
    // return 0;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
    return 0;
}