#include <iostream>
#include <unistd.h>

std::string get_path(std::string str, std::string asset)
{
    std::string temp;
    str = get_current_dir_name();
    int slash = 0;
    int len = 0;
    while (str[len] != '\0') {
        if (str[len] == '/') {
            slash++;
        }
        if (slash == 4) {
            break;
        }
        len++;
    }
    temp = str.substr(0, len + 1) + "assets/" + asset;
    return temp;
}