//total number of ways in ladder jump
#include<bits/stdc++.h>
using namespace std;
int findnum(int n,int k=3){
    int * ptr = new int[n+1];
    ptr[0]=0;
    ptr[1]=1;
    ptr[2]=2;
    for(int i=3;i<=n;i++){
        ptr[i]=ptr[i-1]+ptr[i-2]+ptr[i-3];
    }
    return ptr[n];
}
// this can be further improved by sliding window technique

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    cout<<findnum(n)<<endl;
    cout<<findnumopt(n)<<endl;
    return 0;
}