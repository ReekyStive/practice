/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            int remain = target - nums[i];
            for (int j = 0; j < nums.size(); j++) {
                if (j == i)
                    continue;
                if (nums[j] == remain)
                    return vector<int>{i, j};
            }
        }
        return vector<int>{};
    }
};
// @lc code=end

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    Solution solution;
    vector<int> result = solution.twoSum(nums, target);

    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;

    return 0;
}