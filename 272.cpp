#include <iostream>
using namespace std;

int main()
{
    string in;
    bool flag = true;
    while (getline(cin, in))
    {
        for (int i = 0; i < in.size(); ++i)
        {
            if (in[i] == '"')
            {
                cout << (flag ? "``" : "''");
                flag = !flag;
            }
            else
                cout << in[i];
        }
        cout << '\n';
    }
}
