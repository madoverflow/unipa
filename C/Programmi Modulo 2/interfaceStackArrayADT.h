//definizione del tipo di oggetto
#ifdef intero
 typedef int Item;
#else
 #ifdef virgola
  typedef float Item;
 #else
   typedef char Item;
 #endif
#endif
//
bool stackIsEmpty();
Item take();
void printItem(const Item a);
void stackPush(const Item a);
void printStack();
Item stackPop();