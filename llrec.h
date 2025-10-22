#ifndef LLREC_H
#define LLREC_H
#ifndef NULL
#define NULL 0
#endif

/**
 * Node struct for both problems
 */
struct Node
{
    int val;
    Node *next;

    Node(int v, Node* n) : val(v), next(n) {}
};
// this implementation with the Node* n helps for linking nodes automatically rather than doing it manually with node2->next = node1; we can just do Node* node 2 = new Node(10, node1);
/**
 * Given a linked list pointed to by head, creates two lists
 * where all values less than or equal to the pivot value are
 * placed in a linked list whose head will be pointed to by
 * smaller and all values greater than the pivot
 * value are placed in a linked list whose head will be pointed to
 * by larger.  The input list pointed to by head should be empty
 * upon return and head set to NULL (i.e. we are not making copies)
 * in the smaller and larger lists but simply moving Nodes out of
 * the input list and into the two other lists.
 * 
 * ==============================================================
 * MUST RUN IN O(n) where n is the number of nodes in the input list
 * ==============================================================
 *
 * @pre: smaller and larger may containing garbage (do NOT have
 *       to be NULL)
 *
 * @param[inout] head
 *   Reference to the head pointer to the input list.
 *   Should be set to NULL upon return
 * @param[out] smaller
 *   Reference to a head pointer for the list of nodes with values
 *   less than or equal to the pivot
 * @param[out] larger
 *   Reference to a head pointer for the list of nodes with values
 *   greater than the pivot
 * @param[in] pivot
 *   Pivot value
 *
 */
 
void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot);

/**
 * Given a linked list pointed to by head, removes (filters out) nodes
 * whose value does not meet the criteria given by the predicate
 * function object, pred (i.e. pred should be a function object that implements
 * `bool operator()(int value)` and returns *true* for items that should
 * be *removed/filtered*.  Removed items should be deallocated.
 *
 * ==============================================================
 * MUST RUN IN O(n) where n is the number of nodes in the input list
 * ==============================================================
 *
 * @param[in] head
 *   Reference to the head pointer to the input list.
 * @param[in] pred
 *   Predicate object implementing: `bool operator()(int value)` that
 *   returns true if a node (based on its value) should be removed.
 * @return a head pointer to the resulting list (since the head pointer
 *   may change [i.e. be filtered])
 *
 */



//*****************************************************************************
// Since template implementations should be in a header file, we will
// implement the above function now.
//*****************************************************************************


template <typename Comp>
Node* llfilter(Node* head, Comp pred){
    // b case if head is null return null// recursive case: check if curr node should be filtered using pred head->val
    // if removed, save next node, delete curr, and recursively call llfilter on rest of list// if not removed, keep curr node, recursively filter rest of hte list, update head-> next ot point ot the filtered rest. 
    
    // btw, pred is the paramter name for the functor object that gets passed into the function. its short for predicate and returns true or fals.e 
    if(head == nullptr) return nullptr;
    if(pred(head->val)) { 
        Node* nextNode = head->next;
        delete head;
        return llfilter(nextNode, pred);
    } else {
        head->next = llfilter(head->next, pred);
        return head; 
    }
}


#endif
