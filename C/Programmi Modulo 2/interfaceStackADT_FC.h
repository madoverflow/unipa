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
typedef struct stack * S;
S stackInit(S topPtr);
bool stackIsEmpty(S topPtr);
void stackPush(S topPtr, Item a);
Item *stackPop(S stackPtr);
void stackDisplay(S topPtr);
Item getItem();
void putItem(Item *ptr);
