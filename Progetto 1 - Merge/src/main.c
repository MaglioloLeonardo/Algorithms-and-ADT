#include <stdio.h>
#include <stdlib.h>

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

int main() {
    int len = 5;
    list* L = List_gen(-len,len); list* R = List_gen(len,-len);
    printf("Lists:\n");
    Print_list(R); Print_list(L);
    printf("Result:\n");
    list* merged = MergeLists(L, R, Cmp_func);
    Print_list(merged);
    return 0;
}