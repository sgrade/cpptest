// A. Pashmak and Garden

#include <iostream>
#include <algorithm>


int main(){

    int x1, y1, x2, y2, x3, y3, x4, y4;
    std::cin >> x1 >> y1 >> x2 >> y2;

    bool ans = true;

    if (abs(x1 - x2) != abs(y1 - y2)) {
        if (x1 != x2 && y1 != y2) ans = false;
    }

    int side = std::max(abs(x1 - x2), abs(y1 - y2));

    // x1 and x2 are on the vertical line
    if (ans && x1 == x2) {
        // x3 and x4 should also be on the vertical line: x3 == x4
        if (x1 + side <= 1000) {
            x3 = x1 + side;
            x4 = x1 + side;
        }
        else if (x1 - side >= -1000) {
            x3 = x1 - side;
            x4 = x1 - side;
        }
        else ans = false;

        y3 = y1;
        y4 = y2;
    }

    // x1 and x2 are on the horizontal line, so y1 = y2
    else if (ans && y1 == y2) {
        if (y1 + side <= 1000) {
            y3 = y1 + side;
            y4 = y1 + side;
        }
        else if (y1 - side >= -1000) {
            y3 = y1 - side;
            y4 = y1 - side;
        }
        else ans = false;

        x3 = x1;
        x4 = x2;
    }

    // point 1 and 2 are on the diagonal line
    else if (ans) {
        x3 = x1;
        y3 = y2;
        x4 = x2;
        y4 = y1;
    }

    if (ans) {
        std::cout << x3 << ' ' << y3 << ' ' << x4 << ' ' << y4 << std::endl;
    }
    else std::cout << "-1\n";

    return 0;
}
