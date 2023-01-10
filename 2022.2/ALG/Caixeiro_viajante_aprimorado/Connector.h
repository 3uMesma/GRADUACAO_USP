#ifndef CONN_H
    #define CONN_H
    #include <stdbool.h>
    #include <assert.h>
    #include "DMconfig.h"
    typedef struct node NODE;
    typedef struct line LINE;
    typedef struct web WEB;

    NODE *node_create(int id);
    LINE *line_create(NODE *c, ITEM d);
    bool line_free(LINE **l);
    bool node_free(NODE **n);
    bool node_addline(NODE *n, LINE *l);
    bool node_create_connection(NODE *a, NODE *b, ITEM distance);
    WEB *web_create(DM_MATRIX *d, int initial_id);
    void web_reset(WEB *w);
    void web_setresetbyid(WEB *w,int id);
    void web_showconnections(WEB *w);
    NODE *web_findnodebyid(WEB *w,int id);
    void *web_setmebyid(WEB *w,int id);
    int web_getlennodes(WEB *w);
    NODE *web_getme(WEB *w);
    void web_goto(WEB *w,NODE *go);
    int web_initialnodeid(WEB *w);
    bool web_trymove(WEB *w,int gotoline,ITEM *distance_accumulator);
    bool web_trypath(WEB *w,int *path,int len_path,ITEM *distance_accumulator);
    bool web_trymovePRINT(WEB *w,int gotoline,ITEM *distance_accumulator);
    bool web_trypathPRINT(WEB *w,int *path,int len_path,ITEM *distance_accumulator);
#endif