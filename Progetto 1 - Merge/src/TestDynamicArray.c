//
// Created by magli on 03/04/2019.
//
#include <stdlib.h>
#include <time.h>
#include "assert.h"
#include "DynamicArray.c"
#include "unity.h"

struct _Record{
    int value;
}typedef record;

record* Get_record(){
    record* temp = (record*) malloc(sizeof(record));
    temp->value = 0;
    return temp;
}

void Print_list(list* lista){
    if(lista >0) {
        printf("----------\nlist:%p len:%d size:%d\n", lista, lista->len, lista->size);
        record *temp;
        int i;
        for (i = 0; i < lista->len; i++) {
            temp = (record *) lista->array[i];
            if (temp != NULL) {
                printf("[%d]", temp->value);
            } else printf("[]");
        }
        printf("\n----------");
    }
}

list* List_gen(int len){
    assert(len > 0);
    list* lista = List_new();
    int i;record* temp;
    for(i=1; i<=len; i++){
        temp = Get_record(); temp->value = i;
        Add_record(temp, lista);
    }
    return  lista;
}

void Check_new_nullpointer(){
    list* lista = List_new();
    TEST_ASSERT_MESSAGE(lista != NULL , "List_new returned NULL POINTER");
}

void Check_new_head(){
    list* lista = List_new();
    TEST_ASSERT_MESSAGE(lista->size == 1, "List_new: Size value != 1");
}

void Check_new_len(){
    list* lista = List_new();
    TEST_ASSERT_MESSAGE(lista->len == 0, "List_new: Len != 0");
}
//__________________________________________________________________________________

//_________List_Free________________________________________________________________
void List_free_test(){
    list* lista = List_new();
    free(lista);
}
//__________________________________________________________________________________

//__________Get_record_in_pos_______________________________________________________
void Test_Get_record_in_pos(int iterations){
    int i;list* lista= List_new();
    for(i=1; i<=iterations; i++){
        record* temp = Get_record(); temp->value = i;
        Add_record(temp, lista);
        temp = Get_record_in_pos(i, lista);
        TEST_ASSERT_MESSAGE(temp->value == i, "Get_record_in_pos: failed test (Uses Add_record)");
    }
    List_free(lista);
}
//__________________________________________________________________________________

//___________Add_record_____________________________________________________________
void Add_record_size(int iterations){
    list* lista = List_gen(iterations);
    TEST_ASSERT_MESSAGE(lista->len == iterations, "Add_record: Mismatched len");
    TEST_ASSERT_MESSAGE(lista->size >= iterations, "Add_record: Mismatched size");
    List_free(lista);
}

//__________________________________________________________________________________

//________Add_record_in_pos_________________________________________________________
void Add_record_in_pos_first(int iterations){
    list* lista = List_gen(iterations);
    record* temp = Get_record(); temp->value = -1;
    Add_record_in_pos(1, temp, lista);
    temp = (record*)lista->array[0];
    TEST_ASSERT_MESSAGE(temp->value == -1, "Add_record_in_pos(=1): Wrong first elem");
    temp = (record*)lista->array[lista->len-1];
    TEST_ASSERT_MESSAGE(temp->value == iterations, "Add_record_in_pos(=1): Wrong last elem");
    List_free(lista);
}

void Add_record_in_pos_last(int iterations){
    list* lista = List_gen(iterations);
    record* temp = Get_record(); temp->value = -1;
    Add_record_in_pos(lista->len+1, temp, lista);
    temp = (record*)lista->array[0];
    TEST_ASSERT_MESSAGE(temp->value == 1, "Add_record_in_pos(=tail): Wrong first elem");
    temp = (record*)lista->array[lista->len-1];
    TEST_ASSERT_MESSAGE(temp->value == -1, "Add_record_in_pos(=tail): Wrong last elem");

    List_free(lista);
}

