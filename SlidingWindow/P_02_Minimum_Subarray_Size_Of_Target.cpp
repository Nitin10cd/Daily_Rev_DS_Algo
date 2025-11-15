class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int i = 0, j = 0;
        int n = nums.size();
        int minLength = INT_MAX;
        int sum = 0;

        while (j < n) {
            sum += nums[j];

            while (sum >= target) {
                minLength = min(minLength, j - i + 1);
                sum -= nums[i];
                i++;
            }
            j++;
        }

        return (minLength == INT_MAX) ? 0 : minLength;
    }
};
