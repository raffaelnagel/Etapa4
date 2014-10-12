/*  Compiladores 2014/2 - Etapa 3
    Felipe Prusokowski e Raffael Nagel

*/				
//#include "ast.h"		
#ifndef HASH_HEADER
#define HASH_HEADER

#define HASH_SIZE 997

#define		SYMBOL_UNDEFINED	0
#define		SYMBOL_LIT_INTEGER	1
#define		SYMBOL_LIT_TRUE		2
#define		SYMBOL_LIT_FALSE	3
#define		SYMBOL_LIT_CHAR		4
#define		SYMBOL_LIT_STRING	5
#define		SYMBOL_TK_IDENTIFIER	6
#define		SYMBOL_VARIABLE		7
#define		SYMBOL_ARRAY		8
#define		SYMBOL_FUNCTION		9
#define		SYMBOL_POINTER		10

#define		DATATYPE_INVALID	0
#define		DATATYPE_WORD		1
#define		DATATYPE_BYTE		2
#define		DATATYPE_BOOL		3
#define		TYPE_VAR		4
#define		TYPE_VEC		5
#define		TYPE_FUN		6
#define		TYPE_POINT		7

typedef struct ast_node ast_;

typedef struct hash_node   /* definicao da struct contendo campos para todos os itpos possiveis - LIT_STRING, TK_IDENTIFIER */
	{				/* LIT_INTEGER, LIT_FLOATING, LIT_CHAR */
	char *text; 			
	int token;  
	int intValue; 
	double floatValue; 
	char charValue;
	int type;
	int symbolType;
	int dataType;
	ast_ *list;
	struct hash_node *next;
	}
	HASH;
	
	int hashAddress(char *name, int token);
	HASH* hashInsert(char *name,int token);
	HASH* hashFind(char *name, int token);
	void hashPrint(void);
	void hashInit(void);

#endif
