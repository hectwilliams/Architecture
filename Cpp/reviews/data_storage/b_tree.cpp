/*

  Purpose: Use B_Tree to store list of name.

  Assumptions: Each page can only support 5 records.

  Author : HW 

*/


#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <utility>

const int PAGESIZE = 5;

template <typename T>
struct RefNode {
    int id;
    T value; 
    std::array< RefNode<T>*, 5 >  *ref;
    int n_active; 
};

template <typename T>
using RefList = std::array< RefNode<T>*, 5 >;

template <typename T>
class BTree {
    RefList<T> *root;
public:

    BTree() {root = nullptr;}
    
    void insert(T val) {
        if (!root) {
            // first insert , create root node 
            root = new RefList<T>{};
            (*root)[0] = new RefNode<T>{val, val, nullptr, 1}; // parent list's node
            (*root)[0]->ref = new RefList<T>{}; // parent node connection to child list
            (*((*root)[0]->ref ))[0]  = new RefNode<T>{val, val, nullptr, 1};// child node 
            for( int i = 1 ; i < PAGESIZE; i++){
                // null unused nodes in both parent and child 
                (*root)[i] = nullptr; // other parent list nodes
                (*((*root)[0]->ref ))[i]  = nullptr; // other child list nodes 
            }
        }
    }
    
    bool find(T val) {
        RefList<T> *parent = root;
        RefList<T> *child = nullptr;
        RefNode<T> *child_sel_node = nullptr;
         
        // search array for lowest distance (hamming)
        for (int i = 0; (i < PAGESIZE)  ; i++) {
            if ((*parent)[i] == nullptr) {
                // stop search
                break;   
            }
            if ((*parent)[i]->value > val) {
                // parent node found node to continue search
                break;
            } 
            child = (*parent)[i]->ref;
        }
        
        while (child /* RefList*/) {
            for (int i =0; i < PAGESIZE; i++) {
                if ((*child)[i]->value == val)
                    return true;
                if ((*child)[i]->value <= val ) {
                    child_sel_node = (*child)[i]; // select node 
                }
                child = child_sel_node->ref; // returns next list 
            }
        }
        
        return false;
    }
};

int main() {
    
    std::vector<int> data;
    
    for(int i =0; i < 5; i++) {
        data.push_back(i);
    }
    
    BTree<int> tree;
    tree.insert(1);
    bool ret = tree.find(-1);
    
    std::cout << ret << '\n';
    
    return 0;
  
}
         




  

