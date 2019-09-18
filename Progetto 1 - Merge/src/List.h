//
// Created by magli on 30/03/2019.
//
#ifndef PROGETTO1_LINKEDRECORDS_H
#define PROGETTO1_LINKEDRECORDS_H

typedef struct _List list;

//--------------------------------------
list* List_new();

void List_free(list* this_list);
//--------------------------------------

//--------------------------------------
int Get_len(list* this_list);

void* Get_record_in_pos(int pos, list* this_list);
//--------------------------------------


void Add_record(void* this_record, list* this_list);

void Add_record_in_pos(int pos, void* this_record, list* this_list);

void Remove_last_record(list* this_list);

void Remove_record_in_pos(int pos, list* this_list);//x


#endif //PROGETTO1_LINKEDRECORDS_H
