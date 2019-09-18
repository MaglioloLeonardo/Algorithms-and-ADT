//
// Created by magli on 02/04/2019.
//
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "List.h"

struct _List{
    void** array;
    int len;
    int size;
}typedef list;

list* List_new(){
    list* temp = (list*) malloc(sizeof(list));
    temp->array = (void**)malloc((sizeof(void*)));
    temp->array[0] = NULL;
    temp->len = 0; temp->size= 1;
    return temp;
}

void List_free(list* this_list){
    assert(this_list>0);
    free(this_list->array);
    free(this_list);
}

int Get_len(list* this_list){
    assert(this_list > 0);
    return this_list->len;
}

void* Get_record_in_pos(int pos, list* this_list){
    assert(this_list>0 && pos>0 && pos<=this_list->len);
    return this_list->array[pos-1];
}

void Add_record(void* this_record, list* this_list){
    assert(this_list>0 && this_record>0);
    if(this_list->size < this_list->len+1){
        this_list->array = (void**)realloc(this_list->array, sizeof(void*)*this_list->size*2);
        this_list->size=this_list->size*2 ;
    }
    this_list->array[this_list->len] = this_record;
    this_list->len += 1;
}

void Add_record_in_pos(int pos, void* this_record, list* this_list){
    assert(this_list>0 && this_record>0 && pos>0 && pos<=this_list->size+1); int i;
    if(this_list->size < this_list->len+1){
        this_list->array = (void**)realloc(this_list->array, sizeof(void*)*this_list->size*2);
        this_list->size=this_list->size*2 ;
    }

    for(i=this_list->len; i>=pos; i--){
        this_list->array[i] = this_list->array[i-1];
    }

    this_list->array[pos-1] = this_record;
    this_list->len += 1;
}

void Remove_last_record(list* this_list){
    assert(this_list>0 && this_list->len>0);
    this_list->len -= 1;
    int size = this_list->size, len = this_list->len;
    if(len <= size/4 && size/2 > 1){
        this_list->array = (void**)realloc(this_list->array, sizeof(void*)*size/2);
        this_list->size--;
    }
}

void Remove_record_in_pos(int pos, list* this_list){
    assert(this_list>0 && this_list->len>0 && pos>0 && pos<=this_list->size);
    this_list->len -= 1;
    int size = this_list->size, len = this_list->len, i;
    for(i=pos-1; i<=len; i++) {
        this_list->array[i] = this_list->array[i + 1];
    }


    if(len <= size/4 && size/2>1){
        this_list->array = (void**)realloc(this_list->array, sizeof(void*)*size/2);
        this_list->size--;
    }
}

