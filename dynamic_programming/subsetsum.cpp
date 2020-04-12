#include<bits/stdc++.h>
using namespace std;
bool finsubsetsum(int ptr[] , int sum, int n )
{
    //if (sum <0 || sizeof(ptr)/sizeof(ptr[0])==0 )
    if ( sum<0 || n<0 )
    return false;
    if (sum==0)
    return true;
    bool ans1 =  finsubsetsum(ptr , sum - ptr[n],n-1);
    bool ans2 =  finsubsetsum(ptr , sum, n-1);
    return ans1||ans2;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int set[] = {3,34,4,12,5,2};
    int n = sizeof(set)/sizeof(set[0]);
    int sum = 9;
    cout<<finsubsetsum(set,sum,n-1);
    return 0;
}