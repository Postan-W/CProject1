/*#开头的是编译预处理(编译之前)指令，不属于C语言本身*/
//宏(macro)的替换就是文本替换，所以宏可以定义任意内容,可以换行。
#define PI 3.14159 //编译预处理阶段，程序中的PI都会被替换成3.14159，PI被称作宏。这里直接在宏定义后面注释也是可以的，预处理阶段可以识别出这是注释
#define PI2 2*PI //宏中可以包含宏。除了注释符号即双斜杠，定义时请注意所有内容均会被认为是宏的值，并用该值替换原代码使用的地方
#define PRINT printf("%f\n",PI); \
printf("%f\n",PI2);
//有用的预定义宏有__LINE__,__DATE__,__TIME__,__FILE__等
//带参数的宏。需要注意的是，因为预处理阶段宏只是纯粹地文本替换原代码中的使用的地方，所以要注意可能会产生的bug，原则是宏整体带括号(避免比如算术运算优先级的问题)，每个参数带括号(同上)
#define RADIO2DEG(x) ((x)*57.29578)

/*include也属于预处理指令，所做的事情就是简单地把.h即头文件里的内容从该行开始插入到该文件。
 * 而.h里包含的就是宏定义、函数原型(不包含函数的具体实现)等。以#include <stdio.h>为例，因为其中包含
 * printf的函数原型，编译器可以检查调用时传的参数是否正确。
 *
 *
 *
 * 一般的做法是每一个.c文件都对应其头文件.h，把对外公开的函数原型和全局变量的声明放进去。
 * 不对外公开的函数和全局变量，可以在其前面加上static，这样只有当前.c文件中才能使用。
 * */
#include <stdio.h>
#include<stdlib.h>
#include<string.h>//尖括号的话编译器直接到系统指定目录找
#include "h1.h"//双引号的话编译器会先在当前目录找，找不到再到系统指定目录
typedef  long int64_t;//typedef的作用是设置别名，就是typedef后面跟着的内容用最后一个符号来命名。所以之后就可以用int64_t代替long来使用。
void value_exchange(int *p1,int *p2);
void trial_on_macro(){
    PRINT;
    printf("%s  %s\n",__DATE__,__TIME__);
    printf("%f\n", RADIO2DEG(2+3));//预处理后实际上是printf("%f",((2+3)*57.29578));这里反映出带括号的重要性
}
//有名结构体，可以用名字来创建变量
struct date {
    int year;
    int month;
    int day;
};
struct time{
    int hour;
    int minute;
    int second;
};
//嵌套结构
struct date_time{
    struct date d;
    struct time t;
};
struct date d1,d2;//这里d1,d2是全局的
struct date d3 = {2022,9,30};
struct date d4 = {.year=2022,.day=20};
//无名结构体，所以在定义结构体的时候就创建属于该结构体的变量
struct {
    int width;
    int height;
}p1,p2;

//设置别名。可以是无名结构体
typedef struct house_struct{
    int height;
    int width;
    int length;
} House;

//联合。union所有的元素共用一个内存空间，空间大小由最大的元素确定。也就是说同一时间只有一个元素占用那个空间，给其他元素赋值就会使得新值占用那个空间
//当然，这里可以是无名union
typedef union union_trial{
    int i;
    char ch[sizeof(int)];
}U;

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
void some_string_function(){
    char str1[] = "hello";
    printf("str1的长度:%d\n", strlen(str1));
    char str2[] = "aelcome";
    printf("str1与str2比较:%d", strcmp(str1,str2));//按照字母表顺序进行比较，结果可以看作str2-str1
}

//声明排列在一起的n的const int值用枚举比较方便。后面一个的值是前面一个值加一
enum COLOR{RED,GREEN,YELLOW};//默认不赋值的情形，它们的值依次是0,1,2
enum AGE{MICHAEL=21,TOM,JACK=30};//它们的值依次是21,22,30
void print_enum(){
    printf("%d\n",TOM);
}

void trial_on_struct(){
    printf("d4日期:%d-%d-%d\n",d4.year,d4.month,d4.day);
    d4 = d3;//把另一个struct变量里元素一次赋值给另一个
    printf("d4日期:%d-%d-%d\n",d4.year,d4.month,d4.day);

    struct date d5;
    d5 = (struct date){2022,8,21};
    struct date *d_point = &d5;//要用&符，因为结构的名字并不是地址，数组才是
    struct date d6;
    d6 = *d_point;//struct date类型的指针d_point所指的内存空间通过*得到其内容，即为struct date类型的一个结构体，也即是d5代表的那个结构体，将其值赋给d6
    printf("d6日期:%d-%d-%d\n",d6.year,d6.month,d6.day);
    //等同于
    printf("d6日期:%d-%d-%d\n",(*d_point).year,(*d_point).month,(*d_point).day);
    //等同于。这里引出了新的符号->
    printf("d6日期:%d-%d-%d\n",d_point->year,d_point->month,d_point->day);

    //结构数组
    struct date dates[] = {{2022,1,22},{2022,2,23},{2022,3,24}};
    printf("dates[1].month=%d\n",dates[1].month);

    //嵌套结构
    struct  date_time dt = {{2022,5,23},{22,18,34}};
    printf("dt.d.month=%d\n",dt.d.month);

    //使用别名
    House h = {3,4,5};
    printf("house的高:%d",h.height);
}
void trial_on_union(){
    U u1;
    u1.i = 8679;//此时i使用了空间，那么u1.ch里的内容就是i的内容，但是是以char ch[]的形式放置的
    for(int i=0;i<sizeof(int);i++){
        printf("%02hhX",u1.ch[i]);//以16进制输出。8679的十六进制是21E7，在x86架构中的存放是低位在前，所以会看到E7210000
    }
}
//当前函数名称
void f_name(void){
    printf("%s",__func__ );
}

//静态本地变量在函数结束后仍然保持其值，但作用域仅限所在函数。所以静态本地变量是全局生命期，但局部作用域。
void trial_on_static(void){
    static int a = 1;
    printf("%s:a=%d\n",__func__ ,a++);
}
int main(int argc,char const *argv[]) {
    int a = 10;
    int b =15;
    max_a_b(a,b);
    return 0;
}

void value_exchange(int *p1,int *p2){
    int temp;
    temp = *p2;
    *p2 = *p1;
    *p1 = temp;
}