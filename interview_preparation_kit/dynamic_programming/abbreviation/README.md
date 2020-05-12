# Abbreviation

[题目](https://www.hackerrank.com/challenges/abbr/problem)

## Solution

**实现思路**  
```
** 注意: 读到a[i]表示已经读了i+1个字符.
O(n^2):  
* 设定一个动态规划数组int dp[1001][1001], 
    * dp[i][j]=1表示: 第一个字符串a的<前i个字符>和第二个字符串b的<前j个字符>是abbreviation.
* 若 a[i]的大小写字母 == b[j] , 则dp[i+1][j+1]=1;
* 若 a[i]为小写字母 , 则dp[i+1][j]=1, 即a的前i+1个字符可以成为b的前j个字符的abbreviation.(这里b已读取的长度为j+1)
```

**注意点**  
```
* dp[i+1][j+1]有另一层含义: 决定a[i+1], b[j+1]能否读取(i+1,j+1为下一次遍历的i,j值). 若dp[i+1][j+1]==0, 说明a的前i+1个字符和b的前j+1个字符不是abbreviation.
* 字符串遍历的方式是通过dp[i][j]推进的, 因为dp中的i,j表长度, 数组中的表下标. 下一回的下标i, j(长度i+1, j+1)正好可以用来判断dp[i][j](长度i, j)是否符合条件, 而只有前面的字符串符合条件了, 整体才能往下进行
* b遍历完后, i还要继续往下判断, 因为大写字母不能删除. 所以若是大写字母, bp[i][j]为0.  e.g. a="ABCDEFG", b="ABC"
    * 代码中体现在27行的 j <= b.size()
```

**实现方式**  
```c
#include <bits/stdc++.h>
using namespace std;

char upcase(char c){
    if (isupper(c)) return c;
    return (char)(c - 32);
}

int dp[1001][1001];

int main() {
    int q;
    cin >> q;

    while(q--) {
        string a, b;
        cin >> a;
        cin >> b;

        dp[0][0] = 1;
        for(int i = 1; i <= a.size(); i++) {
            for(int j = 1; j <= b.size(); j++) {
                dp[i][j] = 0;
            }
        }

        for(int j = 0;  j <= b.size(); j++){// <=, j==b.size()后, i还要继续往下判断, 若是大写字母, 为0. e.g. a="ABCDEFG", b="ABC"
            for (int i = 0;  i<a.size(); i++){
                if(dp[i][j]){
                    if(j < b.size() && (upcase(a[i]) == b[j])){ // prevent j == b.size()
                        dp[i + 1][j + 1] = 1;
                        //cout << "i+1:" << i+1 << " j+1:"  << j+1 << " dp[i + 1][j + 1]: " <<dp[i + 1][j + 1] << endl;
                    }
                    if(islower(a[i])){
                        dp[i + 1][j] = 1;
                        //cout << "i+1:" << i+1 << " j:"  << j << " dp[i + 1][j]: " <<dp[i + 1][j] << endl;
                    }
                    //cout << endl;
                }
            }
        }
        if(dp[a.size()][b.size()]) cout << "YES" << endl;
        else cout <<"NO" <<endl;
    }
}

```
