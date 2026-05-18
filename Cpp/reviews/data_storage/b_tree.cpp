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
#include <deque>
const int PAGESIZE = 5;

template <typename T>
struct RefNode {
    T value; 
    // std::array< RefNode<T>*, 5 >  *ref;
    int count;  //  number of referenced nodes . 
    RefNode<T> *down;
    RefNode<T> *up;
    RefNode<T> *next;
    RefNode<T> *back;
    int depth;
    int index; 
};


/**
 * Count number of active page in list 
 * 
 * @param node Pointer to node in list
 */
template<typename T>
int list_size(RefNode<T> *node);

/**
 * Handle creation of reference node at the front page
 * 
 * @param node Pointer to head page
 * @param target Catalyst for new reference generation 
 */
template<typename T>
void hanlde_ref_front(RefNode<T> *node, T target);


/**
 * Handle creation of reference node at the last page
 * 
 * @param node Pointer to last page
 * @param target Catalyst for new reference generation 
 */
template<typename T>
void hanlde_ref_this(RefNode<T> *node, T target);


/**
 * Handle creation of reference node inside bounds
 * 
 * @param node Pointer to non edge page
 * @param target Catalyst for new reference generation 
 */
template<typename T>
void hanlde_ref_between(RefNode<T> *node, T target);


/**
 * Moves to front of page and sets indicies in list
 * 
 * @param node Pointer to last page
 */
template<typename T>
void set_indices(RefNode<T> *node);

/**
 * Get head of list
 * 
 * @param node Pointer to page 
 */
template<typename T>
RefNode<T> * get_head(RefNode<T> * node) ;

// /**
//  *  Travels up tree updating reference node count 
//  * 
//  * @param node Pointer to page
//  * @param target Pointer to page
//  */
// template <typename T> 
// void update_ref_count(RefNode<T> * node, RefNode<T> * target);

/**
 * Find target page in list
 * 
 * @param page Pointer to page 
 * @param target_page Pointer to target
 */
template<typename T>
bool page_in_list(RefNode<T> *page, RefNode<T> *target_page);
    
template <typename T>
class BTree {
    
    RefNode<T> *root;
    
    /**
     * View pages in RefList
     *
     * @param list Pointer to RefList  
     */
    void view_list(RefNode<T> *node) {
        while (node) {
            std::cout << "[" << (node->value) << "]" << "{" << (node->count) <<"}" << " Index " << node->index <<"\t\t";
            node = node->next;
        }
        std::cout << '\n';
    }


/**
 *  Travels up tree updating reference node count 
 * 
 * @param node Pointer to page
 * @param target Pointer to page
 */
 
void update_ref_count(RefNode<T> *node) {
    
    int count = 0;
    
    // std::cout << "WHERE AM I\t" << node->value;
    
    
    // while (!page_in_list(node, target)) {
        
    //     // move to last page
    //     while(node->next)
    //         node = node->next; 
        
    //     // move to ref
    //     while (node) {
    //         count += +(node->down == nullptr);
    //         if (node->up) {
    //             node = node->up;
    //             node->count = count; 
    //             break;
    //         } else {
    //             node = node->back;
    //         }
    //     }
        
    // }
}



public:
  
    BTree() {root = nullptr;}
    
