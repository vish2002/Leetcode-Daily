// 2053. Kth Distinct String in an Array
// LeetCode : Easy 05-08-2024

class Solution {
public:

string kthDistinct(vector<string>& arr, int k) {
    unordered_map<string, int> freq;
    vector<string> distinct;
    for (const auto& str : arr) {
        freq[str]++;
    }

    for (const auto& str : arr) {
        if (freq[str] == 1) {
            distinct.push_back(str);
        }
    }

    if (k > 0 && k <= distinct.size()) {
        return distinct[k - 1];
    }

    return "";
}

};
