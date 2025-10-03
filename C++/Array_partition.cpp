// Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2), ..., (an, bn) such that the sum of min(ai, bi) for all i is maximized. Return the maximized sum.

 

// Example 1:

// Input: nums = [1,4,3,2]
// Output: 4
// Explanation: All possible pairings (ignoring the ordering of elements) are:
// 1. (1, 4), (2, 3) -> min(1, 4) + min(2, 3) = 1 + 2 = 3
// 2. (1, 3), (2, 4) -> min(1, 3) + min(2, 4) = 1 + 2 = 3
// 3. (1, 2), (3, 4) -> min(1, 2) + min(3, 4) = 1 + 3 = 4
// So the maximum possible sum is 4.

// Intuition
// To maximize the sum of the minimums of each pair, you should pair the smallest numbers together. This ensures that the small numbers aren’t wasted by being paired with much larger ones — which would reduce the contribution of min(a, b).

// Approach
// Sort the array in ascending order.

// Pair adjacent elements — i.e., (nums[0], nums[1]), (nums[2], nums[3]), ....

// Since the array is sorted, the smaller value in each pair will always be nums[i] where i is even.

// Sum up all elements at even indices (i = 0, 2, 4, ...).

// Return the total sum.

// Complexity
// Time complexity:𝑂(𝑛log⁡𝑛)
// O(nlogn) — due to the sort operation.
// Space complexity:
// O(1) — if sorting is done in-place (as with std::sort), no extra space is used.



class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxSum = 0;
        for(int i = 0; i < nums.size(); i+=2) {
            maxSum += min(nums[i],nums[i+1]);
        }
        return maxSum;
    }
};
