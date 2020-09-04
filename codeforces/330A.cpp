// A. Cakeminator

#include <iostream>
#include <string>


int main(){

    int r, c;
    scanf("%d %d\n", &r, &c);

    std::string a[r];
    for (int i=0; i<r; ++i){
        std::getline(std::cin, a[i]);
    }

    bool rows[r];
    std::fill(rows, rows+r, true);
    bool columns[c];
    std::fill(columns, columns+c, true);

    int cells = 0;
    for (int i=0; i<r; ++i){
        for (int j=0; j<c; ++j){
            if (a[i][j] == 'S'){
                rows[i] = false;
                columns[j] = false;
            }
        }
    }

    int fullColumns = 0;
    for (auto col: columns){
        if (col) ++fullColumns;
    }
    cells = fullColumns*r;
    
    for (auto row: rows){
        if (row) cells += c - fullColumns;
    }

    std::cout << cells << std::endl;

    return 0;
}