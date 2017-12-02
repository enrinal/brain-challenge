#include "game.h"
#include<string.h>

void timer ( int sec ) {
	clock_t wait_till_end;
	wait_till_end = clock () + sec * CLOCKS_PER_SEC ;
	while (clock() < wait_till_end) {}
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
	if (num>40){//Level diatas 40
		for (i=0;i<20;i++){
	    char simbol = "*$+/-%"[rand () % 6];//rand() Berguna untuk merandom char
	    printf("%c ",simbol);
	    if(simbol=='*'){
	      sum++;
	    }
	  }
	}else {
		for (i=0;i<15;i++){//Level dibawah 40
	    char simbol = "*$+/-%"[rand () % 6];//rand() Berguna untuk merandom char
	    printf("%c ",simbol);
	    if(simbol=='*'){
	      sum++;
	    }
	  }
	}
	printf("\n" );
	printf("Note : Ingatlah Jumlah '*' Pada Scene Ini\n" );
  InsertLast(L,Alokasi(sum)); //Sum di alokasi dan dimasukkan di Last
	if (num<=20){//level dibawah 20
		timer(5);
	}else{//Level diatas 20
		timer(3);
	}
	system("cls");
}

void highscore(){
		int i=0,j,k,l,m;
		char c;

		struct leaderboard{
	      char name[11];
	      int score;
	   }ps[100],temp;																// ps = player scores

	   FILE *scp;
	   scp = fopen("leaderboard.txt","r");											//TEST DATA: scp = fopen("playerScores.txt","r");
		 while (!feof(scp)){
				 fscanf(scp,"%s\n",ps[i].name);
			 	 fscanf(scp," %d",&ps[i].score);
				 i++;
		 }

	   /*for(i=0;i<10;++i)
		{
		 fscanf(scp,"%s",ps[i].name);
		 fscanf(scp," %d",&ps[i].score);
	 }*/

		//strcpy(ps[10].name,name);
		//ps[10].score=score;
		fclose(scp);
		for (k=1;k<11;k++)															// sort 10 file scores & details + current score & details
		{
	     for (j=0;j<11-k;j++)
		 {
	      if(ps[j].score < ps[j+1].score) 											// > sorts largest first
		  {
	       temp = ps[j];
	       ps[j] = ps[j + 1];
	       ps[j + 1] = temp;
	      }
	     }
		}

		for(m=0;m<10;++m)															// OUTPUT: 10 scores higheset to lowest
		{
		 printf("Player: %s \tScore: %d\n",ps[m].name,ps[m].score);
		}																			// TEST DATA: printf("\n\nGameover: %d\n\n",gameover);
}

void tulisscore(char name[] , int score){

	FILE *scp2;																	// write high score
	scp2 = fopen("leaderboard.txt","a");

	fprintf(scp2,"%s\n",name);
	fprintf(scp2,"%d\n",score);

	fclose(scp2);
}
