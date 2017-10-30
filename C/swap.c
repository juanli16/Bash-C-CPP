#include<stdio.h>

void swap(int* a, int* b){
	int tmp=*a;
	*a=*b;
	*b=tmp;
}

int main(void){
	int a=10;
	int b=9;
	printf("a is %d\n",a);
	printf("b is %d\n",b);
	swap(&a,&b);
	printf("a after swap is %d\n",a);
	printf("b after swap is %d\n",b);
}
