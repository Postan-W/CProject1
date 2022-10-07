#include <stdio.h>
#include<stdlib.h>

void value_exchange(int *p1,int *p2);

void buy_something(){
    const int PRICE = 100;
    int pay;
    printf("价格是:%d\n",PRICE);
    printf("付款:");
    scanf("%d",&pay);
    printf("找零:");
    printf("%d\n",pay - PRICE);
}
void add_two_int() {
    printf("请输入两个整数:");
    int a,b;
    scanf("%d %d",&a,&b);
    printf("它们的和是:%d\n",a+b);
}

void exchange_two_variable(){
    //交换两个数的值
    int ex1 = 10;
    int ex2 = 20;
    printf("交换前ex1=%d;ex2=%d\n",ex1,ex2);
    value_exchange(&ex1,&ex2);
    printf("交换后ex1=%d;ex2=%d\n",ex1,ex2);
}
void  operations(){
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
}
void sizeof_point(int *p){
    printf("当指针参数传入的int数组的大小是:%d\n", sizeof(p));
}
void sizeof_point2(int p[]){
    printf("当数组参数传入的int数组的大小是:%d\n", sizeof(p));
}
void trial_on_sizeof(){
    //sizeof()，返回参数占用的字节数。该函数只判断括号内的内容属于什么类型，然后返回占用内存大小，而内容本身并不会执行
    int h = 10;
    printf("sizeof(h++):%d\n",sizeof(h++));
    printf("此时h的值:%d\n",h);
    printf("sizeof(int):%d\n",sizeof(int));
    /*sizeof是根据类型来判断内存占用大小的，以int a[5]为例，sizeof(a)为20；但是将a以参数形式传给函数，
     * 在函数内部使用sizeof(a)，那么结果是4(64位系统为8，这和sizeof函数本身机制有关)，原因是此时a被看做int指针类型，因为数组变量a本身就是指向数组第一个元素
     * 的指针
     */
    int a[] = {1,2,3,4,5};
    printf("sizeof(a)=%d\n",sizeof(a));
    sizeof_point(a);
    sizeof_point2(a);
}

void const_and_point(){
    //const int *p = &variable,是指不能给*p赋其他值,不意味着p不能指向其他变量，也不意味着variable不能修改
    int v1 = 10;
    const int *p = &v1;
    printf("%d\n",*p);
    printf("sizeof(p)=%d\n",sizeof(p));
    //  *p = 26;不允许
    //int const *p 和int *const p 意思一样，指的是指针不能指向其他地址
    int v2 = 20;
    int *const p2 = &v1;
    *p2 = 30;
//    p2 = &v2;不允许
    printf("%d\n",v2);
}
void const_para_point(const int *p);//实参可以是非const int指针，这样只是确保在函数内部不对传入的指针指向目标的值进行修改

void trial_on_array(){
    /*在赋值号右边或者作为函数参数时，数组名是第一个元素的地址,是const类型，换言之是const指针，所以函数参数int a[],int *a,是等效的，因为传入一个数组名或者指针变量都是传入一个地址。
     * 而sizeof函数把数组名当作整个数组看待。
     * */

    int a1[] = {1,2,3,4,5};
    printf("%p\n",a1);//%p指的是地址类型
    printf("%p\n",&a1[0]);
    printf("%d\n",*a1);
    printf("%d\n",a1[0]);
}

