// TODO: nemoj iterirat svako slovo; napravi ko marko
#include <iostream>
using namespace std;

const int sz = 'z' - 'a' + 1;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        string s;
        cin >> s;
        int A[1000][sz] = {}, n = 0;
        for (int a = 0; a < s.size(); ++a)
            A[a][s[a] - 'a']++;

        for (int a = 1; a < s.size(); ++a)
            for (int c = 0; c < sz; ++c)
                A[a][c] += A[a - 1][c];
        
        for (int a = 0; a < s.size(); ++a)
        {
            for (int b = a; b < s.size(); ++b)
            {
                int np = 0;
                for (int c = 0; c < sz; ++c)
                {
                    int k = A[b][c] - (a ? A[a - 1][c] : 0);
                    np += k % 2;
                }
                if (np <= 1)
                    n++;
            }
        }
        cout << "Case " << i + 1 << ": " << n << '\n';
    }
}
