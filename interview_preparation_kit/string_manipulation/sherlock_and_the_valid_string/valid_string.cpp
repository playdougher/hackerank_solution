#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string s) {
    vector<int> letter(26);
    string ret = "NO";
    
    for(char c:s) letter[c-'a']++;  

    //对字母计数 进行计数
    //-1 表示一开始就已经满足条件的情况
    for(int i = -1; i < 26; i++){
        if(i >= 0){
            if(letter[i] == 0) continue;
            letter[i]--;
        }

        unordered_set<char> cnt_cnt; //位置
        for(auto t: letter){
            if(t) cnt_cnt.insert(t); //if(t)
        }
        if(cnt_cnt.size() <= 1) ret = "YES"; 
        if(i >= 0) letter[i]++; 
    }
    return ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

