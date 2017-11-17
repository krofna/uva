#include <iostream>
using namespace std;

string A[3];

bool Wins(char c)
{
    for (int i = 0; i < 3; ++i)
    {
        if (A[i][0] == A[i][1] && A[i][0] == A[i][2] && A[i][0] == c)
            return true;
        if (A[0][i] == A[1][i] && A[0][i] == A[2][i] && A[0][i] == c)
            return true;
    }
    if (A[0][0] == A[1][1] && A[0][0] == A[2][2] && A[0][0] == c)
        return true;
    if (A[0][2] == A[1][1] && A[0][2] == A[2][0] && A[0][2] == c)
        return true;

    return false;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int nx = 0, no = 0;
        for (int i = 0; i < 3; ++i)
        {
            cin >> A[i];
            for (int j = 0; j < 3; ++j)
            {
                if (A[i][j] == 'X')
                    ++nx;
                else if (A[i][j] == 'O')
                    ++no;
            }
        }
        
        bool ex = true;
        if (nx < no || nx > no + 1)
            ex = false;
              
        if (Wins('O'))
        {
            if (Wins('X'))
                ex = false;
            
            if (nx != no)
                ex = false;
        }
        else if (Wins('X'))
        {
            if (nx != no + 1)
                ex = false;
        }
        
        cout << (ex ? "yes" : "no") << '\n';
    }
}
