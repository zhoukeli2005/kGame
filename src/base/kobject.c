#include "kobject.h"
#include "kmem.h"
#include "kgame.h"

#include <assert.h>

void kobject_init(struct kGame * k, struct kObject * obj)
{
	obj->ref_count = 1;
	obj->traits = NULL;
	obj->destructor = NULL;
	obj->k = k;
}

void kobject_grap(struct kObject * obj)
{
	assert(obj->ref_count > 0);
	
	obj->ref_count++;
}

void kobject_drop(struct kObject * obj)
{
	assert(obj->ref_count > 0);
	struct kGame * k = obj->k;

	obj->ref_count --;
	if(obj->ref_count == 0) {
		if(obj->destructor) {
			obj->destructor(obj);
		} else {
			kFree(obj);
		}
	}
}
