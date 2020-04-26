# Counting Valleys

一个人在爬山，他所处的高度设为水平线，高于水平线的是山，低于水平线的是谷。往上爬再回到水平线算爬过一座山，同样的，往下是一座谷。现在问他爬过几个谷。


**Function Description**

Complete the  _countingValleys_  function in the editor below. It must return an integer that denotes the number of valleys Gary traversed.

countingValleys has the following parameter(s):

-   _n_: the number of steps Gary takes
-   _s_: a string describing his path

**Input Format**

The first line contains an integer  `n`, the number of steps in Gary's hike.
The second line contains a single string `s` , of `n` characters that describe his path.

**Constraints**

<img src="http://latex.codecogs.com/gif.latex?2\leq n\leq10^6" border="0"/>

<img src="http://latex.codecogs.com/gif.latex?s[i] \in U,D" border="0"/>

**Output Format**

Print a single integer that denotes the number of valleys Gary walked through during his hike.

**Sample Input**

```
8
UDDDUDUU
```

**Sample Output**

```
1
```

**Explanation**

If we represent  `_`  as sea level, a step up as  `/`, and a step down as  `\`, Gary's hike can be drawn as:

```
_/\      _
   \    /
    \/\/
```

He enters and leaves one valley.

**Solution**

```
_/\      _
   \    / <-- 看看有几个‘/’
    \/\/
```

山谷的尾巴'/'的个数就是山谷的个数。

```c
int countingValleys(int n, string s) {
    int valley_count = 0;
    int level = 0;
    for(char c:s)
        if(c == 'U' ) {
	        //若往上爬，且爬到水平线，说明过了一个山谷。
            if(level++<0 && level == 0) ++valley_count;
        }
        else --level;
    return valley_count;
}
```
