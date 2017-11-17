#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct fis
{
    float d;
    int r;
    string s;
};

int main()
{
    int n, p, u = 1;
    string in;
    while (cin >> n >> p, n && p)
    {
        if (u > 1)
            cout << "\n";

        cin.ignore();
        for (int i = 0; i < n; ++i)
            getline(cin, in);
        
        vector<fis> V(p);
        for (int i = 0; i < p; ++i)
        {
            getline(cin, V[i].s);
            cin >> V[i].d >> V[i].r;
            cin.ignore();
            for (int j = 0; j < V[i].r; ++j)
                getline(cin, in);
        }
        
        fis& min = *min_element(V.begin(), V.end(), [] (fis& a, fis& b)
        {
            if (a.r == b.r)
                return a.d < b.d;
            return a.r > b.r;
        });
        
        cout << "RFP #" << u++ << '\n';
        cout << min.s << '\n';
    }
}
