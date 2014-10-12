/*  Compiladores 2014/2 - Etapa 3
    Felipe Prusokowski e Raffael Nagel

*/				
		

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

extern FILE *out_file;
int first_time=NOT_OPEN;
ast* astCreate(int type, HASH *symbol, ast *s0,ast *s1, ast *s2, ast *s3)
{
	ast *newnode;
	newnode= (ast*) calloc(1,sizeof(ast));
	newnode->lineNumber = getLineNumber();
	newnode->type = type;
	newnode->symbol = symbol;
	newnode->sons[0]= s0;
	newnode->sons[1]= s1;
	newnode->sons[2]= s2;
	newnode->sons[3]= s3;
	return newnode;
};

void astPrintNode ( ast *node)
{
	if(node==0)
		return;
	printf("ast:");
	switch(node->type)
	{
		case AST_LIT_INTEGER:
		case AST_LIT_CHAR:
		case AST_LIT_TRUE:
		case AST_LIT_FALSE:
		case AST_VETOR:
		 { printf("symbol ");}
		break;
		case AST_ADD: { printf("add ");}
		break;
		case AST_SUB: {printf("sub ");}
		break;
		case AST_MUL: {printf("mul ");}
		break;
		case AST_DIV: {printf("div ");}
		break;
		case AST_LCMD: {printf("lcmd ");}
		break;
		case AST_ATRIB: {printf("atrib ");}
		break;
		case AST_REFERENCE : {printf("reference ");};
		break;
		case AST_PAR_EXPR: {printf("parenteses expr");}
		break;
		case AST_FUNC_CALL: {printf("func call ");}
		break;
		case AST_DE_REFERENCE: {printf("de-reference ");}
		break;
		case AST_RETURN: {printf("return ");}
		break;
		case AST_IF : {printf("if ");}
		break;
		case AST_CMD_THEN : {printf("then ");}
		break;
		case AST_CMD_ELSE : {printf("else ");}
		break;
		case AST_CMD_LOOP: {printf("loop ");}
		break;
		case AST_INDEX: {printf("index ");}
		break;
		case AST_IN: {printf("input ");}
		break;
		case AST_BLOCO: {printf("block ");}
		break;
		case AST_LISTCMD: {printf("cmd list ");}
		break;
		case AST_BOOL: {printf(" bool type");}
		break;
		case AST_WORD: {printf(" word type");}
		break;
		case AST_BYTE: {printf(" byte type");}
		break;
		case AST_FUN_DEF: { printf(" function definition ");}
		break;
		case AST_NDEC: {printf(" var declaration ");}
		break;
		case AST_POINTER_DEC: {printf(" pointer declaration ");}
		break;
		case AST_ARRAY_DEC: {printf(" array declaration ");}
		break;
		case AST_LIT_ATRIB: {printf(" literal of array declaration ");}
		break;
		case AST_PROGRAM: {printf("program is ... ");}
		break;
		case AST_OUTARGS: {printf("out arguments ");}
		break;
		case AST_OUT: {printf("output ");}
		break;
		case AST_PARAM: {printf("parametro ");}
		break;
		case AST_PASS_PARAM: {printf("parametro ");}
		break;
		case AST_PARAM_REF: {printf("parametro  ref");}
		break;
		case AST_DECLARACAO: {printf(" declaracao var + fun  ");}
		break;
		case AST_DEC: {printf(" declaracao var ");}
		break;
		default: {printf("comando errado");}
		break;
	}
	if(node->symbol)
		printf("%s \n",node->symbol->text);
	else
		printf("\n");
}

void astPrintTree (ast* node, int level){
	int i = 0;
	int j = 0;
	if (!node)
		return;

	for (j = 0; j < level; ++j)
		fprintf(stderr, " ");
	printf("%d",level);

	astPrintNode(node);

	for (i = 0; i < MAX_SONS; ++i){
		if(node->sons[i])
			astPrintTree(node->sons[i], level + 1);
	}

}

