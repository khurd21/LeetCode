#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

namespace {

const std::string emptyString{};

struct FoodType {
    std::string food;
    std::string cuisine;
    int rating;

    FoodType() = default;
    FoodType(std::string food, std::string cuisine, int rating)
        : food(std::move(food)), cuisine(std::move(cuisine)), rating(rating) {}
};

bool operator>(const FoodType& lhs, const FoodType& rhs) {
    if (lhs.rating == rhs.rating) {
        return lhs.food < rhs.food;
    }
    return lhs.rating > rhs.rating;
}

}

class FoodRatings {
public:
    FoodRatings(const std::vector<std::string>& foods, const std::vector<std::string>& cuisines, const std::vector<int>& ratings) {
        for (int i{}; i < foods.size(); ++i) {
            m_foodToFoodType[foods[i]] = { foods[i], cuisines[i], ratings[i] };
            m_cuisineToFoodType[cuisines[i]].insert(m_foodToFoodType[foods[i]]);
        }
    }
    
    void changeRating(const std::string& food, int newRating) {
        FoodType& foodType{ m_foodToFoodType[food] };
        m_cuisineToFoodType[foodType.cuisine].erase(foodType);
        foodType.rating = newRating;
        m_cuisineToFoodType[foodType.cuisine].insert(foodType);
    }
    
    const std::string& highestRated(const std::string& cuisine) const noexcept {
        auto itr{ m_cuisineToFoodType.find(cuisine) };
        if (itr == m_cuisineToFoodType.end()) {
            return emptyString;
        }
        return itr->second.begin()->food;
    }

private:
    std::map<std::string, FoodType> m_foodToFoodType;
    std::map<std::string, std::set<FoodType, std::greater<FoodType>>> m_cuisineToFoodType;
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
