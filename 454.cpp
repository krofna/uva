#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<string, string> ss;

void Anagram(ss& a, ss& b)
{
    string& si = a.second, &sj = b.second;
    if (si.size() != sj.size() ||
        !is_permutation(si.begin(), si.end(), sj.begin()))
        return;
    
    string& fi = a.first, &fj = b.first;
    if (fi < fj)
        cout << fi << " = " << fj << '\n';
    else
        cout << fj << " = " << fi << '\n';
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(2);
    while (t--)
    {
        ss A[100];
        int n = 0;
        string in;
        while (getline(cin, in), !in.empty())
        {
            string ino = in;
            in.erase(remove_if(in.begin(), in.end(), ::isspace), in.end());
            A[n++] = make_pair(ino, in);
        }
        sort(A, A + n);
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                Anagram(A[i], A[j]);

        if (t) cout << '\n';
    }
}
