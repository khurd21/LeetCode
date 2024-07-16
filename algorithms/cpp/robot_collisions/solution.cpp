#include <vector>
#include <map>
#include <stack>

namespace {

struct Robot {
    int position{};
    int health{};
    char direction{};
};

bool operator<(const Robot& lhs, const Robot& rhs) {
    return lhs.position < rhs.position;
}

}

class Solution {
public:
    std::vector<int> survivedRobotsHealths(std::vector<int>& positions, std::vector<int>& healths, std::string directions) {
        std::map<int, Robot, std::less<>> robots;
        const auto less_than_all = [&](const auto index) {
            return index < positions.size() && index < healths.size() && index < directions.size();
        };
        for (std::size_t i{}; less_than_all(i); ++i) {
            robots.insert_or_assign(
                positions.at(i),
                Robot{positions.at(i), healths.at(i), directions.at(i)});
        }

        std::stack<Robot*> stack;
        for (auto& [position, robot] : robots) {
            if (robot.direction == 'R') {
                stack.push(&robot);
                continue;
            }
            while (!stack.empty() && stack.top()->direction == 'R' && robot.health > 0) {
                auto top{ stack.top() };
                if (robot.health > top->health) {
                    robot.health -= 1;
                    top->health = 0;
                    stack.pop();
                }
                else if (robot.health < top->health) {
                    robot.health = 0;
                    top->health -= 1;
                }
                else {
                    robot.health = 0;
                    top->health = 0;
                    stack.pop();
                }
            }
            if (robot.health != 0) {
                stack.push(&robot);
            }
        }

        std::vector<int> result;
        for (std::size_t i{}; less_than_all(i); ++i) {
            const Robot& robot = robots.at(positions.at(i));
            if (robot.health > 0) {
                result.push_back(robot.health);
            }
        }
        return result;
    }
};
