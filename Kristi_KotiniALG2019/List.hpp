#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <regex>
#include <chrono>

using namespace std;

struct node {
    string fjal;
    struct node *next;
};

class List{
    private:
        node *koka ;
        int i =1;
    public:
        List(const string &s){
            koka = new node{s,nullptr};

        }
        void shto(const string &s){
            koka = new node{s,koka};
            i++;
        }
        void kerko_shto(const string &s){
            node *tmp = koka;
            while(tmp!=NULL){
                if(tmp->fjal == s) return;
                tmp = tmp->next; 
            }
            shto(s);
        }
        int get_nr_fjalesh(){
            return i;
        }
    
};


    
    
    


