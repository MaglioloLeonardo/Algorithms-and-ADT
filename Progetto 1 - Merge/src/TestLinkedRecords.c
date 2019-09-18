#include <stdlib.h>
#include "assert.h"
#include "TestLinkedRecords.h"
#include "List.h"
#include "unity.h"

struct _Record{
    int value;
}typedef record;

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


record* Get_record(){
    record* temp = (record*) malloc(sizeof(record));
    temp->value = 0;
    return temp;
}

void Print_list(list* lista){
    printf("----------\nlist:%p size:%d head:%p tail:%p\n", lista, lista->len, lista->head, lista->tail);
    node* cursor = lista->head;
    while(cursor != NULL){
        record* temp = cursor->record;
        printf("[%d]->", temp->value);
        cursor = cursor->next;
    }
    printf("\n");
    cursor = lista->tail;
    while(cursor != NULL){
        record* temp = cursor->record;
        printf("[%d]->", temp->value);
        cursor = cursor->prev;
    }
    printf("\n----------");
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
    TEST_ASSERT_MESSAGE(lista->head == NULL, "List_new: Head value != NULL");
}

void Check_new_tail(){
    list* lista = List_new();
    TEST_ASSERT_MESSAGE(lista->tail == NULL, "List_new: Tail value != NULL");
}

void Check_new_len(){
    list* lista = List_new();
    TEST_ASSERT_MESSAGE(lista->len == 0, "List_new: Len != 0");
}
//__________________________________________________________________________________

//___________Node_new_______________________________________________________________
void Node_new_nullpointer(){
    node* nodo = Node_new();
    TEST_ASSERT_MESSAGE(nodo != NULL, "Node_new returned NULL POINTER");
}

void Node_new_record(){
    node* nodo = Node_new();
    TEST_ASSERT_MESSAGE(nodo->record == NULL, "Node_new: Record != NULL");
}

void Node_new_next(){
    node* nodo = Node_new();
    TEST_ASSERT_MESSAGE(nodo->next == NULL, "Node_new: Next != NULL");
}

void Node_new_prev(){
    node* nodo = Node_new();
    TEST_ASSERT_MESSAGE(nodo->prev == NULL, "Node_new: Prev != NULL");
}
//_________________________________________________________________________________

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
    List_free_and_records(lista);
}
//__________________________________________________________________________________

//___________Add_record_____________________________________________________________
void Add_record_size(int iterations){
    list* lista = List_gen(iterations);
    TEST_ASSERT_MESSAGE(lista->len == iterations, "Add_record: Mismatched sizes");
    List_free_and_records(lista);
}

void Add_record_tail(int iterations){
    list* lista = List_gen(iterations);
    record* temp = lista->tail->record;
    TEST_ASSERT_MESSAGE(temp->value == iterations, "Add_record: Tail error");
    List_free_and_records(lista);
}

void Add_record_reverse(int iterations){
    int i;list* lista = List_gen(iterations);
    node* temp_node = lista->tail;
    for(i=iterations; i>=1; i--){
        record* temp_record = (record*)temp_node->record;
        TEST_ASSERT_MESSAGE(temp_record->value == i, "Add_record: Wrong reverse oder");
        temp_node = temp_node->prev;
    }
    List_free_and_records(lista);
}
//__________________________________________________________________________________

//________Add_record_in_pos_________________________________________________________
void Add_record_in_pos_first(int iterations){
    list* lista = List_gen(iterations);
    record* old_last = lista->tail->record;
    record* temp = Get_record(); temp->value = -1;
    Add_record_in_pos(1, temp, lista);
    temp = lista->head->record;
    TEST_ASSERT_MESSAGE(temp->value == -1, "Add_record_in_pos(=1): Wrong head");
    temp = lista->tail->record;
    TEST_ASSERT_MESSAGE(temp->value == old_last->value, "Add_record_in_pos(=1): Wrong tail");
    List_free_and_records(lista);
}

void Add_record_in_pos_last(int iterations){
    int i;list* lista = List_gen(iterations);
    record* temp = Get_record(); temp->value = -1;
    Add_record_in_pos(lista->len, temp, lista);
    temp = lista->head->record;
    if(iterations>1) {
        TEST_ASSERT_MESSAGE(temp->value == 1, "Add_record_in_pos(=tail): Wrong head");
        temp = lista->tail->record;
        TEST_ASSERT_MESSAGE(temp->value == -1, "Add_record_in_pos(=tail): Wrong tail");
        node *cursor = lista->tail->prev;
        for (i = lista->len - 1; i >= 1; i--) {
            temp = cursor->record;
            TEST_ASSERT_MESSAGE(temp->value == i, "Add_record_in_pos(=tail): Wrong reverse oder");
            cursor = cursor->prev;
        }
    }else{
        TEST_ASSERT_MESSAGE(temp->value == -1, "Add_record_in_pos(=tail), pos=1: Wrong head");
        temp = lista->tail->record;
        TEST_ASSERT_MESSAGE(temp->value == 1, "Add_record_in_pos(=tail), pos=1: Wrong tail");
        temp = lista->tail->prev->record;
        TEST_ASSERT_MESSAGE(temp->value == -1, "Add_record_in_pos(=tail), pos=1: Wrong reverse oder");
    }
    List_free_and_records(lista);
}

