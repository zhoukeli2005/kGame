#ifndef _k_Object_h_
#define _k_Object_h_

#include "kcommon.h"

struct kGame;
struct kObject;

typedef void (* destructor_fun_t) (struct kObject * obj);

#define kObject_Header \
	int ref_count;\
	void * traits;\
	destructor_fun_t destructor;\
	struct kGame * k

struct kObject {
	kObject_Header;
};

void kobject_init(struct kGame * k, struct kObject * obj);

void kobject_grap(struct kObject * obj);
void kobject_drop(struct kObject * obj);

#endif
