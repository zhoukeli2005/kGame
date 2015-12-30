#ifndef _k_File_h_
#define _k_File_h_

#include "kcommon.h"
#include "kstring.h"

struct kGame;

struct kFile {
	kObject_Header;
	struct kString * filename;
	
	int size;
	const char * p;
};

struct kFile *
kfile_create(struct kGame * k, const char * fname);

#endif