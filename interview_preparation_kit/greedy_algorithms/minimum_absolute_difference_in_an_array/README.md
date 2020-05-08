# Minimum Absolute Difference in an Array 

[题目](https://www.hackerrank.com/challenges/minimum-absolute-difference-in-an-array/problem)  

## Solution

**实现思路**  
O(n logn):  
排序后比较邻近元素.  

**实现方式**  
```c
int minimumAbsoluteDifference(vector<int> arr) {
    sort(arr.begin(),arr.end());
    int min = abs(arr[0]-arr[1]);
    int abs_diff = 0;
    for(int i = 0; i+1 < arr.size(); i++){
        abs_diff = abs(arr[i]-arr[i+1]);
        if(abs_diff < min) min = abs_diff;
    }
    return min;
}
```
