#include<bits/stdc++.h>
using namespace std;
int mincount(int n, int * ptr)
{

 for(int j=2;j*j<=n;j++){
     for(int i=0;i+j*j<=n;i++){
         ptr[i+j*j] = min(ptr[i+j*j], ptr[i]+1);
     }
 }
    
//for(int i=0;i<=n;i++) cout<<ptr[i]<<" "; cout<<endl;
 return ptr[n];
    
}
int minCount(int n){
    
    /*  Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    
int *ptr =  new int [n+1];
    for(int i=0;i<=n;i++)
        ptr[i]=i;
return mincount(n ,ptr);
 
}
int main(){
    int n;
    cin>>n;
    cout<<minCount(n);
}