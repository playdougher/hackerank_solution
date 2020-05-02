# Arrays: Left Rotation

[题目](https://www.hackerrank.com/challenges/ctci-array-left-rotation/problem)

题目给定一个数组，要求我们往左移动d次。

# Solution

**实现思路**  

T(n)=O(n),S(n)=O(n):另设一个长度为n的数组，从原数组d%n处开始取值放到新数组内。直到再次循环到d%n结束。

**实现方式**  
```c
vector<int> rotLeft(vector<int> a, int d) {
    int n = a.size();
    int d_tmp = d % n;
    vector<int> b;
    int i = d_tmp;
    do{
        b.push_back(a[i]);
        i = (i+1)%n;
    }while(i!=d_tmp);
    return b;
}
```
