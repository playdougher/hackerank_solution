# New Year Chaos

[题目](https://www.hackerrank.com/challenges/new-year-chaos/problem)

题目给定一个队列，里面的每个人可以通过贿赂往前插队，每个人最多贿赂两次。  
现给定一个最终队列，问最少贿赂几次能达到该状态。

# Solution

**实现思路**  
只需要原先站在最后面的人往回退到自己位置，就能算出最小值。  
如3,4,1,2。如果3先退，需要三步退到最后，然后4再退两步，变成1,2,3,4； 而4先退，只需2+2。能看出若大的值不先退，较小值需要跨过它，步数会变多。所以由大到小往后退。

**变量设置**  
idx[]: idx[elem]为elem的索引值。  

**实现方式**  
由最大值开始找，进行后移操作，经过的元素值后移、索引减一。  
若成功，返回步数；若后移超过2步，直接失败。  

**复杂度**  
时间：O(n)
空间：O(n)

```c
void minimumBribes(vector<int> q) {
    vector<int> idx(q.size()+1);
    int i = 0;
    for (int elem:q) {
        idx[elem] = i++;
    }

    int count = 0;
    for (int val = q.size(); val > 0; --val) {
        int step = val-1-idx[val];
        if(!step) continue;
        if (step > 2) {
            cout << "Too chaotic\n";
            return;
        }
        //范围：(当前索引值, 其值最终所在位置]，即(idx[val],val-1]
        //j为元素val在q中的下标，他需要往队后(增大方向)移动到他原来排的位置。
        for(int j = idx[val]+1; j < val; ++j){
            --idx[q[j]];
            q[j-1] = q[j];
        }
        count += step;
    }
    cout << count << endl;
}
```
