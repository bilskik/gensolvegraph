#ifndef _H_SEARCHER_
#define _H_SEARCHER_

typedef struct pv {
    double d;
    int p;
} prev_and_weight_t;

prev_and_weight_t *searcher (int start);
#endif
