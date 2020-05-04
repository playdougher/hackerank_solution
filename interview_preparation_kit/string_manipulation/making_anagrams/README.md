# Strings: Making Anagrams 

[题目](https://www.hackerrank.com/challenges/ctci-making-anagrams/problem)  

# Solution

**实现思路**  
设个letter数组给字符串计数, 用另一个字符串的计数相减, 得到的值便是两个字符串中不同的地方. 递归求和letter得结果

**实现方式**  
```c
int makeAnagram(string a, string b) {
    vector<int> letter(26);
    int cnt = 0;
    for(int i = 0; i < a.size();  i++) letter[a[i]-'a']++;
    for(int i = 0; i < b.size();  i++) letter[b[i]-'a']--;
    for(int c:letter) cnt += abs(c);
    return cnt;
}
```
