#include <stdlib.h>
#include <stdio.h>
#include ".\linkedList.h"

/*
 * Inserts the new key at the beginning of the list.
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLInsertAtBeginning(LLElement * first, int key) {
    
    if(first==NULL){
        first=(LLElement *)malloc(sizeof(LLElement));
        first->key=key;
        first->next=NULL;
    }
    
    else{
        
        LLElement * temp;
        temp=(LLElement *)malloc(sizeof(LLElement));
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
    return NULL;
}

/*
 * Inserts the new key at the specified positon of the list.
 * Position is zero-based, meaning that the first element is at position 0,
 * analogous to what happens in arrays.
 * 
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLInsertAtPosition(LLElement * first, int key, int position) {
    // TODO To be implemented
    return NULL;
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
    for(i=0;i<=position;i++){
        key=first->key;
        first=first->next;
    }
    return key;
}

/*
 * Returns the position of the first element, starting from startPosition, that
 * has the specified key.
 * Returns -1 if not found. 
 */ 
int LLFindKey(LLElement * first, int key, int startPosition) {
    // TODO To be implemented
    return -1;
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
  
    return first;
}




