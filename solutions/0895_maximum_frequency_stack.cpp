#include <unordered_map>
#include <stack>

namespace Solution {

class FreqStack {
public:
    FreqStack() {}

    void push(int val) {
        ++m_freq[val];
        m_group[m_freq[val]].push(val);
        m_max_freq = std::max(m_max_freq, m_freq[val]);
    }

    int pop() {
        int val = m_group[m_max_freq].top();
        m_group[m_max_freq].pop();
        --m_freq[val];

        if (m_group[m_max_freq].empty()) {
            --m_max_freq;
        }

        return val;
    }
private:
    std::unordered_map<int, int> m_freq;              // val  to freq
    std::unordered_map<int, std::stack<int>> m_group; // freq to stack
    int m_max_freq {0};                               // max freq
};

} // namespace Solution
