// E. khba Loves to Sleep!
// https://codeforces.com/contest/2167/problem/E

#include <bits/stdc++.h>

using namespace std;


// Count how many positions in [0, x] have distance >= min_dist from all elements in a
long long CountPositionsWithMinDistance(vector<int> &a, int x, int min_dist) {
    if (min_dist == 0) {
        return x + 1;  // All positions are valid
    }
    
    long long count = 0;
    
    // Positions in [0, a[0] - min_dist] are valid
    if (a[0] >= min_dist) {
        count += a[0] - min_dist + 1;
    }
    
    // Positions in gaps between consecutive elements
    int n = a.size();
    for (int i = 0; i < n - 1; ++i) {
        long long gap_start = a[i] + min_dist;
        long long gap_end = a[i+1] - min_dist;
        if (gap_start <= gap_end && gap_end <= x) {
            count += gap_end - gap_start + 1;
        }
    }
    
    // Positions in [a[n-1] + min_dist, x] are valid
    if (a[n-1] + min_dist <= x) {
        count += x - (a[n-1] + min_dist) + 1;
    }
    
    return count;
}

// Collect k positions with distance >= min_dist
vector<int> GetPositionsWithMinDistance(vector<int> &a, int x, int min_dist, int k) {
    set<int> positions_set;  // Use set to avoid duplicates
    int n = a.size();
    
    // Positions in [0, a[0] - min_dist]
    if (a[0] - min_dist >= 0) {
        int start = 0;
        int end = min(a[0] - min_dist, x);
        for (int pos = start; pos <= end && (int)positions_set.size() < k; ++pos) {
            positions_set.insert(pos);
        }
    }
    
    // Positions in gaps between consecutive elements
    for (int i = 0; i < n - 1 && (int)positions_set.size() < k; ++i) {
        long long gap_start = (long long)a[i] + min_dist;
        long long gap_end = (long long)a[i+1] - min_dist;
        if (gap_start <= gap_end && gap_start <= x) {
            gap_end = min(gap_end, (long long)x);
            for (long long pos = gap_start; pos <= gap_end && (int)positions_set.size() < k; ++pos) {
                positions_set.insert(pos);
            }
        }
    }
    
    // Positions in [a[n-1] + min_dist, x]
    if ((long long)a[n-1] + min_dist <= x) {
        long long start = (long long)a[n-1] + min_dist;
        long long end = x;
        for (long long pos = start; pos <= end && (int)positions_set.size() < k; ++pos) {
            positions_set.insert(pos);
        }
    }
    
    // Convert set to vector
    vector<int> positions(positions_set.begin(), positions_set.end());
    return positions;
}


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {

        int n, k, x;
        cin >> n >> k >> x;

        vector<int> a(n);
        for (int &el: a) {
            cin >> el;
        }
        sort(a.begin(), a.end());
        // Remove duplicates from array a
        a.erase(unique(a.begin(), a.end()), a.end());
        n = a.size();

        // Binary search on the minimum distance
        int lo = 0, hi = x;
        int best_dist = 0;
        
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            long long count = CountPositionsWithMinDistance(a, x, mid);
            
            if (count >= k) {
                best_dist = mid;
                lo = mid + 1;  // Try for larger distance
            } else {
                hi = mid - 1;  // Need smaller distance
            }
        }
        
        // Get k positions with distance >= best_dist
        vector<int> ans = GetPositionsWithMinDistance(a, x, best_dist, k);
        
        for (int pos : ans) {
            cout << pos << ' ';
        }
        cout << '\n';
    }

    return 0;
}
