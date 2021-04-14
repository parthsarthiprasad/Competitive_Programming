#include<bits/stdc++.h>
using namespace std;

bool ispossible(vector<int> & nums, vector<int> &sol, int index, int n, int64_t &sum){
    if(index==n){
        for(auto a:sol){
            if(a!=sum) return false;
        }
        return true;
    }
    for(auto a:sol){
        if(a>sum) return false;
    }
    for(int i=0;i<sol.size();i++){
        sol[i]+= nums[index];
        if(ispossible(nums,sol, index+1, n, sum)) return true;
        sol[i]-=nums[index];
    }
    return false;
}

bool canPartitionKSubsets(vector<int>& nums, int k) {
    int64_t sum = 0;
    for(auto a:nums)sum+=a;
    if(sum%k) return false;
    sum/=k;
    vector<int> sol(k,0);
    return ispossible(nums,sol,0,(int)nums.size(), sum);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin>>n>>k;
    vector<int> vec(n);
    for(auto &a:vec)cin>>a;
    cout<<canPartitionKSubsets(vec,k)<<"\n";
    return 0;
}
    
/*
16 4
730 580 401 659 5524 405 1601 3 383 4391 4485 1024 1175 1100 2299 3908
