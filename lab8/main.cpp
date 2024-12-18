#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
std::string constructSetString(std::set<char> letter){
    std::string ans = "(";
     for (char i: letter){
        ans = ans + i + ", ";
    }
    if(letter.size()){
    ans.pop_back();
    ans.pop_back();
    }
    ans += ")";
    return ans;
}
bool checkPalindrome(std::string str){
        if(str.size()>2){
            std::string rev (str.rbegin(), str.rend());
            if (str==rev){
                return 1;
            }
        }
        return 0;
    }
std::set<char> findAllUniqueLetters(std::string str){
        std::set<char> ans;
        std::set<char> ignore = {'\'', '\"', ',', '.', '!', '?', '-'};
        for(char i: str){
            if (ignore.count(i) == 0){
                ans.insert(i);
            }
        }
        return ans;
    }
int countVowels(std::string str, std::set<char>& vowels){
    double ans = 0.0;
    for (char i: str){
        if (vowels.count(i)){
            ans+=1;
        }
    }
    return ans;
}
    bool compareByAmountofVowels(std::string a, std::string b){
        std::set vowels = {'e','y','u','i','o','a'};
        double a1 = countVowels(a, vowels);
        double b1 = countVowels(b, vowels);
        if((a1>0)&&(b1>0)){
            return (a.size()/a1) < (b.size()/b1);
        }
        else if((a1==0)&&b1){
            return 1;
        }
        else if((a1==0)&&(b1==0)){
            return 1;
        }
        return 0;
        }
int main(){
    std::ifstream file ("a.txt");
    char find;
    std::cout << "Введите букву на которую должно начинаться слово: ";
    std::cin >> find;
    std::vector<std::string> mas;
    mas.reserve(2000);
    std::string tmp;
    std::vector<std::string> foundwords;
    while (!file.eof())   {
        file >> tmp; 
        mas.push_back(tmp);
    }
    int n = mas.size();
    
    for (int i = 0; i<n; i++){
        if (mas[i][0] == find){
            foundwords.push_back(mas[i]);
        }
    }
    n = foundwords.size();
    foundwords.erase(std::unique(foundwords.begin(),foundwords.end()),foundwords.end()); 
    if(n){
        std::cout << "Найденные слова на букву '" << find << "': ";
        std::sort(foundwords.begin(),foundwords.end(), [](std::string& a, std::string& b){return a.size() < b.size();});
        for (std::string& i : foundwords){
            std::cout << i << " ";
        }
    }
    else{
        std::cout << "Не нашлось ни одного слова на букву " << find << " :( \n" ;
    }
    std::cout << "\n2. ";
    file.close();
    mas.clear();
    file.open("b.txt");
    while (!file.eof()){
        file >> tmp;
        mas.push_back(tmp);
    }
    std::set vowels = {'e','y','u','i','o','a'};
    bool haspalindromes = 0;
    for (std::string i : mas){
        if (checkPalindrome(i)){
            haspalindromes = 1;
            break;
        }
    }
    if (haspalindromes){
        std::cout << "Есть палиндром! Вот что получилось: ";
        std::sort(mas.begin(),mas.end(), compareByAmountofVowels);
        for (std::string i : mas){
            std::cout << i << " ";
        }
    }
    else {
        for (int i = 0; i<mas.size();i++){
            for (int j = 0; j<mas[i].size();j++){
                if (vowels.count(mas[i][j])){
                    mas[i].erase(mas[i].begin() + j);
                    j--;
                }
                else{
                    mas[i].insert(j,1,mas[i][j]);
                    j++;
                }
            }
        }
        std::sort(mas.begin(),mas.end());
        std::cout << "Палиндрома нет :( , получилось вот что: ";
        for(std::string i : mas){
            std::cout << i << " ";
        }
    }
    file.close();
    mas.clear();
    file.open("input.txt");
    std::ofstream out("output.txt");
    
    while(!file.eof()){
        file >> tmp;
        mas.push_back(tmp);
    }
    mas.shrink_to_fit();
    std::set signs = {'\'', '\"', ',', '.', '!', '?', '-'};
    for(int i = 0; i < mas.size(); i++){
        std::set<char> found = findAllUniqueLetters(mas[i]);
        std::string ins = constructSetString(found);
        int l = found.size();
        if (l>7){
            int where = mas[i].size()-1;
            for (int j = mas[i].size() -1 ; j>0;j--){
                if(signs.count(mas[i][j])==0){
                    where = j;
                    break;
                }
            }
            mas[i] = std::string(mas[i].begin(), mas[i].begin() + where+1) + ins + std::string(mas[i].begin()+where+1,mas[i].end());
            mas[i] = "!!" + mas[i] + " ";
        }
        else{
            mas[i]+=' ';
        }
        out << mas[i];
        
    }
    return 0;
}
