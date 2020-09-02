class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.empty())
            return 0;

        int left = 0;
        int right = rotateArray.size() - 1;
        int mid = 0;
        while (rotateArray[left] >= rotateArray[right]) {
            //两个下标相邻
            if (right - left == 1) {
                mid = right;
                break;
            }
            mid = left + ((right - left) >> 1);
            if (rotateArray[mid] == rotateArray[left] && rotateArray[left] == rotateArray[right]) {
                //无法判断mid在左侧还是右侧 遍历比较大小
                int result = rotateArray[left];
                for (int i = left + 1; i < right; ++i) {
                    if (result > rotateArray[i])
                        result = rotateArray[i];
                }
                return result;
            }
            if (rotateArray[mid] >= rotateArray[left]) {
                //mid在数组的左侧 最小元素位于中间元素的右侧
                ///试想两者相等， 隐含条件rotateArray[left] >= rotateArray[right]
                left = mid;
            }
            else {
                right = mid;
            }
        }
        return rotateArray[mid];
    }
};

