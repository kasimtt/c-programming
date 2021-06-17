#include <stdio.h>
#include <stdlib.h>

int main()
{
   int secim,numara;
   char isim[30];
   float bakiye;
   FILE *dosya;

   if((dosya=fopen("musteriler.txt","r"))==NULL)
   {
       printf("dosya okuma hatasi\n");
       exit(1);
   }

   while(1)
   {
       printf("1-Bankada parasi olan musteriler\n");
       printf("2-Bankada parasi olmayan musteriler\n");
       printf("3-Bankaya borcu olan musteriler\n");
       printf("4-cýkýs\n");
       scanf("%d",&secim);
       fscanf(dosya,"%d\t%s\t%f",&numara,isim,&bakiye);
       switch(secim)
       {
        case 1:
        printf("bankamizda bakiyesi olan musteriler....\n");
        while(!feof(dosya))
        {
            if(bakiye>0)
            {
               printf("%d\t%s\t%f",numara,isim,bakiye);
               printf("\n");
            }
            fscanf(dosya,"%d\t%s\t%f",&numara,isim,&bakiye);
        }
        break;

        case 2:
        printf("bankamizda bakiyesi olmayan musteriler....\n");
        while(!feof(dosya))
        {
            if(bakiye==0)
            {
               printf("%d\t%s\t%f",numara,isim,bakiye);
               printf("\n");
            }
            fscanf(dosya,"%d\t%s\t%f",&numara,isim,&bakiye);
        }
        break;

        case 3:
        printf("bankamiza borcu olan musteriler...\n");
        while(!feof(dosya))
        {
            if(bakiye<0)
            {
               printf("%d\t%s\t%f",numara,isim,bakiye);
               printf("\n");
            }
            fscanf(dosya,"%d\t%s\t%f",&numara,isim,&bakiye);
        }
        break;

        case 4:printf("cikis yapildi");
        exit(1);
        break;
       }
       rewind(dosya);
   }


  return 0;
}
