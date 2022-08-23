#include <stdbool.h>
#ifdef intero
 typedef int Item;
#else
 #ifdef virgola
  typedef float Item;
 #else
   typedef char Item;   
 #endif
#endif
void dequeInit();
Item getItem();
void pushDeque(Item a);
Item *popDeque();
bool dequeIsEmpty();
void display();
void putItem(Item *ptr);