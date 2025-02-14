#include <iostream>
#include <cstdlib> // 用于rand()和srand()
#include <ctime>   // 用于time()
#include "question_database.h"
#include "utils.h"

int main() {
    // 初始化随机数种子
    srand(static_cast<unsigned>(time(0)));

    // 初始化题库并加载状态
    std::vector<Question> questionDatabase = initializeAndLoadQuestionDatabase("questions.json");

    // 记录已做题目的数量
    int solvedCount = 0;
    for(auto question : questionDatabase){
        if(question.isSolved){
            solvedCount++;
        }
    }
    if(solvedCount >= questionDatabase.size()){
		std::cout << "题库中的题目已经全部解决！" << std::endl;
        getchar();

        return EXIT_SUCCESS;
	}
	else{
		std::cout << "题库已做题目数: " << solvedCount << std::endl;
	}
    

    // 循环选择题目并解决
    std::string continueChoice;
    do {
        try {
            // 随机选择一个题目索引
            size_t selectedIndex = getRandomUnsolvedQuestionIndex(questionDatabase);

            // 获取选中的题目
            Question& selectedQuestion = questionDatabase[selectedIndex];

            // 打印题目名称和URL
            std::cout << "\n随机选中的题目是: " << selectedQuestion.title << std::endl;
            std::cout << "题目网址: " << selectedQuestion.url << std::endl;

            // 标记该题目为已解决，并更新已做题目的数量
            selectedQuestion.isSolved = true;
            solvedCount++;

            // 打印当前已做题目的数量
            std::cout << "当前已做题目的数量: " << solvedCount << std::endl;

            // 保存题库状态到文件
            saveQuestionDatabase(questionDatabase, "questions.json");

            if(solvedCount >= questionDatabase.size()){
                std::cout << "恭喜你已经解决了题库的全部题目！" << std::endl;
	        }
            else{
                // 询问是否继续选择另一道题
                std::cout << "是否再选一道题目？(输入 yes 继续，其他任意键退出): ";
                std::getline(std::cin, continueChoice);
                continueChoice = toLowerCase(continueChoice); // 转换为小写以便比较
            }

        } catch (const std::exception& e) {
            std::cerr << "发生错误: " << e.what() << std::endl;
            return EXIT_FAILURE;
        }
    } while (continueChoice == "yes" && solvedCount < questionDatabase.size());

    if(solvedCount < questionDatabase.size()){
		std::cout << "程序结束。" << std::endl;
	}
    
	getchar();
	
    return EXIT_SUCCESS;
}