#include <iostream>
#include <algorithm>
#include "mylist.hpp"
namespace mylib {
    bool num_starts_with_three(int n){
        
        while(n>9){
            n/=10;
        }
        if (n==3) return 1;
        return 0;
    }
    bool is_prime(int n){
        if (n<2){
            return 0;
        }
        for(int i = 2; i <= sqrt(n);i++){
            if (n%i == 0){
                return 0;
            }
        }
        return 1;
    }
    void fwdlist::push_back(int _val){
        Node* p = new Node(_val);
        size++;
        if (is_empty()){
            first = p;
            last = p;
            return;
        }
        last->next = p;
        last = p;
    }
    void fwdlist::print(){
    Node* curr = first;
    while(curr!=nullptr){
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    } 
    bool fwdlist::is_empty(){
        return first == nullptr;
    }
    void fwdlist::sort_one(){
            for(int i = 0;i<size;i++){
                Node* curr = first;
                while(curr != nullptr){
                Node* currnext = curr -> next;
                if (currnext!=nullptr){
                    if (std::abs(curr->val)%10 < std::abs(currnext->val)%10)
                    { 
                        std::swap (curr->val,currnext->val);
                    }
                }
                curr = currnext;
                }
            }   
        }
    void fwdlist::delete_next(Node* curr){
        if(curr->next->next==nullptr) {
            curr->next=nullptr;
            last = curr;
            size--;
            delete curr;
        }
        else{
            Node* tmp = curr->next;
            curr->next=tmp->next;
            delete tmp;
            size--;
        }
    }
    void fwdlist::duplicate(Node* curr){
        Node* newelem = new Node(curr->val);
        newelem -> next = curr->next;
        if (curr->next == nullptr){
            last = newelem;
        }
        curr->next = newelem;
        size++;
    }
    void fwdlist::edit(){
        Node* curr = first;
        while((curr->next!=nullptr)){
            if((curr->next->val % 2 == 0) && (curr->next->val!=2)){
                delete_next(curr);
            }
            else{
                curr=curr->next;
            }
        }
        curr = first;
        if ((curr->val%2==0)&&(curr->val!=2)){
            first = curr->next;
            delete curr;
        }
        curr = first;
        while (curr != nullptr)
        {
            if (is_prime(curr->val)){
                duplicate(curr);
                curr=curr->next;
            }
            curr = curr->next;
        }
    }
    bool fwdlist::check_condition(){
        Node* curr = first;
        while(curr!=nullptr){
        if(num_starts_with_three(curr->val)){
            return 1;
            }
            curr = curr->next;
        }
        return 0; //чисел, начинающихся на три нет 
    }
}
