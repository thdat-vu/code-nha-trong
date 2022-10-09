#include<stdio.h>
void getValue(int* a, int b, int* c, int d){
	*a = b + d;
	*c += *a;
	d = *a + *c;
	b = *a - *c;
}
main(){
	int x = 1, y = 2, z = 3, t = 4;
	getValue(&x, y, &t, z);
	printf("x = %d, y = %d,z = %d, t = %d\n", x, y, z, t);
}