#include "miniunit.h"
#include <lcthw/lcthw_list.h>
#include <assert.h>

static List *list = NULL;
char *test1 = "test1 data";
char *test2 = "test2 data";
char *test3 = "test3 data";

void setup()
{
  if (list == NULL) {
    list = List_Create();
  }
}

void teardown()
{
  if (list != NULL) {
    List_Clear_Destroy(list);
    list = NULL;
  }
}

char *test_create()
{
  setup();

  mu_assert(list != NULL, "Failed to create list");

  teardown();

  return NULL;
}

char *test_destroy()
{
  setup();

  List_Clear_Destroy(list);

  list = NULL;

  return NULL;
}

char *test_push_pop()
{
  setup();

  List_Push(list, test1);
  mu_assert(List_Last(list) == test1, "Wrong last value.");

  List_Push(list, test2);
  mu_assert(List_Last(list) == test2, "Wrong last value");

  List_Push(list, test3);
  mu_assert(List_Last(list) == test3, "Wrong last value.");
  mu_assert(List_Count(list) == 3, "Wrong count on push.");

  char *val = List_Pop(list);
  mu_assert(val == test3, "Wrong value on pop.");

  val = List_Pop(list);
  mu_assert(val == test2, "Wrong value on pop.");

  val = List_Pop(list);
  mu_assert(val == test1, "Wrong value on pop.");
  mu_assert(List_Count(list) == 0, "Wrong count after pop.");

  teardown();

  return NULL;
}

char *test_unshift()
{
  setup();

  List_Unshift(list, test1);
  mu_assert(List_First(list) == test1, "Wrong first value.");

  List_Unshift(list, test2);
  mu_assert(List_First(list) == test2, "Wrong first value");

  List_Unshift(list, test3);
  mu_assert(List_First(list) == test3, "Wrong last value.");
  mu_assert(List_Count(list) == 3, "Wrong count on unshift.");

  return NULL;
}

char *test_remove()
{
  // we only need to test the middle remove case since push/shift
  // already tests the other cases
  setup();

  char *val = List_Remove(list, list->first->next);
  mu_assert(val == test2, "Wrong removed element.");
  mu_assert(List_Count(list) == 2, "Wrong count after remove.");
  mu_assert(List_First(list) == test3, "Wrong first after remove.");
  mu_assert(List_Last(list) == test1, "Wrong last after remove.");

  return NULL;
}

char *test_shift()
{
  mu_assert(List_Count(list) != 0, "Wrong count before shift.");

  char *val = List_Shift(list);
  mu_assert(val == test3, "Wrong value on shift.");

  val = List_Shift(list);
  mu_assert(val == test1, "Wrong value on shift.");
  mu_assert(List_Count(list) == 0, "Wrong count after shift.");

  return NULL;
}

char *all_tests()
{
  mu_suite_start();

  mu_run_test(test_create);
  mu_run_test(test_destroy);
  mu_run_test(test_push_pop);
  mu_run_test(test_unshift);
  mu_run_test(test_remove);
  mu_run_test(test_shift);

  return NULL;
}

RUN_TESTS(all_tests);
//
