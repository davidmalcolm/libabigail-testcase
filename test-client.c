#include <assert.h>
#include "libfoo-external.h"

int
main (int argc, const char **argv)
{
  int result;
  foo_context *ctxt = foo_context_acquire ();

  result = foo_context_add (ctxt, 3);
  assert (result == 3);

  result = foo_context_add (ctxt, 4);
  assert (result == 7);

  foo_context_release (ctxt);

  return 0;
}
