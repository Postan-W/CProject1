/*#��ͷ���Ǳ���Ԥ����(����֮ǰ)ָ�������C���Ա���*/
//��(macro)���滻�����ı��滻�����Ժ���Զ�����������,���Ի��С�
#define PI 3.14159 //����Ԥ����׶Σ������е�PI���ᱻ�滻��3.14159��PI�������ꡣ����ֱ���ں궨�����ע��Ҳ�ǿ��Եģ�Ԥ����׶ο���ʶ�������ע��
#define PI2 2*PI //���п��԰����ꡣ����ע�ͷ��ż�˫б�ܣ�����ʱ��ע���������ݾ��ᱻ��Ϊ�Ǻ��ֵ�����ø�ֵ�滻ԭ����ʹ�õĵط�
#define PRINT printf("%f\n",PI); \
printf("%f\n",PI2);
//���õ�Ԥ�������__LINE__,__DATE__,__TIME__,__FILE__��
//�������ĺꡣ��Ҫע����ǣ���ΪԤ����׶κ�ֻ�Ǵ�����ı��滻ԭ�����е�ʹ�õĵط�������Ҫע����ܻ������bug��ԭ���Ǻ����������(������������������ȼ�������)��ÿ������������(ͬ��)
#define RADIO2DEG(x) ((x)*57.29578)

/*includeҲ����Ԥ����ָ�������������Ǽ򵥵ذ�.h��ͷ�ļ�������ݴӸ��п�ʼ���뵽���ļ���
 * ��.h������ľ��Ǻ궨�塢����ԭ��(�����������ľ���ʵ��)�ȡ���#include <stdio.h>Ϊ������Ϊ���а���
 * printf�ĺ���ԭ�ͣ����������Լ�����ʱ���Ĳ����Ƿ���ȷ��
 *
 *
 *
 * һ���������ÿһ��.c�ļ�����Ӧ��ͷ�ļ�.h���Ѷ��⹫���ĺ���ԭ�ͺ�ȫ�ֱ����������Ž�ȥ��
 * �����⹫���ĺ�����ȫ�ֱ�������������ǰ�����static������ֻ�е�ǰ.c�ļ��в���ʹ�á�
 * */
#include <stdio.h>
#include<stdlib.h>
#include<string.h>//�����ŵĻ�������ֱ�ӵ�ϵͳָ��Ŀ¼��
#include "h1.h"//˫���ŵĻ������������ڵ�ǰĿ¼�ң��Ҳ����ٵ�ϵͳָ��Ŀ¼
typedef  long int64_t;//typedef�����������ñ���������typedef������ŵ����������һ������������������֮��Ϳ�����int64_t����long��ʹ�á�
void value_exchange(int *p1,int *p2);
void trial_on_macro(){
    PRINT;
    printf("%s  %s\n",__DATE__,__TIME__);
    printf("%f\n", RADIO2DEG(2+3));//Ԥ�����ʵ������printf("%f",((2+3)*57.29578));���ﷴӳ�������ŵ���Ҫ��
}
//�����ṹ�壬��������������������
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
//Ƕ�׽ṹ
struct date_time{
    struct date d;
    struct time t;
};
struct date d1,d2;//����d1,d2��ȫ�ֵ�
struct date d3 = {2022,9,30};
struct date d4 = {.year=2022,.day=20};
//�����ṹ�壬�����ڶ���ṹ���ʱ��ʹ������ڸýṹ��ı���
struct {
    int width;
    int height;
}p1,p2;

//���ñ����������������ṹ��
typedef struct house_struct{
    int height;
    int width;
    int length;
} House;

//���ϡ�union���е�Ԫ�ع���һ���ڴ�ռ䣬�ռ��С������Ԫ��ȷ����Ҳ����˵ͬһʱ��ֻ��һ��Ԫ��ռ���Ǹ��ռ䣬������Ԫ�ظ�ֵ�ͻ�ʹ����ֵռ���Ǹ��ռ�
//��Ȼ���������������union
typedef union union_trial{
    int i;
    char ch[sizeof(int)];
}U;

