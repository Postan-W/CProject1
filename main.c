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
    return 0;
}
