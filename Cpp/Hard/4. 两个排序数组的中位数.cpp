/*
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2 。

请找出这两个有序数组的中位数。要求算法的时间复杂度为 O(log (m+n)) 。

你可以假设 nums1 和 nums2 不同时为空。

示例 1:

nums1 = [1, 3]
nums2 = [2]

中位数是 2.0
示例 2:

nums1 = [1, 2]
nums2 = [3, 4]

中位数是 (2 + 3)/2 = 2.5
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int k = 0;
        int mid1 = 0, mid2 = 0;
        int pA = 0, pB = 0;
        double res = 0;
        while(k <= (n + m) / 2) {
            mid1 = mid2;
            if(pA == nums1.size()) {
                mid2 = nums2[pB++];
            } else if(pB == nums2.size()) {
                mid2 = nums1[pA++];
            } else if(nums1[pA] < nums2[pB]) {
                mid2 = nums1[pA++];
            } else {
                mid2 = nums2[pB++];
            }
            k++;
        }
        if((n + m) % 2 == 1) {
            res = mid2 / 1.0;
        } else {
            res = (mid1 + mid2) / 2.0;
        }
        return res;
    }
};

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int lenA = nums1.size();
        int lenB = nums2.size();
        if((lenA + lenB) % 2 == 0) {
            double r1 = (double) findKth(nums1, 0, lenA, nums2, 0, lenB, (lenA + lenB) / 2);
            double r2 = (double) findKth(nums1, 0, lenA, nums2, 0, lenB, (lenA + lenB) / 2 + 1);
            return (r1 + r2) / 2.0;
        } else {
            return findKth(nums1, 0, lenA, nums2, 0, lenB, (lenA + lenB + 1) / 2);
        }
    }
    int findKth(vector<int>& A, int startA, int endA, vector<int>& B,int startB, int endB, int k) {
        int n = endA - startA;
        int m = endB - startB;
        if(n <= 0) {
            return B[startB + k - 1];
        }
        if(m <= 0) {
            return A[startA + k - 1];
        }
        if(k == 1) {
            return A[startA] < B[startB] ? A[startA] : B[startB];
        }
        int midA = (startA + endA) / 2;
        int midB = (startB + endB) / 2;
        if(A[midA] <= B[midB]) {
            if(n / 2 + m / 2 + 1 >= k) {
                return findKth(A, startA, endA, B, startB, midB, k);
            } else {
                return findKth(A, midA + 1, endA, B, startB, endB, k - n / 2 - 1);
            }
        } else {
            if(n / 2 + m / 2 + 1 >= k) {
                return findKth(A, startA, midA, B, startB, endB, k);
            } else {
                return findKth(A, startA, endA, B, midB + 1, endB, k - m / 2 - 1);
            }
        }
    }
};
