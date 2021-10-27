#include <iostream>
#include <string>

bool AreOpposite(char x, char y)
{
    if (x == '(' && y == ')')
        return true;
    else if (x == '[' && y == ']')
        return true;
    else if (x == '{' && y == '}')
        return true;
    else
        return false;
}

bool AreValid(std::string s)
{
    for (int i = 0; i < s.length()-i-1; i++)
    {
        if (!AreOpposite(s[i], s[s.length()-i-1]))
            return false;
    }
    return true;
}

int main()
{
    std::cout << AreValid("[()]") << std::endl;
    std::cout << AreValid("[([([])])]") << std::endl;
    std::cout << AreValid("[[}}") << std::endl;
    std::cout << AreValid("[(])") << std::endl;
    return 0;
}