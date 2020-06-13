#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    srand(time(NULL));
    int satir,sutun,i,j,a,b,c,soldansagasayac=0,metinuzunluk=0,uzunluk=0,yukaridanasagi=0,sagdansolasayac=0,asagidanyukari=0;
    char *pmat=NULL,*p=NULL;
    printf("dizinin once satir ve sonra sutun olacak sekilde boyutunu giriniz :\n");
    scanf("%d %d",&satir,&sutun);
    char dizi[satir][sutun];
    printf("\n\n\n");
    pmat=dizi;

    for(i=0; i<satir; i++)
    {
        for(j=0; j<sutun; j++)
        {
            dizi[i][j]='A'+rand()%26; // random bir karakter ata
        }//satir icin for
    }//sutun icin for
//diziye hangi karakterleri atadýgýný görelim
    for(i=0; i<satir; i++)
    {
        for(j=0; j<sutun; j++)
        {
            printf("%c ",dizi[i][j]);
        }
        printf("\n");
    }
//
    char metin[20];//Ben kullanici en fazla 20 karakter aratir diye düsündüm daha fazla aramak isterseniz icine yazabilirsiniz.
    printf("aramak istediginiz metni giriniz :\n\n");
    scanf("%s",metin);
    p=metin;
//girilen karakterin uzunlugunu bulalim

    for(c=0; metin[c]!='\0'; c++)
    {
        metinuzunluk++;
    }
    printf("girdiginiz metnin uzunlugu :%d\n\n",metinuzunluk);




//soldan saga metni bulalim

    c=0;
    uzunluk=0;
    for(i=0; i<satir; i++)
    {

        for(j=0; j<sutun; j++)
        {
            if(*(pmat+(sutun*i)+j)==*(p+c))
            {
                c++;
                uzunluk++;

                if(uzunluk==metinuzunluk)
                {

                    soldansagasayac++;

                    printf("dizi[%d][%d]\n",i,j-(metinuzunluk-1));/*baslangic adresini göstersin diye son indisten
                    (metinuzunluk-1)'i çýkardim.*/

                }
            }
            else
            {
                c=0;
                uzunluk=0;
            }
        }
    }


    printf("Soldan saga :%d adet bulundu.\n\n\n",soldansagasayac);



//yukaridan asagi metni bulalim
    c=0;
    uzunluk=0;
    for(i=0; i<sutun; i++)
    {
        for(j=0; j<satir; j++)
        {
            if(*(pmat+(sutun*j)+i)==*(p+c))
            {
                c++;
                uzunluk++;
                if(uzunluk==metinuzunluk)
                {
                    yukaridanasagi++;

                    printf("dizi[%d][%d]\n",j-(metinuzunluk-1),i);
                }

            }
            else
            {
                c=0;
                uzunluk=0;
            }
        }
    }

    printf("yukaridan asagi:%d adet bulundu.\n\n\n\n",yukaridanasagi);




//sagdan sola metni bulalim
    c=0;
    uzunluk=0;
    for(a=0; a<satir; a++)
    {
        b=sutun;
        while(b!=0)
        {
            if(*(pmat+(sutun*a)+b)==*(p+c))
            {
                uzunluk++;
                c++;
                if(uzunluk==metinuzunluk)
                {
                    sagdansolasayac++;

                    printf("dizi[%d][%d]\n",a,b+1);/*sagdan sola baslangýc adresini göstermek icin 1 ekliyorum soldan saga
                     yapsaydim 1 çikaracaktim yani yukarida yaptiklarimin aynisi*/

                }
            }
            else
            {
                c=0;
                uzunluk=0;
            }
            b--;
        }

    }


    printf("sagdan sola :%d adet bulundu.\n\n\n\n",sagdansolasayac);




//asagidan yukari metni bulalim

    c=0;
    uzunluk=0;
    for(b=0; b<sutun; b++)
    {
        a=satir;
        while(a!=0)
        {
            if(*(pmat+(sutun*a)+b)==*(p+c))
            {
                c++;
                uzunluk++;
                if(uzunluk==metinuzunluk)
                {
                    asagidanyukari++;

                    printf("dizi[%d][%d]\n",a+(metinuzunluk-1),b);/*burada eger a ve b yi yazdýrýrsam girdigim metnin son
                     karakterinin adresini yazar ama ben ilk karakterini yazmasini istedigim icin a ile metinuzunluðuyla 1
                     i topladim yukaridaki mantigin aynisi*/
                }
            }
            else
            {
                c=0;
                uzunluk=0;
            }
            a--;
        }
    }


    printf("asagidan yukari :%d adet bulundu.\n\n\n\n",asagidanyukari);


    return 0;
}
