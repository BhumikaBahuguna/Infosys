#include<bits/stdc++.h>
using namespace std;

// Segment Tree encapsulated entirely in a struct
struct SegmentTree {
    int n;
    vector<int> arr;
    vector<int> seg;

    // CONSTRUCTOR: Automatically sizes the arrays and builds the tree
    SegmentTree(vector<int>& input_arr) {
        n = input_arr.size();
        arr = input_arr;
        seg.resize(4 * n);
        buildseg(0, 0, n - 1);
    }

    // Original Build Logic
    void buildseg(int node, int l, int r) {
        if (l == r) {
            seg[node] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        buildseg(2 * node + 1, l, mid);
        buildseg(2 * node + 2, mid + 1, r);
        seg[node] = seg[2 * node + 1] + seg[2 * node + 2];
    }

    // Original Query Logic
    int query(int node, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) return 0;
        if (ql <= l && r <= qr) return seg[node];
        int mid = (l + r) / 2;
        return query(2 * node + 1, l, mid, ql, qr) + query(2 * node + 2, mid + 1, r, ql, qr);
    }

    // WRAPPER: Makes calling query from main() super clean!
    int query(int ql, int qr) {
        return query(0, 0, n - 1, ql, qr);
    }

    // Original Update Logic
    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            seg[node] = val;
            arr[idx] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid)
            update(2 * node + 1, l, mid, idx, val);
        else
            update(2 * node + 2, mid + 1, r, idx, val);
        seg[node] = seg[2 * node + 1] + seg[2 * node + 2];
    }

    // WRAPPER: Makes calling update from main() super clean!
    void update(int idx, int val) {
        update(0, 0, n - 1, idx, val);
    }
};

int main() {
    int n;
    cin >> n;
    
    // Read the initial array
    vector<int> input_arr(n);
    for(int i = 0; i < n; i++) {
        cin >> input_arr[i];
    }
    
    // Instantiate the segment tree struct directly with the array
    SegmentTree st(input_arr);
    
    int q;
    cin >> q;
    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int l, r;
            cin >> l >> r;
            // Look how clean this is now!
            cout << st.query(l, r) << "\n";
        } else if(type == 2) {
            int idx, val;
            cin >> idx >> val;
            // Look how clean this is now!
            st.update(idx, val);
        }
    }
    return 0;
}
