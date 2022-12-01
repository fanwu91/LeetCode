#include <vector>

class Solution {
public:
    int nearestValidPoint(int x, int y, std::vector<std::vector<int>>& points) {
        int min_dist = INT_MAX;
        int dist = INT_MAX;
        int idx = -1;

        for (int i = 0; i < points.size(); ++i) {
            if (points[i][0] == x || points[i][1]) {
                dist = std::abs(points[i][0] - x) + std::abs(points[i][1] - y);
                if (dist < min_dist) {
                    min_dis = dist;
                    idx = i;
                }
            }
        }

        return idx;
    }
};
