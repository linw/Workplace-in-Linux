#include <stdio.h>
#include <limits.h>
typedef struct Color{
  int r;
  int g;
  int b;
  struct Color* next;
}Color;

int distance(Color* a, Color* b)
{
  return (a->r-b->r)*(a->r-b->r) + (a->g-b->g)*(a->g-b->g) + (a->b-b->b)*(a->r-b->b);
}

main()
{
  int r,g,b;
  Color *head;
  Color *tmp;
  Color *tmp1;
  Color *first;
  Color *min_d;
  int dis = INT_MIN;
  int dis_min = INT_MAX;
  int i;
  head = NULL;
  do{
    scanf("%d%d%d",&r,&g,&b);
    if(r == -1 && g == -1 && b == -1) break;
    else {
      tmp = (Color*)malloc(sizeof(Color));
      tmp->r = r;
      tmp->g = g;
      tmp->b = b;
      tmp->next = head;
      head = tmp;
    }
  }while(1);
  tmp = head->next;
  first = head;
  for(i = 0; i < 5; ++i){
    first = first->next;
  }
  tmp = head->next;
  for(i = 0; i < 5; ++i){
    tmp = head->next;
    tmp1 = first;
    dis_min = INT_MAX;
    while(tmp1 && dis_min > 0){
      dis = distance(tmp,tmp1);
      if(dis_min > dis){
	min_d = tmp1;
	dis_min = dis;
      }
      tmp1 = tmp1->next;
    }
    printf("(%d,%d,%d) maps to (%d,%d,%d)\n",tmp->r,tmp->g,tmp->b,min_d->r,min_d->g,min_d->b);
    
  }
  while(head){
    tmp = head;
    head = head->next;
    free(tmp);
  }
}

