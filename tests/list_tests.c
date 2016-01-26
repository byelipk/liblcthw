#include "miniunit.h"
#include <lcthw/lcthw_list.h>
#include <assert.h>

static List *list = NULL;
char *test1 = "test1 data";
char *test2 = "test2 data";
char *test3 = "test3 data";

char *test_create()
{
  list = List_Create();
  mu_assert(list != NULL, "Failed to create list");

  return NULL;
}

char *test_destroy()
{
  if (list == NULL) {
    list = List_Create();
  }

  List_Clear_Destroy(list);

  return NULL;
}

char *all_tests()
{
  mu_suite_start();

  mu_run_test(test_create);
  mu_run_test(test_destroy);

  return NULL;
}

RUN_TESTS(all_tests);