void decompile(ast *root)
{
	
	if (root !=0)
	{
	switch(root->type)
	{
		case AST_PROGRAM :	{
				  	decompile(root->sons[0]);}
		break;
		case AST_DECLARACAO :	{
				      	decompile(root->sons[0]);
					decompile(root->sons[1]);
					fprintf(out_file,";\n");
				      	}
		break;
		case AST_DEC:		{
					decompile(root->sons[0]);
					decompile(root->sons[1]);
					fprintf(out_file,";\n");
					}
		break;
		case AST_NDEC:  	{decompile(root->sons[0]);
			     		fprintf(out_file,"%s : ",root->symbol->text);
					decompile(root->sons[1]);
					}
		break;
		case AST_POINTER_DEC: 	{decompile(root->sons[0]);
					fprintf(out_file,"$%s : ",root->symbol->text); 
					decompile(root->sons[1]);
					}
		break;
		case AST_ARRAY_DEC: 	{decompile(root->sons[0]);
					fprintf(out_file,"%s[",root->symbol->text);
					decompile(root->sons[1]);
					fprintf(out_file,"]");
					if(root->sons[2] !=0)
						fprintf(out_file,":");
					decompile(root->sons[2]);
					}
		break;
		case AST_LIT_ATRIB :	{
					decompile(root->sons[0]);
					decompile(root->sons[1]);
					}
		break;
		case AST_FUN_DEF:	{ decompile(root->sons[0]);
					fprintf(out_file,"%s (",root->symbol->text); 
					decompile(root->sons[1]);
					fprintf(out_file,")");
					fprintf(out_file,"\n");
					decompile(root->sons[2]); 
					}
		break;
		case AST_PARAM:		{decompile(root->sons[0]);
					fprintf(out_file,"%s",root->symbol->text); 
					if(root->sons[1] !=0)
						fprintf(out_file,",");
					decompile(root->sons[1]);
					}
		break;
		case AST_BLOCO:		{
					fprintf(out_file,"{\n");
					decompile(root->sons[0]);
					fprintf(out_file,"}\n");					
					}
		break;
		case AST_LISTCMD:	{decompile(root->sons[0]);
					if(root->sons[1]!=0)
						fprintf(out_file,";\n");
					decompile(root->sons[1]);
					}
		break;
		case AST_IN:		{fprintf(out_file,"input ");
					fprintf(out_file,"%s",root->symbol->text); 
					decompile(root->sons[1]);
					}
		break;
		case AST_ATRIB: 	{decompile(root->sons[0]);
					fprintf(out_file,"= ");
					decompile(root->sons[1]);
					}
		break;
		case AST_RETURN:	{fprintf(out_file,"return ");
					decompile(root->sons[0]);
					}
		break;
		case AST_OUT:		{fprintf(out_file,"output ");
					decompile(root->sons[0]);
					}
		break;
		case AST_OUTARGS:	{if(root->symbol !=0)
						fprintf(out_file,"%s ",root->symbol->text);
					decompile(root->sons[0]);
					if(root->sons[1]!=0)
						fprintf(out_file,", ");
					decompile(root->sons[1]);					
					}
		break;
		case AST_IF:		{fprintf(out_file,"if (");
					decompile(root->sons[0]);
					fprintf(out_file,") ");
					decompile(root->sons[1]);
					decompile(root->sons[2]);
					}
		break;
		case AST_CMD_THEN:	{fprintf(out_file,"then ");}
		break;
		case AST_CMD_ELSE:	{fprintf(out_file,"else ");}
		break;
		case AST_CMD_LOOP:	{fprintf(out_file,"loop ");}
		break;
		case AST_INDEX:		{fprintf(out_file,"[");
					decompile(root->sons[0]);
					fprintf(out_file,"]");
					}
		break;
		case AST_REFERENCE:	{fprintf(out_file,"&%s ",root->symbol->text);
					}
		break;
		case AST_DE_REFERENCE: 	{ fprintf(out_file,"$%s ",root->symbol->text);
					}
		break;
		case AST_ADD:		{decompile(root->sons[0]);
					fprintf(out_file,"+ ");
					decompile(root->sons[1]);
					}
		break;
		case AST_SUB:		{decompile(root->sons[0]);
					fprintf(out_file,"- ");
					decompile(root->sons[1]);
					}
		break;
		case AST_MUL:		{decompile(root->sons[0]);
					fprintf(out_file,"* ");
					decompile(root->sons[1]);
					}
		break;
		case AST_DIV:		{decompile(root->sons[0]);
					fprintf(out_file,"/ ");
					decompile(root->sons[1]);
					}
		break;
		case AST_GREATER:	{decompile(root->sons[0]);
					fprintf(out_file,"> ");
					decompile(root->sons[1]);
					}
		break;
		case AST_LESS:		{decompile(root->sons[0]);
					fprintf(out_file,"< ");
					decompile(root->sons[1]);
					}
		break;
		case AST_AND:		{decompile(root->sons[0]);
					fprintf(out_file,"&& ");
					decompile(root->sons[1]);
					}
		break;
		case AST_OR:		{decompile(root->sons[0]);
					fprintf(out_file,"|| ");
					decompile(root->sons[1]);
					}
		case AST_LE:		{decompile(root->sons[0]);
					fprintf(out_file,"<= ");
					decompile(root->sons[1]);
					}
		break;
		case AST_GE:		{decompile(root->sons[0]);
					fprintf(out_file,">= ");
					decompile(root->sons[1]);
					}
		break;	
		case AST_EQ:		{decompile(root->sons[0]);
					fprintf(out_file,"== ");
					decompile(root->sons[1]);
					}
		break;
		case AST_NE:		{decompile(root->sons[0]);
					fprintf(out_file,"!= ");
					decompile(root->sons[1]);
					}
		break;
		case AST_PAR_EXPR:	{fprintf(out_file,"(");
					decompile(root->sons[1]);
					fprintf(out_file,")");
					}
		break;
		case AST_FUNC_CALL:	{fprintf(out_file,"%s",root->symbol->text);
					fprintf(out_file,"(");
					decompile(root->sons[0]);
					fprintf(out_file,")");
					}
		break;
		case AST_PASS_PARAM:	{
					decompile(root->sons[0]);
					if(root->sons[1]!=0)
						fprintf(out_file,",");
					decompile(root->sons[1]);
					}
		break;
		case AST_NEG_EXPR:	{decompile(root->sons[0]);
					fprintf(out_file,"(");
					decompile(root->sons[1]);
					fprintf(out_file,")");
					}
		break;
		case AST_BOOLEAN_NEG:	{fprintf(out_file,"!");
					}
		break;
		case AST_ARIT_NEG:	{fprintf(out_file,"-");
					}
		break;
		case AST_WORD : 	{fprintf(out_file,"word ");}
		break;
		case AST_BYTE :		{fprintf(out_file,"byte ");}
		break;
		case AST_BOOL : 	{fprintf(out_file,"bool ");}
		break;
		case AST_SYMBOL :	{ fprintf(out_file,"%s ",root->symbol->text);
					decompile(root->sons[0]);}
		break;
		default:		{ printf("fim");}
		break;
	}
	}
}

