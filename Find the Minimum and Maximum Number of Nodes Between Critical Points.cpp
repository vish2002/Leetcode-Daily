// 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points
// Leetcode : Medium 05-07-2024

std::vector<int> nodesBetweenCriticalPoints(ListNode* head) {
    if (!head || !head->next || !head->next->next) return {-1, -1};
    
    ListNode* prev = head;
    ListNode* curr = head->next;
    ListNode* next = curr->next;
    int index = 1;
    int firstCP = -1;
    int lastCP = -1;
    int minDist = INT_MAX;

    std::vector<int> criticalPoints;

    while (next) {
        if ((curr->val > prev->val && curr->val > next->val) || 
            (curr->val < prev->val && curr->val < next->val)) {
            if (firstCP == -1) {
                firstCP = index;
            } else {
                minDist = std::min(minDist, index - lastCP);
            }
            lastCP = index;
            criticalPoints.push_back(index);
        }
        prev = curr;
        curr = next;
        next = next->next;
        ++index;
    }

    if (criticalPoints.size() < 2) return {-1, -1};
    int maxDist = criticalPoints.back() - criticalPoints.front();
    
    return {minDist, maxDist};
}
