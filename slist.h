#define MAXL 30

typedef struct slist_s {
  char voc[MAXL+1];
  struct slist_s * next;
} slist_t;

/*prototipi delle funzioni*/
slist_t * append(slist_t *, char []);
slist_t * push(slist_t *, char []);
slist_t * find(slist_t * , char []);
slist_t * delete(slist_t *, char []);
slist_t * emptylist(slist_t *);
int listlength(slist_t *);
void listprint(slist_t * );