void operation_on_point() {
    /*指针就是地址，本身占用的内存大小是固定的，和其类型无关(类型理应是其指向目标的类型)，64位系统则8字节，32位系统则4字节*/
    /*指针加一或减一指的是地址变化1，所以char或int类型的指针加减一变化的是1或4字节*/
    char a[] = {0, 1, 2, 3};
    char *p = a;
    printf("p=%p\n", p);
    printf("a=%p\n", a);
    p += 1;
    printf("p+1=%p", p);//可以发现地址增加了1

    //下面用int类型做实验
    int a2[] = {0, 1, 2, 3};
    int *p2 = a2;
    printf("p2=%p\n", p2);
    printf("a2=%p\n", a2);
    p2 += 1;
    printf("p2+1=%p\n", p2);//可以发现地址增加了4

    /*  已知a++和++a的区别是：二者都是使a的值加一，但前者返回加一前的值，后者返回加一后的值。
     *  所以*p++，因为++优先级高，所以等效于*(p++),即p指向下一个地址，但取出的仍是移动p之前的地址上的值。
     *  一个例子是遍历数组的值，即取出当前位置的值，并且位置移到下一位
     *
     * */
    int a3[] = {22,33,44,55,66};
    int *p3 = a3;
    for(int i = 0; i <sizeof(a3)/sizeof(a3[0]);i++){
        printf("%d\n",*p3++);
    }

    //可以对指针进行比较大小，即地址值的大小，不作演示
    //void 类型的指针，如果位置移动会是什么样的
    int a4 [] = {222,333,444};
    void *p4 = a4;
    int *p5 = a4;
    printf("p4=%p\n",p4++);
    printf("p4=%p\n",p4);//增加了1。由此可见，void指针虽然指向了目标，但是并不是与目标类型保持一致
    printf("p4=%p\n",p5++);
    printf("p4=%p\n",p5);//增加了4

}

void trial_on_malloc(){
    /*malloc返回类型是void*即void指针，申请的内存大小是以字节为单位的
     *
     *
     */
    int *p = (int*)malloc(3*sizeof(int));//连续内存空间
    for(int i=0;i<3;i++){
        scanf("%d",&p[i]);
    }
    for(int i=0;i<3;i++){
        printf("%d\n",p[i]);
    }
    /*从上面可以看出一些本质的东西。上面的p的表现很像数组，因为使用了下标，但它是个int类型的指针，不是数组，
     * 只是指针也可以使用下标，p[3]即相当于p+3，其中p是该指针指向的地址。
     * */
    free(p);//释放内存
}

void constant_string(){
    int *p = "hello";
    printf("consta_string函数内部的hello的地址:%p\n",p);
}

void trial_on_string(){
    /*C语言中，字符串即为以\0结尾的字符数组,下面几种形式等同。
     * */
    char str1[] = {'h','e','l','l','o','\0'};
    char str2[] = "hello";//注意字符数组的长度是6，编译器将\0放在末尾
    char str3[] = "hello";
    printf("str2的地址:%p\n",str2);
    printf("str3的地址:%p\n",str3);//二者是不一样的，因为二者是不同的局部变量

    char *p1 = "hello";
    char *p2= "hello";
    printf("p1=%p\np2=%p\n",p1,p2);
    constant_string();//三者是一样的，这是因为此时"hello""为字符串常量，后者叫字面量，全局只有一个，只读的。注意是程序全局，生命周期也与程序同在
}
void input_output_string(){
    char string[8];
    scanf("%7s",string);//读到空格、tab或者换行为止。这里指定了最多读7个字符，避免数组越界
    printf("%s",string);


}
void para_main(int argc,char const *argv[]){
    //输出参数。argc是参数个数,参数用空格分割，参数0是文件本身。argv是const指针数组，每个指针指向一个字符串，即参数。
    for(int i=0;i<argc;i++){
        printf("%d:%c\n",i,*argv[i]);//argv[i]实际上是指向第i个字符串第一个字母的指针
    }
    for(int i=0;i<argc;i++){
        printf("%d:%s\n",i,argv[i]);//用%s进行输出，编译器会将argv[i]指向的char开始，直到\0结束的部分作为字符串
    }
}
int main(int argc,char const *argv[]) {
    para_main(argc,argv);
    return 0;
}

void value_exchange(int *p1,int *p2){
    int temp;
    temp = *p2;
    *p2 = *p1;
    *p1 = temp;
}