
#include<bits/stdc++.h>

using namespace std; 
#define ll long long 




ll solve(){
    int n;
    cin>>n;
    vector<int> ptr(n);
    for(int i=0;i<n;++i){
        cin>>ptr[i];
    }
    sort(ptr.begin(), ptr.end());
    int k = 5;
    long product = 1; 
	if (ptr[n - 1] == 0 && (k & 1)) 
		return 0; 
	if (ptr[n - 1] <= 0 && (k & 1)) { 
		for (int i = n - 1; i >= n - k; i--) 
			product *= ptr[i]; 
		return product; 
	} 

	int i = 0; 

	int j = n - 1; 

	if (k & 1) { 
		product *= ptr[j]; 
		j--; 
		k--; 
	} 

	k >>= 1; 

	for (int itr = 0; itr < k; itr++) { 

		int left_product = ptr[i] * ptr[i + 1]; 

		int right_product = ptr[j] * ptr[j - 1]; 

		if (left_product > right_product) { 
			product *= left_product; 
			i += 2; 
		} 
		else { 
			product *= right_product; 
			j -= 2; 
		} 
	} 

	return product; 
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
    return 0;
}