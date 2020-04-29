# 2D Array - DS

[题目](https://www.hackerrank.com/challenges/2d-array/problem)  

题目要求按‘工’字型求和计算6 x 6数组中最大的‘工’字型的和。

# Solution

**实现思路**  
简单设置一个计算‘工’字形和的宏定义，嵌套遍历。

```c
#define SUMHG(arr,i,j) (arr[i-1][j-1]+arr[i-1][j]+arr[i-1][j+1]+arr[i][j]+arr[i+1][j-1]+arr[i+1][j]+arr[i+1][j+1])
// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
    int max = -63;
    for(int i = 1; i < 5; i++) {
        for(int j = 1; j < 5; j++) {
            if (max < SUMHG(arr,i,j)) {
                max = SUMHG(arr,i,j);
            }
        }
    }
    return max;
}
```
