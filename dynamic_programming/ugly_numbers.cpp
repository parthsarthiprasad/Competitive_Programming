//ugly numbers 
/*
those numbers who have factors of 2 ,3 or 5 .  1,2,3,4,5... are ugly numbers 
*/
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int maxdivide(int num , int base)
{
    while(num%base == 0){
        num/=base;
    }
    return num;
}

bool isugly(int num){

    int temp = num;
    temp = maxdivide(temp, 2);
    temp = maxdivide(temp, 3);
    temp = maxdivide(temp, 5);
    return (temp == 1);
}

int findugly(int n)
{
  int i =1;
  int count = 0 ;  // the latest ugly number I've found 
    while(count < n){
      if(isugly(i)){
          count++;
      }
      i++;
    }

  return i-1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n ;
    cin>>n;
    auto start = high_resolution_clock::now(); 
    cout<<findugly(n)<<endl;
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
  
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl; 
    
    return 0;
}