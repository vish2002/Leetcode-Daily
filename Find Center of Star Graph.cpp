// 1791. Find Center of Star Graph
// Leetcode : Easy 27-06-2024


class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> degree;

        for (vector<int> edge : edges) {
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        for (pair<int, int> nodes : degree) {
            int node = nodes.first;
            int nodeDegree = nodes.second;

            if (nodeDegree == edges.size()) {
                return node;
            }
        }

        return -1;
    }
};
