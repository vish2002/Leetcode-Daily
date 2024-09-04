// 874. Walking Robot Simulation
// Leetcode : Medium 04-09-2024

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        unordered_map<int, unordered_set<int>> mp;
        for (int i = 0; i < obstacles.size(); i++) {
            mp[obstacles[i][0]].insert(obstacles[i][1]);
        }
        int k = 0;
        int x = 0;
        int maxi = 0;
        int y = 0;
        for (int i = 0; i < commands.size(); i++) {
            if (commands[i] == -1) {
                k++;
                k %= 4;
            } else if (commands[i] == -2) {
                k--;
                if (k < 0)
                    k += 4;
            } else {
                int temp = 1;
                while (temp <= commands[i]) {
                    int newx = x + directions[k].first;
                    int newy = y + directions[k].second;
                    if (mp.count(newx) && mp[newx].count(newy)) {
                        break;
                    }
                    x = newx, y = newy;
                    maxi = max(maxi, x * x + y * y);
                    temp++;
                }
            }
        }
        return maxi;
    }
};
