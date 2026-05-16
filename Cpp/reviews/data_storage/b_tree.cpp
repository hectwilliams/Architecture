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
    T value; 
    std::array< RefNode<T>*, 5 >  *ref;
    int n_active; 
};

template <typename T>
using RefList = std::array< RefNode<T>*, 5 >;
template <typename T>
using SearchTuple = std::pair<RefList<T>*, int>;

template <typename T>
class BTree {
    
    RefList<T> *root;
    
    /**
     * View pages in RefList
     *
     * @param list Pointer to RefList  
     */
    void view_list(RefList<T> *list) {
        for (int i = 0; i < PAGESIZE &&  (*list)[i] !=nullptr ; i++) {
            std::cout << "[" << (*list)[i]->value << "]";
        }
        std::cout << '\n';
    }
    /**
     * Update leaf RefLists 
     *  
     * @param parent_list Parent RefList 
     * @param index Location of node in RefList 
     * @param target Value to add to leaf layer in tree 
     */
    void leaf_update(RefList<T> *parent_list, int index, T target) {
        RefList<T> * node_list;
        RefList<T> * child_list;
        int n_active_parent_pg = 0;
        int eff_index;
        
        if(!parent_list) {
            // Parent List not received
            return;
        }
        
        // number of active parent pages 
        while((*parent_list)[n_active_parent_pg++]);
        n_active_parent_pg--; 
            
        if(n_active_parent_pg < PAGESIZE){
            // effective index (parent RefList)
            switch(index) {
                case -1:
                    eff_index = 0;
                    break;
                case PAGESIZE:
                    eff_index = 4;
                    break;
                default:
                    eff_index = index; 
            }
            
            // save child page which active parent pages reference 
            child_list = (*parent_list)[0]->ref;
            
            // check if target in-between
            if ((*parent_list)[eff_index]) {
               if (target >=  (*parent_list)[eff_index]->value  ) {
                   eff_index += 1;
               }
            }
            
            if ((*parent_list)[eff_index] == nullptr ) {
               // add childpage and parent page to child and parent list, respectively
            } else if (eff_index + 1 < PAGESIZE){
                // shift pages to the right in front of page at eff_index position 
                for (int i = PAGESIZE-1; i > eff_index ; i--) {
                    // shift and free page for next write operation 
                    (*parent_list)[i] =  (*parent_list)[i - 1];
                    (*child_list)[i] =  (*child_list)[i - 1];
                }
            }
            
            // write new page to parent list 
            RefNode<T> *new_parent_page = new RefNode<T>{target, nullptr, 0 };
            (*parent_list)[eff_index] = new_parent_page;
            
            // point new parent page to child list 
            new_parent_page->ref =  child_list;
            
            // write child page
            RefNode<T> *new_child_page = new RefNode<T>{target, nullptr, 0 };
            (*child_list)[eff_index] = new_child_page; 
            
            // verify
            view_list(parent_list);
            view_list(child_list);
            std::cout << "----checked\n";

                
        } else {
            std::cout << "NOT READY" << '\n';
        }
        
    }
    
public:

    BTree() {root = nullptr;}
    
    /** 
    * Search/traverse b-tree. 
    *  
    * @param val Value to insert into b-tree.
    * 
    */
    void insert(T val) {
        if (!root) {
            // first insert , create root node 
            root = new RefList<T>{};
            (*root)[0] = new RefNode<T>{ val, nullptr, 1}; // parent list's node
            (*root)[0]->ref = new RefList<T>{}; // parent node connection to child list
            (*((*root)[0]->ref ))[0]  = new RefNode<T>{val, nullptr, 1};// child node 
            for( int i = 1 ; i < PAGESIZE; i++){
                // null unused nodes in both parent and child 
                (*root)[i] = nullptr; // other parent list nodes
                (*((*root)[0]->ref ))[i]  = nullptr; // other child list nodes 
            }
        } else {
            RefList<T> *parent = root;
            RefNode<T> *node = nullptr;
            int parent_list_null_index = PAGESIZE ;
            SearchTuple<T> tuple;
            RefList<T> list = (*parent);
            
            view_list(parent);

            // set farthest null index
            while(list[--parent_list_null_index]);
            
            // ^edge check 
            if (val < list[0]->value) {
                // update first page with new ref window bound
                if (parent_list_null_index != 4) {
                    // parents nodes are full
                } else {
                    tuple = tree_traveral(val, -1);
                }

            } else if ( parent_list_null_index !=PAGESIZE-1 && val > list[PAGESIZE-1]->value  ) {
                // update last page with new ref window bound 
                tuple = tree_traveral(val, 1);
            } else {
                // quiet, value within ref window bound
                tuple = tree_traveral(val, -1);
            }
            
            // use information returned from tree_traversal to update leaf nodes 
            leaf_update(tuple.first, tuple.second, val);
            
        }
    }
    
    /** 
    * Search/traverse b-tree. 
    * 
    * @param val Target of search.
    * @param end_select  Select end to modify (-1 (not change) 0 (left edge) 1(right edge)).
    */
    SearchTuple<T> tree_traveral(T val, T end_select = -1) {
        RefList<T> *node_list = root; /* RefList*/
        RefList<T> *prev_node_list;; /* Parent of previous node*/
        RefNode<T> *node ;
        int i;
        
        if (!node_list) {
            return {nullptr, i};    
        }
    
        prev_node_list= root;
        
        while (node_list /* RefList*/) {
            
            // for (i =0; i < PAGESIZE; i++) {
                node = (*node_list)[i]; // node in current RefList; at least one node exist in RefLists
                
                if (!node) {
                    // return immediately, provide the parent list and index to caller 
                    return {prev_node_list, i};
                } else if ( val <= node->value ) {
                    if (node->ref == nullptr) {
                        // target found
                        if (val == node->value)
                            return {prev_node_list, i + 1};
                        // target not found but target's leaf locality returned for differing features
                        if (val < node->value)
                            return {prev_node_list, i - 1};
                    } else {
                        prev_node_list = node_list; 
                        node_list = node->ref;
                        i = 0; // reset i
                        continue;          
                    }
                } else {
                    // nonleaf nodes 
                    // if (  (node->ref != nullptr)) 
                    // TODO: if i traverse deeper how do i know which edge to update, overwriting edges is not the correct way!
                    // if (end_select == 0 && i == 0) {
                    //     // update first page
                    //     node->value = val;
                    // } else if (end_select  == 1 && i == PAGESIZE - 1 ) {
                    //     // update last page
                    //     node->value = val;                        
                    // }
                    // search will continue to leafs
                    // break; 
                    // }
                }
            
            i += 1;
            if (i == PAGESIZE) {
                i = 0;
                prev_node_list = node_list; 
                // If search fails, search will continue down from last page
                node_list = node->ref; 
            }
            
        }
        return {prev_node_list, i } ; 
    }
    
    /* Call find_ and return boolean of search*/
    /** 
    * Notify caller if value was find. 
    *  
    * @param val Target of search.
    */
    bool find(T val) { 
        SearchTuple<T> ret = this->tree_traveral(val);
        if(ret.second == -1 || ret.second == PAGESIZE) {
            return false; 
        }
        return true;
    }
};

int main() {
    std::vector<int> data;
    
    for(int i =0; i < 5; i++) {
        data.push_back(i);
    }
    
    BTree<int> tree;
    tree.insert(1);
    tree.insert(-1);
    tree.insert(100);
    tree.insert(-2);
    tree.insert(69);

    tree.insert(50);

    // bool ret = tree.find(-1);
    // std::cout << ret << "\n";
    
    return 0;
  
}
         





