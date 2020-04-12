#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;


int findugly(int ans){
 int i2 , i3, i5 ;
 i2 = 0;
 i3 = 0;
 i5 = 0;
 int * ptr = new int[ans+1];
 //memset(ptr,1,sizeof(ptr));
 ptr[0]=1;
 int min2 , min3 , min5 ;
 min2 = ptr[i2];
 min3 = ptr[i3];
 min5 = ptr[i5];
 int i=0;
 while(i<ans){
    int minnum = min(min2,min(min3,min5));
    ptr[i]=minnum;
    if(minnum==min2){
        min2= ptr[i2]*2;
        i2++;
    }
    if(minnum==min3){
        min3= ptr[i3]*3;
        i3++;
    }
    if (minnum==min5){
        min5 = ptr[i5]*5;
        i5++;

    }
    
    i++;
 }

 return ptr[ans-1];

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    //inputted the ugly number number that I wanted to search

    auto start = high_resolution_clock::now(); 
    cout<<findugly(n)<<endl;
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
  
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl; 
    return 0;
}