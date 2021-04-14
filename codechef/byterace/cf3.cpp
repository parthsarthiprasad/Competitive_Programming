#include<bits/stdc++.h>
using namespace std;
#define int int64_t
class node{
    public:
    int left;
     int right;
     int sum;
     int first;
     int last;
     node * left_child;
     node * right_child;

     node(vector<int> & vec, int l, int r){
         left = l;
         right = r;
         if(l==r){
             sum = vec[l];
         }else{
             int m = (l+r)/2;
             left_child = new node(vec, l ,m);
             right_child = new node(vec,m+1,r);
             sum = left_child->sum + right_child->sum;
         }
     }
      void add(int l, int r, int X) {
        // Lazy propagation
        propagate();
        if ((r < left) || (right < l)) {
            // If updated interval doesn't overlap with current subtree
            return;
        } else if ((l <= left) && (right <= r)) {
            // If updated interval fully covers the current subtree
            // Update the first and last items of the arithmetic progression
            int first_item_offset = (left - l) + 1;
            int last_item_offset = (right - l) + 1;
            first = X * first_item_offset;
            last = X * last_item_offset;
            // Lazy propagation
            propagate();
        } else {
            // If updated interval partially overlaps with current subtree
            left_child->add(l, r, X);
            right_child->add(l, r, X);
            // Update accumulated sum
            sum = left_child->sum + right_child->sum;
        }
    }

    /**
     * Returns the sum on the interval [l, r]
     * O(log(N))
     */
    int query(int l, int r) {
        // Lazy propagation
        propagate();
        if ((r < left) || (right < l)) {
            // If requested interval doesn't overlap with current subtree
            return 0;
        } else if ((l <= left) && (right <= r)) {
            // If requested interval fully covers the current subtree
            return sum;
        } else {
            // If requested interval partially overlaps with current subtree
            return left_child->query(l, r) + right_child->query(l, r);
        }
    }


     void propagate(){
         int items = (right - left) + 1;
         sum += ((first + last) * items) / 2;
        if (right != left) { // Current node is not a leaf
            // Calculate the step of the Arithmetic Progression of the current node
            int step = (last - first) / (items - 1);
            // Update the first and last items of the arithmetic progression
            // inside the left and right subtrees
            // Distribute the arithmetic progression between child nodes
            // [a(1) to a(N)] -> [a(1) to a(N/2)] and [a(N/2+1) to a(N)]
            int mid = (items - 1) / 2;
            left_child->first += first;
            left_child->last += first + (step * mid);
            right_child->first += first + (step * (mid + 1));
            right_child->last += last;
        }
        // Reset the arithmetic progression of the current node
        first = 0;
        last = 0;
     }
};
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        vector<int> vec(n);
        for(int i=0;i<n;i++){
            vec[i] = 0;
        }
        node *segtree = new node(vec,0,n-1);

        while(q--){
            int l,r;
            cin>>l>>r;
            l--;r--;
            segtree->add(l,r,1);
        }

        for(int i=0;i<n;i++){
            cout<<segtree->query(i,i)<<" ";
        }
        delete [] segtree;
        cout<<endl;
        

    }
}