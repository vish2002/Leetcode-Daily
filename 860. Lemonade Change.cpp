// 860. Lemonade Change
// LeetCode : Easy 15-08-2024

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for (auto price : bills) {
            if (price == 5) {
                five++;
            } else if (price == 10) {
                if (five == 0)
                    return false;
                five--;
                ten++;
            } else if (price == 20) {
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
