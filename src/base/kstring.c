#include "kstring.h"
#include "kgame.h"
#include "kmem.h"

#include <string.h>

static void _destructor(struct kObject * obj);
static unsigned int _hash(const char * str, int len);

struct kString *
kstring_create(struct kGame * k, const char * str)
{
	int len = strlen(str);
	return kstring_create_len(k, str, len);
}

struct kString *
kstring_create_len(struct kGame * k, const char * str, int len)
{
	struct kString * kstr = (struct kString *)kMalloc(char, sizeof(struct kString) + len + 1);
	kobject_init(k, cast(struct kObject *, kstr));
	
	kstr->destructor = &_destructor;
	
	kstr->length = len;
	kstr->hash = _hash(str, len);
	
	memcpy(kstring_data(kstr), str, len + 1);
	
	return kstr;
}

int
kstring_equip(struct kString * kstr1, struct kString * kstr2)
{
	if((kstr1->hash != kstr2->hash) || (kstr1->length != kstr2->length)) {
		return 0;
	}
	int i = 0;
	const char * p1 = kstring_data(kstr1);
	const char * p2 = kstring_data(kstr2);
	for(i = 0; i < kstr1->length; ++i) {
		if(p1[i] != p2[i]) {
			return 0;
		}
	}
	return 1;
}

static void _destructor(struct kObject * obj)
{
	struct kGame * k = obj->k;
	kFree(obj);
}

static unsigned int _hash(const char * str, int len)
{
	unsigned int h = 0;
	int step = (h >> 5) + 1;
	int i;
	for(i = 0; i < len; i += step) {
		h = h ^ ((h<<5) + (h>>2) + cast(unsigned char, str[i]));
	}
	
	return h;
}
