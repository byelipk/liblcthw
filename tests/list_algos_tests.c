#include "miniunit.h"
#include <lcthw/lcthw_list_algos.h>
#include <assert.h>
#include <string.h>

char *values[] = {"XXXX", "1234", "abcd", "xjvef", "NDSS"};
#define NUM_VALUES 5

List *create_words()
{
  List *words = List_Create();

  for (int i = 0; i < NUM_VALUES; i++) {
    List_Push(words, values[i]);
  }

  return words;
}

int is_sorted(List *words)
{
  LIST_FOREACH(words, first, next, cur) {
    if(cur->next && strcmp(cur->value, cur->next->value) > 0) {
      debug("%s %s", (char *)cur->value, (char *)cur->next->value);
      return 0;
    }
  }

  return 1;
}

char *test_bubble_sort()
{
  List *words = create_words();

  // should work on a list that needs sorting
  int rc = List_bubble_sort(words, (List_compare)strcmp);
  mu_assert(rc == 0, "Bubble sort failed.");
  mu_assert(is_sorted(words), "Words are not properly sorted after bubble sort.");

  // cleanup
  List_Destroy(words);

  // should work on an empty list
  words = List_Create(words);
  rc = List_bubble_sort(words, (List_compare)strcmp);
  mu_assert(rc == 0, "Bubble sort failed on empty list.");
  mu_assert(is_sorted(words), "Words should be sorted if empty.");

  // cleanup
  List_Destroy(words);

  return NULL;
}

char *test_merge_sort()
{
  return NULL;
}

char *all_tests()
{
  mu_suite_start();

  mu_run_test(test_bubble_sort);
  mu_run_test(test_merge_sort);

  return NULL;
}

RUN_TESTS(all_tests);
