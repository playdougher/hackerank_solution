#include <bits/stdc++.h>

using namespace std;

// Complete the substrCount function below.
long substrCount(int n, string s) {
    int mid_idx = -1; //中间字符的位置
    long cnt = n; //special string总数. 每个字符都满足定义, 因此初始化为n
    int consec = 1;//连续字符串长度

    for(int i = 1; i < n; i++){
        if(s[i] == s[i-1]){
            //n个连续字符,special string为 1 + 2 + ... + n-1 .
            cnt += consec;
            ++consec; 

            if(mid_idx != -1 ){
                //对称的点是否存在且相等
                if(s[i] == s[mid_idx-consec] and mid_idx-consec >= 0) ++cnt;
                else mid_idx =-1;
            }
        }
        else{
            consec = 1;
            if(i-2 >= 0 and s[i-2] == s[i]){
                ++cnt;
                mid_idx = i-1;
            }
            else mid_idx = -1;
        }
    }
    return cnt;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    long result = substrCount(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}

