#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
vi A, dp, dp2;

int lis(int n)
{
    if (dp[n] != 0)
        return dp[n];
    
    int m = 0, j = -1;
    for (int i = 0; i < n; ++i)
        if (A[i] < A[n] && lis(i) > m)
            m = lis(i), j = i;
    dp2[n] = j;
    return dp[n] = 1 + m;
}

void rec(int n)
{
    if (dp2[n] != -1)
        rec(dp2[n]);
    cout << A[n] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    cin.ignore(2);
    while (t--)
    {
        A.clear();
        string s;
        while (getline(cin, s), !s.empty())
            A.push_back(stoi(s));
        dp.assign(A.size(), 0);
        dp2.assign(A.size(), -1);
        int m = 0, j = -1;
        for (int i = 0; i < A.size(); ++i)
            if (lis(i) > m)
                m = lis(i), j = i;
        
        cout << "Max hits: " << m << "\n";
        rec(j);
        if (t) cout << '\n';
    }
}
