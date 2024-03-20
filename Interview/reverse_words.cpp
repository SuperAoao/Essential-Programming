#include <iostream>
#include <stack>
#include <sstream>

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

int main()
{

    std::string test = "welcome to Hengge";
    std::string result = reverseWords(test);
    if (result == "Hengge to welcome")
    {
        std::cout << "Correct!" << std::endl;
    }
    else
    {
        std::cout << "Incorrect!" << std::endl;
    }
    return 0;
}

