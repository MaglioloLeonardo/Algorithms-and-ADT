//
// Created by magli on 03/04/2019.
//

#include "List.h"
#include "Merge.h"
#include "assert.h"
#include "stdlib.h"
#include "stdio.h"
#define FuncToCompare int (*compare)(void*, void*)


list* Replace_record(int pos,void* record , list* lista){
    if(pos == Get_len(lista)){
        Add_record(record, lista);
        Remove_record_in_pos(Get_len(lista)-1, lista);
    }else{
        Add_record_in_pos(pos, record,lista);
        Remove_record_in_pos(pos+1, lista);
    }
}


void merge(list* lista, int l, int m, int r, FuncToCompare)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    list* L = List_new(); list* R = List_new();

    for (i = 0; i < n1; i++)
        Add_record(Get_record_in_pos(l+i+1,lista), L);

    for (j = 0; j < n2; j++)
        Add_record(Get_record_in_pos(m+2+j,lista), R);

    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray

    while (i < n1 && j < n2)
    {
        int compared = compare(Get_record_in_pos(i+1, L),Get_record_in_pos(j+1, R));

        if (compared == 0 || compared == -1)
        {
            Replace_record(k+1, Get_record_in_pos(i+1, L), lista);
            i++;
        }
        else
        {
            Replace_record(k+1, Get_record_in_pos(j+1, R), lista);
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        Replace_record(k+1, Get_record_in_pos(i+1, L), lista);
        i++;
        k++;
    }

    while (j < n2)
    {
        Replace_record(k+1, Get_record_in_pos(j+1, R), lista);
        j++;
        k++;
    }
}


void mergeSort(list* lista, int l, int r, FuncToCompare)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
        // Sort first and second halves
        mergeSort(lista, l, m, compare);
        mergeSort(lista, m+1, r, compare);
        merge(lista, l, m, r, compare);
    }
}

list* MergeLists(list* lista1, list* lista2,FuncToCompare){
    list* unique_list = List_new();int i;
    for(i=1; i<=Get_len(lista1); i++){
        Add_record(Get_record_in_pos(i, lista1), unique_list);
    }
    for(i=1; i<=Get_len(lista2); i++){
        Add_record(Get_record_in_pos(i, lista2), unique_list);
    }
    mergeSort(unique_list, 0, Get_len(unique_list)-1, compare);
    return unique_list;
}
//__________________________________________________________




