#include <lcthw/lcthw_list_algos.h>
#include <lcthw/dbg.h>

inline void ListNode_swap(ListNode *a, ListNode *b) {
  /*
   *  In the implementation of the swapping algorithm
   *  it's important to realize that we're not swapping
   *  the position of the nodes themselves. We're actually
   *  changing the values of the nodes.
   */
  void *temp = a->value;
  a->value = b->value;
  b->value = temp;
}

int List_bubble_sort(List *list, List_compare cmp)
{
  int sorted = 1;

  if (List_Count(list) <= 1) {
    return 0;
  }

  do {
    sorted = 1;
    // Remember we have a custom function to iterate
    // over list items!
    LIST_FOREACH(list, first, next, cur) {
      if (cur->next) {
        if(cmp(cur->value, cur->next->value) > 0) {
          ListNode_swap(cur, cur->next);
          sorted = 0;
        }
      }
    }
  } while(!sorted);

  return 0;
}
