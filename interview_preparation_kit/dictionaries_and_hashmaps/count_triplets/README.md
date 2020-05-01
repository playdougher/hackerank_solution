# Count Triplets 

[题目](https://www.hackerrank.com/challenges/count-triplets-1/problem)  

要求找出给定数组中的所有等比数列三元组, 该三元组的下标大小必须是由小到大.

# Solution

**实现思路**  
因为要找的数组下标必须从小到大, 所以若把三元组写成`(a[i], a[i]*r, a[i]*r^2)`, 现给定一个`a[i]`,我们很难确定找出的后两个数是否满足下标 `i<j<k`, 所以设计另外一种表示方法:  
将三元组写成`(a[i]/r, a[i], a[i]*r)`, 将`a[i]/r`, `a[i]*r` 分别存放于两个`unordered_map`. 搜索的时候就能确定左右关系.  
计算某个三元组的组数: `a[i]/r个数`x`a[i]个数` x `a[i]*r个数`

**注意点**  
1. 存在r = 1的情况
2. 返回结果的可能性有10^15种, 变量要设置成`long long`型, 至少8字节大小

**变量设置**  
k : 公比(原题中设为r)

**实现方式**  
```c
long countTriplets(vector<long> arr, long k) {

    unordered_map<long, long> l,r;
    for(long t : arr){
        r[t]++;
    }

    long long count = 0; // C(10^5, 3) = 10^15
    for(long t : arr){
        if(t % k == 0){
            r[t]--;
            count += l[t/k] * r[t*k];
        }
        l[t]++;
    }
    return count;
}
```

