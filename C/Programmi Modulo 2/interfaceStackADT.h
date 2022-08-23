//definizione del tipo di oggetto
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
Item take();
void printItem(const Item a);
void stackPush(const Item a);
void printStack();
bool stackIsEmpty();   
Item stackPop();

