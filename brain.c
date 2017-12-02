#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "boolean.h"
#include "listsingle.h"
#include "game.h"

int main (){
  List L;
	int pilih,i,scene=1,jawaban,benar=0;
	char name[10];
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

	if (pilih==1){//Jika pemain memilih untuk Bermain
		puts("Please Enter Name: ");
		scanf("%s", &name);
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
	printf("Score yang anda dapatkan adalah %d\n",scene-1);
	tulisscore(name,(scene-1));
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
		highscore();
	}

	/*Ditampilkan Score yang didapat oleh pengguna*/





}
