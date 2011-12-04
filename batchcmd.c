#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

#include "defs.h"    /* From the crash source top-level directory */

void cmd_batch(void);
char *help_batch[];

static struct command_table_entry command_table[] = {
	{"batch", cmd_batch, help_batch, 0 },
	{ NULL }
};

int 
_init(void) /* Register the command set. */
{ 
        register_extension(command_table);
	return 1;
}
 
/* 
 *  The _fini() function is called if the shared object is unloaded. 
 *  If desired, perform any cleanups here. 
 */
int 
_fini(void) 
{ 
	return 1;
}

#include "y.tab.c"

extern int yyparse();
extern FILE * batchyyin;

int call_crash_cmd(const char *input)
{
	FILE *fp_bak;

	fp_bak = fp;
	fp = fopen(TMP_FILE, "w");
	if (fp == NULL)
		fp = fopen(TMP_FILE, "a");
	if (fp == NULL) {
		fp = fp_bak;
		perror("fopen tmp file");
		return -1;
	}
	strcpy(pc->command_line, input);
	argcnt = parse_line(pc->command_line, args);
	exec_command();
	fclose(fp);
	fp = fp_bak;
	return 0;
}

void cmd_batch(void)
{
	char *filename;
	if (argcnt < 2) {
		fprintf(fp, "please specific an input file\n");
		return;
	}
	filename = args[1];

	batchyyin = fopen(filename, "r");
	if (batchyyin == 0) {
		perror("fopen input file");
		return;
	}
	yyparse();
	fclose(batchyyin);
}

char *help_batch[] = {
	"batch",		/* command name */
	"run a script",		/* short description */
	"filename",		/* argument synopsis, or " " if none */
	"  This command run a script which can call crash command",
	NULL
};
