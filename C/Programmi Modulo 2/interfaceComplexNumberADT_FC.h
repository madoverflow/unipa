typedef struct complex * ComplexPtr;
ComplexPtr init(double a, double b);
void destroy(const ComplexPtr number);
void display(const ComplexPtr const number);
ComplexPtr add(ComplexPtr x, ComplexPtr y);
ComplexPtr sub(ComplexPtr x, ComplexPtr y);
ComplexPtr prod(ComplexPtr x, ComplexPtr y);
ComplexPtr cdiv(ComplexPtr x, ComplexPtr y);
void nrad(size_t N);