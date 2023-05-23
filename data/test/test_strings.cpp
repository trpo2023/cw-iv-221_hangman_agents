#include <ctest.h>
#include <library/strings.hpp>

CTEST(string, get_path)
{
    std::string result;
    std::string asset = "1.bmp";
    std::string exp = "/home/egor/cw-iv-221_hangman_agents/assets/1.bmp";

    result = get_path(result, asset);

    int i = 0;
    int flag = 0;
    int check = 1;
    while (exp[i] != '\0')
    {
        i++;
        if (result[i] == exp[i])
        {
            flag = 1;
        }
        else
        {
            flag = 0;
        }
    }

    ASSERT_EQUAL(flag, check);
}

