#include <stdio.h>

int main() {

    const int PRICE = 100;
    int pay;
    printf("价格是:%d\n",PRICE);
    printf("付款:");
    scanf("%d",&pay);
    printf("找零:");
    printf("%d\n",pay - PRICE);


    printf("请输入两个整数:");
    int a,b;
    scanf("%d %d",&a,&b);
    printf("它们的和是:%d\n",a+b);

    //赋值操作本身也是运算符，自右向左。运算的结果是就是那个赋予左边的那个值，下面演示
    int c = 6;
    int d;
    int e = 1 + (d = c);
    printf("d的值:%d\ne的值:%d\n",d,e);


    //复合运算，+-*、%和=
    c += 6;
    printf("c加6的值:%d\n",c);
    //自增自减
    printf("c++的返回值:%d\n",c++);
    printf("此时c的值:%d\n",c);
    printf("++c的返回值:%d\n",++c);
    printf("此时c的值:%d\n",c);

    //if或else不带大括号时后面一句属于它们
    if(c > d) d += 6;else d -= 6;
    printf("d的值是:%d\n",d);

    //sizeof()，返回参数占用的字节数。该函数只判断括号内的内容属于什么类型，然后返回占用内存大小，而内容本身并不会执行
    int h = 10;
    printf("sizeof(h++):%d\n",sizeof(h++));
    printf("此时h的值:%d\n",h);
    printf("sizeof(int):%d\n",sizeof(int));

    return 0;
}
