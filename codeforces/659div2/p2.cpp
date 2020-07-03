#include<bits/stdc++.h>
#define ll long long 
#define mp make_pair
#define pb push_back
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

bool finsol(vector<int> &vec, vector<int> &value, int index, int n, int l, int k,int tbegin){
    if(index == n) return true;
    bool ans=false;
    for(int i=0;i<=2*k;i++, tbegin++){
        tbegin%=2*k;
        if(vec[index]+value[tbegin] >l) return false;
        else{
            ans = ans || finsol(vec, value,index+1, n,l,k,tbegin+1);
            if(ans) return true;
        }
    }
    if(ans) return true;
    return false;
}
//     int temp=0;
//     while(temp<=2*k){
//         int t=temp;
//     bool upcycle=true;
//     bool ispossible=true;
//     if(t>=k){
//        t= 2*k-t;
//        upcycle=false;
//     }
//     int i=0;
//     for(;i<n;i++){
       
//         if(t==k){
//             upcycle=false;
//         }
//         if(t==0){
//             upcycle=true;
//         }
//         if(vec[i]+t >l){
//             return false;
//         }
//         if(upcycle){
//             t++;
//         }else{
//             t--;
//         }
//     }
//     if(i==n || ispossible) return "YES";
//     temp++;
//     }
//     return "NO";
// }
string solve(){
    int n,l,k;
    cin>>n>>k>>l;
    // n is length of array, k is tide time 2*k cycle, 
    //l is the max depth
    vector<int> vec(n), value(2*k);
    for(int i=0;i<=k;i++) value[i] = i;
    for(int i=k;i<2*k;i++) value[i] = 2*k-i;
    for(int i=0;i<n;i++) cin>>vec[i];
    if(finsol(vec,value,0,n,l,k,1)){
        return "YES";
    }else return "NO";

    // for(int i=0;i<n;i++) cin>>vec[i];
    // //this vec contains depth
    // int temp=0;
    // while(temp<=2*k){
    //     int t=temp;
    // bool upcycle=true;
    // bool ispossible=true;
    // if(t>=k){
    //    t= 2*k-t;
    //    upcycle=false;
    // }
    // int i=0;
    // for(;i<n;i++){
       
    //     if(t==k){
    //         upcycle=false;
    //     }
    //     if(t==0){
    //         upcycle=true;
    //     }
    //     if(vec[i]+t >l){
    //         ispossible=false;
    //         break;
    //     }
    //     if(upcycle){
    //         t++;
    //     }else{
    //         t--;
    //     }
    // }
    // if(i==n || ispossible) return "YES";
    // temp++;
    // }
    // return "NO";
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<"\n";
    }
    return 0;
}