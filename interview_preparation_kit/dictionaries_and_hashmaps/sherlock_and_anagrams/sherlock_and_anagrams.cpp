#include <bits/stdc++.h>
using namespace std;

void gen_sig(char *signature, int n, string s){
    for(char c:s){
        signature[c-'a'] ++;
    }
}
// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
    unordered_map<string,int> words;
    int str_len = s.size();
    int substr_len = 1;
    int i = 0;
    while(substr_len < str_len){ 

        while(i+substr_len-1 < str_len){
            char signature[27]="";
            cout << "substr: " << s.substr(i,substr_len) << endl;
            gen_sig(signature, 27, s.substr(i,substr_len));
            ++words[string(signature,27)];
            ++i;
        }
        ++substr_len;
        i = 0;
    }

    int count = 0;
    for(auto &t:words){
        if(t.second > 1){
            count += t.second * (t.second-1)/2;
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

