#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <regex>
#include <chrono>
#include <vector>
using namespace std;

struct node_h {
    string fjal;
    struct node_h *next;
};
class Hash_table{
    private:
        vector<node_h *> hv{200,nullptr} ;
        int i =1;
    public:
        Hash_table(){}
        
        int hash(const string &s){
            int sum = 0;
            for(int i= 0;i<s.length();i++){
                sum+=s[i];
            }
            return sum%200;
        }

        void kerko_shto(const string &s){
            int index = hash(s);
            if(hv[index]==nullptr){
             hv[index] = new node_h{s,nullptr};
             i++;
             return;
            }
            node_h *tmp = hv[index];
            while(tmp!=nullptr){
                if(tmp->fjal == s) return;
                tmp= tmp->next;
            }
            hv[index] = new node_h{s,hv[index]};
            i++;
        }
        int get_nr_fjalesh(){
            return i;
        }

};