给定一个整数数组 nums，按要求返回一个新数组 counts。数组 counts 有该性质： counts[i] 的值是  nums[i] 右侧小于 nums[i] 的元素的数量。

示例:

输入: [5,2,6,1]
输出: [2,1,1,0] 
解释:
5 的右侧有 2 个更小的元素 (2 和 1).
2 的右侧仅有 1 个更小的元素 (1).
6 的右侧有 1 个更小的元素 (1).
1 的右侧有 0 个更小的元素.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

暴力解法
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res;
        for(int i = 0; i < nums.size(); i++) {
            int temp = 0;
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[j] < nums[i]) {
                    temp++;
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};

树状数组
class Solution {
public:
    int c[100010];
    void add(int x, int val, int n) {
        while(x <= n) {
            c[x] += val;
            x += x & -x;
        }
    }
    int getSum(int x) {
        int sum = 0;
        while(x > 0) {
            sum += c[x];
            x -= x & -x;
        }
        return sum;
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res;
        int len = nums.size();
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        for(int i = len - 1; i >= 0; i--) {
            int id = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin() + 1;
            res.push_back(getSum(id - 1));
            add(id, 1, len + 1);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
