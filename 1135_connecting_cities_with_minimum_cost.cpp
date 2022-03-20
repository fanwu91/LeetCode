#include <vector>

using namespace std;

class UnionFind {
public:
    explicit UnionFind(int n) : m_count(n) {
        for (int i = 0; i < n + 1; ++i) {
            m_f.emplace_back(i);
        }
    }

    int GetCount() {
        return m_count;
    }

    bool Union(int x, int y) {
        int fx = Find(x);
        int fy = Find(y);

        if (fx != fy) {
            --m_count;
            m_f[fx] = fy;
            return true;
        }

        return false;
    }

    ~UnionFind() {
        vector<int>().swap(m_f);
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

    int m_count;
    vector<int> m_f;
};


class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        UnionFind uf(n);

        auto byCost = [](const vector<int>& a, const vector<int>& b) -> bool {
            return a[2] < b[2];
        };

        sort(connections.begin(), connections.end(), byCost);

        int cost = 0;

        for (const auto& connection : connections) {
            if (uf.Union(connection[0], connection[1])) {
                cost += connection[2];
            }
        }

        return uf.GetCount() == 1 ? cost : -1;
    }
};
