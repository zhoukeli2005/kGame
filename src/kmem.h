/*
 *
 *
 */

#ifndef _k_MEM_h_
#define _k_MEM_h_

struct kGame;

#define kMALLOC(tt, c)	(tt *)(kmem_malloc(k, sizeof(tt) * (c), #tt, __FILE__, __LINE__, __FUNC__))
#define kFree(p)	kmem_free(k, p, __FILE__, __LINE__, __FUNC__)

void *
kmem_malloc(struct kGame * k, int sz, const char * tt, const char * file, int line, const char * func);

void
kmem_free(struct kGame * k, void * p, const char * file, int line, const char * func);

/* --- For Debug --- */
int
kmem_debug_size(struct kGame * k);

#endif