////////////////////////////////////////////////////////////////////////
//////////////////////////  ETAPA 4 ////////////////////////////////////
////////////////////////////////////////////////////////////////////////
void astSetDeclarations(ast *tree)
{
	HASH *symbol;
	int i;
	
	if(tree->type == AST_NDEC || 
	   tree->type == AST_POINTER_DEC || 
	   tree->type == AST_ARRAY_DEC   || 
	   tree->type == AST_FUN_DEF){
	  
		symbol = (HASH*) tree->symbol;
		
		if (symbol->symbolType == SYMBOL_UNDEFINED) 
		{
			
			symbol->symbolType = SYMBOL_TK_IDENTIFIER;
			switch(tree->type)
			{
				case AST_NDEC: symbol->type = TYPE_VAR;
						  break;
				case AST_POINTER_DEC: symbol->type = TYPE_POINT;
						    break;
				case AST_ARRAY_DEC: symbol->type = TYPE_VEC;
						  break;
				case AST_FUN_DEF: symbol->type = TYPE_FUN;
						   symbol->list = tree->sons[1];
						  break;
				default: break;
			}
			switch(tree->sons[0]->type)
			{
				case AST_WORD: symbol->dataType = DATATYPE_WORD;
						    break;
				case AST_BOOL: symbol->dataType = DATATYPE_BOOL;
						    break;
				case AST_BYTE: symbol->dataType = DATATYPE_BYTE;
						    break;
				default: symbol->dataType = DATATYPE_INVALID;
				         break;
			}			
			
		}
		else 
			fprintf(stderr,"Line %d: Variable/Vector/Function/Pointer name redeclared\n",tree->sons[0]->lineNumber);
	}
	for (i = 0; i < 4; ++i)
    	   if (tree->sons[i])
              astSetDeclarations(tree->sons[i]);
}


