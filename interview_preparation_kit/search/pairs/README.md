# Pairs

[题目](https://www.hackerrank.com/challenges/pairs/problem)  
找数组中两数之差为k的对儿.

**约束条件:**  
数组中无重复的数  

**输入格式：**  
```
n: 数组长度
k: 两数之差为k
arr: 数组
```

## Solution

**实现思路**  
```c
O(n):
* 用arr 构建 unordered_set<int> arr_set. 
* arr_set中取值val, 并寻找val+k, 找到则凑成一对.
    * 对数不会重复, 因为规定了第一个值为较小值
```

**实现方式**  
```c
#include <bits/stdc++.h>
using namespace std;
int pairs(int k, vector<int> arr){
    unordered_set<int> arr_set;
    int ans = 0;
    for(auto t:arr){
        arr_set.insert(t);
    }
    for(auto t:arr_set){
        if(arr_set.count(t+k)) ans++;
    }
    return ans;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    int i = 0;
    while(n--){
        cin >> arr[i++];
    }
    n = i;

    int ans = pairs(k, arr);
    cout << ans;

    return 0;
}
```
