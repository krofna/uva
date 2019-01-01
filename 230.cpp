#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
using namespace std;

typedef pair<string, string> ss;
typedef vector<ss> vp;

vp A;
map<ss, int> B;

string get_author(const string& title)
{
    return find_if(A.begin(), A.end(), [&](ss q)
    {
        return q.second == title;
    })->first;
}

int main()
{
    string in;
    while (getline(cin, in), in != "END")
    {
        size_t ti = in.find('\"', 1);
        string title = in.substr(0, ti + 1);
        string author = in.substr(ti + 5);
        A.emplace_back(author, title);
    }
    sort(A.begin(), A.end());
    while (cin >> in, in != "END")
    {
        string title;
        if (in == "BORROW")
        {
            cin.ignore();
            getline(cin, title);
            B[make_pair(get_author(title), title)] = 1;
        }
        else if (in == "RETURN")
        {
            cin.ignore();
            getline(cin, title);
            B[make_pair(get_author(title), title)] = 2;
        }
        else if (in == "SHELVE")
        {
            for (auto& q : B)
            {
                auto p = q.first;
                if (q.second != 2) continue;
                q.second = 0;
                auto it = find_if(A.begin(), A.end(), [&](ss q)
                {
                    return q.second == p.second;
                });
                auto jt = find_if(vp::reverse_iterator(it), A.rend(), [&](ss q)
                {
                    return B[q] == 0;
                });
                if (jt != A.rend())
                    cout << "Put " << p.second << " after " << jt->second << "\n";
                else
                    cout << "Put " << p.second << " first\n";
            }
            cout << "END\n";
        }
    }
}
