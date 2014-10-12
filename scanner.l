/*  Compiladores 2014/2 - Etapa 3
    Felipe Prusokowski e Raffael Nagel

*/				
					
		
/*declaracoes*/
%option noyywrap
%{
/* variaveis de controle de execucao e controle do numero de linhas*/
int Running = 1;
int lineNumber = 1;
char string[512];
char text[512];

#include "ast.h"
/*
#define SYMBOL_UNDEFINED 0
#define SYMBOL_LIT_INTEGER 1
#define SYMBOL_LIT_FLOATING 2
#define SYMBOL_LIT_TRUE 3
#define SYMBOL_LIT_FALSE 4
#define SYMBOL_LIT_CHAR 5
#define SYMBOL_LIT_STRING 6
#define SYMBOL_TK_IDENTIFIER 7
*/
	#include "hash.h"
	#include "y.tab.h"


%}
/*definicoes dos tokens*/
DIGIT	[0-9]
CHAR	[A-Za-z_]
SPECIAL [;:,(){}\[\]\+\-\*<>=!&$\/]

/* CONTEXTOS 
cria dois tipos de comentarios - diferentes contextos
tudo que nao for desse tipo, sera por defaul do tipo INITIAL
cada tipo tem suas regras definidas com o nome no inicio*/

%x 		COMMENT
%x		COMMENT2
%x		STRING
%x 		CHAR
/* REGRAS CRIADAS ABAIXO 
 caracteres especiais - serao referidos com o proprio codigo ASCII convertido para inteiro
 palavras reservadas
 operadores compostos
 Identificadores 
 Literais 
 Novo contexto - comentario do tipo barra asterisco
 Novo contexto - comentario do tipo barra barra
 tudo que nao foi `casado` acima entra no erro*/

%%

{SPECIAL}	{return yytext[0];}
\n	{lineNumber++;}      						        

byte	  	{ return(KW_BYTE);}
word		{ return(KW_WORD);}
bool		{ return(KW_BOOL);}
if     		{ return(KW_IF); }
then		{ return(KW_THEN); }
else		{ return(KW_ELSE);}
loop		{ return(KW_LOOP);}
input		{ return(KW_INPUT);}
output		{ return(KW_OUTPUT);}
return		{ return(KW_RETURN);}
TRUE		{ if(hashFind(yytext,SYMBOL_LIT_TRUE) == NULL) 
		   {
		      hashInsert(yytext,SYMBOL_LIT_TRUE);
		      return LIT_TRUE;
		   }
		   else
		     return LIT_TRUE;
		}
FALSE		{ if(hashFind(yytext,SYMBOL_LIT_FALSE) == NULL) 
		   {
		      hashInsert(yytext,SYMBOL_LIT_FALSE);
		      return LIT_FALSE;
		   }
		   else
		     return LIT_FALSE;

		}  

"<="		{ return(OPERATOR_LE);}
">="		{ return(OPERATOR_GE);}
"=="		{ return(OPERATOR_EQ);}
"!="		{ return(OPERATOR_NE);}
"&&"		{ return(OPERATOR_AND);}
"||"		{ return(OPERATOR_OR);}



[0-9]+	     				        { yylval.symbol = hashInsert(yytext,SYMBOL_LIT_INTEGER);return(LIT_INTEGER);}

[0-9]+[A-Za-z_]+[A-Za-z_0-9]*		   { yylval.symbol = hashInsert(yytext,SYMBOL_TK_IDENTIFIER);return(TK_IDENTIFIER);}  

'(\\.|[^\\'])+\'  { yylval.symbol= hashInsert(yytext,SYMBOL_LIT_CHAR);return (LIT_CHAR);}

\"(\\.|[^\\"])*\"  {yylval.symbol= hashInsert(yytext,SYMBOL_LIT_STRING);return (LIT_STRING);}


[ \t]		{ }
[\n|\r] 	{ ++lineNumber; }

<<EOF>>                                                                 { Running = 0; return(0);}

"/*" 		BEGIN(COMMENT);
<COMMENT>.	{ }
<COMMENT>"\n"	{++lineNumber;}
<COMMENT>"*/"	BEGIN(INITIAL);


"//"		BEGIN(COMMENT2);
<COMMENT2>.	{ }
<COMMENT2>[\n]	++lineNumber;BEGIN(INITIAL);




.		{ return TOKEN_ERROR;}

%%

/* Funcao criada encarregada de fazer a inicializacao da tabela hash*/
void initMe(){
	hashInit();
}

/* Funcao criada para retornar o numero de linhas */
int getLineNumber ()
{
	return (lineNumber);
}



