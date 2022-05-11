#include<stdio.h>
int main(){
	int islem;
	int bakiye = 1000;
	int tutar;
	printf("1)para cekme\n2)para yatirma\n3)havale\n4)bakiye ogrenme\n5)kart iade\n\n\n\n\n ");
	printf("isleminizi secin= ");
	scanf("%d",&islem);
	switch(islem){
		case 1:
			printf("Bakiyeniz=%d\n",bakiye);
			printf("Cekilecek tutar=");
			scanf("%d",&tutar);
			if(tutar>bakiye){
				printf("bakiyeniz yetersiz!\n");	
			}
			else{
				bakiye-=tutar;
				printf("bakiyeniz=%d",bakiye);
		break;
			}
		case 2:
			printf("Bakiyeniz=%d\n",bakiye);
			printf("Yatırılacak tutar=");
			scanf("%d",&tutar);
	
			bakiye+=tutar;
			printf("bakiyeniz=%d",bakiye);
		break;
		case 3:
			printf("Bakiyeniz=%d\n",bakiye);
			printf("Havale tutarı=");
			scanf("%d",&tutar);
			if(tutar>bakiye){
				printf("bakiyeniz yetersiz!\n");	
			}
			else{
				bakiye-=tutar;
				printf("bakiyeniz=%d",bakiye);
		break;
		case 4:
			printf("Bakiyeniz: %d",bakiye);
		break;
		case 5:
			printf("Kartiniz iade edilmistir");
		break;
		default:
			printf("bilinmeyen islem!");
}
}
return 0;	
}

