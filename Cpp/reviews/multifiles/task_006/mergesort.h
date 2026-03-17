#ifndef MERGESORT_H
#define MERGESORT_H

#include <iostream>
#include <vector>
#include <cmath>
#include <utility> // swap

enum SortOrder {
  increasing,
  decreasing
};
 
using NumberV = std::vector<int>;

void mergesort(NumberV& v, SortOrder order= SortOrder::increasing);
  
void display(NumberV& v);

#endif
