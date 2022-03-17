#include <vector>

using namespace std;

class UnionFind {
public:
    UnionFind(int n) {
        for (int i = 0; i < n; ++i) {
            m_f.push_back(i);
        }
    }

    bool Union(int x, int y) {
        int fx = Find(x);
        int fy = Find(y);

        if (fx != fy) {
            m_f[fx] = fy;
            return true;
        }

        return false;
    }

private:
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

    vector<int> m_f;
};

class Solution {
public:
    vector<int> find_redundant_connection(vector<vector<int>>& edges) {
        int n = edges.size();
        UnionFind uf(n);

        for (const auto& edge : edges) {
            if (!uf.Union(edge[0] - 1, edge[1] - 1)) {
                return edge;
            }
        }

        return {};
    }
};
