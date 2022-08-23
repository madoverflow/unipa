#include <stdbool.h>
/*#ifdef intero
 typedef int Item;
#else
 #ifdef virgola
  typedef float Item;
 #else
  #ifdef struttura*/
   typedef struct node * Item;
  /*#else
   typedef char Item;   
  #endif
 #endif
#endif*/
void queueInit();
//Item getItem();
bool queueIsEmpty();
void enqueue(Item val);
void display();
Item *dequeue();
//void putItem(Item *ptr);