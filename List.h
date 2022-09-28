#include<iostream>
class list{
    private:
        struct info{
            int data=123;
        };
    public:
        list *next=nullptr;
        list *prev=nullptr;
        list *head=nullptr;
        list *current=nullptr;
        list *last=nullptr;
        info *data1;
        
        void make_new();
        void get_info();
        void get_info_to_index(int index);
        void put_info();
        void add_to_end();
        void add_to_beg();
        void del_last();
        void del_first();
        void add_to_index(int index);
        void del_to_index(int index);
        int get_len();
        void del_all();
        void replace_to_index(int index);
        bool check();
        void view_all();
};
int compare_list(list *A, list *B);