void buy_something(){
    const int PRICE = 100;
    int pay;
    printf("�۸���:%d\n",PRICE);
    printf("����:");
    scanf("%d",&pay);
    printf("����:");
    printf("%d\n",pay - PRICE);
}
void add_two_int() {
    printf("��������������:");
    int a,b;
    scanf("%d %d",&a,&b);
    printf("���ǵĺ���:%d\n",a+b);
}

void exchange_two_variable(){
    //������������ֵ
    int ex1 = 10;
    int ex2 = 20;
    printf("����ǰex1=%d;ex2=%d\n",ex1,ex2);
    value_exchange(&ex1,&ex2);
    printf("������ex1=%d;ex2=%d\n",ex1,ex2);
}
void  operations(){
    //��ֵ��������Ҳ���������������������Ľ���Ǿ����Ǹ�������ߵ��Ǹ�ֵ��������ʾ
    int c = 6;
    int d;
    int e = 1 + (d = c);
    printf("d��ֵ:%d\ne��ֵ:%d\n",d,e);

    //�������㣬+-*��%��=
    c += 6;
    printf("c��6��ֵ:%d\n",c);
    //�����Լ�
    printf("c++�ķ���ֵ:%d\n",c++);
    printf("��ʱc��ֵ:%d\n",c);
    printf("++c�ķ���ֵ:%d\n",++c);
    printf("��ʱc��ֵ:%d\n",c);

    //if��else����������ʱ����һ����������
    if(c > d) d += 6;else d -= 6;
    printf("d��ֵ��:%d\n",d);
}
void sizeof_point(int *p){
    printf("��ָ����������int����Ĵ�С��:%d\n", sizeof(p));
}
void sizeof_point2(int p[]){
    printf("��������������int����Ĵ�С��:%d\n", sizeof(p));
}
void trial_on_sizeof(){
    //sizeof()�����ز���ռ�õ��ֽ������ú���ֻ�ж������ڵ���������ʲô���ͣ�Ȼ�󷵻�ռ���ڴ��С�������ݱ�������ִ��
    int h = 10;
    printf("sizeof(h++):%d\n",sizeof(h++));
    printf("��ʱh��ֵ:%d\n",h);
    printf("sizeof(int):%d\n",sizeof(int));
    /*sizeof�Ǹ����������ж��ڴ�ռ�ô�С�ģ���int a[5]Ϊ����sizeof(a)Ϊ20�����ǽ�a�Բ�����ʽ����������
     * �ں����ڲ�ʹ��sizeof(a)����ô�����4(64λϵͳΪ8�����sizeof������������й�)��ԭ���Ǵ�ʱa������intָ�����ͣ���Ϊ�������a�������ָ�������һ��Ԫ��
     * ��ָ��
     */
    int a[] = {1,2,3,4,5};
    printf("sizeof(a)=%d\n",sizeof(a));
    sizeof_point(a);
    sizeof_point2(a);
}

void const_and_point(){
    //const int *p = &variable,��ָ���ܸ�*p������ֵ,����ζ��p����ָ������������Ҳ����ζ��variable�����޸�
    int v1 = 10;
    const int *p = &v1;
    printf("%d\n",*p);
    printf("sizeof(p)=%d\n",sizeof(p));
    //  *p = 26;������
    //int const *p ��int *const p ��˼һ����ָ����ָ�벻��ָ��������ַ
    int v2 = 20;
    int *const p2 = &v1;
    *p2 = 30;
//    p2 = &v2;������
    printf("%d\n",v2);
}
void const_para_point(const int *p);//ʵ�ο����Ƿ�const intָ�룬����ֻ��ȷ���ں����ڲ����Դ����ָ��ָ��Ŀ���ֵ�����޸�

void trial_on_array(){
    /*�ڸ�ֵ���ұ߻�����Ϊ��������ʱ���������ǵ�һ��Ԫ�صĵ�ַ,��const���ͣ�����֮��constָ�룬���Ժ�������int a[],int *a,�ǵ�Ч�ģ���Ϊ����һ������������ָ��������Ǵ���һ����ַ��
     * ��sizeof�����������������������鿴����
     * */

    int a1[] = {1,2,3,4,5};
    printf("%p\n",a1);//%pָ���ǵ�ַ����
    printf("%p\n",&a1[0]);
    printf("%d\n",*a1);
    printf("%d\n",a1[0]);
}

