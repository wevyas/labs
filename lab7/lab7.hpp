#pragma once
#include <vector>
namespace lab7{
    void printInt(int a); // тестовая функция
    std::vector<std::vector<int>> makeMatrOfSize(int n);
    void printMatr(const std::vector<std::vector<int>>& mas, int n);
    bool containsEights(std::vector<int> mas, int n);
    bool checkCondition (std::vector<std::vector<int>> mas, int n);
    void sortIfHasEights(std::vector<std::vector<int>>& mas,int n);
}
