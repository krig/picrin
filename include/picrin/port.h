/**
 * See Copyright Notice in picrin.h
 */

#ifndef PICRIN_PORT_H__
#define PICRIN_PORT_H__

#if defined(__cplusplus)
extern "C" {
#endif

enum pic_port_flag {
  PIC_PORT_IN = 1,
  PIC_PORT_OUT = 2,
  PIC_PORT_TEXT = 4,
  PIC_PORT_BINARY = 8,
};

enum pic_port_status {
  PIC_PORT_OPEN,
  PIC_PORT_CLOSE,
};

struct pic_port {
  PIC_OBJECT_HEADER
  xFILE *file;
  int flags;
  int status;
};

#define pic_port_p(v) (pic_type(v) == PIC_TT_PORT)
#define pic_port_ptr(v) ((struct pic_port *)pic_ptr(v))

pic_value pic_eof_object();

struct pic_port *pic_stdin(pic_state *);
struct pic_port *pic_stdout(pic_state *);
struct pic_port *pic_stderr(pic_state *);

struct pic_port *pic_open_output_string(pic_state *);
struct pic_string *pic_get_output_string(pic_state *, struct pic_port *);

void pic_close_port(pic_state *pic, struct pic_port *);

#if defined(__cplusplus)
}
#endif

#endif
