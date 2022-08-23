#include <stdbool.h>
#ifdef intero
 typedef int Item;
#else
 #ifdef virgola
  typedef float Item;
 #else
  #ifdef struttura
   #include "item.h"
  #else
   typedef char Item;   
  #endif
 #endif
#endif
typedef struct Coda * queuePtr;
queuePtr queueInit(queuePtr Q);
void enqueue(queuePtr Q, Item val);
Item *dequeue(queuePtr Q);
bool queueIsEmpty(queuePtr Q);
void putItem(Item *ptr);
Item getItem();
void display(queuePtr Q);
