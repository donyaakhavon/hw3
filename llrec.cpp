#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
// Write a recursive function to split the elements of a singly-linked list into two output lists, 
// one containing the elements less than or equal to a given number, the other containing the elements larger than the number. 
// You must MAINTAIN the relative ordering of items from the original list when you split them into the two output lists. The original list should not be preserved
//  Your function must be recursive - you will get NO credit for an iterative solution. It must also run in O(n), where n is the length of the input list 
//  (and can be done with only one pass/traversal through the list).

//*********************************************

void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot) {
  // base 
  if(head == nullptr) {
    smaller = nullptr;
    larger = nullptr;
    return;
  }

  else {
    Node* temp = head->next; // save next node
    if(head->val <= pivot) {
      smaller = head; // add to smaller list, recursively build rest of smaller and all of larger
      head = nullptr;
      llpivot(temp, smaller->next, larger, pivot);
    }
    else if(head->val > pivot) {
      larger=head; 
      head =nullptr;
      llpivot(temp, smaller, larger->next, pivot); // recursively build all of smaller and rest of larger 
    }
  }
}
