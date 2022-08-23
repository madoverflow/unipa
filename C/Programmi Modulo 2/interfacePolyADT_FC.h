typedef struct poly * Poly;
Poly term(int coef, size_t expo);
Poly add(Poly p1, Poly p2);
Poly mult(Poly p1, Poly p2);
float eval(Poly p, float x);
void show(Poly comodoPtr);