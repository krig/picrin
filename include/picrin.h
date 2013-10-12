#ifndef PICRIN_H__
#define PICRIN_H__

#include <stddef.h>
#include <stdbool.h>

#include "picrin/value.h"

struct pic_env {
  pic_value assoc;
  struct pic_env *parent;
};

typedef struct {
  pic_value *sp;
  pic_value *stbase, *stend;

  struct pic_env *global_env;
} pic_state;

void *pic_alloc(pic_state *, size_t);
struct pic_object *pic_gc_alloc(pic_state *, size_t, enum pic_tt);
void pic_free(pic_state *, void *);

pic_state *pic_open();
void pic_close(pic_state *);

pic_value pic_cons(pic_state *, pic_value, pic_value);
pic_value pic_car(pic_state *, pic_value);
pic_value pic_cdr(pic_state *, pic_value);

bool pic_eq_p(pic_state *, pic_value, pic_value);

pic_value pic_intern_cstr(pic_state *, const char *);

pic_value pic_parse(pic_state *, const char *);

pic_value pic_eval(pic_state *, pic_value, struct pic_env *);

void pic_debug(pic_state *, pic_value);

#endif