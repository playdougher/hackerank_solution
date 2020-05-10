# Minimum Time Required

[题目](https://www.hackerrank.com/challenges/minimum-time-required/problem)  

## Solution

**实现思路**  
```c
O(n log10^14):  
* 其实就是二分查找, 查找的值是: 天数, 该天数要能完成任务, 且尽量小. 
```

**注意点**  
```
天数最大值 = n * machines[i] = 10^5 * 10^9 = 10^14  
```

**实现方式**  
```c
#include <bits/stdc++.h>
using namespace std;
long minTime(vector<long> machines, long goal){
    long l = 0;
    long r = 1e14; //1e9 x 1e5 : machines[i] x n
    long mid = (l+r)/2;
    long ret = mid;
    while(l <= r){
        mid = (l+r)/2;

        int full = 0; //忘初始化
        for(int i = 0; i < machines.size(); i++){
            full += mid/machines[i];
            if(full >= goal) break;
        }

        if(full >= goal){
            r = mid-1;
            ret = mid;
        }
        else{
            l = mid+1;
        }
    }
    return ret;
}

int main(){
    int n, goal;
    cin >> n >> goal;
    vector<long> machines(n);
    for(int i=0; i<n; i++){
        cin >> machines[i];
    }
    cout << minTime(machines, goal);
    return 0;
}
```
