给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。

示例 1:

输入: [1,2,3,4,5,6,7] 和 k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右旋转 1 步: [7,1,2,3,4,5,6]
向右旋转 2 步: [6,7,1,2,3,4,5]
向右旋转 3 步: [5,6,7,1,2,3,4]
示例 2:

输入: [-1,-100,3,99] 和 k = 2
输出: [3,99,-1,-100]
解释: 
向右旋转 1 步: [99,-1,-100,3]
向右旋转 2 步: [3,99,-1,-100]
说明:

尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
要求使用空间复杂度为 O(1) 的原地算法。

方法一：
最简单的想法，进行k次循环，每次循环转移所有元素
时间复杂度O(n*k)
空间复杂度O(1)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int temp,previous;
        for(int i=0;i<k;i++){
            previous = nums[nums.size()-1];
            for(int j=0;j<nums.size();j++){
                temp = nums[j];
                nums[j] = previous;
                previous = temp;
            }
        }
    }
};

方法二：用一个额外的数组Array[Accepted]
另开一个数组，将每一个元素按正确的位置赋值给新数组，最后将新数组复制到原数组。
时间复杂度为O(n)
空间复杂度为O(n)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> a(nums.size());
        for(int i=0;i<nums.size();i++){
            a[(i+k)%nums.size()] = nums[i];
        }
        for(int i=0;i<nums.size();i++){
            nums[i] = a[i];
        }
    }
};
方法三：
时间复杂度为O(n)
空间复杂度为O(1)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       k = k%nums.size();
        int count = 0;
        for(int start=0;count<nums.size();start++){
            int current = start;
            int prev = nums[start];
            do{
                int next = (current+k)%nums.size();
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                current = next;
                count++;
            }while(start!=current);
        }
    }
};


方法四：用reverse函数
时间复杂度为O(n)
空间复杂度为O(1)
例如：
Original List                   : 1 2 3 4 5 6 7
After reversing all numbers     : 7 6 5 4 3 2 1
After reversing first k numbers : 5 6 7 4 3 2 1
After revering last n-k numbers : 5 6 7 1 2 3 4 --> Result

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       k = k%nums.size();
       reverse(nums,0,nums.size()-1);
       reverse(nums,0,k-1);
       reverse(nums,k,nums.size()-1);
    }
     public:
    void reverse(vector<int>& nums,int start,int end){
        while(start<end){
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
};
