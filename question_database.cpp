#include "question_database.h"
#include "utils.h"
#include <fstream>
#include <json.hpp>

#include "json.hpp"

using json = nlohmann::json;

// 初始化题库并从文件加载状态
std::vector<Question> initializeAndLoadQuestionDatabase(const std::string& filePath) {
    std::vector<Question> questions = {
        {"两数之和", "https://leetcode-cn.com/problems/two-sum/",false},
        {"两数相加", "https://leetcode-cn.com/problems/add-two-numbers/",false},
        {"无重复字符的最长子串", "https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/",false},
        {"寻找两个正序数组的中位数", "https://leetcode-cn.com/problems/median-of-two-sorted-arrays/",false},
        {"最长回文子串", "https://leetcode-cn.com/problems/longest-palindromic-substring/",false},
        {"字符串转换整数 (atoi)", "https://leetcode-cn.com/problems/string-to-integer-atoi/",false},
        {"回文数", "https://leetcode-cn.com/problems/palindrome-number/",false},
        {"盛最多水的容器", "https://leetcode-cn.com/problems/container-with-most-water/",false},
        {"三数之和", "https://leetcode-cn.com/problems/3sum/",false},
        {"字母异位词分组", "https://leetcode-cn.com/problems/group-anagrams/",false},
        {"螺旋矩阵 II", "https://leetcode-cn.com/problems/spiral-matrix-ii/",false},
        {"跳跃游戏 II", "https://leetcode-cn.com/problems/jump-game-ii/",false},
        {"合并K个升序链表", "https://leetcode-cn.com/problems/merge-k-sorted-lists/",false},
        {"括号生成", "https://leetcode-cn.com/problems/generate-parentheses/",false},
        {"合并区间", "https://leetcode-cn.com/problems/merge-intervals/",false},
        {"旋转图像", "https://leetcode-cn.com/problems/rotate-image/",false},
        {"不同路径", "https://leetcode-cn.com/problems/unique-paths/",false},
        {"最小覆盖子串", "https://leetcode-cn.com/problems/minimum-window-substring/",false},
        {"二叉树的层序遍历", "https://leetcode-cn.com/problems/binary-tree-level-order-traversal/",false},
        {"二叉树的最大深度", "https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/",false},
        {"从前序与中序遍历序列构造二叉树", "https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/",false},
        {"验证二叉搜索树", "https://leetcode-cn.com/problems/validate-binary-search-tree/",false},
        {"二叉树中的最大路径和", "https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/",false},
        {"打家劫舍", "https://leetcode-cn.com/problems/house-robber/",false},
        {"打家劫舍 II", "https://leetcode-cn.com/problems/house-robber-ii/",false},
        {"单词拆分", "https://leetcode-cn.com/problems/word-break/",false},
        {"乘积最大子数组", "https://leetcode-cn.com/problems/maximum-product-subarray/",false},
        {"不同的二叉搜索树", "https://leetcode-cn.com/problems/unique-binary-search-trees/",false},
        {"被围绕的区域", "https://leetcode-cn.com/problems/surrounded-regions/",false},
        {"岛屿数量", "https://leetcode-cn.com/problems/number-of-islands/",false},
        {"课程表", "https://leetcode-cn.com/problems/course-schedule/",false},
        {"零钱兑换", "https://leetcode-cn.com/problems/coin-change/",false},
        {"颜色分类", "https://leetcode-cn.com/problems/sort-colors/",false},
        {"环形链表", "https://leetcode-cn.com/problems/linked-list-cycle/",false},
        {"反转链表", "https://leetcode-cn.com/problems/reverse-linked-list/",false},
        {"LRU缓存机制", "https://leetcode-cn.com/problems/lru-cache/",false},
        {"全排列", "https://leetcode-cn.com/problems/permutations/",false},
        {"全排列 II", "https://leetcode-cn.com/problems/permutations-ii/",false},
        {"组合总和", "https://leetcode-cn.com/problems/combination-sum/",false},
        {"组合总和 II", "https://leetcode-cn.com/problems/combination-sum-ii/",false},
        {"下一个排列", "https://leetcode-cn.com/problems/next-permutation/",false},
        {"搜索旋转排序数组", "https://leetcode-cn.com/problems/search-in-rotated-sorted-array/",false},
        {"在排序数组中查找元素的第一个和最后一个位置", "https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/",false},
        {"有效的数独", "https://leetcode-cn.com/problems/valid-sudoku/",false},
        {"解数独", "https://leetcode-cn.com/problems/sudoku-solver/",false},
        {"合并两个有序数组", "https://leetcode-cn.com/problems/merge-sorted-array/",false},
        {"多数元素", "https://leetcode-cn.com/problems/majority-element/",false},
        {"缺失的第一个正数", "https://leetcode-cn.com/problems/first-missing-positive/",false},
        {"接雨水", "https://leetcode-cn.com/problems/trapping-rain-water/",false},
        {"每日温度", "https://leetcode-cn.com/problems/daily-temperatures/",false},
        {"移除无效的括号", "https://leetcode-cn.com/problems/remove-invalid-parentheses/",false},
        {"滑动窗口最大值", "https://leetcode-cn.com/problems/sliding-window-maximum/",false},
        {"二叉树的最近公共祖先", "https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/",false},
        {"从前序与中序遍历序列构造二叉树", "https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/",false},
        {"二叉树的直径", "https://leetcode-cn.com/problems/diameter-of-binary-tree/",false},
        {"二叉树的所有路径", "https://leetcode-cn.com/problems/binary-tree-paths/",false},
        {"二叉树的锯齿形层序遍历", "https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/",false},
        {"对称二叉树", "https://leetcode-cn.com/problems/symmetric-tree/",false},
        {"二叉树的最小深度", "https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/",false},
        {"平衡二叉树", "https://leetcode-cn.com/problems/balanced-binary-tree/",false},
        {"二叉树的层次遍历 II", "https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/",false},
        {"二叉树的右视图", "https://leetcode-cn.com/problems/binary-tree-right-side-view/",false},
        {"翻转二叉树", "https://leetcode-cn.com/problems/invert-binary-tree/",false},
        {"填充每个节点的下一个右侧节点指针", "https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/",false},
        {"填充每个节点的下一个右侧节点指针 II", "https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/",false},
        {"路径总和", "https://leetcode-cn.com/problems/path-sum/",false},
        {"路径总和 II", "https://leetcode-cn.com/problems/path-sum-ii/",false},
        {"路径总和 III", "https://leetcode-cn.com/problems/path-sum-iii/",false},
        {"二叉树展开为链表", "https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/",false},
        {"相同的树", "https://leetcode-cn.com/problems/same-tree/",false},
        {"对称二叉树", "https://leetcode-cn.com/problems/symmetric-tree/",false},
        {"二叉树的最大宽度", "https://leetcode-cn.com/problems/maximum-width-of-binary-tree/",false},
        {"二叉树的垂序遍历", "https://leetcode-cn.com/problems/vertical-order-traversal-of-a-binary-tree/",false},
        {"二叉树的前序遍历", "https://leetcode-cn.com/problems/binary-tree-preorder-traversal/",false},
        {"二叉树的中序遍历", "https://leetcode-cn.com/problems/binary-tree-inorder-traversal/",false},
        {"二叉树的后序遍历", "https://leetcode-cn.com/problems/binary-tree-postorder-traversal/",false},
        {"二叉树的层平均值", "https://leetcode-cn.com/problems/average-of-levels-in-binary-tree/",false},
        {"二叉树的层序遍历", "https://leetcode-cn.com/problems/binary-tree-level-order-traversal/",false},
        {"二叉树的层序遍历 II", "https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/",false},
        {"二叉树的右视图", "https://leetcode-cn.com/problems/binary-tree-right-side-view/",false},
        {"二叉树的所有路径", "https://leetcode-cn.com/problems/binary-tree-paths/",false},
        {"二叉树的锯齿形层序遍历", "https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/",false},
        {"二叉树的最小深度", "https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/",false},
        {"二叉树的最大深度", "https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/",false},
        {"二叉树的直径", "https://leetcode-cn.com/problems/diameter-of-binary-tree/",false},
        {"二叉树的层平均值", "https://leetcode-cn.com/problems/average-of-levels-in-binary-tree/",false},
        {"二叉树的垂序遍历", "https://leetcode-cn.com/problems/vertical-order-traversal-of-a-binary-tree/",false},
        {"二叉树的前序遍历", "https://leetcode-cn.com/problems/binary-tree-preorder-traversal/",false},
        {"二叉树的中序遍历", "https://leetcode-cn.com/problems/binary-tree-inorder-traversal/",false},
        {"二叉树的后序遍历", "https://leetcode-cn.com/problems/binary-tree-postorder-traversal/",false},
        {"二叉树的层序遍历", "https://leetcode-cn.com/problems/binary-tree-level-order-traversal/",false},
        {"二叉树的层序遍历 II", "https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/",false},
        {"二叉树的右视图", "https://leetcode-cn.com/problems/binary-tree-right-side-view/",false},
        {"二叉树的所有路径", "https://leetcode-cn.com/problems/binary-tree-paths/",false},
        {"二叉树的锯齿形层序遍历", "https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/",false},
        {"二叉树的最小深度", "https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/",false},
        {"二叉树的最大深度", "https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/",false},
        {"二叉树的直径", "https://leetcode-cn.com/problems/diameter-of-binary-tree/",false},
        {"二叉树的层平均值", "https://leetcode-cn.com/problems/average-of-levels-in-binary-tree/",false},
        {"二叉树的垂序遍历", "https://leetcode-cn.com/problems/vertical-order-traversal-of-a-binary-tree/",false},
    };

    std::ifstream file(filePath);

    if (file.is_open()) {
        // 获取文件大小
        file.seekg(0, std::ios::end);
        std::streampos fileSize = file.tellg();
        file.seekg(0, std::ios::beg);

        if (fileSize > 0) {
                json j;
                file >> j;
                for (size_t i = 0; i < questions.size(); ++i) {
                    if (j["questions"].size() > i) {
                        questions[i].isSolved = j["questions"][i]["isSolved"];
                    }
                } 
        } 
		else {
            // 文件为空，初始化并保存默认题库
            saveQuestionDatabase(questions, filePath);
        }

        file.close();
    } else {
        // 文件不存在，初始化并保存默认题库
        saveQuestionDatabase(questions, filePath);
    }

    return questions;
}

// 将题库状态保存到文件
void saveQuestionDatabase(const std::vector<Question>& questions, const std::string& filePath) {
    json j;
    for (const auto& q : questions) {
        j["questions"].push_back({{"title", q.title}, {"url", q.url}, {"isSolved", q.isSolved}});
    }

    std::ofstream file(filePath);
    if (file.is_open()) {
        file << j.dump(4); // 格式化输出
        file.close();
    }
}

// 随机选择一个未解决的题目，并返回其索引
size_t getRandomUnsolvedQuestionIndex(const std::vector<Question>& questions) {
    if (questions.empty()) {
        throw std::runtime_error("题库为空");
    }

    size_t index;
    do {
        index = rand() % questions.size();
    } while (questions[index].isSolved);

    return index;
}