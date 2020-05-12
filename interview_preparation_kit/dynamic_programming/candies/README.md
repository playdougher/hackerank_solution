# Candies

[题目](https://www.hackerrank.com/challenges/candies/problem)  

## Solution

**实现思路**  
```
O(n):
* 设一个糖果分配数组candies.
* 从左往右遍历
    * 若递增, 则糖果candies[i]加1
    * 若递减, 设为1, (因为此时无法确定最小值, 比如:8,6,2,1, 则8给的糖果的最小值应是4, 取决于递减的长度.
* 从右往左遍历
    * 若递增, 则糖果加1.
        * 此时candies[i] = max(candies[i], candies[i+1]+1); 因为要取两趟遍历中的最大值, 也即在第一趟没有确定给多少糖果的那些值.
```
**注意点**  
求和时: 1+ ... +10^5 = 10^10, 需要8字节long long型 

**实现方式**  
```c
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> candies(n);
    candies[0] = 1;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(int i = 1; i < n; i++){
        if(arr[i] > arr[i-1]){
            candies[i] = candies[i-1]+1;
        }
        else candies[i] = 1;
    }
    for(int i = n-2; i >= 0; i--){
        if(arr[i] > arr[i+1]){
            candies[i] = max(candies[i], candies[i+1]+1);
        }
    }
    cout << accumulate(candies.begin(), candies.end(), long(0));
    return 0;
}
```
