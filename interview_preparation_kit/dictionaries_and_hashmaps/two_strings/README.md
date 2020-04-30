# Two Strings 

[题目](https://www.hackerrank.com/challenges/two-strings/problem)  

题目让我们找出两个字符串是否有相同字符.

# Solution

**实现思路**  

O(m+n):将较长的字符串放进unordered_set. 用第二个字符串在里面查找是否存在.


**实现方式**  
```c
string twoStrings(string s1, string s2) {
    unordered_set<char> words;

    for(auto c:s1) words.insert(c);

    for(auto c:s2){
        if(words.count(c)) return "YES";
    }
    return "NO";
}
```
