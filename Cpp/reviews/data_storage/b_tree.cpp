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
#include <stack>
const int PAGESIZE = 5;

template <typename T>
struct RefNode {
    T value; 
    std::array< RefNode<T>*, 5 >  *ref;
    int count; 
};

template <typename T>
using RefList = std::array< RefNode<T>*, 5 >;
template <typename T>
using SearchTuple = std::pair<RefList<T>*, int>;

/**
 *  Overwritte node value
 * 
 * @param node RefNode
 * @param new_value Integer 
 */
template<typename T>
void wr_node(RefNode<T> *node, T new_value);

/**
 *  Determines if target page reside in list. If it does, increment the count. 
 * 
 * @param page_list RefList
 * @param index Index of the analysis page  
 * @param target Target of interest
 */
template<typename T>
bool page_exist(RefList<T> *page_list, T target) ;

/**
 * Shift page list to the right from index
 * 
 * @param list Pointer to list
 * @param Integer index 
 */
template<typename T>
void shift_list(RefList<T> *list, int index) ;


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
        bool target_in_tree;
        
        if(!parent_list) {
            // Parent List not received
            return;
        }
        
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
        
        // number of active parent pages 
        while((*parent_list)[n_active_parent_pg++]);
        n_active_parent_pg--; 
            
        target_in_tree = false;
        if(n_active_parent_pg < PAGESIZE){
            
            // save child page which active parent pages reference 
            child_list = (*parent_list)[0]->ref;
            
            // check if target exists 
            target_in_tree |= page_exist<T>(parent_list, target);
            target_in_tree |= page_exist<T>(child_list, target);
            if (target_in_tree) {
                // target found in b-tree. Update count attribute and return
                return;
            }

            // check if target in-between
            if ((*parent_list)[eff_index]) {
               if (target >=  (*parent_list)[eff_index]->value  ) {
                   eff_index += 1;
               }
            }
            
            // shift list ( if needed :) )
            shift_list(parent_list, eff_index);
            shift_list(child_list, eff_index);

 
            // write new page to parent list 
            RefNode<T> *new_parent_page = new RefNode<T>{target, nullptr, 1 };
            (*parent_list)[eff_index] = new_parent_page;
            
            // point new parent page to child list 
            new_parent_page->ref =  child_list;
            
            // write child page
            RefNode<T> *new_child_page = new RefNode<T>{target, nullptr, 1 };
            (*child_list)[eff_index] = new_child_page; 
            
            // verify
            view_list(parent_list);
            view_list(child_list);
            std::cout << "----checked\n";

        } else {
            child_list = (*parent_list)[0]->ref;
            view_list(parent_list);
            view_list(child_list);
            
            RefNode<T> *parent_node = (*parent_list)[eff_index - 1];
            RefNode<T> *child_node = (*child_list)[eff_index - 1];
            
            bool found = false;
            found = page_exist<T>(parent_list, target) ;
            found |= page_exist<T>(child_list, target);
            if ( found  ) {
                std::cout << child_node->count ;
                return;   
            }
            
            if (eff_index == 4) {
                // page cannot be added to list's end
                // if (child_node->) {
                    
                // }
            } else if (eff_index == 0) {
                // page cannot be added to lis'ts front ( upper layers updated)
            }
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
            int n_active_pages = 0 ;
            SearchTuple<T> tuple = {nullptr, 0};
            RefList<T> list = (*parent);
            
            view_list(parent);

            // set farthest null index
            for (int i = 0 ; i < PAGESIZE; i++)
                n_active_pages += +( list[i] != nullptr);
            
            // ^edge check 
            if (n_active_pages == PAGESIZE) {
                if (val < list[0]->value) {
                    // target < list's first page
                    tuple = tree_traveral(val, 0);
                } else if ( val > list[PAGESIZE-1]->value ) {
                    // target > all pages 
                    tuple = tree_traveral(val, 1);
                } else {
                    // handles other cases (e.g. equal target)
                    tuple = tree_traveral(val, -1);
                    std::cout << tuple.first << "\n";
                }
            } else if (!tuple.first){
                // search without modifying parent pages 
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
        int i = 0;
        bool overwrite_edge;
        std::stack<RefList<T>*> stack{};
        
        if (!node_list) {
            return {nullptr, i};    
        }
    
        prev_node_list= root;
        
        while (node_list /* RefList*/) {
                
                node = (*node_list)[i]; // node in current RefList; at least one node exist in RefLists
                
                if (!!node ) {
                    if ( (i == 0 && end_select == 0)  || (i == PAGESIZE-1 && end_select == 1) ) {
                        overwrite_edge = true;
                    } else {
                        overwrite_edge= false;
                    }
                }
                
                if (!node) {
                    // return immediately, provide the parent list and index to caller 
                    return {prev_node_list, i};
                } else if ( val <= node->value ) {
                    if (node->ref == nullptr) {
                        // leaf 
                        if (val == node->value) {
                            // target found
                            return {prev_node_list, i + 1};
                        }
                        if (val < node->value) {
                            // target not found but target's leaf locality returned for differing features
                            return {prev_node_list, i - 1};
                        }
                    } else {
                        // non-leaf
                        prev_node_list = node_list; 
                        node_list = node->ref;
                        i = 0; // reset i
                        continue;          
                    }
                }
                
                if (overwrite_edge && node->ref){
                    // update either end of page ( supports insert method)
                    wr_node(node, val);
                }
                
            i += 1;
            if (i == PAGESIZE) {
                i = 0;
                stack.push(node_list);
                prev_node_list = node_list; 
                // If search fails, search will continue down from last page
                node_list = node->ref; 
            }
            
        }
        
        stack.pop(); // pop off lowest RefList
        return { stack.top(), PAGESIZE } ; 
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

template<typename T>
void shift_list(RefList<T> *list, int index) {
    if ((*list)[index] == nullptr ) {
       // add childpage and parent page to child and parent list, respectively
    } else if (index + 1 < PAGESIZE){
        // shift pages to the right in front of page at eff_index position 
        for (int i = PAGESIZE-1; i > index ; i--) {
            // shift and free page for next write operation 
            (*list)[i] =  (*list)[i - 1];
        }
    }
}

template<typename T>
void wr_node(RefNode<T> *node, T new_value) {
    node->value = new_value;
}

template<typename T>
bool page_exist( RefList<T> *page_list, T target) {
    bool found = false;
    for(int i = 0; i < PAGESIZE && (*page_list)[i] != nullptr ; i++) {
        if ( (*page_list)[i]->value == target) {
            (*page_list)[i]->count++;
            return true; 
        }
    }
    return false; 
}


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
    tree.insert(1);

    // bool ret = tree.find(-1);
    // std::cout << ret << "\n";
    
    return 0;
  
}
         





