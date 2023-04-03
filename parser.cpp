#include <bits/stdc++.h>
#include <fstream>

using namespace std;

string removeSpaces(string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

string convert_to_binary(int num)
{
    string temp = "";
    int t = 10;
    char sign = '0';

    if (num < 0)
        sign = '1';

    while (t--)
    {
        if (num % 2 == 0)
            temp = '0' + temp;

        else
            temp = '1' + temp;
        num /= 2;
    }

    temp = sign + temp;
    return temp;
}

string decoded(string str)
{
     string op1 = str.substr(0, 1), op2;

    for (int i = 1; i < str.length(); i++)
    {
        if (str[i] == '+')
        {
            op2 = str.substr(i + 1, str.length());
            return "000" + convert_to_binary(stoi(op1)) + convert_to_binary(stoi(op2));
        }

        else if (str[i] == '-')
        {
            op2 = str.substr(i + 1, str.length());
            return "001" + convert_to_binary(stoi(op1)) + convert_to_binary(stoi(op2));
        }

        else if (str[i] == '*')
        {
            op2 = str.substr(i + 1, str.length());
            return "010" + convert_to_binary(stoi(op1)) + convert_to_binary(stoi(op2));
        }

        else if (str[i] == '/')
        {
            op2 = str.substr(i + 1, str.length());
            return "011" + convert_to_binary(stoi(op1)) + convert_to_binary(stoi(op2));
        }

        else if (str[i] == '>')
        {
            op2 = str.substr(i + 2, str.length());
            return "100" + convert_to_binary(stoi(op1)) + convert_to_binary(stoi(op2));
        }

        else if (str[i] == '<')
        {
            op2 = str.substr(i + 2, str.length());
            return "101" + convert_to_binary(stoi(op1)) + convert_to_binary(stoi(op2));
        }

        else if (str[i] == '&')
        {
            op2 = str.substr(i + 1, str.length());
            return "110" + convert_to_binary(stoi(op1)) + convert_to_binary(stoi(op2));
        }

        else if (str[i] == '|')
        {
            op2 = str.substr(i + 1, str.length());
            return "111" + convert_to_binary(stoi(op1)) + convert_to_binary(stoi(op2));
            ;
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

    ofstream output_file("intermediate.txt");

    if (file.is_open())
    {

        string line;
        while (getline(file, line))
        {
            string s = line;

            s = removeSpaces(s);

            if (output_file.is_open())
            {
                string decoded_string = decoded(s);
                output_file << decoded_string << endl;
            }
        }
    }

    output_file.close();
    return 0;
}