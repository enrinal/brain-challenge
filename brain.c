/* Definisi type boolean */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


#ifndef _BOOLEAN_h
#define _BOOLEAN_h

#define boolean unsigned char
#define true 1
#define false 0

#endif

#define Nil NULL

typedef int infotype;
typedef struct tElmtlist *address;
typedef struct tElmtlist {
	infotype info;
	address next;
} ElmtList;
typedef struct {
	address First;
} List;

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=Nil */

#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) (L).First

/****************** TEST LIST KOSONG ******************/
boolean IsListEmpty(List L){
  /* Mengirim true jika list kosong */
	return (First(L) == Nil);
}
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList (List *L){
  /* I.S. sembarang             */
  /* F.S. Terbentuk list kosong */
	First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X){
  /* Mengirimkan address hasil alokasi sebuah elemen */
  /* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
  /* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
  /* Jika alokasi gagal, mengirimkan Nil */
	address P;
	P = (address) malloc (sizeof(ElmtList));
	if(P != Nil)
	{
		Info(P) = X;
		Next(P) = Nil;
		return P;
	}
	else
	{
		return Nil;
	}
}

void Dealokasi (address *P){
  /* I.S. P terdefinisi */
  /* F.S. P dikembalikan ke sistem */
  /* Melakukan dealokasi/pengembalian address P */
	free(*P);
}

void InsertFirst (List *L, address P){
  /* I.S. Sembarang, P sudah dialokasi  */
  /* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
	Next(P) = First(*L);
	First(*L) = P;
}
void InsertAfter (List *L, address P, address Prec){
  /* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
  /*      P sudah dialokasi  */
  /* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
	Next(P) = Next(Prec);
	Next(Prec) = P;
}

void InsertLast (List *L, address P){
  /* I.S. Sembarang, P sudah dialokasi  */
  /* F.S. P ditambahkan sebagai elemen terakhir yang baru */
	address Last;
	if(IsListEmpty(*L))
	{
		InsertFirst(&(*L),P);
	}
	else
	{
		Last  = First(*L);
		while(Next(Last) != Nil)
		{
			Last = Next(Last);
		}
		InsertAfter(&(*L),P,Last);
	}
}

void DelFirst (List *L, address *P){
  /* I.S. List tidak kosong */
  /* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
  /*      Elemen list berkurang satu (mungkin menjadi kosong) */
  /* First element yg baru adalah suksesor elemen pertama yang lama */
	*P = First(*L);
	First(*L) = Next(First(*L));
	Dealokasi(P);
}

void sec_wait ( int sec ) {
	clock_t wait_till_end;
	wait_till_end = clock () + sec * CLOCKS_PER_SEC ;
	while (clock() < wait_till_end) {}
}

void timer (){
	int t;
	for(t=0;t<5;t++){
		sec_wait(1);
	}
}

void Help(){
  /*Menampilkan Cara Bermain Game Brain Challange*/
  printf("Petunjuk Permainan\n");
  printf("1. Pemain diminta untuk mengingat jumlah simbol '*' yang muncul pada suatu scene\n");
  printf("2. Pada awal permainan akan diberikan 3 scene yang masing masing memuat 15 simbol\n");
  printf("3. Setiap Scene akan diberikan waktu 5 detik untuk menghitung jumlah '*' yang muncul\n" );
  printf("4. Setelah diawali dengan menampilkan 3 scene, pemain selanjutnya diberikan pertanyaan jumlah '*' yang muncul pada scene pertama\n" );
	printf("5. Jika jawaban benar, maka akan dimunculukan scene berikutnya , dan diberikan pertanyaan jumlah '*' pada scene kedua dan selanjutnya, jika salah maka permainan berakhir\n");
	printf("\n");

}

void Scene(int num, List *L){
  int i,sum=0;
  /*Berguna Untuk menampilkan scene dan memasukan jawaban ke link list*/
	/*Num berfungsi untuk menampilkan scene ke-num*/
	/*Sum berfungsi untuk menghitung banyaknya bintang dan memasukkan sum dengan
	InsertLast*/
	/*timer() memanggil fungsi timer yang digunakan untuk countdown perscene*/
  printf("Scene %d\n",num);
  for (i=0;i<15;i++){
    char simbol = "*$+/-%"[rand () % 6];//rand() Berguna untuk merandom char
    printf("%c ",simbol);
    if(simbol=='*'){
      sum++;
    }
  }
	printf("\n" );
	printf("Note : Ingatlah Jumlah '*' Pada Scene Ini\n" );
  InsertLast(L,Alokasi(sum)); //Sum di alokasi dan dimasukkan di Last
	timer();
	system("cls");
}

int main (){
  List L;
	int pilih,i,scene=1,jawaban,benar=0;
	address P;
	boolean a=true;
  CreateList(&L);

	a://Fungsi Goto
	srand(time(NULL));
	printf("-----Brain Challange------\n");
	printf("[1]Main\n" );
	printf("[2]Help\n" );
	printf("[3]Highscore\n" );
	printf("[0]Keluar\n\n" );
	printf("Pilihan : \n");
	scanf("%d",&pilih );
	system("cls");

	if (pilih==1){//Jika pemain memilih untuk berman
		for (i=1;i<=3;i++){
			/*Disini Program akan melakukan pemanggilan 3 scene pertama
			dan memasukannya ke linklist*/
			Scene(i,&L);//Program memanggul fungsi scene
		}
	while (a){
		printf("Berapa Jumlah '*' yang muncul pada scene ke-%d ?\n",scene);
		printf("Jawaban : " );
		scanf("%d",&jawaban);
		system("cls");
		if (jawaban==Info(First(L))){
			/*Jika Jawaban Benar maka variabel benar akan bertambah 1
			variabel benar digunakan untuk menampung score pemain*/
			benar++;
		}else {
			/*Apabila jawaban salah maka variable a menjadi false, break digunakan
			untuk memberhentikan loop secara langsung*/
			a=false;
			break;
		}
		Scene(i,&L); //Memanggil fungsi scene ke-4 dan seterusnya
		i++;
		scene++;
		/*Setelah Scene Ke-4 maka scene pertama dihapus, dan begitu juga untuk scene
		ke 5 dan seterusnya*/
		P=First(L);
		DelFirst(&L,&P);
		/*Alur programnya adalah InsertLast untuk scene baru, lalu DelFirst untuk
		scene sebelumnya*/
	}
	}
	else if(pilih==2){
		/*Pilihan 2 digunakan apabila user ingin melihat cara bermain program
		akan memanggil Help() untuk menampilkan petunjuk program*/
		Help();
		/*Untuk menampilkan "Press Any Key to Continue" jadi user harus mengkil apapun
		untuk kembali ke menu awal*/
		system("pause");
		system("cls"); //Akan Dilakukan clear screen
		goto a; // Kembali ke menu awal (a:)
	}else if (pilih==3){
	}else {
		//exit(0);
	}
	/*Ditampilkan Score yang didapat oleh pengguna*/
	printf("Score yang anda dapatkan adalah %d\n",scene-1);

}
