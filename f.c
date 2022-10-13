#include "h1.h"
#include <stdio.h>

/*由于h1.h中定义了原型为void max_a_b(int a,int b)，所以这里include后，实现函数时必须和原型一致。在调用max_a_b的.c文件中
 * include h1.h文件后，也必须传正确类型的参数才能使用该函数。所以头文件用于帮编译器检查代码规范性。
 * 否则的话，以该函数为例，调用的.c文件中没有include该原型，调用的时候传入double类型参数也是可以编译通过的。
 * */
void max_a_b(int a,int b){
    printf("%d\n",a>b?a:b);
}

/*当一条字符串的内容一行写不下时，可以在上一行的结尾加上\。也可以将每一行的内容都用双引号包裹起来，编译器处理多个这样的
 * 被双引号包裹的内容时，只要它们之间没有其他字符或者只有空格，那么它们就会被合并成一条字符串*/
void multi_rows_str(){
    printf("a dog in the left road and a cat in the right road,"
           "the tiger wants to eat the dog,"
           "so the tiger come to the left\n");
    puts("a book with a beautiful cover has more attraction to the reader\
           ,than when it hasn't a beautiful cover\n");
    puts("the people's republic of china is built in \
         oct 1,1949");
}