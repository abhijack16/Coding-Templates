#include<bits/stdc++.h>
using namespace std;

class SegTree {
    private:
    int n;
    vector<int> seg;

    void build(int idx, int low, int high, vector<int>& arr) {
        if(low == high) {
            seg[idx] = arr[low];
            return;
        }

        int mid = (low + high) >> 1;

        int left = 2 * idx + 1;
        int right = 2 * idx + 2;

        build(left, low, mid, arr);
        build(right, mid + 1, high, arr);

        seg[idx] = min(seg[left], seg[right]);
    }

    int query(int idx, int l, int r, int low, int high) {
        // complete overlap
        if(low >= l && high <= r) {
            return seg[idx];
        }

        // no overlap
        if(low > r || high < l) {
            return INT_MAX;
        }    

        // partial overlap
        else {
            int mid = (low + high) >> 1;
            return min(query(2 * idx + 1, l, r, low, mid),
            query(2 * idx + 2, l, r, mid + 1, high));
        }
    }

    void update(int idx, int low, int high, int pos, int val) {
        if(low == high) {
            seg[idx] = val;
            return;
        }

        int left = 2 * idx + 1;
        int right = 2 * idx + 2;

        int mid = (low + high) >> 1;
        if(pos <= mid) {
            update(left, low, mid, pos, val);
        }

        else {
            update(right, mid + 1, high, pos, val);
        }

        seg[idx] = min(seg[left], seg[right]);
    }

    public:
    SegTree(vector<int>& arr) {
        n = arr.size();
        seg.resize(4 * n);

        if(n > 0)
            build(0, 0, n-1, arr);
    }

    int query(int l, int r) {
        return query(0, l, r, 0, n - 1);
    }

    void update(int pos, int val) {
        return update(0, 0, n-1, pos, val);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    
    for(auto& a: arr) {
        cin >> a;
    }
    
    SegTree seg(arr);

    //Write logic if required
}

// main function here!
int main() {
    solve();
}