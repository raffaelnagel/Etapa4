/*  Compiladores 2014/2 - Etapa 3
    Felipe Prusokowski e Raffael Nagel

*/				
			
#include <stdio.h>
#include "hash.h"
#include "lex.yy.h"
	
	HASH* Table[HASH_SIZE+1];
	
	/* funcao hashInit ==> cria a tabela hash de tamanho HashSize */
	void hashInit(void)
	{
		int i;
		for (i=0; i<HASH_SIZE; ++i)
			Table[i]=0;
	}

	/* funcao hashPrint ==> imprime a tabela hash partindo do primeiro endereco ateh o fim, com tipo, posicao na hash e valor */	
	void hashPrint(void) {
		int address;
		HASH* node;
		for (address=0; address<HASH_SIZE; ++address)
			for (node=Table[address]; node!=0; node=node->next)
				printf (".:. Token do Tipo: %d .:. Conteudo %d: %s\n",node->token, address , node->text );
	}	
	
	/* funcao hashAddress ==>  */		
	int hashAddress(char *name, int token)
	{
		int i;
		int address = 1;
		for (i=0; name[i]!='\0'; ++i)
			address = (address *name[i]+token)%HASH_SIZE+1;
		return address;
	}


	/*Insert: atraves do texto do token, encontra a posicao na tabela a inserir: 		*
	 *se é o primeiro, cria uma lista a partir do vetor da tabela, atualizando seu ponteiro.*
	 *se não eh o primeiro, passa a apontar pro antigo primeiro (referenciado no vetor) e o *
	 *vetor passa a apontar para este novo nodo inserido 					*/
 
	HASH* hashInsert(char *name, int token) 
	{
		int address;
		HASH* newnode;
		newnode = hashFind(name,token);
		
		if (newnode!=0) 
			return (newnode); /* se o encontrou, retorna o nodo e nao insere-o novamente */
		
		address = hashAddress(name, token);
		newnode = (HASH*) calloc(1,sizeof(HASH));
		if (!newnode)
		{
			printf("Erro na alocação da memória\n");
			exit(1);
		}
		newnode -> text = calloc(1,strlen(name)+1);
		if (!newnode -> text)
		{
			printf("Erro na alocação da memória\n");
			exit(1);
		}
		strcpy(newnode->text, name);
		newnode->token = token;
		
		switch (token)
		{
		case 281: //LIT_INTEGER
				newnode->intValue = atoi (name);
				newnode->floatValue = 0.0;
				newnode->charValue = 0;
				break; 
		case 282: //LIT_FLOATING
				newnode->intValue = 0;
				newnode->floatValue = strtod (name,NULL);
				newnode->charValue = 0;
				break; 
		case 285: //LIT_CHAR
				newnode->intValue = 0;
				newnode->floatValue =0.0;
				newnode->charValue = name[0];
				break; 
		default: 
				newnode->intValue = 0;
				newnode->floatValue =0.0;
				newnode->charValue = 0;
				break;
		}


		newnode->next = Table[address];
		Table[address] = newnode;
		return (newnode);
	}
	/* funcao hashFind ==> varre a tabela em busca de um nodo igual, verificando conteudo e tipo */
	HASH* hashFind(char *name, int token)
	{
		int address;
		HASH* node;
		for (address=1; address<HASH_SIZE; ++address)
			for (node=Table[address]; node!=0; node=node->next)
				if (strcmp(node->text, name) == 0)
					if (node->token == token) 
						return node;
			return 0;
	}
