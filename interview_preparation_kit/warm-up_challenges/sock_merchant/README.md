# Sock Merchant

题目给了一堆袜子，有不同颜色，相同颜色可以组成一双。现在让我们计算出一堆袜子里有几双成对的袜子。

**Input Format**

The first line contains an integer `n`, the number of socks represented in `ar` .  
The second line contains `n` space-separated integers describing the colors `ar[i]` of the socks in the pile.

**Constraints**

* 1 <= n <= 100 
* 1 <= ar[i] <= 100 where 0 <= i < n  
>

**Output Format**

Return the total number of  _matching pairs_  of socks that John can sell.

**Sample Input**

```
9
10 20 20 10 10 30 50 10 20
```

**Sample Output**

```
3
```

**Solutions**

将每个数作数组下标，以计算每个颜色的出现次数。简单处理后求和。

```c
int sockMerchant(int n, vector<int> ar) {
    int atmp[101] = {0}; //we need 100+1,cause socks start at 1
    for(auto i:ar) atmp[i]++;

    int count = 0;
    for(int elem:atmp) count += elem/2;

    return count;
}
```
