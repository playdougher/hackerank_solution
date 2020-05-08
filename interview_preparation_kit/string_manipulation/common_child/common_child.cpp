#include <bits/stdc++.h>

using namespace std;

// Complete the commonChild function below.
int arr[5000][5000]; //初始化为0
int LCS(string s1, string s2){
    for(int t = 0; t < s1.size(); t++){
        for(int s = 0; s < s2.size(); s++){
            int t_tmp = t;
            int s_tmp = s;
            //若 <0 , 先 ++, 后面 --. 省的写数组越界的判断语句, 统一代码.
            if(t-1 < 0) t_tmp++;
            if(s-1 < 0) s_tmp++;

            if(s1[t] == s2[s]){
                    arr[t][s] = arr[t_tmp-1][s_tmp-1] + 1; //[x]++
            }
            else{
                int n1 = arr[t_tmp-1][s];
                int n2 = arr[t][s_tmp-1];
                arr[t][s] = n1 > n2 ? n1 : n2;
            }
        }
    }
    return arr[s1.size()-1][s2.size()-1];
}

int commonChild(string s1, string s2) {
    return LCS(s1, s2);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}