void astCheckDeclarations(ast *tree)
{
	HASH* symbol;
	int i;
	if(tree)
	{		
		if(tree->type == AST_IN || tree->type == AST_INDEX || tree->type == AST_ATRIB || tree->type == AST_REFERENCE
		|| tree->type == AST_DE_REFERENCE || tree->type == AST_FUNC_CALL || tree->type == AST_VETOR ){	
			symbol = (HASH*) tree->symbol;
			if(symbol)
			{			
				if(symbol->symbolType == SYMBOL_UNDEFINED)
				{
					fprintf(stderr,"Line %d: Symbol undeclared\n",tree->lineNumber);
				}
			}
		}
	}
	for (i = 0; i < 4; ++i)
			if (tree->sons[i])
					astCheckDeclarations(tree->sons[i]);		
}

int astCheckNature(ast *tree){

	HASH* symbol;
	int i, nature1, nature2;
	int a[4] = {0, 0, 0, 0};
	
	if(tree){
	
		switch(tree->type){
		
			case AST_ARRAY_DEC:  
						break;
			case AST_IN:
						break;
			case AST_ATRIB: 
						break;			
			case AST_OUT:
						break;
			case AST_OUTARGS:
						break;
			case AST_RETURN:
						break;
			case AST_IF:
						break;
			case AST_INDEX:
						break;
			case AST_VETOR: //id + vetor
						break;
			case AST_REFERENCE: //& id
						break;
			case AST_DE_REFERENCE: // $ + id
						break;
			case AST_FUNC_CALL:
						break;
			case AST_NEG_EXPR:
						break;
			case AST_SUB:
						break;
			case AST_LE:
			case AST_GE:
			case AST_EQ:
			case AST_NE:
			case AST_AND:
			case AST_OR:
			case AST_GREATER:
			case AST_LESS:
						break;
			case AST_MUL:
			case AST_DIV:
						break;
			case AST_ADD:
						break;
			//case AST_SYMBOL:
			//			break;
			case AST_PAR_EXPR:
						break;
			case AST_PASS_PARAM:
						break;
			
		}	
		for (i = 0; i < 4; ++i)
    	   		if (tree->sons[i] && a[i] != 1)
              			astCheckNature(tree->sons[i]);
		
		return 1;	
	}
	return 0;
}

int astGetNature(ast *tree){
	
	HASH *symbol;
	int type = tree->type;
	
	if (tree==0)
		return DATATYPE_INVALID;
		
	switch(type){
		case AST_NDEC:
		case AST_POINTER_DEC:
		case AST_ARRAY_DEC:
		case AST_FUN_DEF:
		case AST_IN:
		case AST_ATRIB:
		case AST_INDEX:
		case AST_REFERENCE:
		case AST_DE_REFERENCE:
		case AST_FUNC_CALL:
				symbol = (HASH*) tree->symbol;
				if (symbol) 
					return symbol->dataType;
				else 
					return DATATYPE_INVALID;
				break;
		
		case AST_SYMBOL: //vector
				break;
		case AST_ADD:
		case AST_SUB:
		case AST_MUL:
		case AST_DIV:
				break;
		case AST_EQ:
		case AST_LE:
		case AST_GE:
		case AST_NE:
		case AST_AND:
		case AST_OR:
		case AST_GREATER:
		case AST_LESS:
				break;
		case AST_PAR_EXPR:
		case AST_NEG_EXPR:
				break;
		
	}	
}













