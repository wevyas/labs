#pragma once
namespace mylib{
    bool num_starts_with_three(int n);
    bool is_prime(int n);
    struct Node{
        int val;
        Node* next = nullptr;
        Node (int _val) : val(_val) , next(nullptr) {};
    };
    class fwdlist{
        public:
            int size = 0;
            Node* first = nullptr;
            Node* last = nullptr;    
            bool is_empty();
            void push_back(int _val);
            void print();
            void sort_one();
            void delete_next(Node* curr);
            void duplicate(Node* curr);
            void edit();
            bool check_condition();
    };
}
