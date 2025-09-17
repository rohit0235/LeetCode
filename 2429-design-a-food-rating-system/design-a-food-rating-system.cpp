#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>

class FoodRatings {
public:
    // Main data structure: Cuisine -> {Rating -> {Set of Foods}}
    unordered_map<string, map<int, set<string>>> cuisine_ratings_data;
    
    // Helper maps for fast lookups
    unordered_map<string, int> food_ratings;
    unordered_map<string, string> food_to_cuisine;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); ++i) {
            // Populate all three data structures
            food_to_cuisine[foods[i]] = cuisines[i];
            food_ratings[foods[i]] = ratings[i];
            cuisine_ratings_data[cuisines[i]][ratings[i]].insert(foods[i]);
        }
    }
    
    void changeRating(string food, int newRating) {
        // 1. Get the food's cuisine and old rating
        string cuisine = food_to_cuisine[food];
        int oldRating = food_ratings[food];

        // 2. Remove the food from its old rating entry
        cuisine_ratings_data[cuisine][oldRating].erase(food);
        
        // 3. Clean up: if the set for the old rating is now empty, remove that rating entry
        if (cuisine_ratings_data[cuisine][oldRating].empty()) {
            cuisine_ratings_data[cuisine].erase(oldRating);
        }

        // 4. Add the food to its new rating entry
        cuisine_ratings_data[cuisine][newRating].insert(food);

        // 5. Update the food's current rating in the helper map
        food_ratings[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        // 1. Get the map of ratings for the given cuisine.
        auto& ratings_map = cuisine_ratings_data[cuisine];
        
        // 2. The map's last element has the highest rating (the key).
        //    rbegin() gives a reverse iterator to the last element.
        //    ->second gives the set of foods with that rating.
        const set<string>& highest_rated_foods = ratings_map.rbegin()->second;
        
        // 3. The set sorts foods lexicographically, so its first element is the answer.
        //    begin() gives an iterator to the first element.
        return *highest_rated_foods.begin();
    }
};