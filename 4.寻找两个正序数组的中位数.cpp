/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
        {
            vector<int> temp = nums1;
            nums1 = nums2;
            nums2 = temp;
        }
        int m = nums1.size(), n = nums2.size();
        int l = (m + n + 1) / 2;
        int left = 0, right = m;
        while (left < right)
        {
            int mid1 = (left + right + 1) / 2;
            int mid2 = l - mid1;
            if (nums1[mid1 - 1] > nums2[mid2])
            {
                right = mid1 - 1;
            }
            else left = mid1;
        }
        int leftmax1;
        if(left == 0) leftmax1 = -1e7; else leftmax1 = nums1[left - 1];
        int leftmax2;
        if(l - left == 0) leftmax2 = -1e7; else leftmax2 = nums2[l - left - 1];
        int rightmin1;
        if(left == m) rightmin1 = 1e7; else rightmin1 = nums1[left];
        int rightmin2;
        if(l - left == n) rightmin2 = 1e7; else rightmin2 = nums2[l - left];
        if((m + n) % 2)
        {
            return max(leftmax1, leftmax2);
        }
        return (max(leftmax1, leftmax2) + min(rightmin1, rightmin2)) / 2.0;
    }
};
// @lc code=end

