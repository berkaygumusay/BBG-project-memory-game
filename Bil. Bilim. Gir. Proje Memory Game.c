#include <stdio.h>
#include <stdlib.h>
#include <time.h> 


int main()
{
// DEGISKEN TANIMLAMA BASLANGICI
	int zorluk,kenar,dongu=0,i,j,k,t,p,bitis=0,koord;
	int find,a,b,c,d,e,f,dongu2=0,sayac=0,sec,secim;
  srand(time(NULL));
// DEGISKEN TANIMLAMA BITISI
// MENU BASLANGICI

printf("* OYUNA HOS GELDINIZ *");
printf("\n\n");

while (dongu2 == 0){

printf("| Oyuna Basla = 1 |\n\n");
printf("| Nasil Oynanir = 2 |\n\n");
printf("| Cikis = 3 |\n\n");

printf("\n\n");
printf("Secim Yapiniz : ");
scanf("%d",&sec);


// SEVIYE SECME ASAMASI
if(sec == 1){
	system("cls");
		while(dongu==0){
		printf("\n\n");
		printf("| Kolay = 1 | Orta = 2 | Zor = 3 |\n\n");
	  	printf("Seviye Seciniz: ");
		scanf("%d",&zorluk);
	  	printf("\n");
	    
		  switch (zorluk){
	      	case 1 :{
		    	printf("Kolay Seviyeyi Sectiniz\n\n");
		    	kenar=4;
		    	koord=4;  //HATIRLAMA 2 KART YANI 4 KOORDINAT
			    dongu++;
		    }break;
		  	case 2 :{
			    printf("Orta Seviyeyi Sectiniz\n\n");
			    kenar=6;
			    koord=12; //HATIRLAMA 6 KART YANI 12 KOORDINAT
			    dongu++;
		    } break;
		    case 3 :{
			    printf("Zor Seviyeyi Sectiniz\n\n");
			    kenar=8;
			    koord=32; //HATIRLAMA 16 KART YANI 32 KOORDINAT
			    dongu++;
		    } break;
		    default:{
			    printf("Gecersiz Secim Yaptiniz Tekrar Secim Yapiniz\n\n");
		    } break;
	    }
	    dongu2=1;
	    printf("\n\n*Devam Etmesi Icin Enteri Tuslayiniz*");
		getch();
		system("cls"); 
	}
}
else if(sec == 2){
	system("cls");
	printf("|  Bu oyun temel olarak kart acma mantigina dayanir  | \n");
	printf("|  Once oyuncu kart acarak baslar | \n| Eger dogru kart ikilisini acarsa sira oyuncudan devam eder  |\n");
	printf("|  Eger oyuncu dogru kart ikilsini acamazsa sira bilgisayara gecer  |\n");
	printf("|  Bilgisayarin Kolay seviyede 2 Orta seviyede 6 Zor seviyede ise 16 kartlik hafizasi vardýr  |\n");
	printf("|  Ve bu hafizayi kullanmaktan cekinmez :)  | \n");
	printf("|  E haydi baslayalim o zaman :) |\n\n");
	printf("*Devam Etmesi Icin Enteri Tuslayiniz*");
	getch();
	system("cls"); 	
}
else if(sec==3){
	dongu2=1;
	bitis=1;
	printf("\n\nOyundan Cikiliyor ...");
}
}
// MENU BITISI
while(bitis != 1){
int hatirlama[100]; //MEMORY DIZISI OLUSTUMA
for(i=0;i<100;i++){ 
  hatirlama[i]=0;  // MEMORYNIN HEPSINI 0 A ESITLEME
}
// SEVIYE SECME BITISI

// DESTEYI TANIMLAMA BASLANGICI 
int acikdeste[kenar][kenar];
int gizlideste[kenar][kenar];
// DESTEYI TANIMLAMA BITISI

// ACIK DESTENÝN TUM ELEMANLARINI 0 YAPMA
	for(i=0;i<(kenar);i++){
		for(j=0;j<(kenar);j++){
			acikdeste[i][j]=0;
		}
	}
	
// GIZLI DESTENIN TUM ELEMANLARINI '*' YAPMA
for(i=0;i<(kenar);i++){
		for(j=0;j<(kenar);j++){
		  gizlideste[i][j]='*';
		}
	}

// ELEMANLARI MATRISE ATAMA
int max,x,y,deger=1;
max=(kenar*kenar)/2;

	for(i=1;i<=max;i++){
		for(j=1;j<=2;j++){
				x= rand() % kenar;
				y= rand() % kenar;
				while(acikdeste[x][y] != 0){
					x= rand() % kenar;
					y= rand() % kenar;
			}	
			acikdeste[x][y] = i;		
		}
	}

//ACIK DESTE7
	
	printf("\n** Mevcut Kart Destesi **\n\n");
	for(i=0;i<(kenar);i++){
		for(j=0;j<(kenar);j++){
			printf(" %2d ",acikdeste[i][j]);
		}
	printf("\n\n");
	}

  printf("\n\n");
  	printf("*Desteyi Kontrol Etmek Icin 3 Saniyeniz Var*");
	sleep(3);
	system("cls"); 

// OYUN BASLANGICI
// GEREKLI DEGISKENLER
int puan1=0,puan2=0,sira=1,h=0;
int ox1,oy1,ox2,oy2;
int cx1,cy1,cx2,cy2;
int t1,t2,t3,t4;
int os=0,cs=0;

//OYUNUN ANA DONGUSU
while((puan1<=(max/2) && puan2<=(max/2)) && sira!=0){
	if(puan1== max/2 && puan2==max/2){
		sira==0;
	}
  if(sira%2 != 0){   //OYUNCUNUN OYNAMASI BASLANGICI
    printf("* Destenin Guncel Hali *\n\n");
	for(i=0;i<(kenar);i++){
      for(j=0;j<(kenar);j++){           
        printf(" %c ",gizlideste[i][j]);
      }
    printf("\n\n");
    }
	printf("Oyuncunun Puani : %d \n\n",puan1);
    printf("Bilgisayarin Puani : %d \n\n",puan2);
    printf("SIRA OYUNCUDA \n\n");
    printf("*Devam Etmesi Icin Enteri Tuslayiniz*");
	getch();
	system("cls");
    printf("1. Tahmininizin Satir Ve Sutununu Giriniz: ");
    scanf("%d %d",&ox1,&oy1);
    printf("\n");
    printf("2. Tahmininizin Satir Ve Sutununu Giriniz: ");
    scanf("%d %d",&ox2,&oy2);
    ox1=ox1-1;
    oy1=oy1-1;
    ox2=ox2-1;
    oy2=oy2-1;
    while((gizlideste[ox1][oy1] == '-' || gizlideste[ox2][oy2] == '-') || ((ox1 == ox2) && (oy1 == oy2))){
    	system("cls");
    	printf("\n||  Yanlis Degerler Girdiniz  ||\n");
    	printf("\n||  Lutfen Yeni Degerler Giriniz  ||\n\n");
    	printf("1. Tahmininizin Satir Ve Sutununu Giriniz: ");
	    scanf("%d %d",&ox1,&oy1);
	    printf("\n");
	    printf("2. Tahmininizin Satir Ve Sutununu Giriniz: ");
	    scanf("%d %d",&ox2,&oy2);
	    ox1=ox1-1;
	    oy1=oy1-1;
	    ox2=ox2-1;
	    oy2=oy2-1;
	}
    os++;
     
    printf("\n\n");
      for(i=0;i<(kenar);i++){  //DESTEYI YAZDIRMA
        for(j=0;j<(kenar);j++){
          if( (i==ox1 && j==oy1) ){
            printf(" %d ",acikdeste[i][j]); // 1. SE?LEN KARTI YAZDIRMA
          }
          else if(i==ox2 && j==oy2){
            printf(" %d ",acikdeste[i][j]); // 2. SE?LEN KARTI YAZDIRMA
          }
          else{
            printf(" %c ",gizlideste[i][j]); // KALAN KISIMLARA '*' YAZDIRMA
          }
        }
      printf("\n\n");
      }
    printf("\n\n");
    if(acikdeste[ox1][oy1]==acikdeste[ox2][oy2]){ 
      gizlideste[ox1][oy1]='-';             // DOGRU SECILIRSE '*' ISARETINI '-' ILE DEGISTIRME
      gizlideste[ox2][oy2]='-';
      puan1++; 
	     
    }
    else{   // YANLIS SECIMDE DESTEDE DEGISIKLIK YAPMADAN SIRANIN BILGISAYARA GECMESI VE SAYILARI HAFIZAYA ALMA
      hatirlama[h]=ox1;
      h++;
      hatirlama[h]=oy1;
      h++;
      hatirlama[h]=ox2;
      h++;
      hatirlama[h]=oy2;
      h++;
      sira++;
    
    }

    printf("\n\n");
    
    printf("*Devam Etmesi Icin Enteri Tuslayiniz*");
  	getch();
  	system("cls");
  	
  } // OYUNCUNUN OYNAMASI BITISI

  else{ //BILGISAYRIN OYNAMASI BASLANGIC
  printf("* Destenin Guncel Hali *\n\n");
    for(i=0;i<(kenar);i++){
      for(j=0;j<(kenar);j++){            // DESTEYI YENIDEN YAZDIRMA
        printf(" %c ",gizlideste[i][j]);
      }
    printf("\n\n");
    }
  
  printf("*Devam Etmesi Icin Enteri Tuslayiniz*");
  getch();
  system("cls"); 
  printf("\n\n");
  		cx1= rand() % kenar;
		cy1= rand() % kenar;
		while( gizlideste[cx1][cy1] == '-'){
			cx1= rand() % kenar;
			cy1= rand() % kenar;
		}
		
	  if(h>koord){
      	i=h-koord;
      } 
      else{
      	i=0;
	      }
		while(i<h){
			
          	for(j=i+2;j<h;j=j+2){
          	sayac=0;
        	a=hatirlama[i];
			b=hatirlama[i+1];
			c=hatirlama[j];
			d=hatirlama[j+1];
			
			if((acikdeste[a][b] == acikdeste[c][d])  && (gizlideste[a][b]!='-')&& ((a != c) || (b != d)) ){
				printf("Oyuncunun Puani : %d \n\n",puan1);
  				printf("Bilgisayarin Puani : %d \n\n",puan2);
  				printf("SIRA BILGISAYARDA\n\n");
				
				printf("Bilgisayar Tahmini : 1= %d,%d | 2= %d,%d \n\n",a+1,b+1,c+1,d+1);
				t1=a;   
				t2=b;
				t3=c;    // HAFIZADAN IKI KARTIN BIRIBIRININ AYNISI OLMA DURUMU
				t4=d;		
				cs++;
				puan2++;
				gizlideste[t1][t2]='-';
				gizlideste[t3][t4]='-';
				for(k=0;k<(kenar);k++){  //DESTEYI YAZDIRMA
		      	  for(t=0;t<(kenar);t++){
		       		  if( (k==t1 && t==t2) || (k==t3 && t==t4) ){
		        	    printf(" %d ",acikdeste[k][t]); // HAFIZADAN YAZILAN 1. VEYA 2. KART
				     }      
		        	  else{
		         	   printf(" %c ",gizlideste[k][t]); // KALAN KISIMLARA '*' YAZDIRMA
		         	 }
		      	  }
		     	 printf("\n\n");
		    	}
		    	  	printf("\n\n");
		    		printf("*Devam Etmesi Icin Enteri Tuslayiniz*");
					getch();
					system("cls");
		   		}	
		} 
		printf("\n");
        i=i+2;
	}
			p=0;
		   	while((p<=h)){
		   		e=hatirlama[p];
		   		f=hatirlama[p+1];
		   		if((acikdeste[cx1][cy1] == acikdeste[e][f]) && (gizlideste[a][b]!='-')&& ((cx1 != e) || (cy1 != f)) ){
		   			p= 60;
		   			printf("Oyuncunun Puani : %d \n\n",puan1);
  					printf("Bilgisayarin Puani : %d \n\n",puan2);
  					printf("SIRA BILGISAYARDA\n\n");
				 
		   			printf("Bilgisayar Tahmini : 1= %d,%d | 2= %d,%d \n\n",cx1+1,cy1+1,e+1,f+1);
		   			for(k=0;k<(kenar);k++){  //DESTEYI YAZDIRMA
					   	for(t=0;t<(kenar);t++){
					        if( (k==cx1 && t==cy1) || (k==e && t==f) ){
					        printf(" %d ",acikdeste[k][t]); // HAFIZADAN YAZILAN 1. KART
					        }
					        else{
					    	printf(" %c ",gizlideste[k][t]); // KALAN KISIMLARA GIZLI DESTEYI YAZDIRMA
					    	}
					    }
					    printf("\n\n");
			    	}
						puan2++;
						gizlideste[cx1][cy1]='-';
						gizlideste[e][f]='-';
					printf("\n\n");
					printf("*Devam Etmesi Icin Enteri Tuslayiniz*");
					getch();
					system("cls"); 
					   			
				   }
				   p=p+2;
			   }
		
		while(gizlideste[cx1][cy1] == '-'){
			cx1= rand() % kenar;
	  		cy1= rand() % kenar;
		}	
			cx2= rand() % kenar;
			cy2= rand() % kenar;
		while(((cx2 == cx1 && cy2 == cy1) || (cx2 == a && cy2 == b ) || (cx2 == c && cy2 == d)) && gizlideste[cx2][cy2] == '-'){
			cx2= rand() % kenar;
			cy2= rand() % kenar;	
		}
		
			printf("Oyuncunun Puani : %d \n\n",puan1);
  			printf("Bilgisayarin Puani : %d \n\n",puan2);
  			printf("SIRA BILGISAYARDA\n\n"); 
			printf("Bilgisayar Tahmini : 1= %d,%d | 2= %d,%d \n\n",cx1+1,cy1+1,cx2+1,cy2+1);
			cs++;
			for(k=0;k<(kenar);k++){  //DESTEYI YAZDIRMA
			    for(t=0;t<(kenar);t++){
			        if( (k==cx1 && t==cy1) || (k==cx2 && t==cy2) ){
			        printf(" %d ",acikdeste[k][t]); // HAFIZADAN YAZILAN 1. KART
			        }
			        else{
			    	printf(" %c ",gizlideste[k][t]); // KALAN KISIMLARA '*' YAZDIRMA
			    	}
			    }
			    printf("\n\n");
			    }
			if( acikdeste[cx1][cy1] == acikdeste[cx2][cy2] ){
			   	puan2++;
				gizlideste[cx1][cy1]='-';
				gizlideste[cx2][cy2]='-';
				}
			else{
				sira++;
				}
		printf("\n\n");		
        printf("*Devam Etmesi Icin Enteri Tuslayiniz*");
		getch();
		system("cls"); 
  }
  
}

// OYUN KISMININ BITISI

// SONUCUN YAZDIRILMASI
if(puan1>(max/2)){ 
  printf("||  OYUNCU KAZANDI  ||");
  printf("\n\n");
  printf("||  OYUNCU %d DENEMEDE KAZANDI  ||",os);
  printf("\n\n");
  printf("||  OYUNCUNUN PUANI : %d  ||\n\n\n",puan1);
  printf("||  3 Saniye Sonra Menuye Gecilecek...  ||");
  sleep(3);
  system("cls");
}
else if(puan2>(max/2)){
  printf("||  BILGISAYAR KAZANDI  ||");
  printf("\n\n");
  printf("||  BILGISAYAR %d DENEMEDE KAZANDI  ||",cs);
  printf("\n\n");
  printf("||  BILGISAYARIN PUANI : %d  ||\n\n\n",puan2);
  printf("||  3 Saniye Sonra Menuye Gecilecek...  ||");
  sleep(3);
  system("cls");
}
  printf("\n\n");
  printf("|| Tekrar Oynama = 1  ||");
  printf("\n\n");
  printf("||  Cikis = 2  ||");
  printf("\n\n");
  printf("||  SECIM YAPINIZ :");
  scanf("%d",&secim);
  if(secim == 2){
	bitis=1;
	system("cls");
	printf("||  Cikis Yapiliyor ...  ||");
  }
  else if(secim==1){
  	printf("||  Tekrar Oynamak Icin Enteri Tuslayiniz  ||\n\n");
	getch();
	printf("||  Oyun 3 Saniye Sonra Tekrardan Baslayacak...  ||");
	sleep(3);
	system("cls"); 
  }
  
// SONUCUN YAZDIRILMASI BITISI
}

//ODEV BITIS

    return 0;
}
