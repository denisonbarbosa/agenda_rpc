/* rbd_srp.c - inicializar, insere, remove, busca*/ 

#include "rbd_srp.h"



/* Procedimentos remotos do servidor e dados globais */ 


char bd[BDSIZE][MAXWORD]; /* armazena o dicionário de palavras */ 
int  npalavras = 0;   /* número de palavras no dicionário */ 

int inicializar() 
{ 
    npalavras = 0; 
     return 1; 
} 

int insere(palavra) 
char *palavra; 
{ 
     strcpy(bd[npalavras], palavra); 
     npalavras++; 
     return npalavras; 
}

int remover(palavra) 
char *palavra; 
{ 
  int i; 
  for (i=0; i<npalavras; i++) 
   if (strcmp(palavra, bd[i]) == 0) { 
        npalavras--; 
        strcpy(bd[i], bd[npalavras]); 
        return 1; 
   } 
  return 0; 
} 

int busca(palavra) 
char *palavra; 
{ 
  int i; 
  for (i=0; i<npalavras; i++) 
   if (strcmp(palavra, bd[i]) == 0 ) 
       return 1; 
  return 0; 
} 

