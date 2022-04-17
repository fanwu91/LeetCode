#include <vector>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        initialize(board);
        fill(board, 0);
        reset();
    }
private:
    int m_rows[9][9];
    int m_cols[9][9];
    int m_cubes[9][9];
    vector<pair<int, int>> m_spaces;
    string m_digits;

    void initialize(vector<vector<char>>& board)
    {   
        memset(m_rows, 0, sizeof(m_rows));
        memset(m_cols, 0, sizeof(m_cols));
        memset(m_cubes, 0, sizeof(m_cubes));
        m_digits = "123456789";

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int k = i / 3 * 3 + j / 3;
                    int d = board[i][j] - '1';
                    ++m_rows[i][d];
                    ++m_cols[j][d];
                    ++m_cubes[k][d];
                } else {
                    m_spaces.emplace_back(pair<int, int>(i, j));
                }
            }
        }
    }

    void reset()
    {
        memset(m_rows, 0, sizeof(m_rows));
        memset(m_cols, 0, sizeof(m_cols));
        memset(m_cubes, 0, sizeof(m_cubes));
        m_spaces.clear();
        vector<pair<int, int>>().swap(m_spaces);
    }

    bool fill(vector<vector<char>>& board, int index) {
        if (index == m_spaces.size()) {
            return true;
        }

        for (const auto& c : m_digits) {
            pair<int, int> space = m_spaces[index];
            int i = space.first;
            int j = space.second;
            int k = i / 3 * 3 + j / 3;
            int d = c - '1';

            if (m_rows[i][d] > 0 || m_cols[j][d] > 0 || m_cubes[k][d] > 0) {
                continue;
            }
            ++m_rows[i][d];
            ++m_cols[j][d];
            ++m_cubes[k][d];
            board[i][j] = c;

            if (fill(board, index + 1)) {
                return true;
            }
            // board[i][j] = '.';
            --m_rows[i][d];
            --m_cols[j][d];
            --m_cubes[k][d];
        }

        return false;
    }
};
