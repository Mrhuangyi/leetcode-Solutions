颠倒给定的 32 位无符号整数的二进制位。

示例:

输入: 43261596
输出: 964176192
解释: 43261596 的二进制表示形式为 00000010100101000001111010011100 ，
     返回 964176192，其二进制表示形式为 00111001011110000010100101000000 。
进阶:
如果多次调用这个函数，你将如何优化你的算法？

方法一：
遍历整数的所有位。 如果第i个位置的一个位置在I / P编号中。
然后将该位设置为（NO_OF_BITS - 1） - i in o / p。 NO_OF_BITS是给定数字中存在的位数。
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        unsigned int  NO_OF_BITS = sizeof(n) * 8;
        unsigned int reverse_num = 0, i, temp;

    for (i = 0; i < NO_OF_BITS; i++)
    {
        temp = (n & (1 << i));
        if(temp)
            reverse_num |= (1 << ((NO_OF_BITS - 1) - i));
    }
 
    return reverse_num;
    }
};

时间复杂度：O(logn)
空间复杂度：O(1)
方法二：
保持reversenum每一位与给定num相等直到num变成0，之后反向移动剩余的位

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
      unsigned int count = sizeof(n) * 8 - 1;
      unsigned int reverse_num = n;
     
    n >>= 1; 
    while(n)
    {
       reverse_num <<= 1;       
       reverse_num |= n & 1;
       n >>= 1;
       count--;
    }
    reverse_num <<= count;
    return reverse_num;
    }
};

时间复杂度：O(logn)
空间复杂度：O(1)
