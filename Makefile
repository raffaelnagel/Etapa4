#
# UFRGS - Compiladores B - Marcelo Johann - 2014/2 - Etapa 2
# Felipe Prusokowski e Raffael Nagel
# Makefile for three compiler calls
# Read the comments on Makefile2. All of them apply here too.
# But now the hash table is compiled in a separate gcc call
# Therefore, there must be a header of it to be included in scanner.l
#

etapa2: lex.yy.o main.o hash.o y.tab.o ast.o
	gcc -o etapa3 lex.yy.o main.o hash.o y.tab.o 
y.tab.o: y.tab.c
	gcc -c y.tab.c
y.tab.c: parser.y
	yacc parser.y 
y.tab.h: parser.y
	yacc -d parser.y
lex.yy.o: lex.yy.c y.tab.h
	gcc -c lex.yy.c
lex.yy.c: scanner.l
	flex --header-file=lex.yy.h scanner.l 
main.o: main.c
	gcc -c main.c
hash.o: hash.c
	gcc -c hash.c
ast.o: ast.c
	gcc -c ast.c
clean:
	rm *.o lex.yy.c lex.yy.h y.tab.c y.tab.h etapa3

# dependencies for y.tab.h and its generation
# yyerror
# retirados type and union
