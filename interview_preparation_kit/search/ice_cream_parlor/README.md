# Hash Tables: Ice Cream Parlor

[题目](https://www.hackerrank.com/challenges/ctci-ice-cream-parlor/problem)  
给定一个数组, 求和为money的一组数.  
note:  
* 数中有重复值
* 答案只有一组

## Solution

**实现思路**  
```c
O(n):
* 若结果为ci, cj. 则有cj = money-ci. 
* 哈希表对数组元素计数
* 若ci==cj, ci的计数应为2
* 若ci!=cj, ci, cj计数各为1
```

**实现方式**  
```c
void whatFlavors(vector<int> cost, int money) {
    unordered_map<int,int> cnt;
    int val1 = 0;
    int val2 = 0;
    for(auto t:cost) cnt[t]++;

    for(auto &t: cnt){
        int val = t.first;
        int count = t.second;
        if(val == money-val){
            if(count == 2){
                val1 = val2 = val;
                break;
            }
        }
        else{
            if(cnt.count(val) and cnt.count(money-val)){
                val1 = val;
                val2 = money-val;
                break;
            }
        }
    }

    set<int> idx; //用set,保证有序
    for(int i=0; i<cost.size(); i++){
        if(cost[i] == val1 || cost[i] == val2){
            idx.insert(i);
        }
    }
    for(auto t:idx){
        cout << t+1 << ' ';
    }
    cout << endl;
}
```
