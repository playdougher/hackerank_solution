# Greedy Florist

[题目](https://www.hackerrank.com/challenges/greedy-florist/problem)  
题目要买一个花店所有种类的花. 若k个人去买, 买前k朵花按原价买, 若继续购买, 价格=(已买数/k + 1) x c[i]

## Solution

**实现方式**  
```c
int getMinimumCost(int k, vector<int> c) {
    sort(c.begin(), c.end(), greater<int>());
    int ans = 0;
    int cnt = 0;
    for(int i = 0; i < c.size(); i++){
        ans += (cnt/k + 1)*c[i];
        cnt++;
    }
    return ans;
}
```