      /**
     * Print all lists
     * 
     */
    void view_all(void) {
        
        std::deque< RefNode<T>*> q;
        
        q.push_back(root);
        
        RefNode<T>* page;
        
        while (  !q.empty()  ) {
            
            page =  q.front();
            
            q.pop_front();
            
            std::cout << "-------------------" << "\n";
            if (page->index == 0) {
                std::cout << "DEPTH:* " << page->depth<<"\nLIST: "<< "\n";
                // view_list(page);
                std::cout << "\n";
            }
            
            // search linked list, add references found in queue
            while (page) {
                std::cout <<"IDX:" << page->index << "\t" << "[" << page->value << "]" << " < " << page->index << "  <" << page->count <<  ">\n" ;
                if (page->down) {
                    std::cout << " -REF "  << "\n";
                    q.push_back(page->down);
                } else {
                    std::cout << std::endl;
                }
                page = page->next; 
            }
            
        }
        
    }

    
    /** 
    * Search/traverse b-tree. 
    *  
    * @param val Value to insert into b-tree.
    * 
    */
    void insert(T val) {
        
        if (!root) {
            // first insert , create root node 
            root = new RefNode<T>{ val, 1, nullptr /*down*/, nullptr/*up*/,nullptr/*next*/, nullptr/*back*/ , 0, 0}; // parent list's node
            
        } else {
            
            RefNode<T> *ret_node;
            
            ret_node = tree_traveral(val);
            
            if (ret_node->value == val) {
                
                ret_node->count++;
                
            } else if(val < ret_node->value) {
                RefNode<T> * head = get_head(ret_node);
                int n_pages = list_size(head);
                
                // view_list(get_head(ret_node));

                if (n_pages == PAGESIZE) {
                        // full 
                    if (ret_node->index == 0) {
                        // ref case (head)
                        hanlde_ref_front(ret_node, val); // after expression is complete, ret_node->back represents new ref
                        
                        // ret_node->back->value;
                        
                        set_indices(ret_node);
                        
                        update_ref_count(ret_node->back);

                    } else {
                
                        // ref drill down ( ref between)
                        hanlde_ref_this(ret_node->back, val); // notice the back (node->back is drilled down)
                        
                        set_indices(ret_node);

                        update_ref_count(ret_node->back);
                        
                        //debug 
                        // view_list(get_head(ret_node));
                    }
                    
                } else {
                    
                    // std::cout << val <<  "---" << ret_node->index << "\t" << "\t"<< ret_node->value<< "\t"<<  n_pages<<  "\n";
                    // not full, inject 
                    RefNode<T> *ret_node_back = ret_node->back;
                    RefNode<T> *new_page = new RefNode<T>{ val, 1, nullptr /*down*/, nullptr/*up*/,nullptr/*next*/, nullptr/*back*/ , ret_node->depth, ret_node->index}; 
                    // ret_node->index += 1;
                    new_page->next = ret_node;
                    ret_node->back = new_page;
                    new_page->back = ret_node_back; 
                    
                    if(ret_node_back) {
                        ret_node_back->next = new_page;
                        new_page->back = ret_node_back;
                    }
                    
                    if(ret_node == root) { root = new_page;}
                    
                    if (new_page->depth > 0 && ret_node->index == 0 ) {
                        // ret_node points to ref
                        
                        // update the value of the ref node
                        ret_node->up->value = val;
                        
                        // store ref node 
                        RefNode<T> *ref = ret_node->up;
                        
                        // detach ref node from ret_node 
                        ret_node->up->down = nullptr;
                        ret_node->up = nullptr;
                        
                        // attach new front to ref
                        new_page ->up = ref;
                        ref->down = new_page;
                    
                    }
             
                    set_indices(new_page);
                    
                    
                    
                    // ref may be located to the left of new page
                    
                    RefNode<T> * possible_ref = get_head(ret_node);
                    
                    update_ref_count(possible_ref);
                    
      
        
                }
                
            } else if (val > ret_node->value) {
                
                if (ret_node->index == PAGESIZE - 1) {
                    
                    // ref case (tail)
                    hanlde_ref_this(ret_node, val); // ret_node is ref
                    
                    RefNode<T> * possible_ref = get_head(ret_node);
                    // view_list(head);

                } else {
                    
                    // extend list in forward 
                    RefNode<T> *new_page = new RefNode<T>{ val, 1, nullptr /*down*/, nullptr/*up*/,nullptr/*next*/, nullptr/*back*/ , ret_node->depth, ret_node->index + 1};
                    ret_node->next = new_page;
                    new_page->back = ret_node; 
                    
                    // ref may be located to the left of new page

                    RefNode<T> * possible_ref = get_head(new_page);
                    
                    update_ref_count(possible_ref);

                    // view_list(head);
                    set_indices(get_head(ret_node));
                }
            }
            
        }
    }
    
    /** 
    * Search/traverse b-tree. 
    * 
    * @param val Target of search.
    * @param end_select  Select end to modify ( -1 (not change) 0 (left edge) 1(right edge) ).
    */
    RefNode<T> *tree_traveral(T target) {
        RefNode<T> *node ;
        RefNode<T> *prev ;
        
        if (!root) 
            return nullptr;
        
        node = root;
        
        while(node) {
            
            if (target == node->value) {
                if (!node->down) {
                    return node;
                }
                node = node->down;
                continue;
            } else if(target < node->value) {
                if (!node->down) 
                    return node;
                node = node->down;
                continue;
            } else {
                if (node->next) {
                    if ((node->value < target && target < node->next->value)  && node->down) {
                        // between case 
                        node = node->down;
                        continue;
                    } 
                } else {
                    if (node->value <= target && node->down) {
                        node = node->down;
                        continue;
                    }
                }
            }
            prev = node; 
            node = node->next; 
        }
       
        return prev;
    }
    
};

