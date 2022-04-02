#include <algorithm>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

class UnionFind {
public:
    explicit UnionFind(int n) {
        for (int i = 0; i < n; ++i) {
            m_f.emplace_back(i);
        }
    }

    void Union(int x, int y) {
        int fx = Find(x);
        int fy = Find(y);
        
        if (fx != fy) {
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
            m_f[x] = j;
            x = fx;
        }

        return j;
    }

private:
    vector<int> m_f;
};

struct Point {
    int i;
    int j;
    int val;

    bool operator < (const Point& rhs) const {
        return val < rhs.val;
    }
};

class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        int n = grid.size();
        int m = grid[0].size();

        UnionFind uf(n * m);
        priority_queue<Point> pq;
        const vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        int maxMinPath = min(grid[0][0], grid[n - 1][m - 1]);
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                pq.push({i, j, grid[i][j]});
            }
        }

        while (uf.Find(0) != uf.Find(n * m  - 1)) {
            Point node = pq.top();
            pq.pop();
            int i = node.i;
            int j = node.j;
            
            maxMinPath = min(maxMinPath, node.val);
            visited[i][j] = 1;

            for (const auto& dir : dirs) {
                int ni = i + dir.first;
                int nj = j + dir.second;

                if (ni >= 0 && ni < n && nj >= 0 && nj < m &&
                    visited[ni][nj]) {
                    uf.Union(i * m + j, ni * m + nj);
                }
            }
        }

        return maxMinPath;
    }
};
