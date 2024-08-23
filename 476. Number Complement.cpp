// 476. Number Complement
// Leetcode : Easy 22-08-2024

class Solution {
public:

    int findComplement(int num) {
        if (num == 0) return 1; 
        int num_bits = static_cast<int>(log2(num)) + 1;
        
        // Handle the case where num_bits is 31 to avoid overflow
        unsigned int mask = (1U << num_bits) - 1; 
        
        return num ^ mask; 
    }
};
