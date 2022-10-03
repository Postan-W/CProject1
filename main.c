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


    return 0;
}
