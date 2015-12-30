#include "kfile.h"
#include "kgame.h"
#include "kmem.h"

static void _destructor(struct kObject * obj);

struct kFile *
kfile_create(struct kGame * k, const char * filename)
{
	struct kFile * kf = kMalloc(struct kFile, 1);
	
	kobject_init(k, cast(struct kObject *, kf));
	
	kf->destructor = _destructor;
	
	kf->filename = kstring_create(k, filename);
	
	return kf;
}

void _destructor(struct kObject * obj)
{
	struct kGame * k = obj->k;
	kFree(obj);
}