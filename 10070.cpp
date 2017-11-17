#include <iostream>
#include <numeric>
using namespace std;

int main()
{
    string in;
    bool flg = false;
    while (getline(cin, in), cin)
    {
        if (flg)
            cout << '\n';

        int s = -1;

        bool div4 = atoi(&in[in.size() - 2]) % 4 == 0;
        bool div100 = atoi(&in[in.size() - 2]) == 0;
        bool div400 = atoi(&in[in.size() - 4]) % 400 == 0;
        bool div5 = in.back() == '0' || in.back() == '5';
        bool div3 = accumulate(in.begin(), in.end(), 0, [](int k, char c)
        {
            return k + c - '0';
        }) % 3 == 0;
        bool div11 = accumulate(in.rbegin(), in.rend(), 0, [&](int k, char c)
        {
            s *= -1;
            return k + s * (c - '0');
        }) % 11 == 0;
        bool div15 = div3 && div5;
        bool div55 = div11 && div5;
    
        bool leap = (div4 && !div100) || div400;
        bool bulu = leap && div55;
        bool hulu = div15;
        bool ordi = !(leap || bulu || hulu);

        if (leap)
            cout << "This is leap year.\n";
        if (hulu)
            cout << "This is huluculu festival year.\n";
        if (bulu)
            cout << "This is bulukulu festival year.\n";
        if (ordi)
            cout << "This is an ordinary year.\n";

        flg = true;
    }
}
