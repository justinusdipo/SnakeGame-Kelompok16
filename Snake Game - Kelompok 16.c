/*snake game 
dibuat oleh kelompok 16:
Muhammad Paquito Hanafi (1606834794)
Justinus Dipo Nugroho (1706026600)
*/


#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>

// Merepresentasikan nilai ASCII dari keyboard "arah"
#define ATAS 72
#define BAWAH 80
#define KIRI 75
#define KANAN 77

// Mendeklarasikan tipe data yang dibutuhkan
int panjang;
int belokan_jml;
int pan;
char kunci;
void rekamjejak();
void load();
int nyawa;
void Jeda(long double);
void Gerak();
void Makanan();
int Skor();
void Print();
void gotoxy(int x, int y);
void GotoXY(int x,int y);
void Belokan();
void Boarder();
void Bawah();
void Kiri();
void Atas();
void Kanan();
void KeluarPermainan();
int Hanyaskor();

struct koordinat{
    int x;
    int y;
    int arah;
};
// Membuat nama alias/inisial dari suatu tipe data
typedef struct koordinat koordinat;

//Tipe data struct menjadi nama alias
koordinat kepala, belokan[500],makanan,tubuh[30];

int main()
{

    char kunci;

    Print();

    system("cls");

    load();

    panjang=5; // Panjang awal ular sebesar 5 karakter (4 bintang dan 1 panah).

    kepala.x=25; // Posisi awal berada di x = 25

    kepala.y=20; // Posisi awal berada di y = 20

    kepala.arah=KANAN; // Arah gerak awal saat permainan dimulai ke arah kanan.

    Boarder(); // Fungsi dari setiap arahan yang diinput

    Makanan(); 

    nyawa=3; 

    belokan[0]=kepala;

    Gerak();   

    return 0;

}

void Gerak()
{
    int a,i;

    do{

        Makanan();
        fflush(stdin); // Mereset/ merefresh tampilkan setiap saat

        pan=0;

        for(i=0;i<30;i++)

        {
            tubuh[i].x=0;

            tubuh[i].y=0;

            if(i==panjang)
            
            break;

        }

        Jeda(panjang);

        Boarder();

        if(kepala.arah==KANAN)

            Kanan();

        else if(kepala.arah==KIRI)

            Kiri();

        else if(kepala.arah==BAWAH)

            Bawah();

        else if(kepala.arah==ATAS)

            Atas();

        KeluarPermainan();

    }while(!kbhit());

    a=getch();

    if(a==27)

    {

        system("cls");

        exit(0);

    }
    kunci=getch();

    if((kunci==KANAN&&kepala.arah!=KIRI&&kepala.arah!=KANAN)||(kunci==KIRI&&kepala.arah!=KANAN&&kepala.arah!=KIRI)||(kunci==ATAS&&kepala.arah!=BAWAH&&kepala.arah!=ATAS)||(kunci==BAWAH&&kepala.arah!=ATAS&&kepala.arah!=BAWAH))

    {

        belokan_jml++;

        belokan[belokan_jml]=kepala;

        kepala.arah=kunci;

        if(kunci==ATAS)

            kepala.y--;

        if(kunci==BAWAH)

            kepala.y++;

        if(kunci==KANAN)

            kepala.x++;

        if(kunci==KIRI)

            kepala.x--;

        Gerak();

    }

    else if(kunci==27)

    {

        system("cls");

        exit(0);

    }

    else

    {

        printf("\a");

        Gerak();

    }
}

void gotoxy(int x, int y)
{

 COORD coord;

 coord.X = x;

 coord.Y = y;

 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}
void GotoXY(int x, int y)
{
    HANDLE a;
    COORD b;
    fflush(stdout);
    b.X = x;
    b.Y = y;
    a = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(a,b);
 }
