# Hash Tables: Ransom Note 

[题目](https://www.hackerrank.com/challenges/ctci-ransom-note/problem)  

题目给定两个string数组, 问第二个数组中的所有元素(有重复)能否在第一个数组中找到. 

# Solution

**实现思路**  

`O(m*log(m)+n*log(m))`: 先对第一个数组排序,然后在第一个数组中搜索

`O(m+n)`: 运用unordered_map<string, int> 为每个字符串计数. 

**注意点**  

map的操作都为O(log n),实现用的红黑树  
unordered_map的操作都为O(1),实现用的是哈希表  

用下标操作unordered_map时,若无该元素,则自动创建并初始化.  

**实现方式**  
```c
void checkMagazine(vector<string> magazine, vector<string> note) {
    unordered_map<string, int> words;
    for(auto &w:magazine){
        words[w]++;
    }
    for(auto &w:note){
        if(words[w]>0){
            words[w]--;
        }
        else {
            cout << "No" <<endl;
            return;
        }
    }
    cout << "Yes" << endl;
}
```
