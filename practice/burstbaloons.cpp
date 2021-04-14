//burst balloons
#include<bits/stdc++.h>
using namespace std;
int findmax(int ptr[],int start,int end){
    int index = start;
    for(int i=start;i<=end;++i){
        if(ptr[i]<ptr[index]){
            index=i;
        }
    }
    return index;
}
int findrecur(int ptr[],int start, int end){
    if(start==end) return ptr[start];
    if(start>end) return 0;
    int maxelement = findmax(ptr,start,end);
    cout<<maxelement<<endl;
    return ptr[maxelement]*(maxelement>start?ptr[maxelement-1]:1)*
            (maxelement<end?ptr[maxelement+1]:1) 
            + findrecur(ptr,start,maxelement-1) + findrecur(ptr,maxelement+1,end);

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int ptr[n];
    for(int i=0;i<n;++i) cin>>ptr[i];
    cout<<findrecur(ptr,0,n-1);
    return 0;
}