// 703. Kth Largest Element in a Stream
// LeetCode : Easy 12-08-2024

class KthLargest {
public:
int k;
    priority_queue<int, vector<int>, greater<int>> pq; // Min-heap
    
    KthLargest(int i, vector<int>& nums) {
        k = i;
        for(auto num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > k) {
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
