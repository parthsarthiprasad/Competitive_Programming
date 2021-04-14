

#include<bits/stdc++.h>
using namespace std;
bool isvalid(int m, vector<int> &vec){
    int count =0;
    vector<int>::iterator it1 = vec.begin();
    vector<int>::iterator it2 =upper_bound(vec.begin(), vec.end(), m);

    for(int i=1;i<=3 && it2!=vec.end() ;i++){
        it1=it2;
        cout<<m<<" "<<i*m + (*it1)<<endl;
        it2= upper_bound(vec.begin(), vec.end(), i*m + (*it1) );
    }

    return (it1==vec.end() || it2!=vec.end()); 
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++) cin>>vec[i];
    sort(vec.begin(), vec.end());
    // erasing duplicates
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    for(int i=vec.size()-1;i>=0; i--){
        vec[i]-=vec[0];
    }
    for(int i=0;i<vec.size(); i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    int start= 1, end=vec[vec.size()-1];
    int mid;
    float ans;
    while(start<end){
        mid = start + (end-start)/2;
        if(isvalid(mid, vec)){
            ans = mid;
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    ans = mid;
    // ans = min(ans,start);
    cout<<fixed<<setprecision(1)<<((ans))<<endl;

}