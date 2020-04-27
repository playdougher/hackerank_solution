# Repeated String

题目给定一字符串`s`和整型`n`，求由`s`重复所得的、长度为`n`的字符串中有几个字符`a`。  
如s='abcac', n=10. 得字符串abcacabcac,有4个a  


**Function Description**

Complete the  _repeatedString_  function in the editor below. It should return an integer representing the number of occurrences of  `a`  in the prefix of length `n` in the infinitely repeating string.

repeatedString has the following parameter(s):

-   _s_: a string to repeat
-   _n_: the number of characters to consider

**Input Format**

The first line contains a single string, `s` .
The second line contains an integer, `n` .

**Constraints**

![](images.png)


**Output Format**

Print a single integer denoting the number of letter  `a`'s in the first  `n` letters of the infinite string created by repeating `s` infinitely many times.

**Sample Input 0**

```
aba
10
```

**Sample Output 0**

```
7
```

**Explanation 0**

The first  n = 10 letters of the infinite string are  `abaabaabaa`. Because there are  `7a`'s, we print  `7` on a new line.

**Sample Input 1**

```
a
1000000000000
```

**Sample Output 1**

```
1000000000000
```

**Explanation 1**

Because all of the first `n=1000000000000` letters of the infinite string are  `a`, we print `1000000000000` on a new line.

**Solution**

先设一个数组arr，arr[i]中存放s[0]~s[i]中a的个数;  
容易得到结果等于`count * (n/size) + arr[n%size-1];`  

```c
long repeatedString(string s, long n) {
    int size = s.size();
    int arr[size] ={0};

    int count = 0;
    for(int i = 0; i < size; i++){
        if(s[i] == 'a') ++count;
        arr[i] = count;
    }
    long result = count * (n/size) + arr[n%size-1];
    return result;
}
```
