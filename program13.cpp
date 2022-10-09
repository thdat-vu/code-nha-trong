#include<stdio.h>
void getValue(int* a, int *b, int *c, int *d){
	*a = *b - *c;
	*c = *d + *b;
	*d = *a - *c;
	*b = *c + *d;
}
main(){
	int x = 1, y = 2, z = 3, t = 4;
	getValue(&y, &z , &x, &t);
	printf("x = %d, y = %d, z = %d,t = %d", x , y ,z ,t);
}