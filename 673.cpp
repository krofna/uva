#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    while (n--)
    {
        string in;
        getline(cin, in);
        stack<char> S;
        bool correct = true;
        for (char c : in)
        {
            switch (c)
            {
                case '(':
                case '[':
                    S.push(c);
                    break;
                case ')':
                    if (S.empty() || S.top() != '(')
                        correct = false;
                    else
                        S.pop();
                    break;
                case ']':
                    if (S.empty() || S.top() != '[')
                        correct = false;
                    else
                        S.pop();
                    break;
            }
        }
        cout << (correct && S.empty() ? "Yes\n" : "No\n");
    }
}
