#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<conio.h>

char *strcpy(char *dest, const char *source);
int main()
{

    int evli_sayisi=0,bekar_sayisi=0,es_calisan_sayisi=0,cocuk_sayisi_ort=0,cocugu_olan_sayisi=0,cocuk_sayisi3=0,engelli_sayisi=0;
    int a,ikiyuz,yuz,elli,yirmi,on,bes,bir,ellikurus,yirmibeskurus,onkurus,beskurus,birkurus;
    int cocuk_sayisi,altidanbuyuk_cocuksayisi,engellilik_orani,es_para=0,cocuk_para=0,engel_derecesi,sayac1,kisi_sayisi=0,net_ucret_sayisi=0;
    int aylikvergi[4]={0,0,0,0};
    int para_sayisi[15]={0,0,0,0,0,0,0,0,0,0,0,0};
    int tc_sayac;
    char ad[50],soyad[50],tc[50];
    char enbuyuk_isim[50],enbuyuk_soyisim[50],enbuyuk_tc[50];
    char medeni,esiniz,engel,i;
    float aylik_brutucret,engel_indirimi,aylik_vergi,kalan,net_ucret,toplam_netucret=0,toplam_vergi=0,toplam_brut=0,enyuksek_brut=0,enyuksek_toplambrut=0,enyuksek_net=0;
    float enyuksek_aylikvergi=0,enyuksek_ayliknetucret=0;

    do
    {
        do{
        printf("TC Kimlik numaranizi giriniz :");
        scanf("%s",&tc);
        tc_sayac=0;
        for(i=0;i<11;i++)
        {
            if(isdigit(tc[i])==0)
            {
                tc_sayac++;
            }
        }
     	}while(tc_sayac!=0 || strlen(tc)!=11);
     	printf("Adiniz ve Soyadiniz :");
        scanf("%s %s",&ad,&soyad);
        printf("Aylik brut ucretinizi giriniz :");
        scanf("%f",&aylik_brutucret);
        if(aylik_brutucret<=1770.50)
        {
            aylik_brutucret=1770.50;

        }
        do
        {
          printf("Medeni durumunuzu giriniz (Evli/Bekar icin e/E/B/b):");
          scanf("%s",&medeni);
          if(medeni=='e'||medeni=='E'||medeni=='B'||medeni=='b')
            break;
        }
        while(medeni!='e'||medeni!='E'||medeni!='b'||medeni!='B');
        if(medeni=='e'||medeni=='E')
            {
            evli_sayisi++;
            do
            {
                printf("Esiniz calisiyor mu (Evet/Hayir icin e/E/H/h)?");
                scanf("%s",&esiniz);
                if(esiniz=='e'||esiniz=='E')
                    break;
                if(esiniz == 'h' || esiniz == 'H')
                {
                    es_para=220;
                    break;
                }
                else
                {
                    es_calisan_sayisi++;
                    es_para=0;
                }
            }
            while(esiniz!='e'||esiniz!='E'||esiniz!='H'||esiniz!='h');
            }
            else
                bekar_sayisi++;

            do
            {
                printf("Bakmakla yukumlu oldugunuz cocuk sayisi (0 yada daha buyuk):");
                scanf("%d",&cocuk_sayisi);
                if(cocuk_sayisi>=0)
                break;
            }
            while(cocuk_sayisi<0);
                if(cocuk_sayisi>0)
                {
                    if(cocuk_sayisi>3)
                    {
                         cocuk_sayisi3++;
                    }
                    cocuk_sayisi_ort+=cocuk_sayisi;
                    cocugu_olan_sayisi++;
                    do
                    {
                        printf("Yasi 6 dan buyuk olanlarin sayisi (0 yada daha buyuk):");
                        scanf("%d",&altidanbuyuk_cocuksayisi);
                        if(altidanbuyuk_cocuksayisi>=0)
                            break;
                    }
                    while(altidanbuyuk_cocuksayisi<0);
                    if(altidanbuyuk_cocuksayisi>0)
                    {
                        cocuk_para=cocuk_para+(altidanbuyuk_cocuksayisi*45);
                    }
                    if(cocuk_sayisi-altidanbuyuk_cocuksayisi>0)
                    {
                        cocuk_para=cocuk_para+((cocuk_sayisi-altidanbuyuk_cocuksayisi)*25);
                    }
                }
                else
                {
                    cocuk_para=0;
                }




        do
        {
            printf("Herhangi bir engeliniz varmi (Evet/Hayir icin e/E/H/h)?");
            scanf("%s",&engel);
            if(engel=='e'||engel=='E'||engel=='h'||engel=='H')
                break;
        }
        while(engel!='e'||engel!='E'||engel!='H'||engel!='h');
        if(engel=='e'||engel=='E')
        {
            engelli_sayisi++;
            do
            {
                printf("Engellilik oraninizi giriniz (0-100 arasi tam sayi):");
                scanf("%d",&engellilik_orani);
                if(engellilik_orani>=80)
                {
                    engel_derecesi=1;
                    engel_indirimi=900;

                }
                else if(engellilik_orani>=60 && engellilik_orani<80)
                {
                    engel_derecesi=2;
                    engel_indirimi=470;
                }
                else if(engellilik_orani>=40 && engellilik_orani<60)
                {
                    engel_derecesi=3;
                    engel_indirimi=210;
                }
                else
                {
                    engel_derecesi=0;
                    engel_indirimi=0;
                }
                if(engellilik_orani>=1 && engellilik_orani<=100)
                    break;
            }
            while(engellilik_orani<0 || engellilik_orani>100);

        }
        else
        {
            engel_derecesi=0;
            engel_indirimi=0;
        }

        if(aylik_brutucret<2000)
        {
            aylik_vergi=((aylik_brutucret*15)/100)-engel_indirimi;
            aylikvergi[0]++;
        }
        else if(aylik_brutucret>=2000 && aylik_brutucret<5000)
        {
            aylik_vergi=((aylik_brutucret*20)/100)-engel_indirimi;
            aylikvergi[1]++;
        }
        else if(aylik_brutucret>=5000 && aylik_brutucret<10000)
        {
            aylik_vergi=((aylik_brutucret*27)/100)-engel_indirimi;
            aylikvergi[2]++;
        }
        else if(aylik_brutucret>=10000)
        {
            aylik_vergi=((aylik_brutucret*35)/100)-engel_indirimi;
            aylikvergi[3]++;
        }

        printf("\n----------------------------------------------------------------------------------------\n");
        printf("\nTC Kimlik numaraniz :%s\nAdiniz ve Soyadiniz : %s %s",tc,ad,soyad);
        printf("\nAylik brut ucretiniz : %.2f",aylik_brutucret);
        printf("\nEs icin aile yardim odenegi(TL): %d",es_para);
        printf("\nAylik toplam brut ucret(TL): %.2f",aylik_brutucret+es_para+cocuk_para);
        printf("\nGelir vergi kesintisi(TL): %.2f",aylik_vergi);
        printf("\nEngelli vergi indiriminden yararlaniyorsa, engel derecesi(1./2./3.) %d",engel_derecesi);
        net_ucret=aylik_brutucret+es_para+cocuk_para-aylik_vergi;
        printf("\nAylik net ucret %.2f\n",net_ucret);

    if(net_ucret/200>=1)
    {
        ikiyuz=net_ucret/200;
        printf("%d adet 200TL vardir.",ikiyuz);
        kalan=net_ucret-ikiyuz*200;
        para_sayisi[0]=para_sayisi[0]+ikiyuz;
    }
    if(kalan/100>=1)
    {
        yuz=kalan/100;
        printf("%d adet 100TL vardir.",yuz);
        kalan=kalan-yuz*100;
        para_sayisi[1]+=yuz;
    }
    if(kalan/50>=1)
    {
        elli=kalan/50;
        printf("%d adet 50TL vardir.",elli);
        kalan=kalan-elli*50;
        para_sayisi[2]+=elli;
    }
    if(kalan/20>=1)
    {
        yirmi=kalan/20;
        printf("%d adet 20TL vardir.",yirmi);
        kalan=kalan-yirmi*20;
        para_sayisi[3]+=yirmi;
    }
    if(kalan/10>=1)
    {
        on=kalan/10;
        printf("%d adet 10TL vardir.",on);
        kalan=kalan-on*10;
        para_sayisi[4]+=on;
    }
    if(kalan/5>=1)
    {
        bes=kalan/5;
        printf("%d adet 5TL vardir.",bes);
        kalan=kalan-bes*5;
        para_sayisi[5]+=bes;
    }
    if(kalan/1>=1)
    {
        bir=kalan/1;
        printf("%d adet 1TL vardir.",bir);
        kalan=kalan-bir*1;
        para_sayisi[6]+=bir;
    }
    if(kalan/(0.50)>=1)
    {
        ellikurus=kalan/(0.50);
        printf("%d adet 50Kurus vardir.",ellikurus);
        kalan=kalan-ellikurus*(0.50);
        para_sayisi[7]+=ellikurus;
    }
    if(kalan/(0.25)>=1)
    {
        yirmibeskurus=kalan/(0.25);
        printf("%d adet 25Kurus vardir.",yirmibeskurus);
        kalan=kalan-yirmibeskurus*(0.25);
        para_sayisi[8]+=yirmibeskurus;
    }
    if(kalan/(0.10)>=1)
    {
        onkurus=kalan/(0.10);
        printf("%d adet 10Kurus vardir.",onkurus);
        kalan=kalan-onkurus*(0.10);
        para_sayisi[9]+=onkurus;
    }
    if(kalan/(0.05)>=1)
    {
        beskurus=kalan/(0.05);
        printf("%d adet 5Kurus vardir.",beskurus);
        kalan=kalan-beskurus*(0.05);
        para_sayisi[10]+=beskurus;
    }
    if(kalan/(0.01)>=1)
    {
        birkurus=kalan/(0.01);
        printf("%d adet 1Kurus vardir.",birkurus);
        kalan=kalan-birkurus*(0.01);
        para_sayisi[11]+=birkurus;
    }

        kisi_sayisi++;
        toplam_netucret=toplam_netucret+net_ucret;
        toplam_vergi=toplam_vergi+aylik_vergi;
        toplam_brut=toplam_brut+aylik_brutucret;
        if(aylik_brutucret>enyuksek_brut)
                {
                    enyuksek_brut=aylik_brutucret;
                    strcpy(enbuyuk_tc,tc);
                    strcpy(enbuyuk_isim,ad);
                    strcpy(enbuyuk_soyisim,soyad);
                    enyuksek_toplambrut=toplam_brut;
                    enyuksek_aylikvergi=aylik_vergi;
                    enyuksek_ayliknetucret=net_ucret;

                }
        if(net_ucret>enyuksek_net)
        {
                    enyuksek_net=net_ucret;
                    strcpy(enbuyuk_tc,tc);
                    strcpy(enbuyuk_isim,ad);
                    strcpy(enbuyuk_soyisim,soyad);
                    enyuksek_toplambrut=toplam_brut;
                    enyuksek_aylikvergi=aylik_vergi;
                    enyuksek_ayliknetucret=net_ucret;
        }
        if(net_ucret<2000)
        {
            net_ucret_sayisi++;
        }
        do
        {
            printf("\n\nBaska calisan varmi(e/E/H/h)?");
            scanf("%s",&i);
            if(i=='e'||i=='E'||i=='H'||i=='h')
                break;
        }
        while(i!='e'||i!='E'||i!='H'||i!='h');
    }

    while(i=='e'||i=='E');

    printf("\nAylik toplam net ucret : %.2f",toplam_netucret);
    printf("\nAylik toplam gelir vergisi : %.2f",toplam_vergi);
    printf("\nAylik toplam brut ucret ortalamasi : %.2f\nAylik toplam net ucret ortalamasi : %.2f",toplam_brut/kisi_sayisi,toplam_netucret/kisi_sayisi);
    printf("\nKagit banknot paralar :");
    printf("\n200'luk :%d\t100'luk :%d\t 50'lik :%d\t 20'lik :%d\t 10'luk :%d\t 5'lik :%d",para_sayisi[0],para_sayisi[1],para_sayisi[2],para_sayisi[3],para_sayisi[4],para_sayisi[5]);
    printf("\nMADENI PARALAR :");
    printf("\n1'lik :%d\t0.50'lik :%d\t0.25'lik :%d\t0.10'lik :%d\t0.05'lik :%d\t0.01'lik :%d",para_sayisi[6],para_sayisi[7],para_sayisi[8],para_sayisi[9],para_sayisi[10],para_sayisi[11]);
    printf("\n2000TL nin altinda aylik net ucret alan calisan sayisi %d",net_ucret_sayisi);
    printf("\nEN YUKSEK BRUT SAHIBI \nSahibi : %s %s %s\nAylik toplam brut ucreti : %.2f\nGelir vergi kesintisi : %.2f\nAylik net ucret : %.2f",enbuyuk_tc,enbuyuk_isim,enbuyuk_soyisim,enyuksek_toplambrut,enyuksek_aylikvergi,enyuksek_ayliknetucret);
    printf("\nEN YUSKSEK NET UCRET SAHIBI \nSahibi : %s %s %s\nAylik toplam brut ucreti : %.2f\nGelir vergi kesintisi : %.2f\nAylik net ucret : %.2f",enbuyuk_tc,enbuyuk_isim,enbuyuk_soyisim,enyuksek_toplambrut,enyuksek_aylikvergi,enyuksek_ayliknetucret);
    printf("\n100'de 15 lik vergi icin calisan sayisi :%d",aylikvergi[0]);
    printf("\n100'de 20 lik vergi icin calisan sayisi :%d",aylikvergi[1]);
    printf("\n100'de 27 lik vergi icin calisan sayisi :%d",aylikvergi[2]);
    printf("\n100'de 35 lik vergi icin calisan sayisi :%d",aylikvergi[3]);
    printf("\nTum calisanlar icinde evli olanlarin yuzdeleri : %d",(evli_sayisi*100)/kisi_sayisi);
    printf("\nTum calisanlar icinde bekar olanlarin yuzdeleri : %d",((bekar_sayisi*100)/kisi_sayisi));
    printf("\nEvli olan calisanlarin icinde,esleri de calisan yuzdesi : %d",((es_calisan_sayisi*100)/evli_sayisi));
    printf("\nCocuk sayisi ortalamasi : %d",(cocuk_sayisi_ort/cocugu_olan_sayisi));
    printf("\nCocuk sayisi 3 den fazla olan kisi sayisi %d",cocuk_sayisi3);
    printf("\nEngelli calisan sayisi : %d\nEngelli calisanlarin tum calisanlar icide yuzdesi : %d",engelli_sayisi,((engelli_sayisi*100)/kisi_sayisi));

    return 0;
}
