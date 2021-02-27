#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char costumerEE[10][10];
char costumerCC[10][10];
char costumerAA[10][10];
char daylyRapor[100][12];
int sonA=0,sonC=0,sonE=0,raporson=0,maxhizmet=0;
void enqueue(char gelen[10],char grup);
void dequeue(char grup);
void raporla(char grup,char gelen[10]);
void yazdir();
void tekekle();
void kontrol();
char *peek();
void serveCostumer(int adet,char grup);
int main()
{


    int i;
    FILE *input;
    char komut[15],grup,isim[10];
    input=fopen("input.txt","r");
    while(fscanf(input,"%s %c %s\n",&komut,&grup,&isim) !=EOF)
    {
        if(strcmp("NewCustomer",komut) == 0)
        {
            enqueue(isim,grup);
        }
        else if(strcmp("ServeCustomers",komut) == 0)
        {
            int x=atoi(isim);

            if(maxhizmet+x<101)
            {
                maxhizmet+=x;
                serveCostumer(x,grup);
            }
            else
            {

            }


        }
    }
    fclose(input);
    yazdir();
    return 0;
}
void enqueue(char gelen[10],char grup)
{
    if(grup=='E')
    {
        if(sonE<10)
        {
            int i;
            for(i=0; i<strlen(gelen); i++)
            {
                costumerEE[sonE][i]=gelen[i];


            }
            sonE++;
        }
        else
        {
        }
    }
    else if(grup=='C')
    {
        if(sonC<10)
        {
            int i;
            for(i=0; i<strlen(gelen); i++)
            {
                costumerCC[sonC][i]=gelen[i];


            }
            sonC++;
        }
        else
        {
        }
    }
    else if(grup=='A')
    {
        if(sonA<10)
        {
            int i;
            for(i=0; i<strlen(gelen); i++)
            {
                costumerAA[sonA][i]=gelen[i];


            }
            sonA++;
        }
        else
        {
        }
    }


}
void dequeue(char grup)
{
    int i,m;
    if(grup=='E')
    {

        for(i=0; i<10; i++)
        {
            for(m=0; m<10; m++)
            {
                costumerEE[i][m]=costumerEE[i+1][m];
            }
        }
        sonE--;
    }
    else if(grup=='C')
    {
        for(i=0; i<10; i++)
        {
            for(m=0; m<10; m++)
            {
                costumerCC[i][m]=costumerCC[i+1][m];
            }
        }
        sonC--;
    }
    else if(grup=='A')
    {
        for(i=0; i<10; i++)
        {
            for(m=0; m<10; m++)
            {
                costumerAA[i][m]=costumerAA[i+1][m];
            }
        }
        sonA--;
    }
}
char *peek()
{
    return costumerEE[0];
}
void serveCostumer(int adet,char grup)
{
    int i;
    if(grup=='E')
    {
        for(i=0; i<adet; i++)
        {
            if(costumerEE[0][0]!='\0')
            {
                raporla('E',costumerEE[0]);
                dequeue(grup);
            }
            else
            {
                raporla('E',"*****");
            }

        }
    }
    if(grup=='C')
    {
        for(i=0; i<adet; i++)
        {
            if(costumerCC[0][0]!='\0')
            {
                raporla('C',costumerCC[0]);

                dequeue(grup);
            }
            else
            {
                raporla('C',"*****");

            }

        }
    }
    if(grup=='A')
    {
        for(i=0; i<adet; i++)
        {
            if(costumerAA[0][0]!='\0')
            {
                raporla('A',costumerAA[0]);

                dequeue(grup);
            }
            else
            {
                raporla('A',"*****");

            }

        }
    }

}
void raporla(char grup,char gelen[10])
{
    daylyRapor[raporson][0]=grup;
    daylyRapor[raporson][1]=' ';
    int i;
    for(i=2; i<12; i++)
    {
        daylyRapor[raporson][i]=gelen[i-2];
    }
    raporson++;
}
void yazdir()
{
    FILE *dosya;
    dosya=fopen("output.txt","w+");
    int i;
    for(i=raporson; i>=0; i--)
    {
        fprintf(dosya,"%s \n",daylyRapor[i]);
    }
}
void kontrol()
{
    int i,k;
    printf("E grubu olanlar \n");
    for(i=0; i<10; i++)
    {
        for(k=0; k<10; k++)
        {
            printf("%c",costumerEE[i][k]);

        }
        printf("\n");
    }
    printf("C grubu olanlar \n");

    for(i=0; i<10; i++)
    {
        for(k=0; k<10; k++)
        {
            printf("%c",costumerCC[i][k]);

        }
        printf("\n");
    }
    printf("A grubu olanlar \n");

    for(i=0; i<10; i++)
    {
        for(k=0; k<10; k++)
        {
            printf("%c",costumerAA[i][k]);

        }
        printf("\n");
    }
    printf("ilk elemen %s \n",peek());
}
