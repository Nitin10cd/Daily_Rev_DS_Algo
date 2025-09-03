#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
void setZeroes(vector<vector<int>>& matrix) {
    int col = 1;
    
    // First pass: mark rows and columns to be zeroed
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0; // Mark the start of the row
                if (j != 0) {
                    matrix[0][j] = 0; // Mark the start of the column
                } else {
                    col = 0; // If the first column has a zero
                }
            }
        }
    }

    // Second pass: use marks to set elements to zero
    for (int i = 1; i < matrix.size(); i++) {
        for (int j = 1; j < matrix[0].size(); j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    // Handle the first row
    if (matrix[0][0] == 0) {
        for (int j = 0; j < matrix[0].size(); j++) {
            matrix[0][j] = 0;
        }
    }

    // Handle the first column
    if (col == 0) {
        for (int i = 0; i < matrix.size(); i++) {
            matrix[i][0] = 0;
        }
    }
}

};