template<typename T>
void hanlde_ref_front(RefNode<T> *curr_page, T target) {
    
    // new curr_page layer
    RefNode<T> *new_head_page = new RefNode<T>{ target, 1, nullptr /*down*/, nullptr/*up*/,nullptr/*next*/, nullptr/*back*/ , curr_page->depth + 1, 0 };
    
    // copy 'analysis' page and append to new head page
    RefNode<T> *copy_page = new RefNode<T>{ curr_page->value, curr_page->count, nullptr /*down*/, nullptr/*up*/,nullptr/*next*/, nullptr/*back*/ , curr_page->depth + 1, 1 };
    
    // forward connect new_head_page to copy_page
    new_head_page->next  = copy_page;
    
    //reverse connect copy_page to new_head_page
    copy_page->back = new_head_page;
    
    // update curr page value to lowest bound 
    if (curr_page->index == 0) {
        curr_page->value = target;
    }
    
    // update size of reference in curr_page 
    curr_page->count = new_head_page->count + copy_page->count; 
    
    // point new head page to ref page
    new_head_page->up = curr_page;
    
    // point ref down to new head
    curr_page->down = new_head_page;
}

template<typename T>
void hanlde_ref_this(RefNode<T> *curr_page, T target) {
    
    // copy node which is new front for new list 
    RefNode<T> *copy_page = new RefNode<T>{ curr_page->value, curr_page->count, nullptr /*down*/, nullptr/*up*/,nullptr/*next*/, nullptr/*back*/ , curr_page->depth + 1, 0 };
    
    // point new head to value
    RefNode<T> * new_page = new RefNode<T>{ target, 1, nullptr /*down*/, nullptr/*up*/,nullptr/*next*/, nullptr/*back*/ , curr_page->depth + 1, 1 };
    
    // forward connect copy page to new page
    copy_page->next = new_page;
    
    // reverse connect copy page to new page
    new_page->back = copy_page;
    
    // point copy page (aka head) to ref
    copy_page->up = curr_page;
    
    // point ref down to copy page
    curr_page->down = copy_page;
    
    // update size of ref node 
    curr_page->count = new_page->count + curr_page->count;
    
}

template<typename T>
bool page_in_list(RefNode<T> *page, RefNode<T> *target_page) {
    // move to index 0 
    while(page->back) 
        page = page->back;
        // is this root
    return (page == target_page); 
}

template<typename T>
RefNode<T> * get_head(RefNode<T> * node) {
    while(node->back)
        node = node->back;
    return node;
}

template<typename T>
void set_indices(RefNode<T> *node) {
    RefNode<T> *head = node;
    int n = 0;
    while(head->back)
        head = head->back;
    while(head) {
        head->index = n++;
        head = head->next;
    }
}

template<typename T>
int list_size(RefNode<T> *node) {
    int c = 0;
    while(node) {
        node= node->next;
        c++;
    }
    return c; 
}

int main() {
    std::vector<int> data;
    
    for(int i =0; i < 5; i++) {
        data.push_back(i);
    }
    
    BTree<int> tree;
    tree.insert(4);
    tree.insert(-1);
    tree.insert(-1);
    tree.insert(100);
    tree.insert(2);
    tree.insert(555);
    tree.insert(69);
    tree.insert(69);
    tree.insert(69);
    tree.insert(73);
    tree.insert(88);
    tree.insert(92);
    tree.insert(97);
    tree.insert(97);
    tree.insert(97);
    tree.insert(-100);
    tree.insert(1000);
    tree.insert(1000);
    tree.insert(1222);
    tree.insert(13433);
    tree.insert(3424553);
    tree.insert(3424555);
    tree.insert(-200);

    tree.view_all();

    // // tree.insert(1);
    // tree.insert(-333);
    // tree.insert(333);
    // tree.insert(-100);
    // tree.insert(-100);
    // tree.insert(-90);
    
    // bool ret = tree.find(-1);
    // std::cout << ret << "\n";
    
    return 0;
  
}
         





