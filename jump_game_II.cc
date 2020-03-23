#include<iostream>
#include<vector>

using std::vector;


// Leetcode link.
// https://leetcode.com/problems/jump-game-ii/

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1) {
            return 0;
        }
        
        if (nums[0] <= 0) {
            return -1;
        }
        
        int i = 0;
        int min_hop = 1;
        int max_idx = i + nums[0];
        
        while(i <= max_idx && max_idx < (nums.size() -1)) {
            int max_idx_saved = max_idx;
            for(;i <= max_idx_saved; i++) {
                max_idx = std::max(max_idx, i + nums[i]);
            }
            if (max_idx_saved < max_idx) {
                min_hop++;
            }
        }
        
        if (max_idx >= (nums.size() - 1)) {
            return min_hop;
        }
        
        return -1;
    }
};
