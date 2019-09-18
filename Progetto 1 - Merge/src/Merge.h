//
// Created by magli on 03/04/2019.
//

#ifndef MERGE_MERGE_H
#define MERGE_MERGE_H

#include "List.h"
#define FuncToCompare int (*compare)(void*, void*);
list* MergeLists(list* lista1, list* lista2,FuncToCompare);

#endif //MERGE_MERGE_H
