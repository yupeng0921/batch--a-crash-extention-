/* routines for parse */

void initSymTable()
{
	int i;
	DBG("come in function\n");
	for (i = 0 ; i < MAX_SYMNUM ; i++) {
		symtab[i].name = NULL;
		symtab[i].pstr = NULL;
	}
	symtop = 0;
}

int symname_lookup(const char *symname)
{
	int i;
	DBG("come in function\n");
	DBG("symtop=%d\n", symtop);
	DBG("symname: %s\n", symname);
	for (i = 0 ; i < symtop ; i++) {
		DBG("i=%d\n", i);
		DBG("symtab[i].name: %s\n", symtab[i].name);
		if (!strcmp(symtab[i].name, symname))
			return i;
	}
	return SYM_NOTFOUND;
}

int symname_install(const char *symname)
{
	int ret;
	DBG("come in function\n");
	ret = symname_lookup(symname);
	if (ret != SYM_NOTFOUND) {
		free((void *)symname);
		return ret;
	}

	if (symtop > MAX_SYMNUM) {
		yyerror("symbol table overflow\n");
		return SYMTAB_OVERFLOW;
	}

	symtab[symtop].name = symname;
	symtop++;
	return (symtop - 1);
}

#define DBG_NODE(p) DBG("p->type=%d ", p->type);			\
	if(p->type == typeLongCon)					\
		DBG("var=%lld\n", p->longCon.var);			\
	else if (p->type == typeStrCon)				\
		DBG("ptr=%s\n", p->strCon.ptr);				\
	else if (p->type == typeVar)					\
		DBG("index=%d\n", p->var.index);			\
	else if (p->type == typeOpr)					\
		DBG("name=%d number=%d\n", p->opr.name, p->opr.number);	\
	else								\
		DBG("unknown node type\n")

nodeType *con_long(LONG value)
{
	nodeType *p;
	size_t nodeSize;

	DBG("come in function\n");
	nodeSize = SIZEOF_NODETYPE(p) + sizeof(longNodeType);
	p = malloc(nodeSize);
	if (p == NULL) {
		yyerror("con_long, malloc node failed!\n");
		return NULL;
	}

	p->type = typeLongCon;
	p->longCon.var = value;
	DBG_NODE(p);
	return p;
}

nodeType *con_str(const char *sptr)
{
	int len;
	nodeType *p;
	size_t nodeSize;

	DBG("come in function\n");
	nodeSize = SIZEOF_NODETYPE(p) + sizeof(strNodeType);
	p = malloc(nodeSize);
	if (p == NULL) {
		yyerror("con_str, malloc node failed!\n");
		free((void *)sptr);
		return NULL;
	}

	len = strlen(sptr);
	p->strCon.ptr = malloc(len+1);
	if (p->strCon.ptr == NULL) {
		yyerror("con_str, mallco string failed!\n");
		free((void *)sptr);
		free(p);
		return NULL;
	}

	p->type = typeStrCon;
	strncpy(p->strCon.ptr, sptr, len);
	free((void *)sptr);
	p->strCon.ptr[len] = '\0';

	DBG_NODE(p);
	return p;
}

nodeType *var(const char *sptr)
{
	int index;
	nodeType *p;
	size_t nodeSize;

	DBG("come in function\n");
	index = symname_lookup(sptr);
	if (index == SYM_NOTFOUND) {
		yyerror("symbol not define");
		free((void *)sptr);
		return NULL;
	}

	nodeSize = SIZEOF_NODETYPE(p) + sizeof(varNodeType);
	p = malloc(nodeSize);
	if (p == NULL) {
		yyerror("var, malloc node failed\n");
		return NULL;
	}

	p->type = typeVar;
	p->var.index = index;

	DBG_NODE(p);
	return p;
}

nodeType *var1(int index)
{
	nodeType *p;
	size_t nodeSize;

	DBG("come in function\n");
	if (index == SYM_NOTFOUND) {
		yyerror("symbol not define");
		return NULL;
	}

	nodeSize = SIZEOF_NODETYPE(p) + sizeof(varNodeType);
	p = malloc(nodeSize);
	if (p == NULL) {
		yyerror("var, malloc node failed\n");
		return NULL;
	}

	p->type = typeVar;
	p->var.index = index;

	DBG_NODE(p);
	return p;
}

