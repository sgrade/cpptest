// 3484. Design Spreadsheet
// https://leetcode.com/problems/design-spreadsheet/

#include <vector>
#include <string>

using std::vector;
using std::string;
using std::pair;


class Spreadsheet {
public:
    Spreadsheet(int rows) {
        cells.assign(rows, vector<int>(26, 0));
    }
    
    void setCell(const string& cell, int value) {
        auto [row, col] = ParseCell(cell);
        cells[row][col] = value;
    }
    
    void resetCell(const string& cell) {
        auto [row, col] = ParseCell(cell);
        cells[row][col] = 0;
    }
    
    int getValue(const string& formula) {
        size_t plus_pos = formula.find('+');
        vector<string> tmp = {formula.substr(1, plus_pos - 1), formula.substr(plus_pos + 1)};
        vector<int> nums(2);
        for (int i = 0; i < 2; ++i) {
            if (isdigit(tmp[i][0])) {
                nums[i] = stoi(tmp[i]);
            } else {
                auto [row, col] = ParseCell(tmp[i]);
                nums[i] = cells[row][col];
            }
        }
        int ans = nums[0] + nums[1];
        return ans;
    }

private:
    vector<vector<int>> cells;

    pair<int, int> ParseCell(const string& cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        return {row, col};
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
