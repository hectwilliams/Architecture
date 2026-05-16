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
        
        // number of active parent pages 
        while((*parent_list)[n_active_parent_pg++]);
        n_active_parent_pg--; 
        
        std::cout << eff_index << '\t' << index << " " << n_active_parent_pg<<'\n';
        
        // // std::cout << "LARGE NUMBER " << index <<'\n';
        if(n_active_parent_pg < PAGESIZE){
            if (index == -1) {
                // insert value before first parent page
                
                // save page the first parent page references 
                child_list = (*parent_list)[0]->ref;

                // shift/move parent pages to right by 1
                for(int i = PAGESIZE-1; i >0; i-- ) 
                    (*parent_list)[i] = (*parent_list)[i-1] ;
                
                // assign page to parent RefList
                RefNode<T> *new_parent_page = new RefNode<T>{target, nullptr, 0 };
                (*parent_list)[eff_index] = new_parent_page; 
                
                // point new parent page to RefList referencing by others in parent list 
                new_parent_page->ref = child_list;

                // shift/move child pages to right by 1
                for(int i = PAGESIZE-1; i >0; i-- ) 
                    (*child_list)[i] = (*child_list)[i-1] ;
                
                // add leaf node to child_list; simply set eff_index in child_list to new page with same info as parent node 
                RefNode<T> *new_child_page = new RefNode<T>{target, nullptr, 0 };
                (*child_list)[eff_index] = new_child_page; 
                

            } else if (index < PAGESIZE){
                std::cout <<  target <<" " << index  << '\n';
                // insert after last active page
                // assign page to parent RefList
                
                  // save page the first parent page references 
                child_list = (*parent_list)[0]->ref;
                
                // std::cout <<  "child_list " << (*child_list)[0] << '\n';
                
                RefNode<T> *new_parent_page = new RefNode<T>{target, nullptr, 0 };
                (*parent_list)[eff_index] = new_parent_page; 
                
                // std::cout <<  "child_list " << (*parent_list)[1] << '\n';
                
                //  // save page the first parent page references 
                // child_list = (*parent_list)[1]->ref;
                // std::cout <<  "PARENT2 " << (*child_list)[0]->value << '\n';
                
                // //  // point new parent page to RefList referencing by others in parent list 
                // new_parent_page->ref = child_list;
                
                // RefNode<T> *new_child_page = new RefNode<T>{target, nullptr, 0 };
                // (*child_list)[eff_index] = new_child_page; 
                
            } else {
                
            }
            
            // std::cout << "-------DEBUG" << '\n';
            //     for ( int  idx =0; idx < n_active_parent_pg + 1; idx++) {
                    
            //     std::cout <<  "PARENT [" <<  idx <<"]" << (*parent_list)[idx]->value << '\n';
            //     // std::cout <<  "PARENT1 " << (*parent_list)[1]->value << '\n';
                
            //     std::cout <<  "CHILD [" <<  idx <<"]" << (*child_list)[idx]->value << '\n';
            //     // std::cout <<  "CHILD1 " << (*child_list)[1]->value << '\n';
            //     }
                
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
        int i=-1;
        
        if (!node_list) {
            return {nullptr, i};    
        }
    
        prev_node_list= root;
        
        while (node_list /* RefList*/) {
            for (i =0; i < PAGESIZE; i++) {
                node = (*node_list)[i]; // node in current RefList; at least one node exist in RefLists
                if ( node == nullptr || (node->ref != nullptr)) {
                    // nonleaf nodes 
                    
                    if (end_select == 0 && i == 0) {
                        // update first page
                        node->value = val;
                    } else if (end_select  == 1 && i == PAGESIZE - 1 ) {
                        // update last page
                        node->value = val;                        
                    }
                    // search will continue to leafs
                    break; 
                } else if ( val == node->value ) {
                    // leaf node-->> target === list element value 
                    return {prev_node_list, i};
                }  else if (val < node->value) {
                    // leaf node-->> target < list element value
                    return {prev_node_list, i - 1};
                }
            }
            
            
            prev_node_list = node_list; 
            node_list = (node) ? node->ref : nullptr; // end if page is nulled Note: If list search fails, search will continue down from the tail of list. 
        }
            // std::cout << "INDE " << val << " " << i << "\t"<<  '\n';
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

    // bool ret = tree.find(-1);
    // std::cout << ret << "\n";
    
    return 0;
  
}
         





