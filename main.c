#include <stdio.h>

int main() {
    int pay;
    const int PRICE = 100;
    printf("�۸���:%d\n",PRICE);
    printf("����:");
    scanf("%d",&pay);
    printf("����:");
    printf("%d",pay - PRICE);
    return 0;
}
