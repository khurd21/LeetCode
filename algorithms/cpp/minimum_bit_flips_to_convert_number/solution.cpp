// Ideal solution: We can template and make function constexpr.
namespace {

template <typename T, std::enable_if_t<std::is_arithmetic_v<T>, bool> = true>
constexpr int minBitFlips(const T start, const T goal) {
    constexpr auto NumBits{ std::numeric_limits<T>::digits + std::numeric_limits<T>::is_signed };
    const auto x{ start ^ goal };
    return std::bitset<NumBits>(x).count();
}

}

class Solution {
public:
    int minBitFlips(const int start, const int goal) {
        return ::minBitFlips(start, goal);
    }
};

// Iterative approach
class Solution {
public:
    int minBitFlips(const int start, const int goal) {
        int result{};
        std::uint64_t index{ 1 };
        while (index < std::numeric_limits<int>::max()) {
            const auto sb{ start & index };
            const auto gb{ goal & index };
            result += static_cast<int>(sb != gb);
            index <<= 1;
        }
        return result;
    }
};
