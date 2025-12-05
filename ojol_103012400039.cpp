#include <iostream>
#include "Penumpang.h"
#include "Ojol.h"

using namespace std;

address_penumpang createElemenChild(infotype_penumpang P) {
    address_penumpang C = new elemen_penumpang;
    C->info_penumpang = P;
    C->next = NULL;
    C->prev = NULL;
    return C;
}

void insertFirstChild(address_ojol O, address_penumpang P) {
    if (O == NULL) return;
    address_penumpang A = O->first_penumpang;
    if (A == NULL) {
        O->first_penumpang = P;
    } else {
        P->next = A;
        A->prev = P;
        O->first_penumpang = P;
    }
}

void insertLastChild(address_ojol O, address_penumpang P) {
    if (O == NULL) return;
    address_penumpang A = O->first_penumpang;
    if (A == NULL) {
        O->first_penumpang = P;
        return;
    }
    address_penumpang cur = A;
    while (cur->next != NULL) cur = cur->next;
    cur->next = P;
    P->prev = cur;
}

void insertAfterChild(address_ojol O, address_penumpang prec, address_penumpang P) {
    if (O == NULL || prec == NULL) return;
    address_penumpang A = O->first_penumpang;
    address_penumpang C = A;
    bool found = false;
    while (C != NULL) {
        if (C == prec) { found = true; break; }
        C = C->next;
    }
    if (!found) return;

    P->next = prec->next;
    P->prev = prec;
    prec->next = P;
    if (P->next != NULL) {
        P->next->prev = P;
    }
}
