#include<bits/stdc++.h>
using namespace std;

void build(int idx, int low, int high, vector<int>& seg, vector<int>& arr) {
    if(low == high) {
        seg[idx] = arr[low];
        return;
    }

    int mid = (low + high) >> 1;

    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    build(left, low, mid, seg, arr);
    build(right, mid + 1, high, seg, arr);

    seg[idx] = min(seg[left], seg[right]);
}

int query(int idx, int l, int r, int low, int high, vector<int>& seg) {
    // complete overlap
    if(low >= l && high <= r) {
        return seg[idx];
    }

    // parital overlap
    if(low > r || high < l) {
        return INT_MAX;
    }    

    // no overlap
    else {
        int mid = (low + high) >> 1;
        return min(query(2 * idx + 1, l, r, low, mid, seg),
        query(2 * idx + 2, l, r, mid + 1, high, seg));
    }
}

void segment() {
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> seg(4*n);
    
    for(auto& a: arr) {
        cin >> a;
    }

    build(0, 0, n-1, seg, arr);
}

int main() {
    segment();
}