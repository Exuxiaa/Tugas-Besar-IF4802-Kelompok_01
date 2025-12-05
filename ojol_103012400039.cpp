#include <iostream>
#include "Ojol.h"
#include "Penumpang.h"
using namespace std;

address_ojol findElemenParent(list_ojol &LO, string info) {
    address_ojol P = LO.first;
    while (P != NULL) {
        if (P->info_ojol.nama_ojol == info) { //nama bang ojol
            return P;
        }
        if (P->info_ojol.plat_nomor == info) { //plat
            return P;
        }
        P = P->next;
    }
    return NULL;
}

void deleteFirstParent(list_ojol &LO, address_ojol &O) {
    O = nullptr;

    if (LO.first == nullptr) {
        // Jika list kosong
        cout << "List ojol kosong, tidak ada data yang dihapus." << endl;

    } else if (LO.first->next == nullptr) {
        // Hanya ada satu elemen
        O = LO.first;
        LO.first = nullptr;
        O->next = nullptr;
        O->first_penumpang = nullptr;

    } else {
        // Elemen lebih dari satu
        O = LO.first;
        LO.first = LO.first->next;
        O->next = nullptr;
        O->first_penumpang = nullptr;
    }

}

void deleteLastParent(list_ojol &LO, address_ojol &O) {
    O = nullptr;

    if (LO.first == nullptr) {
        // List kosong
        cout << "List ojol kosong." << endl;

    } else if (LO.first->next == nullptr) {
        // Hanya satu elemen
        O = LO.first;
        LO.first = nullptr;

        O->next = nullptr;
        O->first_penumpang = nullptr;

    } else {
        // Lebih dari satu elemen
        address_ojol R = LO.first;
        while (R->next->next != nullptr) {
            R = R->next;
        }

        O = R->next;
        R->next = nullptr;

        O->next = nullptr;
        O->first_penumpang = nullptr;
    }

}

void deleteAfterParent(list_ojol &LO, address_ojol prec, address_ojol &O) {
    O = nullptr;

    if (LO.first == nullptr) {
        // List kosong
        cout << "List kosong, tidak ada yang bisa dihapus." << endl;

    } else if (prec == nullptr) {
        // prec tidak valid
        cout << "Node sebelum (prec) tidak ditemukan." << endl;

    } else if (prec->next == nullptr) {
        // Tidak ada elemen setelah prec
        cout << "Tidak ada node setelah prec, tidak bisa dihapus." << endl;

    } else {
        // Terdapat elemen setelah prec → HAPUS
        O = prec->next;
        prec->next = O->next;

        O->next = nullptr;
        O->first_penumpang = nullptr;
    }

}