nodeType *str_param(LONG n)
{
	int len, shift;
	nodeType *p;
	size_t nodeSize;

	DBG("come in function\n");

	if (n < 0 || n >=(batch_argcnt - 1)) {
		yyerror("invalid str param number");
		return NULL;
	}
	/*
	 * input: 
	 * batch test.cr param1 param2
	 * args[0] is batch, args[1] is test.cr, args[2] is param1
	 * We need:
	 * @0 is test.cr, @1 param1, @2 is param2
	 * so shift the input number
	 */
	shift = n + 1;
	nodeSize = SIZEOF_NODETYPE(p) + sizeof(strNodeType);
	p = malloc(nodeSize);
	if (p == NULL) {
		yyerror("con_str, malloc node failed!\n");
		return NULL;
	}

	len = strlen(args[shift]);
	p->strCon.ptr = malloc(len+1);
	if (p->strCon.ptr == NULL) {
		yyerror("con_str, mallco string failed!\n");
		free(p);
		return NULL;
	}

	p->type = typeStrCon;
	strncpy(p->strCon.ptr, batch_args[shift], len);
	p->strCon.ptr[len] = '\0';

	DBG_NODE(p);
	return p;
}

static inline LONG hexstr2long(const char *input)
{
	int i, len;
	LONG val;
	len = strlen(input);
	i = 2;
	val = 0;
	while (i < len) {
		if (islower(input[i]))
			val = (val << 4) + input[i] - 'a' + 10;
		else if (isupper(input[i]))
			val = (val << 4) + input[i] - 'A' + 10;
		else
			val = (val << 4) + input[i] - '0';
		i++;
	}
	return val;
}

static inline LONG str2long(const char *str)
{
	if (str[1] == 'x')
		return hexstr2long(str);
	else
		return atoll(str);
}

nodeType *long_param(LONG n)
{
	nodeType *p;
	const char *param;
	int shift;
	LONG value;
	size_t nodeSize;

	DBG("come in function\n");

	if (n < 0 || n >=(batch_argcnt - 1)) {
		yyerror("invalid str param number");
		return NULL;
	}
	/*
	 * input: 
	 * batch test.cr param1 param2
	 * args[0] is batch, args[1] is test.cr, args[2] is param1
	 * We need:
	 * $0 is test.cr, $1 param1, $2 is param2
	 * so shift the input number
	 */
	shift = n + 1;
	param = batch_args[shift];
	value = str2long(param);

	nodeSize = SIZEOF_NODETYPE(p) + sizeof(longNodeType);
	p = malloc(nodeSize);
	if (p == NULL) {
		yyerror("con_long, malloc node failed!\n");
		return NULL;
	}

	p->type = typeLongCon;
	p->longCon.var = value;
	DBG_NODE(p);
	return p;
}

nodeType *opr(int oper, int nops, ...)
{
	va_list ap;
	nodeType *p;
	size_t nodeSize;
	int i;

	DBG("come in function\n");
	nodeSize = SIZEOF_NODETYPE(p) + sizeof(oprNodeType) +\
		(nops - 1) * sizeof(nodeType *);
	p = malloc(nodeSize);
	if (p == NULL) {
		yyerror("opr, malloc node failed\n");
		return NULL;
	}

	p->type = typeOpr;
	p->opr.name = oper;
	p->opr.number = nops;
	va_start(ap, nops);
	for (i = 0 ; i < nops ; i++) {
		p->opr.op[i] = va_arg(ap, nodeType *);
		if (p->opr.op[i] == NULL) {
			free(p);
			return NULL;
		}
	}
	va_end(ap);

	DBG_NODE(p);
	return p;
}

