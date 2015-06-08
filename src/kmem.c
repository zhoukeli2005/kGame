#include "kmem.h"

#include <stdio.h>
#include <malloc.h>

void * kmem_malloc(struct kGame * k, int sz, const char * tt, const char * file, int line, const char * func)
{
	int total_sz = sz + sizeof(int);

	printf("kmem_malloc:type(%s), file(%s), line(%d), func(%s), size(%d)\n", tt, file, line, func, total_sz);

	int * pint = (int *)malloc(total_sz);
	*pint = total_sz;

	return pint + 1;
};

void kmem_free(struct kGame * k, void * p, const char * file, int line, const char * func)
{
	int * pint = (int *)p;
	pint--;

	int sz = *pint;

	printf("kmem_free:file(%s), line(%d), func(%s), size(%d)\n", file, line, func, sz);

	free(pint);
};

int kmem_debug_size(struct kGame * k)
{
	return 0;
};

