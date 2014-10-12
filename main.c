/*  Compiladores 2014/2 - Etapa 3
    Felipe Prusokowski e Raffael Nagel

*/				
		
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
#include "lex.yy.h"

FILE *out_file;
extern int running;
extern int lineNumber;

int main(int argc, char *argv[])
{
int token;
int i =0;
	if (argc == 3)  
	{
			yyin=fopen(argv[1], "r");
			out_file = fopen(argv[2], "w");	
			yyparse();
			hashPrint();
			printf ("Finalizado com sucesso\n");
			exit(0);
	}
	else
	{
		printf ("Erro de input!\n");
		return 1;
	}
}	
