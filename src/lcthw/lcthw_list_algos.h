#ifndef lcthw_list_algos_h
#define lcthw_list_algos_h

#include <lcthw/lcthw_list.h>

typedef int (*List_compare)(const void *a, const void *b);

int List_bubble_sort(List *words, List_compare cmp);

#endif
