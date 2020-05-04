# Alternating Characters

[题目](https://www.hackerrank.com/challenges/alternating-characters/problem)  

# Solution

**实现思路**  
直接判断前一个字符是否一样, 一样则删除计数加一  

**实现方式**  
```c
int alternatingCharacters(string s) {
    int cnt = 0;
    if (s.size() > 1){
        for(int i = 1; i < s.size(); i++){
            if(s[i-1] == s[i]) ++cnt;
        }
    }
    return cnt;
}
```