void Add_record_in_pos_middle(int iterations){
    int i;list* lista = List_gen(iterations);
    if(lista->len > 2) {
        record *temp = Get_record();
        temp->value = -1;
        Add_record_in_pos(lista->len / 2 + (iterations%2), temp, lista);
        int middle, toggle = 0;
        if(iterations%2==0){
            middle = iterations / 2-1 ;
        }else middle = iterations / 2 ;
        for(i=0; i<lista->len; i++){
            temp = lista->array[i];
            if(i != middle){
                TEST_ASSERT_MESSAGE(temp->value == i+1-toggle, "Add_record_in_pos(=middle): Wrong order");
            }else{
                toggle = 1;
                TEST_ASSERT_MESSAGE(temp->value == -1, "Add_record_in_pos(=middle): Wrong order center");
            }
        }
    }
    List_free(lista);
}
//__________________________________________________________________________________

//___________Remove_last_record_____________________________________________________
void Remove_last_record_sizetail(int iterations){
    list* lista = List_gen(iterations);
    Remove_last_record(lista);
    if(iterations>1){
        record* temp = (record*)lista->array[lista->len-1];
        TEST_ASSERT_MESSAGE(temp->value == iterations - 1, "Remove_last_record_sizetail: Wrong tail");
        TEST_ASSERT_MESSAGE(lista->len == iterations - 1, "Remove_last_record_sizetail: Wrong len");
        TEST_ASSERT_MESSAGE(lista->size >= lista->len, "Remove_last_record_sizetail: Wrong size");
    }else{
        TEST_ASSERT_MESSAGE(lista->len == 0, "Remove_last_record_sizetail, size=1: Wrong len");
        TEST_ASSERT_MESSAGE(lista->size >= 1, "Remove_last_record_sizetail, size=1: Wrong size");
    }
    List_free(lista);
}

void Remove_last_record_integrity(int iterations){
    int i;list* lista = List_gen(iterations);
    Remove_last_record(lista); record* temp;
    for(i=0; i<lista->len; i++){
        temp = lista->array[i];
        TEST_ASSERT_MESSAGE(temp->value == i+1,"Add_record_in_pos(=middle): Wrong next order");
    }
    List_free(lista);
}
//__________________________________________________________________________________

//________________Remove_record_in_pos________________________________________________
void Remove_record_in_pos_head(int iterations) {
    list *lista = List_gen(iterations);
    Remove_record_in_pos(1, lista);
    if(lista->len >= 1) {
        record *temp = (record*)lista->array[0];
        TEST_ASSERT_MESSAGE(temp->value == 2, "Remove_record_in_pos_head(): Wrong first val");
        temp = (record*)lista->array[lista->len-1];
        TEST_ASSERT_MESSAGE(temp->value == iterations, "Remove_record_in_pos_head(): Wrong last val");
        TEST_ASSERT_MESSAGE(lista->len == iterations - 1, "Remove_record_in_pos_head(): Wrong len");
        TEST_ASSERT_MESSAGE(lista->size >= lista->len, "Remove_record_in_pos_head(): Wrong size");
    }else{
        TEST_ASSERT_MESSAGE(lista->len == 0, "Remove_record_in_pos_head(), len = 0: len != 0");
        TEST_ASSERT_MESSAGE(lista->size == 1, "Remove_record_in_pos_head(), len = 0: size != 1");
    }
    List_free(lista);
}

