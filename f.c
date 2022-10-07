#include "h1.h"
#include <stdio.h>
/*由于h1.h中定义了原型为void max_a_b(int a,int b)，所以这里include后，实现函数时必须和原型一致。在调用max_a_b的.c文件中
 * include h1.h文件后，也必须传正确类型的参数才能使用该函数。所以头文件用于帮编译器检查代码规范性。
 * 否则的话，以该函数为例，调用的.c文件中没有include该原型，调用的时候传入double类型参数也是可以编译通过的。
 * */
void max_a_b(int a,int b){
    printf("%d\n",a>b?a:b);
}

