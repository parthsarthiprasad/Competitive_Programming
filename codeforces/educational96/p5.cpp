#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    string s;
    cin>>s;
    string temp = s;
    reverse(temp.begin(), temp.end());
    long int count = 0;
    for(int i=0;i<n;i++){
        int pos = n-1-i;
        char ch = temp[pos];
        while(pos>=0 && s[pos]!=ch){
            pos--;
        }
        while(pos<n-1-i){
            count++;
            swap(s[pos],s[pos+1]);
            pos++;
        }
    }
    cout<<count<<endl;
    //this code will convert the string to palindrome,
    //leaving the digits which don't a palidrome counterpart
    // for(int i=0;i<=n/2;i++){
    //     int j=i;
    //     int k=n-1-i;
        
    //     int pos1,pos2;
    //     pos1 = j, pos2=k;
    //     while(pos1<k && s[pos1]!=s[k]){
    //         pos1++;
    //     }
    //     while(pos2>j && s[pos2]!=s[j]){
    //         pos2--;
    //     }
    //     if(pos1==k+1 && pos2==j-1){
    //         continue;
    //     }else {
    //         int diff1 = k-pos2;
    //         int diff2 = pos1 - j;
    //         if(diff1<diff2){
    //             while(pos2<k){
    //             swap(s[pos2],s[pos2+1]);
    //             count++;
    //             pos2++;
    //             }
    //         }else{
    //             while(pos1>j){
    //             swap(s[pos1],s[pos1-1]);
    //             count++;
    //             pos1--;
    //         }
    //         }
    //     }
        
    // }
    // cout<<count<<endl;
    return 0;

    
}