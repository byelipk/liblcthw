#include <lcthw/lcthw_list.h>
#include <lcthw/dbg.h>

List *List_Create()
{
  return calloc(1, sizeof(List));
}

void List_Destroy(List *list)
{
  LIST_FOREACH(list, first, next, cur) {
    if (cur->prev) {
      free(cur->prev);
    }
  }

  if (list->last) free(list->last);
  if (list) free(list);
}

void List_Clear(List *list)
{
  if (list) {
    LIST_FOREACH(list, first, next, cur) {
      if (cur->value) {
        free(cur->value);
      }
    }
  }
}

void List_Clear_Destroy(List *list)
{
  List_Clear(list);
  List_Destroy(list);
}

void List_Push(List *list, void *value)
{
  ListNode *node = calloc(1, sizeof(ListNode));
  check_mem(node);

  node->value = value;

  if (list->last == NULL) {
    // the list is empty; all addresses point to
    // the new list node.
    list->first = node;
    list->last  = node;
  } else {
    // tell the last element in the list it
    // has a new neighbor on its right.
    list->last->next = node;

    // inform the new list item it has a neighbor
    // to its left.
    node->prev = list->last;

    // update the address of the last element
    // in the list.
    list->last = node;
  }

  list->count++;

error:
  return;
}

void *List_Pop(List *list)
{
  ListNode *node = list->last;
  return node != NULL ? List_Remove(list, node) : NULL;
}

void List_Unshift(List *list, void *value)
{
  ListNode *node = calloc(1, sizeof(ListNode));
  check_mem(node);

  node->value = value;

  if (list->first == NULL) {
    list->first = node;
    list->last = node;
  } else {
    // tell the first element in the list it
    // has a new neighbor on its left.
    list->first->prev = node;

    // inform the new list item it has a neighbor
    // to its right.
    node->next = list->first;

    // update the address of the first element
    // in the list.
    list->first = node;
  }

  list->count++;

error:
  return;
}

void *List_Shift(List *list)
{
  ListNode *node = list->first;
  return node != NULL ? List_Remove(list, node) : NULL;
}

void *List_Remove(List *list, ListNode *node)
{
  void *result = NULL;

  check(list->first && list->last, "List is empty.");
  check(node, "node can't be NULL");

  /*
   *  Condition 1: There is only 1 node in the list.
   *  Condition 2: Remove the first node in the list.
   *  Condition 3: Remove the last node in the list.
   *  Condition 4: Remove a node from inside the boundaries.
   *
   */
  if (node == list->first && node == list->last) {
    list->first = NULL;
    list->last  = NULL;
  } else if (node == list->first) {
    list->first = node->next;
    check(list->first != NULL, "Invalid list: first element in list containing multiple elements cannot be NULL after remove operation.")
    list->first->prev = NULL;
  } else if (node == list->last) {
    list->last = node->prev;
    check(list->last != NULL, "Invalid list: last element in list containing multiple elements cannot be NULL after remove operation.")
    list->last->next = NULL;
  } else {
    ListNode *after = node->next;
    ListNode *before = node->prev;
    after->prev  = before;
    before->next = after;
  }

  list->count--;
  result = node->value;
  free(node);

error:
  return result;
}
