#include <stdio.h>
int main()
{
    int i,c,asal,n;
    printf("Bir sayi giriniz:");
    scanf("%d",&n);
    printf("1 ile %d arasindaki asal sayilar:\n",n);
    for(i=2 ; i<=n; i++)
    {
        asal=1;
        for(c=2; c<i; c++)
        {
            if(i%c==0)
            {
                asal=0;
            }
        }
        if(asal==1)
            {
                printf("%d\n",i);
            }
        }

    return 0;
}