void operation_on_point() {
    /*ָ����ǵ�ַ������ռ�õ��ڴ��С�ǹ̶��ģ����������޹�(������Ӧ����ָ��Ŀ�������)��64λϵͳ��8�ֽڣ�32λϵͳ��4�ֽ�*/
    /*ָ���һ���һָ���ǵ�ַ�仯1������char��int���͵�ָ��Ӽ�һ�仯����1��4�ֽ�*/
    char a[] = {0, 1, 2, 3};
    char *p = a;
    printf("p=%p\n", p);
    printf("a=%p\n", a);
    p += 1;
    printf("p+1=%p", p);//���Է��ֵ�ַ������1

    //������int������ʵ��
    int a2[] = {0, 1, 2, 3};
    int *p2 = a2;
    printf("p2=%p\n", p2);
    printf("a2=%p\n", a2);
    p2 += 1;
    printf("p2+1=%p\n", p2);//���Է��ֵ�ַ������4

    /*  ��֪a++��++a�������ǣ����߶���ʹa��ֵ��һ����ǰ�߷��ؼ�һǰ��ֵ�����߷��ؼ�һ���ֵ��
     *  ����*p++����Ϊ++���ȼ��ߣ����Ե�Ч��*(p++),��pָ����һ����ַ����ȡ���������ƶ�p֮ǰ�ĵ�ַ�ϵ�ֵ��
     *  һ�������Ǳ��������ֵ����ȡ����ǰλ�õ�ֵ������λ���Ƶ���һλ
     *
     * */
    int a3[] = {22,33,44,55,66};
    int *p3 = a3;
    for(int i = 0; i <sizeof(a3)/sizeof(a3[0]);i++){
        printf("%d\n",*p3++);
    }

    //���Զ�ָ����бȽϴ�С������ֵַ�Ĵ�С��������ʾ
    //void ���͵�ָ�룬���λ���ƶ�����ʲô����
    int a4 [] = {222,333,444};
    void *p4 = a4;
    int *p5 = a4;
    printf("p4=%p\n",p4++);
    printf("p4=%p\n",p4);//������1���ɴ˿ɼ���voidָ����Ȼָ����Ŀ�꣬���ǲ�������Ŀ�����ͱ���һ��
    printf("p4=%p\n",p5++);
    printf("p4=%p\n",p5);//������4

}

void trial_on_malloc(){
    /*malloc����������void*��voidָ�룬������ڴ��С�����ֽ�Ϊ��λ��
     *
     *
     */
    int *p = (int*)malloc(3*sizeof(int));//�����ڴ�ռ�
    for(int i=0;i<3;i++){
        scanf("%d",&p[i]);
    }
    for(int i=0;i<3;i++){
        printf("%d\n",p[i]);
    }
    /*��������Կ���һЩ���ʵĶ����������p�ı��ֺ������飬��Ϊʹ�����±꣬�����Ǹ�int���͵�ָ�룬�������飬
     * ֻ��ָ��Ҳ����ʹ���±꣬p[3]���൱��p+3������p�Ǹ�ָ��ָ��ĵ�ַ��
     * */
    free(p);//�ͷ��ڴ�
}

void constant_string(){
    int *p = "hello";
    printf("consta_string�����ڲ���hello�ĵ�ַ:%p\n",p);
}

