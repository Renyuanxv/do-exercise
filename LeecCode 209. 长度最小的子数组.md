# LeecCode 209. 长度最小的子数组

给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的 连续 子数组，并返回其长度。如果不存在符合条件的子数组，返回 0。

 

示例：

输入：s = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。

链接：https://leetcode-cn.com/problems/minimum-size-subarray-sum

```cpp
//暴力解法 
//时间：O(n^2)
//空间：O(1)

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int result=INT_MAX;
        int sum=0;
        int length=0;
        for (int i=0; i<nums.size(); ++i) {
            sum=0;
            for (int j=i; j<nums.size(); ++j){
                sum+=nums[j];
                if (sum>=s){
                    length=j-i+1;//子数组长度
                    result=result < length ? result : length;
                    break;
                }
            }
        }
        return result==INT_MAX ? 0 : result; 
    }
};

```

```cpp
//滑动窗口
//时间：O(n)
//空间：O(1)

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int result=INT_MAX;
        int sum = 0;
        int left = 0;
        int length = 0;
        for (int right = 0; right < nums.size(); ++right) {
            sum += nums[right];
            //每次更新 left 不断比较子数组是否符合条件
            while(sum >= s) {
                length = right - left + 1;
                result = length < result ? length : result;
                sum -= nums[left];//窗口左端 右移
                ++left;
            }
        }
        return result == INT_MAX ? 0 : result;
    }
};

```
