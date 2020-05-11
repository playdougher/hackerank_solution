# Max Array Sum 

[题目](https://www.hackerrank.com/challenges/max-array-sum/problem)  

## Solution

**实现思路**  
```
O(n):
* 运用动态规划
* 假设dp[i]存储的是数组arr前i个数的max array sum.
    * dp[i]=max(dp[i-1],dp[i-2]+arr[i]);
```

**实现方式**  
```c
#include <bits/stdc++.h>
using namespace std;

int maxSubsetSum(vector<int> arr) {
    int dp[arr.size()];
    dp[0]=max(0,arr[0]);
    if(arr.size()>1){
        dp[1]=max(dp[0],arr[1]);
    }
    for(int i=2;i<arr.size();i++)
    {
        dp[i]=max(dp[i-1],dp[i-2]+arr[i]);
    }
    return dp[arr.size()-1];
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << maxSubsetSum(arr);
    return 0;
}
```
