#include<bits/stdc++.h>
using namespace std;
int bsearch(string &s, int l, int r, char key){
    int index = -1;
    while(l<=r){
        int mid = l + (r-l)/2;
        if (s[mid]<=key) r = mid-1;
        else{
            l=mid+1;
            if(index == -1 || s[index]>=mid) index = mid;
        }
    }
    return index;
}
string nextpermuation(string s){
    int len = s.length();
    int i = len-1;
    while(i-1 >-1 && s[i-1]>s[i]){
        i--;
    }
    if(i==0) return "NOT POSSIBLE";
    else{
        int index = bsearch(s,i+1, len-1, s[i]);
        swap(s[i], s[index]);
        sort(s.begin()+i-1,s.end());
    }
    return s;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    cout<<nextpermuation(s);
    return 0;
}