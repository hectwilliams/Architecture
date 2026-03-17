#include "mergesort.h"

void display(NumberV& v){
  for( int i = 0; i < v.size(); i++)
    std::cout << v[i] << " " ;
  std::cout << '\n';
}

void mergesort(NumberV& v, SortOrder order ) {

  int mid_index = std::floor(v.size()/2);

  if (v.size() > 1) {
    int k = static_cast<int>(v.size() % 2 != 0); // is odd
    std::vector<int> a(v.begin() , v.begin() + mid_index  + k); // 1st arg inclusive, 2nd arg exclusive
    std::vector<int> b(v.begin() + mid_index + k,v.end());
    mergesort(a);
    mergesort(b);

    // sort a and b in increasing order assuming they are contigious( a concatenate with b)
    int a_index = 0;
    int b_index = 0;
    int v_index = 0;

    // assume a and b are sorted once returned from inner/recursive scope

    if ( (a.size() + b.size() == v.size()) && order == decreasing  ) {

      // decreasing  order 

      a_index = a.size() - 1;
      b_index = b.size() - 1;
 
      while( (v_index < v.size() )  ) {

        if (a_index == -1)  {
          v[v_index++] = b[b_index--];
        }
        else if (b_index == -1) {
          v[v_index++] = a[a_index--];
        }
        else if( (a[a_index] > b[b_index])   )  {
          v[v_index++] = a[a_index--];
        }
        else if ( (b[b_index]  <  a[a_index])  ) {
          v[v_index++] = b[b_index--];
        }
        else if (b[b_index] == a[a_index]) {
          v[v_index++] = a[a_index--] ;
          v[v_index++] = b[b_index--] ;
        }

      }
    
    } else {
 
       // increasing  order 
     
       while( (v_index < v.size() )  ) {

        if (a_index == a.size())  {
          v[v_index++] = b[b_index++];
        }
        else if (b_index == b.size()) {
          v[v_index++] = a[a_index++];
        }
        else if( ( a[a_index] <  b[b_index])   )  {
          v[v_index++] = a[a_index++];
        }
        else if ( (b[b_index] < a[a_index])  ) {
          v[v_index++] = b[b_index++];
        }
        else if (b[b_index] == a[a_index]) {
          v[v_index++] = a[a_index++] ;
          v[v_index++] = b[b_index++] ;
        }

      }


    }

  }

}

