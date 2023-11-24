#include "elemtype.h"

#define _unused(x) ((void)(x))

ElemType ElemCopy(const ElemType* e) {
    return *e;
}

void ElemDelete(ElemType* e) {
    // In questo caso la funzione ElemDelete non deve fare nulla, ma il 
    // compilatore potrebbe segnalare il mancato utilizzo di e, come warning
    // o come errore. Utilizzando la macro _unused sopra definita eliminiamo
    // questo problema.
    _unused(e);
}

int ElemRead(FILE* f, ElemType* e) {
    return fscanf(f, "%d %d", &e->x, &e->y);
}
void ElemWrite(const ElemType* e, FILE* f) {
    fprintf(f, "%d %d", &e->x, &e->y);
}