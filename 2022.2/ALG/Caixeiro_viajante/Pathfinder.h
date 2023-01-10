#ifndef PATHFINDER_H
    #define PATHFINDER_H
    #include "DMconfig.h"
    #include "Connector.h"
    typedef struct walker WALKER;
    WALKER *walker_create(int lenpath,int cidadeinicial);
    void walker_free(WALKER **w);
    ITEM walker_getdistance(WALKER *w);
    ITEM walker_getbestdistance(WALKER *w);
    int walker_getlenpath(WALKER *w);
    int *walker_getpath(WALKER *w);
    void walker_setbest(WALKER *w);
    void walker_setbestif(WALKER *w);
    void swap(int *a,int *b);
    void heapPermutation(WEB *web,int size, WALKER *walker);
    void walker_run(WALKER *walker, WEB *web);
    void walker_printbest(WALKER *w);
    WALKER *walker_run2(WEB *web, int q_walkers,int q_shuffles);
    int *walker_getpreset(int *presetpath,int len,int initialnode);
    int web_getmeid(WEB *web);
    void walker_printruncodes(WALKER *w,WEB *web);
    void array_copyto(int *copyto,int *copyfrom,int len);
    void walker_setpath(WALKER *w, int *newpath);
    void walker_trypathPRINT(WALKER *walker,WEB *web);
#endif