#include <iostream>
#include "mylist.hpp"
int main(){    
    /*
    void sort_this(){
         Node* curr = first;
         while(curr != nullptr){
            Node* currnext = curr -> next;
            if (currnext!=nullptr){
                if (std::abs(curr->val)%10 < std::abs(currnext->val)%10)
                {
                    std::swap (curr->val,currnext->val);
                    Node* curr = first;
                    Node* currnext = curr -> next;
                }
            }
         }   
        }
    
    */
   
    mylib::fwdlist lis;
    int n;
    std::cout << "Введите число элементов в списке: ";
    std::cin >> n;
    std::cout << "Введите список: ";
    for(int i = 0; i<n;i++){
        int tmp;
        std::cin >> tmp;
        lis.push_back(tmp);
    }
    std::cout << "Изначальный список: ";
    lis.print();
    std::cout<<"\n";
    if (lis.check_condition()){
        std::cout << "нашли число, начинающееся на три.\n";
        lis.edit();
    }
    else{
        std::cout << "не нашли чисел, начинающихся на три.\n";
        lis.sort_one();
    }
    std::cout<<"Итоговый список: ";
    lis.print();
}
