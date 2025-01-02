#ifndef GETCHH_H
#define GETCHH_H

typedef enum {
    EMPTY,
    FULL
} Flag;

int getchh(void);

void ungetchh(int c);
#endif  /* GETCHH_H */