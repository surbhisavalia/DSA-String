#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:

    bool isValid(string s)
    {
        int n = s.length();

        char ch;
        stack<char> BPS;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                BPS.push(s[i]);
            }

            else
            {
                if (BPS.empty())
                {
                    return false;
                }

                ch = BPS.top();

                if (s[i] == ')' && ch != '(')
                {
                    return false;
                }

                if (s[i] == '}' && ch != '{')
                {
                    return false;
                }

                if (s[i] == ']' && ch != '[')
                {
                    return false;
                }

                BPS.pop();
            }
        }

        return BPS.empty();
    }
};