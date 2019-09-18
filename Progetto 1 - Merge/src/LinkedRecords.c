#include "List.h"
#include <stdlib.h>
#include <assert.h>

//
// Created by magli on 30/03/2019.
//

//-----------------------------------
struct _Node{
    void* record;
    struct _Node* next;
    struct _Node* prev;
}typedef node;

struct _List{
    node* head;
    node* tail;
    int len;
}typedef list;

node* Node_new(){
    node* temp = (node*)malloc(sizeof(node));
    temp->record = NULL; temp->next = NULL; temp->prev = NULL;
    return temp;
}

list* List_new(){
    list* this_list = (list*) malloc(sizeof(list));
    this_list->len = 0;
    this_list->head = NULL;this_list->tail = NULL;
    return this_list;
}

void List_free(list* this_list){
    assert(this_list > 0);
    int i; node* temp = this_list->head; node* next;
    for(i=1; i<this_list->len-1; i++){
        next = temp->next;
        free(temp);
        temp = next;
    }
    if(temp != NULL)free(temp);
    free(this_list);
}

void List_free_and_records(list* this_list){
    assert(this_list > 0);
    int i; node* temp = this_list->head; node* next;
    for(i=1; i<this_list->len-1; i++){
        next = temp->next;
        if(temp->record != NULL)free(temp->record);
        free(temp);
        temp = next;
    }
    if(temp != NULL){
        if(temp->record != NULL)free(temp->record);
        free(temp);
    }
    free(this_list);
}
//_____________________________________


int Get_len(list* this_list){
    assert(this_list > 0);
    return this_list->len;
}

void* Get_record_in_pos(int pos, list* this_list){
    assert(this_list>0 && this_list->len >= pos);
    node* temp = this_list->head; int i;

    if(pos <= this_list->len/2){
        for(i=1; i<pos; i++){
            temp = temp->next;
        }
    }else{
        temp = this_list->tail;
        for(i=this_list->len; i>pos; i--){
            temp = temp->prev;
        }
    }
    return temp->record;
}
//_______________________________________

void Add_record(void* this_record, list* this_list){
    assert(this_record>0 && this_list>0);
    if(this_list->len == 0){
        this_list->head = Node_new();
        this_list->head->record = this_record;
        this_list->tail = this_list->head;
    }else if(this_list->len == 1){
        node* head = this_list->head;
        head->next = Node_new();
        head->next->record = this_record; head->next->prev = head;
        this_list->tail = head->next;
    }else{
        node* temp = this_list->tail;
        temp->next = Node_new();
        temp->next->record = this_record; temp->next->prev = temp;
        this_list->tail = temp->next;
    }
    this_list->len += 1;
}

void Add_record_in_pos(int pos, void* this_record, list* this_list){
    assert(this_record>0 && this_list>0 && this_list->len >= pos && pos>0);
    node* temp = this_list->head;
    if(pos == 1){
        this_list->head = Node_new();
        this_list->head->record = this_record;
        this_list->head->next = temp;temp->prev = this_list->head;
        if(this_list->len == 0)this_list->tail = this_list->head;
        if(this_list->len == 1)this_list->tail = temp;
    }else if(pos == this_list->len) {
        Add_record(this_record, this_list);
        this_list->len -= 1;
    }else{
        int i;
        if(pos <= this_list->len/2) {
            for (i = 1; i < (pos - 1); i++) {
                temp = temp->next;
            }
        }else{
            temp = this_list->tail;
            for(i=this_list->len; i > (pos-1); i--){
                temp = temp->prev;
            }
        }
        node* old = temp->next;
        temp->next = Node_new();
        temp->next->record = this_record; temp->next->next = old;
        temp->next->prev = temp; temp->next->next->prev = temp->next;
        if(pos == this_list->len){
            if(temp->next->next != NULL){
                this_list->tail = temp->next->next;
            }else this_list->tail = temp->next;
        }
    }
    this_list->len += 1;
}

void Remove_last_record(list* this_list){
    assert(this_list->len>=1);
    if(this_list->len == 1){
        free(this_list->head);this_list->head = NULL; this_list->tail = NULL;
    }else{
        this_list->tail = this_list->tail->prev;
        free(this_list->tail->next);
        this_list->tail->next = NULL;
    }
    this_list->len -= 1;

}

void Remove_record_in_pos(int pos, list* this_list){
    assert(this_list>0 && this_list->len>=1 && pos>=1);
    if(this_list->len == 1){
        free(this_list->head); this_list->head = NULL; this_list->tail = NULL;
    }else if(pos == 1){
        node* temp = this_list->head;
        this_list->head = this_list->head->next; this_list->head->prev = NULL;
        free(temp);
    }else if(pos == this_list->len){
        Remove_last_record(this_list); this_list->len += 1;
    }else{
        int i; node* temp = this_list->head;
        if(pos <= this_list->len/2) {
            for (i = 1; i < (pos - 1); i++) {
                temp = temp->next;
            }
        }else{
            temp = this_list->tail;
            for(i=this_list->len; i > (pos-1); i--){
                temp = temp->prev;
            }
        }
        node* next = temp->next->next;
        free(temp->next); temp->next = next; next->prev = temp;
    }
    this_list->len -= 1;
}




