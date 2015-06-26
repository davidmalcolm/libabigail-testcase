/* This struct ought to be hidden.  */

class internal_context
{
 public:
  internal_context ();
  int add (int i);

 private:
  int m_field;
};

/* This struct also ought to be hidden.  */

struct foo_context : public internal_context
{
  /* nothing extra.  */
};
