#include<iostream> 
#include <fstream>
#include <time.h>
#include <vector>
using namespace std; 

int c=0;

struct  node_pb { 
	 
	string fjal; 
	node_pb *left; 
	node_pb *right; 
	int niv; 
}; 

int get_niv(node_pb *N) 
{ 
	if (N == NULL) 
		return 0; 
	return N->niv; 
} 

int max(int a, int b) { 
	return (a > b)? a : b; 
} 

node_pb* newnode_p(const string& s) { 
	node_pb* node_p = new node_pb{s,nullptr,nullptr,1}; 
	return(node_p); 
} 
 
node_pb *rightRotate(node_pb *y) { 
	node_pb *x = y->left; 
	node_pb *T2 = x->right; 
	x->right = y; 
	y->left = T2; 
	y->niv = max(get_niv(y->left),get_niv(y->right)) + 1; 
	x->niv = max(get_niv(x->left),get_niv(x->right)) + 1; 	
	return x; 
} 


node_pb *leftRotate(node_pb *x) 
{ 
	node_pb *y = x->right; 
	node_pb *T2 = y->left; 
	y->left = x; 
	x->right = T2; 
	x->niv = max(get_niv(x->left),	 
					get_niv(x->right)) + 1; 
	y->niv = max(get_niv(y->left), 
					get_niv(y->right)) + 1; 
	return y; 
} 


int getBalance(node_pb *N) 
{ 
	if (N == NULL) 
		return 0; 
	return get_niv(N->left) - get_niv(N->right); 
} 


node_pb* insert(node_pb* node_p, const string& fjal) 
{ 	
	if (node_p == NULL){
		
		return(newnode_p(fjal)); }

	if (fjal < node_p->fjal) 
		node_p->left = insert(node_p->left, fjal); 
	else if (fjal > node_p->fjal) 
		node_p->right = insert(node_p->right, fjal); 
	else 
		
		return node_p; 
	node_p->niv = 1 + max(get_niv(node_p->left), 
						get_niv(node_p->right)); 
	int balance = getBalance(node_p); 
	if (balance > 1 && fjal < node_p->left->fjal) 
		return rightRotate(node_p); 
	if (balance < -1 && fjal > node_p->right->fjal) 
		return leftRotate(node_p); 
	if (balance > 1 && fjal > node_p->left->fjal) 
	{ 
		node_p->left = leftRotate(node_p->left); 
		return rightRotate(node_p); 
	} 
	if (balance < -1 && fjal < node_p->right->fjal) 
	{ 
		node_p->right = rightRotate(node_p->right); 
		return leftRotate(node_p); 
	} 
	return node_p; 
} 


bool gjendet(node_pb *root, const string& s){
	node_pb *tmp = root;
	while(tmp!=NULL){
		if(tmp->fjal == s) return true;
                if(s<tmp->fjal) {
                    if (tmp->left == NULL)
                    {
                        return false;
                    }else tmp =tmp->left;
                    
                }else{
                    if (tmp->right == NULL)
                    {
                        return false;
                    }else tmp =tmp->right;
                }
            }
		return false;
	}



int main() 
{ 
	
	vector<string> sv;
    int length = 1000000;
    sv.reserve(length);
    fstream file("teksti.txt",ios::in);
    string fjal;
        if (file.is_open())
        {     
        for(int i=0;i<length && file>>fjal;i++){
            sv.push_back(fjal);
			
        }
	node_pb *root = new node_pb{sv[0],nullptr,nullptr,0}; 
	clock_t start, end;
    double cpu_time_used;	
    start = clock();
    cout<<"Programi nisi"<<endl;
    
    for(int i=1;i<length;i++)
    {
		if(!gjendet(root,sv[i]))
		{
        	insert(root,sv[i]);
		}	
    }
	
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    cout<<endl;
    cout<<"Koha exe: "<<cpu_time_used*1000<<" milisekonda"<<endl;
	return 0; 
}
} 