void freeNode(nodeType *p)
{
	int i;
	DBG("come in function\n");
	if (!p)
		return;
	if (p->type == typeOpr) {
		for (i = 0 ; i < p->opr.number ; i++)
			freeNode(p->opr.op[i]);
	} else if (p->type == typeStrCon) {
		free(p->strCon.ptr);
	}
	free(p);
}

void freeSymTable()
{
	int i;
	DBG("come in function\n");
	for (i = 0 ; i < symtop ; i++) {
		if (symtab[i].type == typeStr) {
			free(symtab[i].pstr);
			symtab[i].pstr = NULL;
		}
		free((void *)(symtab[i].name));
	}
	symtop = 0;
}

int call_crash_cmd(const char *input);
char *call_func(const char *input)
{
	FILE *fpr;
	char *p;
	long len;
	int ret;

	DBG("come in function\n");
	ret = call_crash_cmd(input);
	if (ret < 0)
		return NULL;

	fpr = fopen(TMP_FILE, "r");
	if (fpr == NULL) {
		yyerror("call_func, fopen failed\n");
		return NULL;
	}

	ret = fseek(fpr, 0, SEEK_END);
	if (ret != 0) {
		yyerror("call_func, SEEK_END failed\n");
		fclose(fpr);
		return NULL;
	}

	len = ftell(fpr);
	if (len < 0) {
		yyerror("call_func, ftell failed\n");
		fclose(fpr);
		return NULL;
	}

	ret = fseek(fpr, 0, SEEK_SET);
	if (ret != 0) {
		yyerror("call_func, SEEK_SET failed\n");
		fclose(fpr);
		return NULL;
	}

	p = malloc(len + 1);
	if (p == NULL) {
		yyerror("call_func, malloc failed\n");
		fclose(fpr);
		return NULL;
	}

	ret = fread(p, len, 1, fpr);
	if (ret <= 0) {
		yyerror("call_func, fread failed\n");
		fclose(fpr);
		free(p);
		return NULL;
	}
	p[len] = '\0';
	fclose(fpr);
	return p;
}

char *get_func(const char *input, long lineno,long start, long len)
{
	char *p;
	char *input1;
	int i;

	DBG("come in function\n");
	for (i = 0 ; i < lineno ; i++) {
		input = strchr(input, '\n');
		if (input == NULL)
			return NULL;
		input++;
	}

	if (len == -1) {
		input1 = strchr(input, '\n');
		if (input1 != NULL)
			len = input1 - input;
		else
			len = strlen(input);
	}

	p = malloc(len + 1);
	if (p == NULL) {
		yyerror("get_func, malloc failed\n");
		return NULL;
	}
	strncpy(p, input+start, len);
	p[len] = '\0';
	return p;
}

LONG lines_func(const char *input)
{
	LONG count;

	DBG("come in function\n");

	if (!input || strlen(input) == 0)
		return 0;
	count = 0;
	while (1) {
		input = strchr(input, '\n');
		if (!input)
			break;
		count++;
		input++;
	}
	if (count == 0)
		count++;
	return count;
}

void free_itpType(itpType *pret)
{
	DBG("come in function\n");
	if (pret == NULL)
		return;
	if (pret->type == typeStr && pret->pstr)
		free(pret->pstr);
	free(pret);
}

#define DBG_INTERPRET(pret) DBG("pret->type=%d ", pret->type);	\
	if(pret->type == typeStr)					\
		DBG("pstr=%s\n", pret->pstr);				\
	else if (pret->type == typeLongCon)				\
		DBG("ival=%d\n", pret->ival);				\
	else								\
		DBG("unknown itpType type\n")

