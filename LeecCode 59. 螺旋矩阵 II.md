# LeecCode 59. 螺旋矩阵 II

给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

示例:

* 输入: 3

* 输出:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/spiral-matrix-ii

```cpp
//从左到右 从上到下 再从右到左 再从下到上 顺时针旋转
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n,0));
        int leftBorder=0,rightBorder=n-1,upBorder=0,downBorder=n-1;
        int num=1;
        while(1) {
            for (int y=leftBorder; y<=rightBorder; ++y)
                ans[upBorder][y]=num++;
            //终止条件：上边界越过下边界
            if (++upBorder>downBorder)
                break;
            
            for (int x=upBorder; x<=downBorder; ++x)
                ans[x][rightBorder]=num++;
            //终止条件：右边界越过左边界
            if (--rightBorder<leftBorder)
                break;
            
            for (int y=rightBorder; y>=leftBorder; --y)
                ans[downBorder][y]=num++;
            //终止条件：下边界越过上边界
            if (--downBorder<upBorder)
                break;
            
            for (int x=downBorder; x>=upBorder; --x)
                ans[x][leftBorder]=num++;
            //终止条件：左边界越过右边界
            if(++leftBorder>rightBorder)
                break;
        }
        return ans;
    }
};
```
