#ifndef lcthw_list_h
#define lcthw_list_h

#include <stdlib.h>

/*
 * struct ListNode
 *
 * The ListNode data structure represents the
 * heart of the doubley linked list.
 *
 * It knows the memory address of the node to
 * its left and the node to its right - this is
 * why we can define the list as doubley linked.
 *
 * It is a robust data structure because it can hold
 * a pointer to any data type.
 */
struct ListNode;

typedef struct ListNode {
  struct ListNode *next;
  struct ListNode *prev;
  void *value;
} ListNode;

/*
 * struct List
 *
 * The List is nothing more than a wrapper around
 * an arbitrary number of ListNode structs.
 *
 * It has special knowledge of the nodes at
 * the extreme left and extreme right - making access
 * to those nodes particularly fast.
 *
 * It also keeps track of the total number of nodes it contains.
 */
typedef struct List {
  int count;
  ListNode *first;
  ListNode *last;
} List;

List *List_Create();
void List_Destroy(List *list);
void List_Clear(List *list);
void List_Clear_Destroy(List *list);

#define List_Count(A) ((A)->count)
#define List_First(A) ((A)->first != NULL ? (A)->first->value : NULL)
#define List_Last(A)  ((A)->last != NULL ? (A)->last->value : NULL)

void List_Push(List *list, void *value);
void *List_Pop(List *list);

void List_Unshift(List *list, void *value);
void *List_Shift(List *list);

void *List_Remove(List *list, ListNode *node);

#define LIST_FOREACH(L, S, M, V) \
  ListNode *_node = NULL; \
  ListNode *V = NULL; \
  for(V = _node = L->S; _node != NULL; V = _node = _node->M)

#endif
