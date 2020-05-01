# Sherlock and Anagrams 

[题目](https://www.hackerrank.com/challenges/sherlock-and-anagrams/problem)  

题目要求找出一个字符串的所有**unordered pair anagram**子串对数.  
其中unordered pair还是不能理解, 维基解释就大概是`<a, b>`中a, b没有先后关系.  
anagram 意思是 某字符串的异序字符串.如"afi","aif","fai"互为anagram. 

# Solution

**实现思路**  
1. 找互为anagram的子串: 因为每个子串只是顺序不同, 它们共同点是字符串中的字符个数相同. 如"afi","aif","fai",它们的'a''f''i'个数都为1. 那么设置一个标记字符的数组signature, 令signature=[1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0], 就能保证同一个signature的字符串都是由'a''f''i'排列构成. 
2. 计算互为anagram的子串能构成的对数: 通过数学里的"排列", 可以计算 "afi","aif","fai" 能组成的unordered pair为C(3,2)= 3, 即`<"afi","aif">`,`<"afi","fai">`,`<"aif","fai">`;
3. 计算不同子串长度能构成的子串对数的和: 上面计算了其中一个长度为3的子串对数的和. 现在来计算所有长度的所有子串对数的和. 设置一个`unordered_map<string, int> words`, `string`表示signature, `int`表示signature出现个数. 遍历map, 求和每个signature的排列值C(words.second, 2), 就能得到答案.

**注意点**  
1. 题目给了三个例子, 每个都要仔细看, 因为它的定义对我来说比较模糊, 在例子中才能比较清楚地看出题目要求的是什么. 
2. 题目要求找出所有**下标不同**的对数: 如"kkkk":  
[k, k]对数有6个: [0, 1], [0, 2], [0, 3], [1, 2], [1, 3], [2, 3].
我一开始以为这只算做一对.

**实现方式**  
```c
void gen_sig(char *signature, int n, string s){
    for(char c:s){
        signature[c-'a'] ++;
    }
}
// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
    unordered_map<string,int> words;
    int str_len = s.size();
    int substr_len = 1;
    int i = 0;

    while(substr_len < str_len){ 
        while(i+substr_len-1 < str_len){
            char signature[27]="";
            cout << "substr: " << s.substr(i,substr_len) << endl;
            gen_sig(signature, 27, s.substr(i,substr_len));
            ++words[string(signature,27)];
            ++i;
        }
        ++substr_len;
        i = 0;
    }

    int count = 0;
    for(auto &t:words){
        if(t.second > 1){
            count += t.second * (t.second-1)/2;
        }
    }
    return count;
}
```

# 疑问

1. 直到题目做完也没有明白 unordered pair 体现在题目中的哪个地方?
