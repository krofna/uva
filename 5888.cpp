#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <cstdint>
using namespace std;

enum
{
    NUM,
    POP,
    INV,
    DUP,
    SWP,
    ADD,
    SUB,
    MUL,
    DIV,
    MOD
};

const map<string, int> M =
{
    { "NUM", NUM },
    { "POP", POP },
    { "INV", INV },
    { "DUP", DUP },
    { "SWP", SWP },
    { "ADD", ADD },
    { "SUB", SUB },
    { "MUL", MUL },
    { "DIV", DIV },
    { "MOD", MOD }
};

template <class T>
bool BinaryOP(stack<int64_t>& S, T F)
{
    if (S.size() < 2)
        return true;
    int a = S.top();
    S.pop();
    int b = S.top();
    S.pop();
    return !F(b, a);
}

bool Push(stack<int64_t>& S, int64_t k)
{
    if (llabs(k) > 1000000000)
        return false;
    S.push(k);
    return true;
}

int main()
{
    string cmd;
    while (cin >> cmd, cmd != "QUIT")
    {
        vector<int> P;
        vector<int64_t> Q;
        while (cmd != "END")
        {
            P.push_back(M.find(cmd)->second);
            if (cmd == "NUM")
            {
                int64_t p;
                cin >> p;
                Q.push_back(p);
            }
            cin >> cmd;
        }
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            int v;
            cin >> v;
            stack<int64_t> S;
            S.push(v);
            int qi = 0;
            bool error = false;
            for (int j = 0; j < P.size() && !error; ++j)
            {
                switch (P[j])
                {
                    case NUM:
                        error = !Push(S, Q[qi++]);
                        break;
                    case POP:
                        if (!S.empty())
                            S.pop();
                        else error = true;
                        break;
                    case INV:
                        if (!S.empty())
                            S.top() = -S.top();
                        else error = true;
                        break;
                    case DUP:
                        if (!S.empty())
                            S.push(S.top());
                        else error = true;
                        break;
                    case SWP:
                        error = BinaryOP(S, [&](int lhs, int rhs)
                        {
                            S.push(rhs);
                            S.push(lhs);
                            return true;
                        });
                        break;
                    case ADD:
                        error = BinaryOP(S, [&](int lhs, int rhs)
                        {
                            return Push(S, lhs + rhs);
                        });
                        break;
                    case SUB:
                        error = BinaryOP(S, [&](int lhs, int rhs)
                        {
                            return Push(S, lhs - rhs);
                        });
                        break;
                    case MUL:
                        error = BinaryOP(S, [&](int64_t lhs, int64_t rhs)
                        {
                            return Push(S, lhs * rhs);
                        });
                        break;
                    case DIV:
                        error = BinaryOP(S, [&](int lhs, int rhs)
                        {
                            if (rhs == 0)
                                return false;

                            return Push(S, lhs / rhs);
                        });
                        break;
                    case MOD:
                        error = BinaryOP(S, [&](int lhs, int rhs)
                        {
                            if (rhs == 0)
                                return false;

                            return Push(S, lhs % rhs);
                        });
                        break;
                }
            }
            if (!error && !S.empty() && !(S.size() > 1))
                cout << S.top() << '\n';
            else
                cout << "ERROR\n";
        }
        cout << '\n';
    }
}
