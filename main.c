#include <stdio.h>
#include<stdlib.h>

void value_exchange(int *p1,int *p2);

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