# LeetCode 53. 最大子序列和.md

给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4]
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。

链接：https://leetcode-cn.com/problems/maximum-subarray

```cpp
//暴力法
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result=nums[0];
        int count=0;
        for(size_t i=0;i<nums.size();++i){
            count=0;
            for(size_t j=i;j<nums.size();++j){
                count+=nums[j];
                result=count>result?count:result;
            }
        }
        return result;
    }
};

//贪心
//每次找局部最优解
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result=INT_MIN;
        int count=0;
        for(size_t i=0;i<nums.size();++i){
            count+=nums[i];
            if(count>result)
                result=count;
            if(count<=0)//count小于0 nums[i]影响最后的结果 直接重新开始算
                count=0;
        }
        return result;
    }
};

```
