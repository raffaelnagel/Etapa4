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
		|| tree->type == AST_DE_REFERENCE || tree->type == AST_FUNC_CALL || tree->type == AST_VETOR || tree->type == AST_ATRIB){	
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
						astCheckNature_ARRAY_DEC(tree);
						a[1] = 1;
						break;
			case AST_IN:
						astCheckNature_IN(tree);
						a[0] = 1;
						break;
			case AST_ATRIB:
						symbol = (HASH*) tree->symbol;
						if(!symbol)return 0;	
						switch(symbol->type){
							case TYPE_VEC:
									if(!tree->sons[0]){
										fprintf(stderr,"Line %d: Vector without index\n",tree->lineNumber);
									}
									else{
										
										if(astCheckNature(tree->sons[0]) != TYPE_VAR){
											fprintf(stderr,"Line %d: index of vector is not scalar\n",tree->lineNumber);
											a[0] = 1;
										}
										if(astCheckNature(tree->sons[1]) != TYPE_VAR){
												fprintf(stderr,"Line %d: nature of left side and right side doesn't match\n",tree->lineNumber);
												a[1] = 1;
										}
									}
									break;
							case TYPE_POINT:
							case TYPE_VAR:						
									if(astCheckNature(tree->sons[0]) != symbol->type){
										fprintf(stderr,"Line %d: nature of left side and right side doesn't match\n",tree->lineNumber);
										a[0] = 1;
									} 
									break;
							default:fprintf(stderr,"Line %d: attribution error\n",tree->lineNumber);
									break;
						}
						break;			
			case AST_OUT:
						astCheckNature(tree->sons[0]);
						a[0] = 1;
						break;
			case AST_OUTARGS_STRING:
						if(tree->symbol){
							if(tree->sons[0]){
								return astCheckNature(tree->sons[0]);
							}
							else{
								return TYPE_VAR;
							}
						}
						break;
			case AST_OUTARGS_EXPR:
						if(tree->sons[0]){			
							astCheckNature(tree->sons[0]);
							if(tree->sons[1]){
								if(astCheckNature(tree->sons[1]) == TYPE_VAR){
									a[1] = 1;
									return TYPE_VAR;
								}								
							}
						}
						break;
			case AST_RETURN:
						if(astCheckNature(tree->sons[0]) != TYPE_VAR){
							fprintf(stderr,"Line %d: nature of return invalid, expected scalar value\n",tree->lineNumber);
							a[0] = 1;
						}
						break;
			case AST_IF:
						if(astCheckNature(tree->sons[0]) != TYPE_VAR){
							fprintf(stderr,"Line %d: nature of if expression invalid, expected scalar value\n",tree->lineNumber);
							a[0] = 1;
						}
						break;
			case AST_INDEX:
						symbol = (HASH*) tree->symbol;
						switch(symbol->type)
						{
							case TYPE_VEC:   fprintf(stderr,"Line %d: Vector used as scalar\n",tree->lineNumber); 
									 break;
							case TYPE_FUN:   fprintf(stderr,"Line %d: Function used as a scalar\n",tree->lineNumber);
									 break;
							case TYPE_VAR:
							case TYPE_POINT: return symbol->type;
									 break;
							default: break;
						}
						break;
			case AST_VETOR: 
						symbol = (HASH*) tree->symbol;
						switch(symbol->type)
						{
							case TYPE_VAR:   fprintf(stderr,"Line %d: scalar used as vector\n",tree->lineNumber); 
									 break;
							case TYPE_FUN:   fprintf(stderr,"Line %d: Function used as vector\n",tree->lineNumber);
									 break;
							case TYPE_POINT: fprintf(stderr,"Line %d: Pointer used as vector\n",tree->lineNumber);
									 break;
							case TYPE_VEC:   
									if(astCheckNature(tree->sons[0]) != TYPE_VAR){
										fprintf(stderr,"Line %d: index of vector is not scalar\n",tree->lineNumber);
										a[0] = 1;
									 }
									 return TYPE_VAR;
									 break;
							default: break;
						}
						break;
			case AST_REFERENCE: 
						symbol = (HASH*) tree->symbol;
						switch(symbol->type)
						{
							case TYPE_VEC: fprintf(stderr,"Line %d: Vector used as scalar\n",tree->lineNumber);
									   break;
							case TYPE_FUN: fprintf(stderr,"Line %d: Function used as scalar\n",tree->lineNumber);
									   break;
							case TYPE_POINT: fprintf(stderr,"Line %d: Pointer used as scalar\n",tree->lineNumber);
									   break;
							case TYPE_VAR:   return TYPE_POINT;
									   break;
							default:   break; 
						}
						break;
			case AST_DE_REFERENCE: 
						symbol = (HASH*) tree->symbol;
						switch(symbol->type){
							case TYPE_VEC: fprintf(stderr,"Line %d: Vector used as pointer\n",tree->lineNumber);
									   break;
							case TYPE_FUN: fprintf(stderr,"Line %d: Function used as pointer\n",tree->lineNumber);
									   break;
							case TYPE_VAR: fprintf(stderr,"Line %d: Scalar used as pointer\n",tree->lineNumber);
									   break;
							case TYPE_POINT: return TYPE_VAR;
									   break;
							default:   break; 
						}
						break;
			case AST_FUNC_CALL:
						symbol = (HASH*) tree->symbol;
						switch(symbol->type)
						{
							case TYPE_VEC: fprintf(stderr,"Line %d: Vector used as function\n",tree->lineNumber);
									   break;
							case TYPE_FUN: 
									   //if(astree_naturecheck_args(tree)){
									  //	return TYPE_VAR;
									  // }
									   return TYPE_FUN;
									   break;
							case TYPE_VAR: fprintf(stderr,"Line %d: Scalar used as function\n",tree->lineNumber);
									   break;
							case TYPE_POINT: fprintf(stderr,"Line %d: Pointer used as function\n",tree->lineNumber);
									   break;
							default:   break; 
						}
						break;
			case AST_NEG_EXPR:
						if(tree->sons[0]){
							nature1 = astCheckNature(tree->sons[0]);
							a[0] = 1;
							if(nature1 == TYPE_VAR){
								return TYPE_VAR;
							}
							else{
								fprintf(stderr,"Line %d: Expected a scalar\n",tree->lineNumber);
							}
						}
						break;
			case AST_SUB:
						if(tree->sons[1]){
							nature1 = astCheckNature(tree->sons[0]);
							nature2 = astCheckNature(tree->sons[1]);
							a[0] = 1;
							a[1] = 1;
							if(nature1 == TYPE_VAR && nature2 == TYPE_VAR){
								return TYPE_VAR;
							}
							else{
								fprintf(stderr,"Line %d: Invalid subtraction/multiply/division, just allowed those operations of aritmetics\n",tree->lineNumber);
							}
						}
						else{
							nature1 = astCheckNature(tree->sons[0]);
							a[0] = 1;
							if(nature1 == TYPE_VAR){
								return TYPE_VAR;
							}
							else{
								fprintf(stderr,"Line %d: Invalid subtraction/multiply/division, just allowed those operations of aritmetics\n",tree->lineNumber);
							}
						}
						break;
			case AST_LE:
			case AST_GE:
			case AST_EQ:
			case AST_NE:
			case AST_AND:
			case AST_OR:
			case AST_GREATER:
			case AST_LESS:
						if(tree->sons[1] && tree->sons[0]){
							nature1 = astCheckNature(tree->sons[0]);
							nature2 = astCheckNature(tree->sons[1]);
							a[0] = 1;
							a[1] = 1;
							if(nature1 == TYPE_VAR && nature2 == TYPE_VAR){
								return TYPE_VAR;
							}
							else{
								fprintf(stderr,"Line %d: Invalid logic expression, just allowed binary logic expressions of 2 aritmetics or booleans\n",tree->lineNumber);
							}
						}
						break;
			case AST_MUL:
			case AST_DIV:
						if(tree->sons[1] && tree->sons[0]){
							nature1 = astCheckNature(tree->sons[0]);
							nature2 = astCheckNature(tree->sons[1]);
							a[0] = 1;
							a[1] = 1;
							if(nature1 == TYPE_VAR && nature2 == TYPE_VAR){
								return TYPE_VAR;
							}
							else{
								fprintf(stderr,"Line %d: Invalid subtraction/multiply/division, just allowed those operations of aritmetics\n",tree->lineNumber);
							}
						}
						break;
			case AST_ADD:
						if(tree->sons[1] && tree->sons[0]){
							nature1 = astCheckNature(tree->sons[0]);
							nature2 = astCheckNature(tree->sons[1]);
							a[0] = 1;
							a[1] = 1;
							if(nature1 == TYPE_VAR && nature2 == TYPE_VAR){
								return TYPE_VAR;
							}
							else{
								if(nature1 == TYPE_VAR && nature2 == TYPE_POINT){
									return TYPE_POINT;
								}
								else{
									if(nature1 == TYPE_POINT && nature2 == TYPE_VAR){
										return TYPE_POINT;
									}
									else{
										fprintf(stderr,"Line %d: Invalid sum, just allowed sum of 2 aritmetics or 1 aritmetic and 1 pointer \n",tree->lineNumber);
									}
								}
							}
						}
						break;
			case AST_LIT_INTEGER:
			case AST_LIT_CHAR:
			case AST_LIT_TRUE:
			case AST_LIT_FALSE:
						return TYPE_VAR;
						break;
			case AST_PAR_EXPR:
						a[0] = 1;			
						return astCheckNature(tree->sons[0]);
						break;
			case AST_PASS_PARAM:
						astCheckNature(tree->sons[1]);
						a[1] = 1;
						return astCheckNature(tree->sons[0]);
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
		
		case AST_VETOR: 
				if(tree->sons[0]){
					symbol = (HASH*) tree->symbol;
					if(astGetNature(tree->sons[0]) == DATATYPE_WORD){				
						if(symbol)
							return symbol->dataType;
						else
							return DATATYPE_INVALID;
					}
					else{
						printf("Line %d: Incompatible index value for vector\n",tree->lineNumber);
						if(symbol)
							return symbol->dataType;
						else
							return DATATYPE_INVALID;
					}
				}
				break;
		case AST_LIT_INTEGER:
		case AST_LIT_CHAR:
		case AST_ADD:
		case AST_SUB:
		case AST_MUL:
		case AST_DIV:
				return DATATYPE_WORD;
				break;
		case AST_LIT_TRUE:
		case AST_LIT_FALSE:
		case AST_EQ:
		case AST_LE:
		case AST_GE:
		case AST_NE:
		case AST_AND:
		case AST_OR:
		case AST_GREATER:
		case AST_LESS:
				return DATATYPE_BOOL;
				break;
		case AST_PAR_EXPR:
		case AST_NEG_EXPR:
				if (tree->sons[0])
					return astGetNature(tree->sons[0]); 
				break;
		
	}	
}

