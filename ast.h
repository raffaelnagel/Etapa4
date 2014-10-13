/*  Compiladores 2014/2 - Etapa 3
    Felipe Prusokowski e Raffael Nagel

*/				
		
#include "hash.h"
#define NOT_OPEN 0
#define OPENED 1
#define MAX_SONS 4
#define AST_SYMBOL 1
#define AST_ADD  2
#define AST_SUB 3
#define AST_MUL 4
#define AST_DIV 5
#define AST_LCMD 6
#define AST_LE 7
#define AST_GE 8
#define AST_EQ 9
#define AST_NE 10
#define AST_AND 11
#define AST_OR 12
#define AST_GREATER 13
#define AST_LESS 14
#define AST_ATRIB 15
#define AST_REFERENCE 16
#define AST_PAR_EXPR 17
#define AST_FUNC_CALL 18
#define AST_DE_REFERENCE 19
#define AST_RETURN 20
#define AST_IF 21
#define AST_CMD_THEN 22
#define AST_CMD_ELSE 23
#define AST_CMD_LOOP 24
#define AST_INDEX 25
#define AST_IN 26
#define AST_BLOCO 27
#define AST_LISTCMD 28
#define AST_WORD 29
#define AST_BYTE 30
#define AST_BOOL 31
#define AST_FUN_DEF 32
#define AST_NDEC 33
#define AST_POINTER_DEC 34
#define AST_ARRAY_DEC 35
#define AST_LIT_ATRIB 36
#define AST_PROGRAM 37
#define AST_DEC 38
#define AST_OUTARGS 39
#define AST_OUT 40
#define AST_PARAM_REF 41
#define AST_PARAM 42
#define AST_DECLARACAO 43
#define AST_PASS_PARAM 44
#define AST_NEG_EXPR 45
#define AST_BOOLEAN_NEG 46
#define AST_ARIT_NEG 47
#define AST_LIT_INTEGER	   48
#define AST_LIT_CHAR    49
#define AST_LIT_TRUE    50
#define AST_LIT_FALSE	    51
#define AST_VETOR 52
#define AST_OUTARGS_STRING 53
#define AST_OUTARGS_EXPR 54


typedef struct ast_node
{
	HASH *symbol;
	int type;
	struct ast_node *sons[MAX_SONS];
	//etapa 4
	int lineNumber; 
} ast;



ast *astCreate(int type, HASH *symbol, ast *s0,ast *s1, ast *s2, ast *s3);
void astPrintNode( ast *node);
void astPrintTree (ast *node,int level);
void decompile(ast *root);
//etapa 4
void astSetDeclarations(ast *root);
void astCheckDeclarations(ast *root);
int astCheckNature(ast *root);
int astGetNature(ast *root);
