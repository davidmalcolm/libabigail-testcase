#include "test-internal.h"

int test_lib_entrypoint (int i)
{
  hidden_in_file_1.field += i;
  return hidden_in_file_1.field;
}
