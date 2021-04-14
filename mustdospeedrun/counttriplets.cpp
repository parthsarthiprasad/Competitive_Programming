/*
https://practice.geeksforgeeks.org/problems/count-the-triplets/0/
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ptr[n];
        for(int i=0;i<n;i++)cin>>ptr[i];
        unordered_set<int> mp;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                mp.insert(ptr[i] + ptr[j]);
            }
        }
        int count = -1;
        for(int i=0;i<n;i++){
            if(mp.find(ptr[i])!= mp.end()) count++;
        }
        if(count>-1)count++;
        cout<<count<<endl;
    }
    return 0;
}