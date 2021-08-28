// C. Infinity Table

#include <iostream>


int main() {

    int t;
    std::cin >> t;

    while (t--) {

        int k;
        std::cin >> k;

        int layers = 1;
        int total_cells = 1, cells_in_layer = 1;

        // Note: "while(true)" doesn't work, when k == 1
        while (k > total_cells) {

            cells_in_layer += 2;
            layers += 1;
            total_cells += cells_in_layer;

            if (total_cells >= k) {
                break;
            }
        }

        int column = total_cells - k < layers ? total_cells - k + 1 : layers;
        int row = column == layers ? k - (total_cells - cells_in_layer) : layers;

        std::cout << row << ' ' << column << std::endl;
    }

    return 0;
}
