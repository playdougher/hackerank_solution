# Max Min

[题目](https://www.hackerrank.com/challenges/angry-children/problem)  

## Solution

**实现思路**  
O(n logn):  
排序后, 求abs(arr[i] - arr[i+k-1]), 遍历一遍数组得出最小值.

**实现方式**  
```c
int maxMin(int k, vector<int> arr) {
    sort(arr.begin(), arr.end());
    int min = -1;
    if(arr.size() >= k){
        min = abs(arr[0] - arr[k-1]);
    }

    for(int i = 0; i+k-1 < arr.size(); i++){
        int absolute = abs(arr[i] - arr[i+k-1]);
        if(absolute < min) min = absolute;
    }
    return min;
}
```
