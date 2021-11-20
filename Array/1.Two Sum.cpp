// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        vector<pair<int, int>> numsWithIdx;
        for (int i=0;i <= end;i++){
            numsWithIdx.push_back(make_pair(nums[i], i));
        }
        std::sort(numsWithIdx.begin(), numsWithIdx.end());
        
        while(start < end){
            int sum = numsWithIdx[start].first + numsWithIdx[end].first;
            cout << sum << start << end <<endl;
            if (sum == target){
                return {numsWithIdx[start].second, numsWithIdx[end].second};
            } else if (sum < target){
                start++;
            } else {
                end--;
            }
        }
        
        return {numsWithIdx[start].second, numsWithIdx[end].second}; 
        
    }
};