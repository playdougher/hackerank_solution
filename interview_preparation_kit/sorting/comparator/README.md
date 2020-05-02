# Sorting: Comparator 

[题目](https://www.hackerrank.com/challenges/ctci-comparator-sorting/problem)  
题目要求首先将`score`按降序排列, 然后`name`按升序排列. 

## Solution

**实现思路**  
先判断`score`, 再判断`name`大小. 利用好库函数`compare()`比较字符串. 

**注意点**  
我认为题目给的测试代码给反了, 测试代码的`compare`函数中, `== -1` 的那一句应该时`return true`的. 做的时候我就反着做了. 先按着要求正着做, 然后取个负号

**实现方式**  
```c
class Checker{
public:
    // complete this method
    static int comparator(Player a, Player b)  {
        int ret = 0;
        if(a.score == b.score) ret = a.name.compare(b.name);
        else ret = b.score-a.score;

        if (ret > 0) ret = 1;
        return -ret;
    }
};

bool compare(Player a, Player b) {
    if(Checker::comparator(a,b) == -1)
        return false;
    return true;
}
```
