class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9];
        int col[9][9];
        int cube[9][9];

        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(cube, 0, sizeof(cube));

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int val = board[i][j] - '0';

                    if (row[i][val - 1] > 0 || 
                        col[j][val - 1] > 0 || 
                        cube[cubeIndex(i, j)][val - 1] > 0) {
                        return false;
                    }
                    ++row[i][val - 1];
                    ++col[j][val - 1];
                    ++cube[cubeIndex(i, j)][val - 1];
                }
            }
        }
        
        return true;
    }
private:    
    int cubeIndex(int i, int j) {
        return i / 3 * 3 + j / 3;
    }
};
