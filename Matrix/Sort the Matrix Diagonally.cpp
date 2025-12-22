#include <iostream>
#include <vector>
#include <algorithm> // For sort

using namespace std;

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        // Pass 1: Diagonals starting from the top row (0, col)
        for (int col = 0; col < m; col++) {
            vector<int> diag;
            int i = 0, j = col;

            // 1. Collect elements
            while (i < n && j < m) {
                diag.push_back(mat[i][j]);
                i++, j++;
            }

            // 2. Sort elements
            sort(diag.begin(), diag.end());

            // 3. Put them back
            i = 0, j = col;
            int idx = 0;
            while (i < n && j < m) {
                mat[i][j] = diag[idx++];
                i++, j++;
            }
        }

        // Pass 2: Diagonals starting from the left column (row, 0)
        // We start from row=1 because row=0 was covered in Pass 1
        for (int row = 1; row < n; row++) {
            vector<int> diag;
            int i = row, j = 0;

            // 1. Collect elements
            while (i < n && j < m) {
                diag.push_back(mat[i][j]);
                i++, j++;
            }

            // 2. Sort elements
            sort(diag.begin(), diag.end());

            // 3. Put them back
            i = row, j = 0;
            int idx = 0;
            while (i < n && j < m) {
                mat[i][j] = diag[idx++];
                i++, j++;
            }
        }

        return mat;
    }
};

// Helper function to print the matrix
void printMatrix(const vector<vector<int>>& mat) {
    cout << "[" << endl;
    for (const auto& row : mat) {
        cout << "  [ ";
        for (int x : row) {
            cout << x << " ";
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    // Test Case:
    // Input:
    // [ 3, 3, 1, 1 ]
    // [ 2, 2, 1, 2 ]
    // [ 1, 1, 1, 2 ]
    
    // Expected Output:
    // [ 1, 1, 1, 1 ]
    // [ 1, 2, 2, 2 ]
    // [ 1, 2, 3, 3 ]

    vector<vector<int>> mat = {
        {3, 3, 1, 1},
        {2, 2, 1, 2},
        {1, 1, 1, 2}
    };

    cout << "Original Matrix:" << endl;
    printMatrix(mat);

    vector<vector<int>> result = sol.diagonalSort(mat);

    cout << "\nSorted Matrix:" << endl;
    printMatrix(result);

    return 0;
}