/**
 * See Copyright Notice in picrin.h
 */

#ifndef PICRIN_STRING_H__
#define PICRIN_STRING_H__

#if defined(__cplusplus)
extern "C" {
#endif

struct pic_string {
  PIC_OBJECT_HEADER
  xrope *rope;
};

#define pic_str_p(v) (pic_type(v) == PIC_TT_STRING)
#define pic_str_ptr(o) ((struct pic_string *)pic_ptr(o))

pic_str *pic_str_new(pic_state *, const char * /* nullable */, size_t);
pic_str *pic_str_new_cstr(pic_state *, const char *);
pic_str *pic_str_new_fill(pic_state *, size_t, char);

size_t pic_strlen(pic_str *);
char pic_str_ref(pic_state *, pic_str *, size_t);
void pic_str_set(pic_state *, pic_str *, size_t, char);

pic_str *pic_strcat(pic_state *, pic_str *, pic_str *);
pic_str *pic_substr(pic_state *, pic_str *, size_t, size_t);
int pic_strcmp(pic_str *, pic_str *);

const char *pic_str_cstr(pic_str *);

pic_value pic_format(pic_state *, const char *, ...);
pic_value pic_vformat(pic_state *, const char *, va_list);
pic_value pic_vfformat(pic_state *, xFILE *, const char *, va_list);

#if defined(__cplusplus)
}
#endif

#endif
