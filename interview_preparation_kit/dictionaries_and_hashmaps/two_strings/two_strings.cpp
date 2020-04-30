#include <bits/stdc++.h>

using namespace std;

// Complete the twoStrings function below.
//最好保证传进来的s1是比较长的.
string twoStrings(string s1, string s2) {
    unordered_set<char> words;

    for(auto c:s1) words.insert(c);

    for(auto c:s2){
        if(words.count(c)) return "YES";
    }
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result; 
        if(s1.size()>s2.size()) result =twoStrings(s1, s2);
        else result =twoStrings(s2, s1);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

