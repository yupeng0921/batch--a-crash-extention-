#ifndef BATCH_H
#define BATCH_H

#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_STRLEN 5120
#define MAX_SYMLEN 512
#define MAX_SYMNUM 1024

#define SYM_NOTFOUND -1
#define SYMTAB_OVERFLOW -2
#define MEM_MALLOCERR -3

#define TMP_FILE "/tmp/.crash_batch"

#define SIZEOF_NODETYPE(p) ((char *)&p->longCon - (char *)p)
#define SIZEOF_SYMTYPE(p) ((char *)&p->ival - (char *)p)

#define PRINTLONG(p) printf("%lld\n", (LONG)p->ival)
#define PRINTSTR(p) printf("%s\n", p->pstr)

#define STR_TO_LONG(str) atoll(str)

#define DEBUG
#ifdef DEBUG
#define DBG(fmt, args...) fprintf(stdout, "(batchdbg, %s:%d) " fmt, __FUNCTION__, __LINE__, ##args)
#else
#defien DBG(fmt, args...)
#endif

typedef long long int LONG;

typedef enum {
	typeLongCon,
	typeStrCon,
	typeVar,
	typeOpr
} nodeEnum;

typedef enum {
	typeLong,
	typeStr
} symTypeEnum;

typedef struct {
	LONG var;
}longNodeType;

typedef struct {
	char *ptr;
}strNodeType;

typedef struct {
	int index;
}varNodeType;

typedef struct {
	int name;
	int number;
	struct nodeTypeTag *op[1];
} oprNodeType;

typedef struct nodeTypeTag {
	nodeEnum type;
	union {
		longNodeType longCon;
		strNodeType strCon;
		varNodeType var;
		oprNodeType opr;
	};
} nodeType;

typedef struct symTypeTag {
	symTypeEnum type;
	const char *name;
	union {
		LONG ival;
		char *pstr;
	};
} symType, itpType;

static symType symtab[MAX_SYMNUM];
static int symtop = 0;
#endif
