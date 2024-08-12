#include <queue>
#include <vector>

class KthLargest {
public:
    KthLargest(const int k, const std::vector<int>& nums) {
        m_size = k;
        std::ranges::for_each(std::as_const(nums), [this, k](const auto num) {
            pq.push(num);
        });
        checkSize();
    }
    
    int add(const int val) {
        pq.push(val);
        checkSize();
        return pq.top();
    }

private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    std::size_t m_size{};

    void checkSize() {
        while (pq.size() > m_size) {
            pq.pop();
        }
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
