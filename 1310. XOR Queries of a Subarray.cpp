// 1310. XOR Queries of a Subarray
// Leetcode : Medium 13-09-2024

class Solution {
public:
    vector<int> xorQueries(vector<int>& A, vector<vector<int>>& queries) {
         vector<int> ans; // create an answer vector to store output
        
        // STEP 1
        for(int i = 1; i < A.size(); i++) {  // in-place in array A
            A[i] = A[i]^A[i-1];   // store in-place XOR till current index 
        }
        // STEP 2
        for(int i = 0; i < queries.size(); i++) {
            int start = queries[i][0]; 
            int end = queries[i][1];   
            
            if(start == 0) {   
                ans.push_back(A[end]);
            }
            else {
                ans.push_back(A[start-1]^A[end]);
            }
        }
        return ans;
    }
};
