// This problem can also be solved using divide and conquer
//If I have an array and have to determine the number of subarrays 
//That have equal number of odd and even numbers
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
//Time complexity O(n) space complexity O(2*len)
int findcount(int ptr[], int len){
    map<int,int> table;
    int count = 0; 
    //solution construction of array 
    int* temp = new int[len];
    temp[0]= (ptr[0]&1)==0?1:-1;
    for(int i=1;i<len;i++){
        int val = (ptr[i]&1)==0?1:-1;
        temp[i] = temp[i-1]+val;
        if(table.find(temp[i])==table.end())
            table[temp[i]]=0;
        count+=table[temp[i]];
        if(temp[i]==0)
        count++;
        table[temp[i]]++;
    }

    // for(int i=0;i<len;i++){
    //     cout<<temp[i]<<" ";
    // }
    // cout<<endl;
    return count;
}


//SOlution can be improved since temp[i] and temp[i-1] are always in use 
//make the array of size 2
//Time complexity O(n) and space complexity O(len+2)
int findcountopt(int ptr[], int len){
    map<int,int> table;
    int count = 0; 
    //solution construction of array 
    int* temp = new int[2];
    temp[0]= (ptr[0]&1)==0?1:-1;
    for(int i=1;i<len;i++){
        int val = (ptr[i]&1)==0?1:-1;
        temp[i%2] = temp[(i-1)%2]+val;
        if(table.find(temp[i%2])==table.end())
            table[temp[i%2]]=0;
        count+=table[temp[i%2]];
        if(temp[i%2]==0)
        count++;
        table[temp[i%2]]++;
    }
    // This can't exist though
    // for(int i=0;i<len;i++){
    //     cout<<temp[i]<<" ";
    // }
    // cout<<endl;
    return count;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int ptr[]={1,1,1,1,2,3,5,2,5,2,5,2,3,5,3,5,2,3,2,1,6};
    int ptr[]={1,2,3,4};
    int len = sizeof(ptr)/sizeof(ptr[0]);
    auto start = high_resolution_clock::now();
    cout<<findcount(ptr,len)<<endl;
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end-start);
    cout<<"Total duration of execution is :\t"
        <<duration.count()<<"microseconds\n";
    start = high_resolution_clock::now();
    cout<<findcountopt(ptr,len)<<endl;
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end-start);
    cout<<"Total duration of execution is :\t"
        <<duration.count()<<"microseconds\n";
    return 0;
}

// RESULTS
/*
3
Total duration of execution is :        73microseconds
3
Total duration of execution is :        17microseconds
Thus improvement that is taken in invocation for secondard array
*/