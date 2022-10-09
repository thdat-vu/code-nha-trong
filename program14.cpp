#include<stdio.h>
void getValue(int* a, int b, int *c, int d){
	b = *a + d;
	*a = *c + b;
	d = *c - *a;
	*c = *a + d;
}
main(){
	int x = 1, y = 2, z = 3, t = 4;
	getValue(&x, z , &t, y);
	printf("x = %d, y = %d, z = %d,t = %d", x , y ,z ,t);
}