#ifndef QUESTION_DATABASE_H
#define QUESTION_DATABASE_H

#include <vector>
#include <string>

struct Question {
    std::string title;
    std::string url;
    bool isSolved;

    Question(const std::string& t, const std::string& u, bool s)
        : title(t), url(u), isSolved(s) {}
};

// 初始化题库并从文件加载状态
std::vector<Question> initializeAndLoadQuestionDatabase(const std::string& filePath);

// 将题库状态保存到文件
void saveQuestionDatabase(const std::vector<Question>& questions, const std::string& filePath);

// 随机选择一个未解决的题目，并返回其索引
size_t getRandomUnsolvedQuestionIndex(const std::vector<Question>& questions);

#endif // QUESTION_DATABASE_H