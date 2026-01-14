// 3453. Separate Squares II
// https://leetcode.com/problems/separate-squares-ii/

#include <algorithm>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

// Coordinate Compression Segment Tree for Sweep Line Algorithm
// Tracks covered length of x-coordinates as we sweep through y-coordinates
class SegmentTree {
 private:
  vector<int> count_;    // Number of overlapping rectangles at each segment
  vector<int> covered_;  // Total covered length in each segment
  vector<int> xs_;       // Sorted x-coordinates for coordinate compression
  int n_;

  void Modify(int query_left, int query_right, int delta, int left, int right,
              int pos) {
    // No overlap with query range
    if (xs_[right + 1] <= query_left || xs_[left] >= query_right) {
      return;
    }

    // Current segment fully contained in query range
    if (query_left <= xs_[left] && xs_[right + 1] <= query_right) {
      count_[pos] += delta;
    } else {
      int mid = (left + right) / 2;
      Modify(query_left, query_right, delta, left, mid, pos * 2 + 1);
      Modify(query_left, query_right, delta, mid + 1, right, pos * 2 + 2);
    }

    // Update covered length
    if (count_[pos] > 0) {
      covered_[pos] = xs_[right + 1] - xs_[left];
    } else {
      if (left == right) {
        covered_[pos] = 0;
      } else {
        covered_[pos] = covered_[pos * 2 + 1] + covered_[pos * 2 + 2];
      }
    }
  }

 public:
  explicit SegmentTree(const vector<int>& xs) : xs_(xs) {
    n_ = xs_.size() - 1;
    count_.resize(4 * n_, 0);
    covered_.resize(4 * n_, 0);
  }

  void Update(int query_left, int query_right, int delta) {
    Modify(query_left, query_right, delta, 0, n_ - 1, 0);
  }

  int Query() const { return covered_[0]; }
};

class Solution {
 public:
  double separateSquares(vector<vector<int>>& squares) {
    // Create events for sweep line algorithm
    // Event: (y-coordinate, delta, x_left, x_right)
    // delta = +1 when entering (bottom edge), -1 when exiting (top edge)
    vector<tuple<int, int, int, int>> events;
    set<int> x_coords;

    for (const vector<int>& sq : squares) {
      int x = sq[0];
      int y = sq[1];
      int side = sq[2];
      int x_right = x + side;

      // Opening event (bottom edge of square): increment count
      events.emplace_back(y, 1, x, x_right);
      // Closing event (top edge of square): decrement count
      events.emplace_back(y + side, -1, x, x_right);

      x_coords.insert(x);
      x_coords.insert(x_right);
    }

    // Sort events by y-coordinate
    sort(events.begin(), events.end());

    // Coordinate compression for x-coordinates
    vector<int> xs(x_coords.begin(), x_coords.end());
    SegmentTree segment_tree(xs);

    // Track cumulative area and widths at each event
    vector<double> cumulative_area;
    vector<int> widths;
    double total_area = 0.0;
    int prev_y = get<0>(events[0]);

    // Process events in y-order (sweep line)
    for (const auto& [y, delta, x_left, x_right] : events) {
      int covered_width = segment_tree.Query();
      total_area += static_cast<double>(covered_width) * (y - prev_y);

      segment_tree.Update(x_left, x_right, delta);

      cumulative_area.push_back(total_area);
      widths.push_back(segment_tree.Query());
      prev_y = y;
    }

    // Find the y-coordinate that splits the total area in half
    double target_area = total_area / 2.0;
    int idx = lower_bound(cumulative_area.begin(), cumulative_area.end(),
                          target_area) -
              cumulative_area.begin() - 1;

    double area_at_event = cumulative_area[idx];
    int width_at_event = widths[idx];
    int y_at_event = get<0>(events[idx]);

    // Calculate exact y-coordinate for the split line
    double remaining_area = target_area - area_at_event;
    double additional_height = remaining_area / width_at_event;

    return y_at_event + additional_height;
  }
};
