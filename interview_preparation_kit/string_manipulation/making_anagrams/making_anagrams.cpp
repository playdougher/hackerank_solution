#include <bits/stdc++.h>

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {
    vector<int> letter(26);
    int cnt = 0;
    for(int i = 0; i < a.size();  i++) letter[a[i]-'a']++;
    for(int i = 0; i < b.size();  i++) letter[b[i]-'a']--;
    for(int c:letter) cnt += abs(c);
    return cnt;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}

