#include <vector>

class UnionFind {
public:
    UnionFind(int n) : count_(n) {
        for (int i = 0; i < n; ++i) {
            f_.push_back(i);
        }
    }

    void Union(int x, int y) {
        int fx = Find(x);
        int fy = Find(y);
        
        if (fx != fy) {
            --count_;
            f_[fx] = fy;
        }
    }

    int GetCount() {
        return count_;
    }

private:
    int Find(int x) {
        int j = x;
        while (f_[j] != j) {
            j = f_[j];
        }

        while (j != x) {
            int fx = f_[x];
            f_[x] = j;
            x = fx;
        }


        return j;
    }

    int count_;
    vector<int> f_;
};

class Solution {
public:
    int number_of_provinces(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UnionFind uf(n);

        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isConnected[i][j]) {
                    uf.Union(i, j);
                }
            }
        }

        return uf.GetCount();
    }
};
