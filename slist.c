#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "slist.h"

slist_t * append(slist_t * h, char s[])
{
    slist_t * n, * ptr;

    if(n = malloc(sizeof(slist_t))){
      strcpy(n->voc, s);
      n->next = NULL;
      if(!h)
        h = n;
      else{
        for(ptr = h; ptr->next; ptr = ptr->next)
          ;
        ptr->next = n;
      }
    } else
      printf("append: errore allocazione memoria %s\n", s);
    return h;
}

slist_t * push(slist_t * h, char s[])
{
  slist_t * n;

  if(n = malloc(sizeof(slist_t))){
    strcpy(n->voc, s);
    n->next = h;
    h = n;
  } else
    printf("append: errore allocazione memoria %s\n", s);
  return h;
}

slist_t * find(slist_t * h, char s[])
{
  while(h){
    if(!strcmp(h->voc, s))
      return h;
    h = h->next;
  }
  return NULL;
}

slist_t * delete(slist_t * h, char s[])
{
  return h;
}

slist_t * emptylist(slist_t * h)
{
  slist_t * ptr;
  ptr = h;
  while(h){
    free(ptr);
    ptr = h;
    h = h->next;
  }
  return h;
}

int listlength(slist_t * h)
{
  if(!h)
    return 0;
  return 1 + listlength(h->next);
}

void listprint(slist_t * h)
{
  if(!h)
    printf("\n");
  else {
    printf("%s ", h->voc);
    listprint(h->next);
  }
}
