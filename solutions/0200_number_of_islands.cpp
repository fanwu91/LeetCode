#include <vector>
#include <utility> // header file for "pair"
class UnionFind {
public:
    explicit UnionFind(const vector<vector<char>>& grid) : m_count(0) {
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                m_f.push_back(i * m + j);
                if (grid[i][j] == '1') {
                    m_count++;
                }
            }
        }
    }

    int GetCount() {
        return m_count;
    }

    void Union(int x, int y) {
        int fx = Find(x);
        int fy = Find(y);

        if (fx != fy) {
            m_count--;
            m_f[fx] = fy;
        }
    }

    int Find(int x) {
        int j = x;

        while (j != m_f[j]) {
            j = m_f[j];
        }

        while (x != j) {
            int fx = m_f[x];
            m_f[fx] = j;
            x = fx;
        }

        return j;
    }

    ~UnionFind() = default;

private:
    int m_count;
    vector<int> m_f;
};

class Solution {
public:
    int NumOfIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        int n = grid.size();
        int m = grid[0].size();

        UnionFind uf(grid);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1') {
                    for (const auto& dir : m_dir) {
                        int newI = i + dir.first;
                        int newJ = j + dir.second;

                        if (newI >= 0 && newI < n &&
                            newJ >= 0 && newJ < m &&
                            grid[newI][newJ] == '1') {
                            uf.Union(i * m + j, newI * m + newJ);
                        }
                    }
                }
            }
        }

        return uf.GetCount();
    }
private:
    vector<pair<int, int>> m_dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};
