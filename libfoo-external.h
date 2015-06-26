#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef struct foo_context foo_context;

extern foo_context *
foo_context_acquire (void);

extern void
foo_context_release (foo_context *ctxt);

extern int
foo_context_add (foo_context *ctxt, int i);

#ifdef __cplusplus
}
#endif /* __cplusplus */
