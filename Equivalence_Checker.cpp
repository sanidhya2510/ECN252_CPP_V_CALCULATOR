#include <bits/stdc++.h>
using namespace std;

string removeSpaces(string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

int main()
{

    ifstream CPPOutput;
    ifstream VOutput;
    CPPOutput.open("CPP_result.txt");
    VOutput.open("V_result.txt");

    bool ans = true;

    if (CPPOutput.is_open() && VOutput.is_open())
    {

        string res1, res2;
        while (getline(CPPOutput, res1) && getline(VOutput, res2))
        {
            string s1 = removeSpaces(res1);
            string s2 = removeSpaces(res2);

            if (s1 != s2)
            {
                ans = false;
                break;
            }
        }
    }

    if (ans)
    {
        cout << "YES" << endl;
    }

    else
    {
        cout << "NO" << endl;
    }
    return 0;
}