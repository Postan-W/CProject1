#include <stdio.h>

int main() {

    const int PRICE = 100;
    int pay;
    printf("�۸���:%d\n",PRICE);
    printf("����:");
    scanf("%d",&pay);
    printf("����:");
    printf("%d\n",pay - PRICE);


    printf("��������������:");
    int a,b;
    scanf("%d %d",&a,&b);
    printf("���ǵĺ���:%d\n",a+b);

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

    //sizeof()�����ز���ռ�õ��ֽ������ú���ֻ�ж������ڵ���������ʲô���ͣ�Ȼ�󷵻�ռ���ڴ��С�������ݱ�������ִ��
    int h = 10;
    printf("sizeof(h++):%d\n",sizeof(h++));
    printf("��ʱh��ֵ:%d\n",h);
    printf("sizeof(int):%d\n",sizeof(int));

    return 0;
}
