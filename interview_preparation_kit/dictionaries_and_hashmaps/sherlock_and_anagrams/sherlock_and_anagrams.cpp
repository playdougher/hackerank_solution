#include <bits/stdc++.h>

using namespace std;

// Complete the sherlockAndAnagrams function below.
// 建一个子字符串的set
// 遍历set,找set中对应的回文数
int sherlockAndAnagrams(string s) {
    unordered_map<string> words;
    int str_len = s.size();
    int substr_len = 1;
    int i = 0; 
    while(substr_len < str_len-1){
        while(i < str_len-(substr_len-1)){
            ++words.[substr(i,substr_len)];
        }
        ++substr;
        i = 0;
    }

    int count = 0;
    for(string &t:words){
        if(words.find(t) != words.end()) --words[t];
        else break;
        
        reverse(t.begin(),t.end());
        if(words.find(t) != words.end()) {
            --words[t];
            ++count;
        }
    }        
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
