#include <stdlib.h>
#include <stdio.h>
#include ".\linkedList.h"

/*
 * Inserts the new key at the beginning of the list.
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLInsertAtBeginning(LLElement * first, int key) {
      
        LLElement * temp;
        temp=(LLElement *)malloc(sizeof(LLElement));
        
        if(temp!=NULL){
        temp->key=key;
        temp->next=first;
        first=temp;
        }
    
    return first;
}

/*
 * Inserts the new key at the end of the list.
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLInsertAtEnd(LLElement * first, int key) {
    
    LLElement * prossimo=NULL;
    LLElement * temp;
    
    if(first==NULL){
        first=(LLElement *)malloc(sizeof(LLElement));
        first->key=key;
        first->next=NULL;
    }
    else{
        prossimo=first;
        while(prossimo->next!=NULL){
            prossimo=prossimo->next;
        }
        temp=(LLElement *)malloc(sizeof(LLElement));
        temp->key=key;
        temp->next=NULL;
        prossimo->next=temp;
    }
    return first;
}

/*
 * Inserts the new key at the specified positon of the list.
 * Position is zero-based, meaning that the first element is at position 0,
 * analogous to what happens in arrays.
 * 
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLInsertAtPosition(LLElement * first, int key, int position) {
  
    int dimensionemax;
    LLElement * temp=NULL;
    LLElement ** scorri_puntatori;
    int i=0;

    if((LLSize(first)+1) >= position){
        
        scorri_puntatori=&first;
        while(i<position){
            scorri_puntatori= &((*scorri_puntatori)->next);
            i++;
        }
        temp=(LLElement*)malloc(sizeof(LLElement));
        temp->key=key;

        if(temp==NULL){
            fprintf(stderr,"Non ho abbastanza memoria ALLOCAZIONE FALLITA");
            return(first);
        }
        temp->next=*scorri_puntatori;
        *scorri_puntatori=temp;
     
    }
    return first;
}

/*
 * Returns the size of the list.
 */
int LLSize(LLElement * first) {
    int dimensione=0;
    while(first!=NULL){
        dimensione++;
        first=first->next;
    }
    
    return dimensione;
}   

/*
 * Returns the key at the specified position.
 */ 
int LLGetKey(LLElement * first, int position) {

    int i,key;
    if(first==NULL) return -1;
    i=0;
    while(i<=position){
        key=first->key;
        first=first->next;
        i++;
    }
    return key;
}

/*
 * Returns the position of the first element, starting from startPosition, that
 * has the specified key.
 * Returns -1 if not found. 
 */ 
int LLFindKey(LLElement * first, int key, int startPosition) {
    
    int i=0;
    
    while(i<startPosition){
        
        first=first->next;
        i++;
        
    }
    
    while(first->key!=key){
        
        first=first->next;
        i++;
        
    }
    
    
        return i;
}

/*
 * Remove the first element of the list.
 * Returns the updated pointer to the first element of the list.
 */

LLElement * LLRemoveFirst(LLElement * first) {
    
    
    LLElement * prossimo;
    
    
    if(first!=NULL){
        
         prossimo=first->next;
         free(first);
         first=prossimo; 
         
    }
    
    return first;
}

/*
 * Remove the last element of the list.
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLRemoveLast(LLElement * first) {
    
    LLElement ** scorri_puntatori;
    
    
     if(first!=NULL){
         
        scorri_puntatori=&first;
        
        while((*scorri_puntatori)->next!=NULL){
            
            scorri_puntatori = &(*scorri_puntatori)->next;
        }
        free(*scorri_puntatori);
        *scorri_puntatori=NULL;

    }

    return first;
}

/*
 * Remove the element at the specified position.
 * Position is zero-based, meaning that the first element is at position 0,
 * analogous to what happens in arrays.
 * 
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLRemoveAtPosition(LLElement * first, int position) {
  
    //LLElement * temp;
    LLElement * riallaccia;
    LLElement ** scorri_puntatori;
    int i=0;
    
    
    scorri_puntatori=&first;
    
    while(i<position){
        scorri_puntatori= &((*scorri_puntatori)->next);
        i++;
    }
    riallaccia= (*scorri_puntatori)->next;
    free(*scorri_puntatori);
    *scorri_puntatori=riallaccia;
    
    return first;
}




