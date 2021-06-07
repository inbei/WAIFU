#include<WAIFU.hpp>

std::string WAIFU::tell(std::string sentence)
{
    std::transform(sentence.begin(), sentence.end(), sentence.begin(), [](unsigned char c){ return std::tolower(c); });

    return "";
}
