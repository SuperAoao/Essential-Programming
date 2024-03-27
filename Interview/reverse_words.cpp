#include <iostream>
#include <stack>
#include <sstream>
#include <vector>

// 英文语句以单词为单位逆序排放。"welcome to Hengge"逆序排放后为"Hengge to welcome"。
// 所有单词按一个空格隔开，出了英文字母外不再包含其他字符
std::string reverseWords(const std::string& words)
{
    std::stringstream is(words);
    std::stack<std::string> stackWords;
    std::string word;
    while (is >> word)
    {
        stackWords.push(word);
    }
    std::string reversed;
    while (!stackWords.empty())
    {
        std::string popWord = stackWords.top(); 
        stackWords.pop();
        reversed += popWord;
        if (stackWords.size() > 0)
        {
            reversed += " ";
        }
    }
    return reversed;
}

std::vector<std::string> split(const std::string& str)
{
    std::vector<std::string> res;
    char split = ' ';
    size_t start = 0;
    size_t end = 0;
    while ((end = str.find(split, start)) != std::string::npos)
    {
        if (end != start)
        {
            res.push_back(str.substr(start, end - start));
        }
        start = end + 1;
    }
    if (start < str.length())
    {
        res.push_back(str.substr(start));
    }
    return res;
}

void test(const std::string& result)
{
    if (result == "Hengge to welcome")
    {
        std::cout << "Correct!" << std::endl;
    }
    else
    {
        std::cout << "Incorrect!" << std::endl;
    }
}

int main()
{

    std::string example = "welcome to Hengge";
    test(reverseWords(example));
    // 错误示例，未考虑到单词间的空格
    auto splits = split(example);
    std::string res;
    for (int i = splits.size()-1; i > -1; i--)
    {
        res += splits.at(i);
    }
    test(res);
    


    return 0;
}

