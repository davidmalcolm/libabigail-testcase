#include "libfoo-external.h"
#include "libfoo-internal.h"

foo_context *
foo_context_acquire (void)
{
  foo_context *ctxt = new foo_context ();
  return ctxt;
}

void
foo_context_release (foo_context *ctxt)
{
  delete ctxt;
}

int
foo_context_add (foo_context *ctxt, int i)
{
  return ctxt->add (i);
}

internal_context::internal_context ()
  : m_field (0)
{
}

int
internal_context::add (int i)
{
  m_field += i;
  return m_field;
}
