#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<int> segments;
        for(int i=0;i<n;i++){
            int j=i, tocount = 0;
            while(j<n && s[j]==s[i]){
                j++;
                tocount++;
            }
            segments.push_back(tocount);
            i=j-1;
        }
        int p1=0,p2=0, count = 0;
        while(p1<segments.size() && p2<segments.size()){
            while(p2<segments.size() && segments[p2]<2){
                p2++;
            }
            p1++;
            if(p2<segments.size()){
                segments[p2]--;
            }
            count++;
        }
        count+=(p2-p1)/2;
        cout<<count<<endl;
    }
}