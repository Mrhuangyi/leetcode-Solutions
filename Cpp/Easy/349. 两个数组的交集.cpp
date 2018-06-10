给定两个数组，写一个函数来计算它们的交集。

例子:

 给定 num1= [1, 2, 2, 1], nums2 = [2, 2], 返回 [2].

提示:

每个在结果中的元素必定是唯一的。
我们可以不考虑输出结果的顺序。

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s,res;
        for(int i=0;i<nums1.size();i++){
            s.insert(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++){
            if(s.count(nums2[i])){
                res.insert(nums2[i]);
            }
        }
        return vector<int>(res.begin(),res.end());
    }
};