void Add_record_in_pos_middle(int iterations){
    int i;list* lista = List_gen(iterations);
    if(lista->len > 2) {
        record *temp = Get_record();
        temp->value = -1;
        Add_record_in_pos(lista->len / 2 + (iterations%2), temp, lista);
        temp = lista->head->record;
        TEST_ASSERT_MESSAGE(temp->value == 1, "Add_record_in_pos(=middle): Wrong head");
        temp = lista->tail->record;
        TEST_ASSERT_MESSAGE(temp->value == iterations, "Add_record_in_pos(=middle): Wrong tail");
        node *cursor = lista->head;
        for (i = 1; i <= iterations / 2; i++) {
            cursor = cursor->next;
        }
        if(iterations%2==0)cursor = cursor->prev;
        node *middle = cursor;
        cursor = middle->next; temp = cursor->record;
        for (i = temp->value; i <= lista->len - 1; i++) {
            temp = cursor->record;
            TEST_ASSERT_MESSAGE(temp->value == i, "Add_record_in_pos(=middle): Wrong next order");
            cursor = cursor->next;
        }
        cursor = middle->prev; temp = cursor->record;
        for (i = temp->value; i >= 1; i--) {
            temp = cursor->record;
            TEST_ASSERT_MESSAGE(temp->value == i, "Add_record_in_pos(=middle): Wrong reverse order");
            cursor = cursor->prev;
        }
    }
    List_free_and_records(lista);
}
//__________________________________________________________________________________

//___________Remove_last_record_____________________________________________________
void Remove_last_record_sizetail(int iterations){
    list* lista = List_gen(iterations);
    Remove_last_record(lista);
    if(iterations>1){
        record *temp = lista->tail->record;
        TEST_ASSERT_MESSAGE(temp->value == iterations - 1, "Remove_last_record_sizetail: Wrong tail");
        TEST_ASSERT_MESSAGE(lista->len == iterations - 1, "Remove_last_record_sizetail: Wrong size");
    }else{
        TEST_ASSERT_MESSAGE(lista->head == NULL, "Remove_last_record_sizetail, size=1: Wrong head");
        TEST_ASSERT_MESSAGE(lista->tail == NULL, "Remove_last_record_sizetail, size=1: Wrong tail");
        TEST_ASSERT_MESSAGE(lista->len == 0, "Remove_last_record_sizetail, size=1: Wrong size");
    }
    List_free_and_records(lista);
}

void Remove_last_record_integrity(int iterations){
    int i;list* lista = List_gen(iterations);
    Remove_last_record(lista);
    record* temp; node* cursor = lista->head;
    for(i=1; i<=lista->len; i++){
        temp = cursor->record;
        TEST_ASSERT_MESSAGE(temp->value == i,"Add_record_in_pos(=middle): Wrong next order");
        cursor = cursor->next;
    }
    cursor = lista->tail;
    for(i=iterations-1; i>=1; i--){
        temp = cursor->record;
        TEST_ASSERT_MESSAGE(temp->value == i,"Add_record_in_pos(=middle): Wrong next order");
        cursor = cursor->prev;
    }
    List_free_and_records(lista);
}
//__________________________________________________________________________________

//________________Remove_record_in_pos________________________________________________
void Remove_record_in_pos_head(int iterations) {
    list *lista = List_gen(iterations);
    Remove_record_in_pos(1, lista);
    if(lista->len >= 1) {
        record *temp = lista->head->record;
        TEST_ASSERT_MESSAGE(temp->value == 2, "Remove_record_in_pos_head(): Wrong head");
        temp = lista->tail->record;
        TEST_ASSERT_MESSAGE(temp->value == iterations, "Remove_record_in_pos_head(): Wrong tail");
        TEST_ASSERT_MESSAGE(lista->len == iterations - 1, "Remove_record_in_pos_head(): Wrong size");
    }else{
        TEST_ASSERT_MESSAGE(lista->head == NULL, "Remove_record_in_pos_head(), len = 0: Tail != NULL");
        TEST_ASSERT_MESSAGE(lista->head == NULL, "Remove_record_in_pos_head(), len = 0: Head != NULL");
        TEST_ASSERT_MESSAGE(lista->len == iterations - 1, "Remove_record_in_pos_head(), len = 0: size != NULL");
    }
    List_free_and_records(lista);
}

