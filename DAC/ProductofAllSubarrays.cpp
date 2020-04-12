//products of all subarrays
#include<bits/stdc++.h>
#define ll long long 
#define MOD 1000000007
using namespace std;
using namespace std::chrono;
ll findproduct(int ptr[],int n){
    return 0;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[]={1,2,3,4,5,6};
    int len = sizeof(arr)/sizeof(arr[0]);
    auto start = high_resolution_clock::now();
    cout<<findproduct(arr,len)<<endl;
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end-start);
    cout<<"total time taken is "
        <<duration.count()<<"microseconds\n";
    return 0;
}