void load(){
    int row,col,r,c,q;
    gotoxy(36,14);
    printf("loading...");
    gotoxy(30,15);
    for(r=1;r<=20;r++){
    for(q=0;q<=100000000;q++);
    printf("%c",177);}
    getch();
}
void Bawah()
{
    int i;
    for(i=0;i<=(kepala.y-belokan[belokan_jml].y)&&pan<panjang;i++)
    {
        GotoXY(kepala.x,kepala.y-i);
        {
            if(pan==0)
                printf("v");
            else
                printf("*");
        }
        tubuh[pan].x=kepala.x;
        tubuh[pan].y=kepala.y-i;
        pan++;
    }
    Belokan();
    if(!kbhit())
        kepala.y++;
}
void Jeda(long double k)
{
    Skor();
    long double i;
    for(i=0;i<=(10000000);i++);
}
void KeluarPermainan()
{
    int i,check=0;
    for(i=4;i<panjang;i++)   //Mulai dari 4 karena elemen minimum yang dibutuhkan 4 titik untuk menabrak dirinya sendiri
    {
        if(tubuh[0].x==tubuh[i].x&&tubuh[0].y==tubuh[i].y)
        {
            check++;    //mengecek nilai penambahan
        }
        if(i==panjang||check!=0)
            break;
    }
    if(kepala.x<=10||kepala.x>=70||kepala.y<=10||kepala.y>=30||check!=0)
    {
        nyawa--;
        if(nyawa>=0)
        {
            kepala.x=25;
            kepala.y=20;
            belokan_jml=0;
            kepala.arah=KANAN;
            Gerak();
        }
        else
        {
            system("cls");
            printf("-- GAME OVER --\n\nSemoga lain kali lebih beruntung!!!\nTekan tombol apapun pada keyboad untuk kerluar dari permainan");
            rekamjejak();
            exit(0);
        }
    }
}
void Makanan()
{
    if(kepala.x==makanan.x&&kepala.y==makanan.y)
    {
        panjang++;
        time_t a;
        a=time(0);
        srand(a);
        makanan.x=rand()%70;
        if(makanan.x<=10)
            makanan.x+=11;
        makanan.y=rand()%30;
        if(makanan.y<=10)

            makanan.y+=11;
    }
    else if(makanan.x==0)
    {
        makanan.x=rand()%70;
        if(makanan.x<=10)
            makanan.x+=11;
        makanan.y=rand()%30;
        if(makanan.y<=10)
            makanan.y+=11;
    }
}
void Kiri()
{
    int i;
    for(i=0;i<=(belokan[belokan_jml].x-kepala.x)&&pan<panjang;i++)
    {
        GotoXY((kepala.x+i),kepala.y);
       {
                if(pan==0)
                    printf("<");
                else
                    printf("*");
        }
        tubuh[pan].x=kepala.x+i;
        tubuh[pan].y=kepala.y;
        pan++;
    }
    Belokan();
    if(!kbhit())
        kepala.x--;

}
void Kanan()
{
    int i;
    for(i=0;i<=(kepala.x-belokan[belokan_jml].x)&&pan<panjang;i++)
    {
        //GotoXY((kepala.x-i),kepala.y);
        tubuh[pan].x=kepala.x-i;
        tubuh[pan].y=kepala.y;
        GotoXY(tubuh[pan].x,tubuh[pan].y);
        {
            if(pan==0)
                printf(">");
            else
                printf("*");
        }
        /*tubuh[pan].x=kepala.x-i;
        tubuh[pan].y=kepala.y;*/
        pan++;
    }
    Belokan();
    if(!kbhit())
        kepala.x++;
}
void Belokan()
{
    int i,j,diff;
    for(i=belokan_jml;i>=0&&pan<panjang;i--)
    {
            if(belokan[i].x==belokan[i-1].x)
            {
                diff=belokan[i].y-belokan[i-1].y;
                if(diff<0)
                    for(j=1;j<=(-diff);j++)
                    {
                        tubuh[pan].x=belokan[i].x;
                        tubuh[pan].y=belokan[i].y+j;
                        GotoXY(tubuh[pan].x,tubuh[pan].y);
                        printf("*");
                        pan++;
                        if(pan==panjang)
                            break;
                    }
                else if(diff>0)
                    for(j=1;j<=diff;j++)
                    {
                        /*GotoXY(belokan[i].x,(belokan[i].y-j));
                        printf("*");*/
                        tubuh[pan].x=belokan[i].x;
                        tubuh[pan].y=belokan[i].y-j;
                        GotoXY(tubuh[pan].x,tubuh[pan].y);
                        printf("*");
                        pan++;
                        if(pan==panjang)
                            break;
                    }
            }
        else if(belokan[i].y==belokan[i-1].y)
        {
            diff=belokan[i].x-belokan[i-1].x;
            if(diff<0)
                for(j=1;j<=(-diff)&&pan<panjang;j++)
                {
                    /*GotoXY((belokan[i].x+j),belokan[i].y);
                    printf("*");*/
                    tubuh[pan].x=belokan[i].x+j;
                    tubuh[pan].y=belokan[i].y;
                    GotoXY(tubuh[pan].x,tubuh[pan].y);
                        printf("*");
                   pan++;
                   if(pan==panjang)
                           break;
               }
           else if(diff>0)
               for(j=1;j<=diff&&pan<panjang;j++)
               {
                   /*GotoXY((belokan[i].x-j),belokan[i].y);
                   printf("*");*/
                   tubuh[pan].x=belokan[i].x-j;
                   tubuh[pan].y=belokan[i].y;
                   GotoXY(tubuh[pan].x,tubuh[pan].y);
                       printf("*");
                   pan++;
                   if(pan==panjang)
                       break;
               }
       }
   }
}
void Boarder()
{
   system("cls");
   int i;
   GotoXY(makanan.x,makanan.y);   /*Menampilkan makanan*/
       printf("F");
   for(i=10;i<71;i++)
   {
       GotoXY(i,10);
           printf("!");
       GotoXY(i,30);
           printf("!");
   }
   for(i=10;i<31;i++)
   {
       GotoXY(10,i);
           printf("!");
       GotoXY(70,i);
       printf("!");
   }
}
void Print()
{
   //GotoXY(10,12);
   printf("\tSelamat Datang di Dunia Snake Game. \n (Tekan tombol apapun pada keyboard)\n");
  getch();
   system("cls");
   printf("Instruksi Permainan:\n");
   printf("\n-> Gunakan tombol arah pada keyboard untuk menggerakan ular.\n\n-> Kamu akan diberikan makanan di beberapa koordinat layar yang harus kamu makan. Setiap kali kamu makan sebuah makanan maka panjang tubuh ular akan bertambah 1 elemen dan demikian skornya.\n\n-> Di sini kamu diberikan tiga nyawa. Nyawa kamu akan berkurang saat Anda menabrak dinding atau tubuh ular.\n\n-> Kamu dapat menghentikan sementara permainan di tengahnya dengan menekan sembarang pada tombol keyboard. Untuk melanjutkan permainan yang dijeda, tekan tombol lain sekali lagi\n\n-> Jika Kamu ingin keluar, tekan 'esc' \n");
   printf("\n\nTekan tombol keyboard apapun untuk memulai permainan...");
   if(getch()==27)
   exit(0);
}
void rekamjejak(){
   char NamaPemain[20],NamaPemainBaru[20],cha,c;
   int i,j,px;
   FILE *info;
   info=fopen("rekamjejak.txt","a+");
   getch();
   system("cls");
   printf("Ketik nama kamu\n");
   scanf("%[^\n]",NamaPemain);
   //************************
   for(j=0;NamaPemain[j]!='\0';j++){ //Untuk menghasilkan huruf besar jika diisi huruf kecil, jika sebaliknya akan menghasilkan  sama dengan argumen yang diisikan
   NamaPemainBaru[0]=toupper(NamaPemain[0]);
   if(NamaPemain[j-1]==' '){
   NamaPemainBaru[j]=toupper(NamaPemain[j]);
   NamaPemainBaru[j-1]=NamaPemain[j-1];}
   else NamaPemainBaru[j]=NamaPemain[j];
   }
   NamaPemainBaru[j]='\0';
   //*****************************
   fprintf(info,"Nama Pemain :%s\n",NamaPemainBaru);

   time_t mytime;
  mytime = time(NULL);
  fprintf(info,"Waktu Bermain:%s",ctime(&mytime)); // Menampilkan waktu bermain
     //**************************
     fprintf(info,"Skor:%d\n",px=Hanyaskor());// Menampilkan skor
   for(i=0;i<=50;i++)
   fprintf(info,"%c",'_');
   fprintf(info,"\n");
   fclose(info);
   printf("ingin melihat rekam jejak masa lalu tekan 'y'\n");
   cha=getch();
   system("cls");
   if(cha=='y'){
   info=fopen("rekamjejak.txt","r");
   do{
       putchar(c=getc(info));
       }while(c!=EOF);}
     fclose(info);
}
int Skor()
{
   int skor;
   GotoXY(20,8); // untuk menempatkan pada posisi x = 20 dan y = 8.
   skor=panjang-5;
   printf("SKOR : %d",(panjang-5));
   skor=panjang-5;
   GotoXY(50,8);
   printf("Nyawa : %d",nyawa);
   return skor;
}
int Hanyaskor()
{
int skor=Skor();
system("cls");
return skor;
}
void Atas()
{
   int i;
   for(i=0;i<=(belokan[belokan_jml].y-kepala.y)&&pan<panjang;i++)
   {
       GotoXY(kepala.x,kepala.y+i);
       {
           if(pan==0)
               printf("^");
           else
               printf("*");
       }
       tubuh[pan].x=kepala.x;
       tubuh[pan].y=kepala.y+i;
       pan++;
   }
   Belokan();
   if(!kbhit())
       kepala.y--;
}
