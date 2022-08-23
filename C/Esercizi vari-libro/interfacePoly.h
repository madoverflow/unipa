typedef struct poly * Poly;
Poly polyInit(size_t maxgrad, int coeff);
Poly sum(Poly p1, Poly p2);
void printPoly(Poly p);
Poly mul(Poly p1, Poly p2);
void horner(Poly p, int x);
