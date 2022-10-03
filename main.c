#include <stdio.h>

int main() {
    int pay;
    const int PRICE = 100;
    printf("价格是:%d\n",PRICE);
    printf("付款:");
    scanf("%d",&pay);
    printf("找零:");
    printf("%d",pay - PRICE);
    return 0;
}
