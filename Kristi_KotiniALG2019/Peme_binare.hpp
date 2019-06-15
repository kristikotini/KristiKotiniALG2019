#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <regex>
#include <chrono>
using namespace std;

struct node_p {
    string fjal;
    struct node_p *left;
    struct  node_p *right;
    
};

class Peme_binare{
private:
        node_p *rrenja ;
        int i =1;
    public:
        Peme_binare(const string &s){
            rrenja = new node_p{s,nullptr,nullptr};
        }
        
        void kerko_shto(const string &s){
            node_p *tmp = rrenja;
            while(tmp!=NULL){
                if(tmp->fjal == s) return;
                if(s<tmp->fjal) {
                    if (tmp->left == nullptr)
                    {
                        tmp->left = new node_p {s,nullptr,nullptr};
                        i++;
                        return;
                    }else tmp =tmp->left;
                    
                }else{
                    if (tmp->right == nullptr)
                    {
                        tmp->right = new node_p {s,nullptr,nullptr};
                        i++;
                        return;
                    }else tmp =tmp->right;
                }
            }
            
        }
        int get_nr_fjalesh(){
            return i;
        }

};