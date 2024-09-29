#include <string>
#include <map>
#include <set>
#include <cstdint>

class AllOne {
public:
    void inc(const std::string& key) {
        if (m_counts.contains(key)) {
            m_keys.erase({m_counts.at(key), key});
        }
        m_counts[key] += 1;
        m_keys.insert({m_counts.at(key), key});
    }
    
    void dec(const std::string& key) {
        m_keys.erase({m_counts.at(key), key});
        m_counts.at(key) -= 1;
        if (m_counts.at(key)) {
            m_keys.insert({m_counts.at(key), key});
        }
        else {
            m_counts.erase(key);
        }
    }
    
    std::string getMaxKey() const {
        if (m_keys.empty()) {
            return {};
        }
        return m_keys.crbegin()->second;
    }
    
    std::string getMinKey() const {
        if (m_keys.empty()) {
            return {};
        }
        return m_keys.cbegin()->second;
    }

private:
    std::map<std::string, std::uint32_t> m_counts;
    std::set<std::pair<std::uint32_t, std::string>> m_keys;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