itpType *interpret(nodeType *p)
{
	int nodeSize;
	int len, n;
	itpType *pret, *pret1, *pret2, *pret3, *pret4;

	DBG("come in function\n");
	if (p == NULL)
		return NULL;

	DBG_NODE(p);
	pret = malloc(sizeof(itpType));
	if (pret == NULL) {
		yyerror("interpret, malloc pret failed\n");
		return NULL;
	}

	pret->type = typeLong;
	pret->ival = 1;		/* default to return true */

	switch(p->type) {
	case typeLongCon:
		pret->ival = p->longCon.var;
		pret->type = typeLong;
		DBG_INTERPRET(pret);
		return pret;
		break;
	case typeStrCon:
		len = strlen(p->strCon.ptr);
		pret->pstr = malloc(len + 1);
		if (pret->pstr == NULL) {
			yyerror("interpret, typeStrCon malloc failed\n");
			free_itpType(pret);
			return NULL;
		}
		strncpy(pret->pstr, p->strCon.ptr, len);
		pret->pstr[len] = '\0';
		pret->type = typeStr;
		DBG_INTERPRET(pret);
		return pret;
		break;
	case typeVar:
		nodeSize = sizeof(symType);
		memcpy(pret, &symtab[p->var.index], nodeSize);
		if (pret->type == typeStr) {
			len = strlen(pret->pstr);
			pret->pstr = malloc(len + 1);
			if (pret->pstr == NULL) {
				yyerror("interpret, typeVar malloc failed\n");
				free_itpType(pret);
				return NULL;
			}
			strncpy(pret->pstr, symtab[p->var.index].pstr, len);
			pret->pstr[len] = '\0';
		}
		DBG_INTERPRET(pret);
		return pret;
		break;
	case typeOpr:
		switch(p->opr.name) {
		case WHILE:
			pret1 = interpret(p->opr.op[0]);
			if (pret1 == NULL) {
				free_itpType(pret);
				return NULL;
			}
			while ((pret1->type == typeLong && pret1->ival) ||
				(pret1->type == typeStr && pret1->pstr)) {
				pret2 = interpret(p->opr.op[1]);
				free_itpType(pret1);
				free_itpType(pret2);
				pret1 = interpret(p->opr.op[0]);
				if (pret1 == NULL) {
					free_itpType(pret);
					return NULL;
				}
			}
			free_itpType(pret1);
			DBG_INTERPRET(pret);
			return pret;
			break;
		case IF:
			pret1 = interpret(p->opr.op[0]);
			if (pret1 == NULL)
				return NULL;
			if ((pret1->type == typeLong && pret1->ival) ||
				(pret1->type == typeStr && pret1->pstr)) {
				pret2 = interpret(p->opr.op[1]);
				free_itpType(pret1);
				free_itpType(pret2);
			} else if (p->opr.number > 2) {
				pret2 = interpret(p->opr.op[2]);
				free_itpType(pret1);
				free_itpType(pret2);
			}
			DBG_INTERPRET(pret);
			return pret;
		case PRINT:
			pret1 = interpret(p->opr.op[0]);
			if (pret1 == NULL)
				return NULL;
			if (pret1->type == typeLong)
				PRINTLONG(pret1);
			else if (pret1->type == typeStr)
				PRINTSTR(pret1);
			free_itpType(pret1);
			DBG_INTERPRET(pret);
			return pret;
			break;
		case ';':
			pret1 = interpret(p->opr.op[0]);
			pret2 = interpret(p->opr.op[1]);
			if (pret1)
				free_itpType(pret1);
			if (pret2)
				free_itpType(pret2);
			DBG_INTERPRET(pret);
			return pret;
			break;
		case '=':
			pret2 = interpret(p->opr.op[1]);
			if (pret2 == NULL)
				return NULL;
			if (pret2->type == typeLong)
				symtab[p->opr.op[0]->var.index].ival = pret2->ival;
			else if (pret2->type == typeStr) {
				if (symtab[p->opr.op[0]->var.index].type == typeStr)
					free(symtab[p->opr.op[0]->var.index].pstr);
				symtab[p->opr.op[0]->var.index].pstr = pret2->pstr;
			}
			symtab[p->opr.op[0]->var.index].type = pret2->type;
			free(pret2); /* do not free pret2->pstr, as it is used by the variable */
			DBG_INTERPRET(pret);
			return pret;
			break;
		case UMINUS:
			pret1 = interpret(p->opr.op[0]);
			if (pret1 == NULL)
				return NULL;
			if (pret1->type == typeLong) {
				pret->type = typeLong;
				pret->ival = -pret1->ival;
			} else {
				free_itpType(pret1);
				free_itpType(pret);
				return NULL;
			}
			free_itpType(pret1);
			DBG_INTERPRET(pret);
			return pret;
			break;
		case PP:
			if (symtab[p->opr.op[0]->var.index].type == typeLong) {
				symtab[p->opr.op[0]->var.index].ival += 1;
				pret->type = typeLong;
				pret->ival = symtab[p->opr.op[0]->var.index].ival;
			} else {
				free_itpType(pret);
				return NULL;
			}
			DBG_INTERPRET(pret);
			return pret;
			break;
		case SS:
			if (symtab[p->opr.op[0]->var.index].type == typeLong) {
				symtab[p->opr.op[0]->var.index].ival -= 1;
				pret->type = typeLong;
				pret->ival = symtab[p->opr.op[0]->var.index].ival;
			} else {
				free_itpType(pret);
				return NULL;
			}
			DBG_INTERPRET(pret);
			return pret;
			break;
		case '+':
			pret1 = interpret(p->opr.op[0]);
			pret2 = interpret(p->opr.op[1]);
			if (pret1 == NULL || pret2 == NULL) {
				if (pret1 == NULL)
					free_itpType(pret2);
				if (pret2 == NULL)
					free_itpType(pret1);
				free_itpType(pret);
				return NULL;
			}
			if (pret1->type == typeLong && pret2->type == typeLong) {
				pret->type = typeLong;
				pret->ival = pret1->ival + pret2->ival;
				free_itpType(pret1);
				free_itpType(pret2);
				DBG_INTERPRET(pret);
				return pret;
			} else if (pret1->type == typeStr && pret2->type == typeStr) {
				int m = strlen(pret1->pstr);
				int n = strlen(pret2->pstr);
				char *s = malloc(m+n+1);
				if (s == NULL) {
					free_itpType(pret1);
					free_itpType(pret2);
					free_itpType(pret);
					return NULL;
				}
				strncpy(s, pret1->pstr, m);
				s[m] = '\0';
				strncat(s, pret2->pstr, n);
				s[m+n] = '\0';
				free_itpType(pret1);
				free_itpType(pret2);
				pret->type = typeStr;
				pret->pstr = s;
				DBG_INTERPRET(pret);
				return pret;
			} else {
				yyerror("add type not match\n");
				free_itpType(pret1);
				free_itpType(pret2);
				free_itpType(pret);
				return NULL;
			}
			break;
		case '-':
		case '*':
		case '/':
		case '<':
		case '>':
		case '%':
		case AND:
		case OR:
		case GE:
		case LE:
			pret1 = interpret(p->opr.op[0]);
			pret2 = interpret(p->opr.op[1]);
			if (pret1 == NULL || pret2 == NULL) {
				if (pret1 == NULL)
					free_itpType(pret2);
				if (pret2 == NULL)
					free_itpType(pret1);
				free_itpType(pret);
				return NULL;
			}
			if (pret1->type == typeLong && pret2->type == typeLong) {
				pret->type = typeLong;
				if (p->opr.name == '-')
					pret->ival = pret1->ival - pret2->ival;
				else if (p->opr.name == '*')
					pret->ival = pret1->ival * pret2->ival;
				else if (p->opr.name == '/')
					pret->ival = pret1->ival / pret2->ival;
				else if (p->opr.name == '<')
					pret->ival = pret1->ival < pret2->ival;
				else if (p->opr.name == '>')
					pret->ival = pret1->ival > pret2->ival;
				else if (p->opr.name == '%')
					pret->ival = pret1->ival % pret2->ival;
				else if (p->opr.name == AND)
					pret->ival = pret1->ival && pret2->ival;
				else if (p->opr.name == OR)
					pret->ival = pret1->ival || pret2->ival;
				else if (p->opr.name == GE)
					pret->ival = pret1->ival >= pret2->ival;
				else if (p->opr.name == LE)
					pret->ival = pret1->ival <= pret2->ival;
				free_itpType(pret1);
				free_itpType(pret2);
				DBG_INTERPRET(pret);
				return pret;
			} else {
				yyerror("type not match\n");
				free_itpType(pret1);
				free_itpType(pret2);
				free_itpType(pret);
				return NULL;
			}
			break;
		case EQ:
		case NE:
			pret1 = interpret(p->opr.op[0]);
			pret2 = interpret(p->opr.op[1]);
			if (pret1 == NULL || pret2 == NULL) {
				if (pret1 == NULL)
					free_itpType(pret2);
				if (pret2 == NULL)
					free_itpType(pret1);
				free_itpType(pret);
				return NULL;
			}
			if (pret1->type == typeLong && pret2->type == typeLong) {
				pret->type = typeLong;
				if (p->opr.name == EQ)
					pret->ival = pret1->ival == pret2->ival;
				else if (pret->type == NE)
					pret->ival = pret1->ival != pret2->ival;
				free_itpType(pret1);
				free_itpType(pret2);
				DBG_INTERPRET(pret);
				return pret;
			} else if (pret1->type == typeStr && pret2->type == typeStr) {
				pret->type == typeLong;
				if (p->opr.name == EQ)
					pret->ival = !strcmp(pret1->pstr, pret2->pstr);
				else if (p->opr.name == NE) {
					pret->ival = !!strcmp(pret1->pstr, pret2->pstr);
				}
				free_itpType(pret1);
				free_itpType(pret2);
				DBG_INTERPRET(pret);
				return pret;
			} else {
				yyerror("add type not match\n");
				free_itpType(pret1);
				free_itpType(pret2);
				free_itpType(pret);
				return NULL;
			}
			break;
		case CALL:
			pret1 = interpret(p->opr.op[0]);
			if (pret1 == NULL) {
				free_itpType(pret);
				return NULL;
			}
			if (pret1->type != typeStr) {
				free_itpType(pret1);
				free_itpType(pret);
				return NULL;
			}
			pret->type = typeStr;
			pret->pstr = call_func(pret1->pstr);
			free_itpType(pret1);
			if (pret->pstr == NULL) {
				free_itpType(pret);
				return NULL;
			}
			DBG_INTERPRET(pret);
			return pret;
			break;
		case GET:
			pret1 = interpret(p->opr.op[0]);
			pret2 = interpret(p->opr.op[1]);
			pret3 = interpret(p->opr.op[2]);
			pret4 = interpret(p->opr.op[3]);
			if (pret1->type == typeStr && pret2->type == typeLong &&
				pret3->type == typeLong && pret4->type == typeLong) {
				pret->type = typeStr;
				pret->pstr = get_func(pret1->pstr, pret2->ival, pret3->ival, pret4->ival);
				if (pret->pstr == NULL) {
					free_itpType(pret);
					pret = NULL;
				}
			}
			free_itpType(pret1);
			free_itpType(pret2);
			free_itpType(pret3);
			free_itpType(pret4);
			DBG_INTERPRET(pret);
			return pret;
			break;
		case LINES:
			pret1 = interpret(p->opr.op[0]);
			pret->type = typeLong;
			if (pret1->type == typeStr)
				pret->ival = lines_func(pret1->pstr);
			else
				pret->ival = 0;
			free_itpType(pret1);
			DBG_INTERPRET(pret);
			return pret;
			break;
		case LEN:
			pret1 = interpret(p->opr.op[0]);
			pret->type = typeLong;
			if (pret1->type == typeStr)
				pret->ival = strlen(pret1->pstr);
			else
				pret->ival = 0;
			free_itpType(pret1);
			DBG_INTERPRET(pret);
			return pret;
			break;
		case STR2LONG:
			pret1 = interpret(p->opr.op[0]);
			pret->type = typeLong;
			if (pret1->type != typeStr) {
				yyerror("str2long need a string as param\n");
				free_itpType(pret1);
				free_itpType(pret);
				return NULL;
			}
			pret->ival = str2long(pret1->pstr);
			free_itpType(pret1);
			return pret;
			break;
		default:
			yyerror("bad operator!\n");
		}
	default:
		yyerror("bad node type!\n");
	}
	pret->ival = 0;
	return pret;
}
