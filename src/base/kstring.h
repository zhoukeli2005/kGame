#ifndef _k_String_h_
#define _k_String_h_

#include "kobject.h"

struct kGame;

struct kString {
	kObject_Header;
	
	int length;
	unsigned int hash;
};

#define kstring_data(kstr)	(char *)((struct kString *)(kstr) + 1)
#define kstring_len(kstr)	((struct kString *)(kstr))->length

struct kString *
kstring_create(struct kGame * k, const char * str);

struct kString *
kstring_create_len(struct kGame * k, const char * str, int length);

int
kstring_equip(struct kString * kstr1, struct kString * kstr2);

#endif