int astCheckNature_ARRAY_DEC(ast *tree){
	if(astGetNature(tree->sons[1]) == DATATYPE_BOOL)
			{
				fprintf(stderr,"Line %d: index of vector is not scalar\n",tree->lineNumber);
			} 
			if(astCheckNature(tree->sons[1]) != TYPE_VAR)
			{
				printf("%d\n", astCheckNature(tree->sons[1]));				
				fprintf(stderr,"Line %d: index of vector is not scalar\n",tree->lineNumber);				
			}
}

int astCheckNature_IN(ast *tree){
	HASH* symbol = (HASH*) tree->symbol;
	switch(symbol->type)
	{
		case TYPE_VAR:  
				if(tree->sons[0])
					fprintf(stderr,"Line %d: Scalar symbol used as a vector\n",tree->lineNumber);
				break;
		case TYPE_VEC:  
				if(!tree->sons[0]){
					fprintf(stderr,"Line %d: Vector without index\n",tree->lineNumber);
				}
				else{
					if(astCheckNature(tree->sons[0]) != TYPE_VAR){
						fprintf(stderr,"Line %d: index of vector is not scalar\n",tree->lineNumber);
					}
				}
				break;
		default: fprintf(stderr,"Line %d: Function/Pointer used in input command, only accept scalar or indexed vector\n",tree->lineNumber);
	}
}