void trial_on_string(){
    /*C�����У��ַ�����Ϊ��\0��β���ַ�����,���漸����ʽ��ͬ��
     * */
    char str1[] = {'h','e','l','l','o','\0'};
    char str2[] = "hello";//ע���ַ�����ĳ�����6����������\0����ĩβ
    char str3[] = "hello";
    printf("str2�ĵ�ַ:%p\n",str2);
    printf("str3�ĵ�ַ:%p\n",str3);//�����ǲ�һ���ģ���Ϊ�����ǲ�ͬ�ľֲ�����

    char *p1 = "hello";
    char *p2= "hello";
    printf("p1=%p\np2=%p\n",p1,p2);
    constant_string();//������һ���ģ�������Ϊ��ʱ"hello""Ϊ�ַ������������߽���������ȫ��ֻ��һ����ֻ���ġ�ע���ǳ���ȫ�֣���������Ҳ�����ͬ��
}
void input_output_string(){
    char string[8];
    scanf("%7s",string);//�����ո�tab���߻���Ϊֹ������ָ��������7���ַ�����������Խ��
    printf("%s",string);


}
void para_main(int argc,char const *argv[]){
    //���������argc�ǲ�������,�����ÿո�ָ����0���ļ�����argv��constָ�����飬ÿ��ָ��ָ��һ���ַ�������������
    for(int i=0;i<argc;i++){
        printf("%d:%c\n",i,*argv[i]);//argv[i]ʵ������ָ���i���ַ�����һ����ĸ��ָ��
    }
    for(int i=0;i<argc;i++){
        printf("%d:%s\n",i,argv[i]);//��%s����������������Ὣargv[i]ָ���char��ʼ��ֱ��\0�����Ĳ�����Ϊ�ַ���
    }
}
void some_string_function(){
    char str1[] = "hello";
    printf("str1�ĳ���:%d\n", strlen(str1));
    char str2[] = "aelcome";
    printf("str1��str2�Ƚ�:%d", strcmp(str1,str2));//������ĸ��˳����бȽϣ�������Կ���str2-str1
}

//����������һ���n��const intֵ��ö�ٱȽϷ��㡣����һ����ֵ��ǰ��һ��ֵ��һ
enum COLOR{RED,GREEN,YELLOW};//Ĭ�ϲ���ֵ�����Σ����ǵ�ֵ������0,1,2
enum AGE{MICHAEL=21,TOM,JACK=30};//���ǵ�ֵ������21,22,30
void print_enum(){
    printf("%d\n",TOM);
}

void trial_on_struct(){
    printf("d4����:%d-%d-%d\n",d4.year,d4.month,d4.day);
    d4 = d3;//����һ��struct������Ԫ��һ�θ�ֵ����һ��
    printf("d4����:%d-%d-%d\n",d4.year,d4.month,d4.day);

    struct date d5;
    d5 = (struct date){2022,8,21};
    struct date *d_point = &d5;//Ҫ��&������Ϊ�ṹ�����ֲ����ǵ�ַ���������
    struct date d6;
    d6 = *d_point;//struct date���͵�ָ��d_point��ָ���ڴ�ռ�ͨ��*�õ������ݣ���Ϊstruct date���͵�һ���ṹ�壬Ҳ����d5������Ǹ��ṹ�壬����ֵ����d6
    printf("d6����:%d-%d-%d\n",d6.year,d6.month,d6.day);
    //��ͬ��
    printf("d6����:%d-%d-%d\n",(*d_point).year,(*d_point).month,(*d_point).day);
    //��ͬ�ڡ������������µķ���->
    printf("d6����:%d-%d-%d\n",d_point->year,d_point->month,d_point->day);

    //�ṹ����
    struct date dates[] = {{2022,1,22},{2022,2,23},{2022,3,24}};
    printf("dates[1].month=%d\n",dates[1].month);

    //Ƕ�׽ṹ
    struct  date_time dt = {{2022,5,23},{22,18,34}};
    printf("dt.d.month=%d\n",dt.d.month);

    //ʹ�ñ���
    House h = {3,4,5};
    printf("house�ĸ�:%d",h.height);
}
void trial_on_union(){
    U u1;
    u1.i = 8679;//��ʱiʹ���˿ռ䣬��ôu1.ch������ݾ���i�����ݣ���������char ch[]����ʽ���õ�
    for(int i=0;i<sizeof(int);i++){
        printf("%02hhX",u1.ch[i]);//��16���������8679��ʮ��������21E7����x86�ܹ��еĴ���ǵ�λ��ǰ�����Իῴ��E7210000
    }
}
//��ǰ��������
void f_name(void){
    printf("%s",__func__ );
}

//��̬���ر����ں�����������Ȼ������ֵ����������������ں��������Ծ�̬���ر�����ȫ�������ڣ����ֲ�������
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