#include <iostream>
using namespace std;

int L[5000], H[5000], R[5000], n = 0;

int hi(int k)
{
    for (int i = k + 1; i < n && L[i] < R[k]; ++i)
        if (H[i] > H[k])
            return i;
    return -1;
}

int lo(int k)
{
    for (int i = 0; i < n && L[i] < R[k]; ++i)
        if (R[i] > R[k])
            return i;
    return -1;
}

int main()
{
    while (cin >> L[n] >> H[n] >> R[n], ++n && cin);
    int k = 0, l = 0;
    cout << L[k] << " " << H[k] << " " << flush;
    while (k < n)
    {
        int l = hi(k);
        if (l == -1)
        {
            l = lo(k);
            if (l == -1)
            {
                cout << R[k] << " 0 " << flush;
                k++;
                if (k < n)
                    cout << L[k] << " " << H[k] << " " << flush;
            }
            else
                cout << R[k] << " " << H[l] << " " << flush, k = l;
        }
        else
            cout << L[l] << " " << H[l] << " " << flush, k = l;
    }
}
