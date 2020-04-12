#include<bits/stdc++.h>
#define MAXN 100
using namespace std;
int dp[MAXN];
//memset(dp,-1,MAXN*sizeof(int));

// step 1 is finding a recursive solution
int findpermutation(int a, int* ptr){
    if(a<0)
    return 0;
    if (a==0)
    return 1;
    int ans = 0;
    if (dp[a]!=-1)
        return dp[a];
    int len = sizeof(ptr)/sizeof(int);
    for( int i =0 ; i<=len ; i++)
    {
        ans+=findpermutation(a - ptr[i], ptr);
        
    }

    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n ;
    cin>>n;
    int * ptr = new int[4];
    ptr[0] = 1;
    ptr[1] = 3;
    ptr[2] = 5;
    for( int i = 0 ; i<MAXN ; i++)
        dp[i]= -1;

    cout<<findpermutation(n ,ptr)<<endl;
    return 0;
}