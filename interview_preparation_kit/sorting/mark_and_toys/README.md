# Mark and Toys 

[题目](https://www.hackerrank.com/challenges/mark-and-toys/problem)  

## Solution

**实现思路**  
O(nlogn): 把价格放进map, 从头开始买,直到付不起为止.

**注意点**  
题目是要买尽量多的玩具, 而不是种类尽量多的玩具. 

**实现方式**  
```c
int maximumToys(vector<int> prices, int k) {
    map<int, int> toys;
    for(int t:prices){
        toys[t]++;
    }
    int cnt = 0;
    for(auto &t:toys){
        if(k > t.first){
            k -= t.first*t.second;
            cnt += t.second;
        }
        else break;
    }
    return cnt;
}
```
