#include <iostream>
#include "lab7.hpp"
#include <vector>
#include <algorithm>
#include <limits.h>

namespace lab7{

    void printint(int a){
        std::cout<< a;
    }
    std::vector<std::vector<int>> makeMatrOfSize(int n){
        std::vector<std::vector<int>> ans;
        std::vector<int> tmpvec;
        for(int i = 0; i<n; i++){
            int tmp;
            tmpvec.reserve(n);
            std::cout << "Введите строку " << i << ": ";
            for(int j = 0; j<n; j++){
                std::cin >> tmp;
                tmpvec.push_back(tmp);
            } 
            ans.push_back(tmpvec);
            tmpvec.clear();
        }
        ans.resize(n);
    return ans;
    }

    void printMatr(const std::vector<std::vector<int>>& mas, int n) {
        for (int i = 0;i<n;i++){
            for (int j = 0;j<n;j++){
                std::cout << mas[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    bool numHasEight(int n){
        while (n>0){
            if (n%10 == 8){
                return 1;
            }
            n/=10;
        }
        return 0;
    }

    bool containsEights(std::vector<int> mas, int n){
    for (int i = 0;i<n;i++){
        if (numHasEight(mas[i])){
            return 1;
        }
    }

    return 0;
    }
        
    bool checkCondition (std::vector<std::vector<int>> mas, int n){
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for (int i = 0; i<n;i++){
            for(int j = 0; j<n; j++){
                maxi = std::max(maxi,mas[i][j]);
                mini = std::min(mini,mas[i][j]);
            }
        }

        return ((maxi+mini)==0);
    }

    void sortIfHasEights(std::vector<std::vector<int>>& mas,int n){
        for(int i = 0; i<n; i++){
            if(containsEights(mas[i],n) ){
                std::sort(mas[i].begin(),mas[i].end());
            }
        }
    }
}