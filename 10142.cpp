// TODO: katastrofa
#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

int main()
{
    int t, n, B[1000][20], V[20], winner;
    string C[20], l;
    bool R[20], tie;
    cin >> t;
    for (int z = 0; z < t; ++z)
    {
        if (z)
            cout << '\n';

        cin >> n;
        cin.ignore();
        for (int i = 0; i < n; ++i)
            getline(cin, C[i]);
        
        int m = 0;
        while (getline(cin, l), !l.empty())
        {
            istringstream ss(l);
            for (int i = 0; i < n; ++i)
            {
                ss >> B[m][i];
                B[m][i] -= 1;
            }
            m++;
        }
    
        memset(R, true, sizeof(R));
        do
        {
            memset(V, 0, sizeof(V));
            winner = -1;
            for (int i = 0; i < m; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    if (R[B[i][j]])
                    {
                        if (++V[B[i][j]] > m / 2)
                            winner = B[i][j];
                        break;
                    }
                }
            }

            int min = 1000;
            for (int i = 0; i < n; ++i)
                if (R[i] && V[i] < min)
                    min = V[i];
            
            tie = true;
            for (int i = 0; i < n; ++i)
                if (R[i] && V[i] != min)
                    tie = false;
            
            if (tie)
                for (int i = 0; i < n; ++i)
                    if (R[i])
                        cout << C[i] << '\n';

            for (int i = 0; i < n; ++i)
                if (V[i] == min)
                    R[i] = false;
                
        } while (!tie && winner == -1);
        
        if (!tie && winner != -1)
            cout << C[winner] << '\n';
    }
}
