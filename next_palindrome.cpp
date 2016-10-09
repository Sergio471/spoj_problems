#include <iostream>
#include <algorithm>
#include <vector>

std::string next_palin(const std::string &_s)
{
    std::string s;
    s.reserve(_s.size() + 1);
    s.append(_s);

    {
        // Make it plus 1
        int i = s.size() - 1;
        while (s[i] == '9') { s[i] = '0'; --i; }
        if (i == -1)
        {
            // _s contained all 9s
            s.resize(s.size() + 1);
            std::fill(s.begin(), s.end(), '0');
            s[0] = '1';
            s[s.size() - 1] = '1';

            return s;
        }
        else
        {
            // just increment last digit
            s[i] += 1;
        }
    }

    int mid = s.size() / 2;
    // to handle even/odd num of digits
    int r = (s.size() % 2 == 1) ? 0 : 1;

    {
        // Main logic
        int i = 1;

        while ((mid + i - r) < s.size() && s[mid - i] == s[mid + i - r]) ++i;
        if (mid + i - r == s.size()) return s;

        if (s[mid - i] <= s[mid + i - r])
        {
            if (s[mid - r] != '9')
            {
                s[mid - r] += 1;
            }
            else
            {
                int j = mid - r;
                while (s[j] == '9') { s[j] = '0'; --j; }
                s[j] += 1;
            }
        }
    }

    {
        // Reflect around mid
        int i = 1;
        while (mid + i - r < s.size())
        {
            s[mid + i - r] = s[mid - i];
            ++i;
        }
    }

    return s;
}

int main()
{
    int t;
    std::cin >> t;

    std::vector<std::string> vec;
    vec.resize(t);

    for (int i = 0; i < t; ++i)
    {
        std::cin >> vec[i];
    }

    for (const auto& s : vec)
    {
        std::cout << next_palin(s) << std::endl;
    }

    return 0;
}
