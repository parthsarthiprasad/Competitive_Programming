#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5+1;
struct rect{
    int x;
    int y;
    int index;
};
struct dim{
    int x;
    int y;
};

vector<rect> lquery(nax);
vector<rect> bquery(nax);
vector<dim> vec(nax);
int n;
// vector<rect> segtreex(2*nax);
// vector<rect> segtreey(2*nax);
// void buildx(){
//     for(int i=0;i<n;i++){
//         segtreex[i+n] = lquery[i];
//     }
//     for(int i=n-1;i>0;i--){
//         lquery[i] = max(lquery[i*2], lquery[i*2+1]);
//     }
// }
// void buildy(){
//     for(int i=0;i<n;i++){
//         segtreey[i+n] = bquery[i];
//     }
//     for(int i=n-1;i>0;i--){
//         if(bquery[i*2].y>)
//         segtreey[i] = max(bquery[i*2], bquery[i*2+1]);
//     }
// }
// void build(){
//     buildx();
//     buildy();
// }
int lower_boundx(vector<rect> &a, int value){
    int ans = -1;
    int start = 0;
    int end = n-1;
    while(start<=end){
        int mid =  start + (end - start)/2;
        if(a[mid].x < value){
            ans = mid;
            start = mid+1;
        }else{
            end = mid-1;
        }
    }
    return ans;
}
int lower_boundy(vector<rect> &a, int value){
    int ans = -1;
    int start = 0;
    int end = n-1;
    while(start<=end){
        int mid =  start + (end - start)/2;
        if(a[mid].y < value){
            ans = mid;
            start = mid+1;
        }else{
            end = mid - 1;
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
       for(int i=0;i<n;i++){
           int x,y;
           cin>>x>>y;
           vec[i].x = x;
           vec[i].y = y;
           lquery[i].x = x;
           lquery[i].y = y;
           lquery[i].index = i;
           bquery[i].x = x;
           bquery[i].y = y;
           bquery[i].index = i;
       }
       sort(lquery.begin(), lquery.begin() + n,[&](const rect &a, const rect &b){
           if(a.x == b.x){
               return a.y < b.y;
           }
           return a.x < b.x;
       });
       sort(bquery.begin(), bquery.begin() + n,[&](const rect &a, const rect &b){
           if(a.y == b.y) return a.x < b.x;
           return a.y < b.y;
       });

       for(int i=0;i<n;i++){
           
        //    int xindex = lower_bound(lquery.begin(), lquery.end(), vec[i].x) - lquery.begin();
        //    int yindex = lower_bound(bquery.begin(), bquery.end(), vec[i].y) - bquery.begin();
           int xindex = lower_boundx(lquery,vec[i].x);
           int yindex = lower_boundy(bquery, vec[i].y);
        //    int xindex = n;
        //    int yindex = n;
           set<int> s;
            int abc = -1;
            for(int i = 0;i<xindex;i++){
                s.insert(lquery[i].index);
            }
            for(int i=0;i<yindex;i++){
                if(s.find(bquery[i].index)!=s.end()){
                    abc = bquery[i].index;
                    break;
                }
            }
            cout<<abc<<" ";
       }
       cout<<endl;
        // build();

    }
    return 0;
}