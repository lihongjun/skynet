#ifndef SKYNET_SERVER_H
#define SKYNET_SERVER_H

#include <stdint.h>
#include <stdlib.h>

struct skynet_context;
struct skynet_message;

struct skynet_context * skynet_context_new(const char * name, const char * parm);
void skynet_context_grab(struct skynet_context *);
struct skynet_context * skynet_context_release(struct skynet_context *);
uint32_t skynet_context_handle(struct skynet_context *);
void skynet_context_init(struct skynet_context *, uint32_t handle);
int skynet_context_push(uint32_t handle, struct skynet_message *message);
void skynet_context_send(struct skynet_context * context, void * msg, size_t sz, uint32_t source, int session);
int skynet_context_newsession(struct skynet_context *);
int skynet_context_message_dispatch(void);	// return 1 when block

#endif
