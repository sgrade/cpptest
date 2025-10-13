// 774. Minimize Max Distance to Gas Station
// https://leetcode.com/problems/minimize-max-distance-to-gas-station/

#include <vector>

using std::vector;


// Based on Editorial's Approach #4: Binary Search
class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int k) {
        double left = 0, right = 1e8;
        while (right - left > 1e-6) {
            double mid = (left + right) / 2.0;
            if (CanMakeDistanceD(mid, stations, k)) {
                right = mid;
            }
            else {
                left = mid;
            }
        }
        return left;
    }

private:
    bool CanMakeDistanceD (double D, const vector<int>& stations, const int& k) {
        int new_stations = 0;
        for (int i = 0; i < stations.size() - 1; ++i) {
            new_stations += (int) ((stations[i + 1] - stations[i]) / D);
        }
        return new_stations <= k;
    }
};
