#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        
        int score = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            int num = 0;
            while (s[i] == 'O')
                ++num, ++i;
            score += num * (num + 1) / 2;
        }
        
        cout << score << '\n';
    }
}
