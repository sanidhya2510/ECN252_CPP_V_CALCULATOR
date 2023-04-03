#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int ADD(int a, int b)
{
    return a + b;
}

int SUBTRACT(int a, int b)
{
    return a - b;
}

int MULTIPLY(int a, int b)
{
    return a * b;
}

int DIVIDE(int a, int b)
{
    return a / b;
}

int RIGHT_SHIFT(int a, int b)
{
    return a >> b;
}

int LEFT_SHIFT(int a, int b)
{
    return a << b;
}

int AND(int a, int b)
{
    return a & b;
}

int OR(int a, int b)
{
    return a | b;
}

string removeSpaces(string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

int FIND_ANSWER(string str)
{
    string op1 = str.substr(0,1), op2;

    for (int i = 1; i < str.length(); i++)
    {
        if (str[i] == '+')
        {
            op2 = str.substr(i + 1, str.length());
            return ADD(stoi(op1), stoi(op2));
        }

        else if (str[i] == '-')
        {
            op2 = str.substr(i + 1, str.length());
            return SUBTRACT(stoi(op1), stoi(op2));
        }

        else if (str[i] == '*')
        {
            op2 = str.substr(i + 1, str.length());
            return MULTIPLY(stoi(op1), stoi(op2));
        }

        else if (str[i] == '/')
        {
            op2 = str.substr(i + 1, str.length());
            return DIVIDE(stoi(op1), stoi(op2));
        }

        else if (str[i] == '>')
        {
            op2 = str.substr(i + 2, str.length());
            return RIGHT_SHIFT(stoi(op1), stoi(op2));
        }

        else if (str[i] == '<')
        {
            op2 = str.substr(i + 2, str.length());
            return LEFT_SHIFT(stoi(op1), stoi(op2));
        }

        else if (str[i] == '&')
        {
            op2 = str.substr(i + 1, str.length());
            return AND(stoi(op1), stoi(op2));
        }

        else if (str[i] == '|')
        {
            op2 = str.substr(i + 1, str.length());
            return OR(stoi(op1), stoi(op2));
        }

        else
        {
            op1 = op1 + str[i];
        }
    }
}

int main()
{

    ifstream file;
    file.open("input.txt");

    ofstream output_file("CPP_result.txt");

    if (file.is_open())
    {

        string line;
        while (getline(file, line))
        {
            string s = line;

            s = removeSpaces(s);

            if (output_file.is_open())
            {
                int answer = FIND_ANSWER(s);
                output_file << answer << endl;
            }
        }
    }

    output_file.close();
    return 0;
}