void Remove_record_in_pos_tail(int iterations){
    list *lista = List_gen(iterations);
    Remove_record_in_pos(lista->len,lista);
    if(lista->len >= 1) {
        record *temp = lista->tail->record;
        TEST_ASSERT_MESSAGE(temp->value == iterations -1,"Remove_record_in_pos_tail: Wrong tail");
        temp = lista->head->record;
        TEST_ASSERT_MESSAGE(temp->value == 1, "Remove_record_in_pos_head(): Wrong head");
        TEST_ASSERT_MESSAGE(lista->len == iterations -1,"Remove_record_in_pos_tail: Wrong size");
    }else{
        TEST_ASSERT_MESSAGE(lista->head == NULL, "Remove_record_in_pos_head(), len = 0: Tail != NULL");
        TEST_ASSERT_MESSAGE(lista->head == NULL, "Remove_record_in_pos_head(), len = 0: Head != NULL");
        TEST_ASSERT_MESSAGE(lista->len == iterations - 1, "Remove_record_in_pos_head(), len = 0: size != NULL");
    }
    List_free_and_records(lista);

}
void Remove_record_in_pos_middle(int iterations){
    list *lista = List_gen(iterations);
    if(lista->len/2 > 3){
        Remove_record_in_pos(lista->len/2, lista);
        if (lista->len >= 1) {
            record *temp = lista->tail->record;
            TEST_ASSERT_MESSAGE(temp->value == iterations,"Remove_record_in_pos_middle: Wrong tail");
            temp = lista->head->record;
            TEST_ASSERT_MESSAGE(temp->value == 1, "Remove_record_in_pos_middle: Wrong head");
            TEST_ASSERT_MESSAGE(lista->len == iterations -1,"Remove_record_in_pos_middle: Wrong size");
        } else {
            TEST_ASSERT_MESSAGE(lista->head == NULL, "Remove_record_in_pos_middle, len = 0: Tail != NULL");
            TEST_ASSERT_MESSAGE(lista->head == NULL, "Remove_record_in_pos_middle, len = 0: Head != NULL");
            TEST_ASSERT_MESSAGE(lista->len == iterations - 1, "Remove_record_in_pos_middle, len = 0: size != NULL");
        }
    }
    List_free_and_records(lista);
}

void Remove_record_in_pos_integrity_head(int iterations){
    int i; list *lista = List_gen(iterations);
    Remove_record_in_pos(1,lista);
    record *temp; node* cursor = lista->head;
    for(i = 2; i<= iterations; i++){
        temp = cursor->record;
        TEST_ASSERT_MESSAGE(temp->value == i, "Remove_record_in_pos_integrity_head(): Wrong next order");
        cursor = cursor->next;
    }
    cursor = lista->tail;
    for(i = iterations; i>= 2; i--){
        temp = cursor->record;
        TEST_ASSERT_MESSAGE(temp->value == i, "Remove_record_in_pos_integrity_head(): Wrong reverse order");
        cursor = cursor->prev;
    }
    List_free_and_records(lista);
}

void Remove_record_in_pos_integrity_tail(int iterations){
    int i; list *lista = List_gen(iterations);
    Remove_record_in_pos(lista->len,lista);
    record *temp; node* cursor = lista->head;
    for(i = 1; i<= iterations-1; i++){
        temp = cursor->record;
        TEST_ASSERT_MESSAGE(temp->value == i, "Remove_record_in_pos_integrity_tail(): Wrong next order");
        cursor = cursor->next;
    }
    cursor = lista->tail;
    for(i = iterations-1; i>= 1; i--){
        temp = cursor->record;
        TEST_ASSERT_MESSAGE(temp->value == i, "Remove_record_in_pos_integrity_tail(): Wrong reverse order");
        cursor = cursor->prev;
    }
    List_free_and_records(lista);

}

void Remove_record_in_pos_integrity_middle(int iterations) {
    list *lista = List_gen(iterations);
    if (lista->len > 3) {
        int i;
        list *lista = List_gen(iterations);
        Remove_record_in_pos(lista->len / 2, lista);
        record *temp;
        node *cursor = lista->head;
        for (i = 1; i < iterations / 2 - 1; i++) {
            cursor = cursor->next;
        }
        node *left = cursor;
        node *right = left->next;
        cursor = right;
        temp = cursor->record;
        for (i = temp->value; i <= iterations; i++) {
            temp = cursor->record;
            TEST_ASSERT_MESSAGE(temp->value == i, "Remove_record_in_pos_integrity_middle: Wrong next order");
            cursor = cursor->next;
        }
        cursor = left;
        temp = cursor->record;
        for (i = temp->value; i >= 1; i--) {
            temp = cursor->record;
            TEST_ASSERT_MESSAGE(temp->value == i, "Remove_record_in_pos_integrity_middle: Wrong reverse order");
            cursor = cursor->prev;
        }
    }
    List_free_and_records(lista);
}

void Full_test(int iterations){
    assert(iterations > 0);
    Check_new_head();
    Check_new_tail();
    Check_new_len();
    Check_new_nullpointer();

    Node_new_nullpointer();
    Node_new_record();
    Node_new_next();
    Node_new_prev();

    List_free_test();

    Test_Get_record_in_pos(iterations);

    Add_record_size(iterations);
    Add_record_tail(iterations);
    Add_record_reverse(iterations);

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

