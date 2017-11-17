// TODO: rewrite
#include <iostream>
using namespace std;

const char* V = "aeiouAEIOU";

int main()
{
    string l;
    while (getline(cin, l))
    {
        int i = 0;
        while (i < l.size())
        {
            while (i < l.size() && !isalpha(l[i]))
                cout << l[i++];

            if (i == l.size())
                break;

            bool v = false;
            for (int j = 0; V[j]; ++j)
                if (l[i] == V[j])
                    v = true;
            
            char c = l[i];
            if (!v) ++i;
            while (i < l.size() && isalpha(l[i]))
                cout << l[i++];
            
            if (!v)
                cout << c;
            cout << "ay";
        }
        cout << '\n';
    }
}
