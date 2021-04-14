#include<bits/stdc++.h>
using namespace std;
bool isvalid(int ptr[],int mid, int limit , int sz){
    long ans = 1e18-1;
    for(int i=0;i<sz;++i){
        ans = min(ans, (long)(mid*(ptr[i] + mid*i)));
    }

    /*
    when mid is number of objects ;
    i have mid objects of a0 ;
            mid objects of a1 ;
            mid objects of a2;
            ......
            mid objects of ans
    total cost for each group will be mid*( a0 + mid*0)
                                    or mid*(a1 + mid*1)
                                        .... similarly
    */
    return  (limit >= ans);
}
int bsearch(int ptr[], int start, int end ,int limit ,int sz){
    int mid = start + (end - start)/2;
    int ans = start;
    while(start<=end){
        mid = start + (end - start)/2;
        if(isvalid(ptr, mid, limit ,sz)){
            ans = mid;
            start = mid+1;
        }else{
            end = mid-1;
        }
    }
    return ans;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int ptr[n];
        for(int i=0;i<n;++i)cin>>ptr[i];
        //k is the total cost that i have to cover
        cout<<bsearch(ptr,0,n-1, k,n);
    }
}
/*
k coins
each coins have a0,a1,a2,
1, 2, 3, 4, 5 ,6 ,7 ,...n sovieneur
each element has cost of k*i
*/

/*
testcase 
1
4 10
2 5 3 4

OUTPUT: 2


*/