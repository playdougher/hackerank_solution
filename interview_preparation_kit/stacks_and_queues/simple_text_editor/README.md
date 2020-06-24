# Simple Text Editor 

[题目](https://www.hackerrank.com/challenges/simple-text-editor/problem)  

插入和删除时需要备份字符串。

**实现方式**  

```c
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

string str;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int q;

    string s;
    int num;
    int second_num;
    stack<string> stk;
    cin >> q;
    //append/delete/print/undo
    while(q--){
        cin >> num;
        if(num == 1){
            string s;
            cin >> s;
            stk.push(str);
            str+=s;
        }
        else if(num == 2){
            int n;
            cin >> n;
            stk.push(str);
            str.resize(str.size()-n);
        }
        else if(num == 3){
            int n;
            cin >> n;
            //n-1
            cout << str[n-1] << endl;
        }
        else {
            str = stk.top();
            stk.pop();
        }

    }
    return 0;
}
```
