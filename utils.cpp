#include "utils.h"
#include <cctype>

// 将字符串转换为小写
std::string toLowerCase(const std::string& str) {
    std::string lowerStr = str;
    for (char& c : lowerStr) {
        c = std::tolower(c);
    }
    return lowerStr;
}