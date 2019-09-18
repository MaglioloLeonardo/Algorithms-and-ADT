//
// Created by magli on 03/04/2019.
//
#include <stdlib.h>
#include "assert.h"
#include "TestLinkedRecords.h"
#include "List.h"
#include "unity.h"
#include "Merge.h"

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
        printf("----------\nlist:%p len:%d\n", lista, Get_len(lista));
        record *temp;
        int i;
        for (i = 0; i < Get_len(lista); i++) {
            temp = (record *) Get_record_in_pos(i+1, lista);
            if (temp != NULL) {
                printf("[%d]", temp->value);
            }else printf("[]");
        }
        printf("\n----------");
    }
}

list* List_gen(int from, int to){
    list* lista = List_new();
    int i;record* temp;
    if(to>=from){
        for(i=from; i<=to; i++){
            temp = Get_record(); temp->value = i;
            Add_record(temp, lista);
        }
    }else{
        for(i=from; i>=to; i--){
            temp = Get_record(); temp->value = i;
            Add_record(temp, lista);
        }
    }

    return  lista;
}

int Cmp_func(void* P1, void* P2){
    assert(P1 != NULL && P2 != NULL);
    record* R1 = (record*)P1; record* R2 = (record*)P2;
    int a = R1->value, b = R2->value;
    if(R1->value == R2->value){
        return 0;
    }else{
        if(R1->value > R2->value)
            return 1;
        else
            return -1;
    }
}

int Is_ordered(list* lista){
    int i;record* p;record* next;
    for(i=1; i<Get_len(lista); i++){
        p = (record*)Get_record_in_pos(i, lista);
        next = (record*)Get_record_in_pos(i+1, lista);
        if(p->value > next->value)return 0;
    }
    return 1;
}
//____________________________________________________________________
void Test_complementary_list(int len){
    assert(len>0);
    list* L = List_gen(0,len/2); list* R = List_gen(len/2+1,len);
    TEST_ASSERT_MESSAGE(Is_ordered(MergeLists(L, R, Cmp_func)) == 1, "Test_complementary_list: Wrong order");
    List_free(L); List_free(R);
}

void Test_subset_list(int len){
    assert(len>0);
    list* L = List_gen(0,len/2); list* R = List_gen(0,len);
    TEST_ASSERT_MESSAGE(Is_ordered(MergeLists(L, R, Cmp_func)) == 1, "Test_subset_list: Wrong order");
    List_free(L); List_free(R);
}

void Test_equal_list(int len){
    assert(len>0);
    list* L = List_gen(0,len);
    TEST_ASSERT_MESSAGE(Is_ordered(MergeLists(L, L, Cmp_func)) == 1, "Test_equal_list: Wrong order");
    List_free(L);
}

void Test_opposite_list(int len){
    assert(len>0);
    list* L = List_gen(-len,len); list* R = List_gen(len,-len);
    TEST_ASSERT_MESSAGE(Is_ordered(MergeLists(L, R, Cmp_func)) == 1, "Test_opposite_list: Wrong order");
    List_free(L); List_free(R);
}

void Full_test(int len){
    assert(len>0);
    Test_complementary_list(len);
    Test_subset_list(len);
    Test_equal_list(len);
    Test_opposite_list(len);
}
//_____________________________________________________________________



int main() {
    int i;
    for(i=1; i<=100; i++){
        Full_test(i);
    }
    printf("\nAll tests passed-\n");
    return 0;
}