void Remove_record_in_pos_tail(int iterations){
    list *lista = List_gen(iterations);
    Remove_record_in_pos(lista->len,lista);
    if(lista->len >= 1) {
        record *temp = (record*)lista->array[lista->len-1];
        TEST_ASSERT_MESSAGE(temp->value == iterations -1,"Remove_record_in_pos_tail: Wrong last val");
        temp = (record*)lista->array[0];
        TEST_ASSERT_MESSAGE(temp->value == 1, "Remove_record_in_pos_tail(): Wrong head");
        TEST_ASSERT_MESSAGE(lista->len == iterations -1,"Remove_record_in_pos_tail(): Wrong len");
        TEST_ASSERT_MESSAGE(lista->size >= lista->len, "Remove_record_in_pos_tail(): Wrong size");
    }else{
        TEST_ASSERT_MESSAGE(lista->len == 0, "Remove_record_in_pos_tail, len = 0: len != 0");
        TEST_ASSERT_MESSAGE(lista->size == 1, "Remove_record_in_pos_tail, len = 0: len != 1");
    }
    List_free(lista);

}
void Remove_record_in_pos_middle(int iterations){
    list *lista = List_gen(iterations);
    if(lista->len/2 > 3){
        Remove_record_in_pos(lista->len/2, lista);
        if (lista->len >= 1) {
            record *temp = (record*)lista->array[lista->len-1];
            TEST_ASSERT_MESSAGE(temp->value == iterations,"Remove_record_in_pos_middle: Wrong last val");
            temp = (record*)lista->array[0];
            TEST_ASSERT_MESSAGE(temp->value == 1, "Remove_record_in_pos_middle: Wrong first val");
            TEST_ASSERT_MESSAGE(lista->len == iterations -1,"Remove_record_in_pos_middle: Wrong len");
            TEST_ASSERT_MESSAGE(lista->size >= lista->len, "Remove_record_in_pos_middle: Wrong size");
        } else {
            TEST_ASSERT_MESSAGE(lista->len == 0, "Remove_record_in_pos_middle, len = 0: len != 0");
            TEST_ASSERT_MESSAGE(lista->size == 1, "Remove_record_in_pos_middle, len = 0: len != 1");
        }
    }
    List_free(lista);
}

void Remove_record_in_pos_integrity_head(int iterations){
    int i; list *lista = List_gen(iterations);
    Remove_record_in_pos(1,lista);
    record *temp;
    for(i = 0; i<lista->len; i++){
        temp = (record*)lista->array[i];
        TEST_ASSERT_MESSAGE(temp->value == i+2, "Remove_record_in_pos_integrity_head(): Wrong order");
    }
    List_free(lista);
}

void Remove_record_in_pos_integrity_tail(int iterations){
    int i; list *lista = List_gen(iterations);
    Remove_record_in_pos(lista->len,lista);
    record *temp;
    for(i = 0; i< lista->len; i++){
        temp = (record*)lista->array[i];
        TEST_ASSERT_MESSAGE(temp->value == i+1, "Remove_record_in_pos_integrity_tail(): Wrong order");
    }
    List_free(lista);

}

void Remove_record_in_pos_integrity_middle(int iterations) {
    list *lista = List_gen(iterations);
    if (lista->len > 3) {
        int i, left;
        list *lista = List_gen(iterations);
        Remove_record_in_pos(lista->len / 2, lista);
        left = iterations / 2 - 1;
        record *temp;
        for (i = 0; i < left; i++) {
            temp = lista->array[i];
            TEST_ASSERT_MESSAGE(temp->value == i+1, "Remove_record_in_pos_integrity_middle: Wrong next order");
        }
        for(i=left+2; i<lista->len; i++){
            temp = lista->array[i-1];
            TEST_ASSERT_MESSAGE(temp->value == i+1, "Remove_record_in_pos_integrity_middle: Wrong next order");
        }
    }
    List_free(lista);
}

void Full_test(int iterations){
    assert(iterations > 0);
    Check_new_head();
    Check_new_len();
    Check_new_nullpointer();

    List_free_test();

    Test_Get_record_in_pos(iterations);

    Add_record_size(iterations);

    Add_record_in_pos_first(iterations);
    Add_record_in_pos_last(iterations);
    Add_record_in_pos_middle(iterations);

    Remove_last_record_sizetail(iterations);
    Remove_last_record_integrity(iterations);

    Remove_record_in_pos_head(iterations);
    Remove_record_in_pos_tail(iterations);
    Remove_record_in_pos_middle(iterations);
    Remove_record_in_pos_integrity_head(iterations);
    Remove_record_in_pos_integrity_tail(iterations);
    Remove_record_in_pos_integrity_middle(iterations);
}

int main(int argc, char *argv[]){
    int i;
    for(i=1; i<= 100; i++){
        Full_test(i);
    }
    printf("\nAll tests passed-\n");
}


