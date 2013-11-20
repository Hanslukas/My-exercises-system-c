#include <stdio.h>
#include <malloc.h>
#define MaxProc 20
void Inserisci(unsigned char *mappa,unsigned long mem,unsigned long Pid[][MaxProc]);
void Elimina(unsigned char *mappa,unsigned long mem,unsigned long Pid[][MaxProc]);
void visualizza(unsigned char *mappa,unsigned long mem,unsigned long Pid[][MaxProc]);
unsigned long CercaBloccoLibero(unsigned char *mappa,unsigned long mem,unsigned long Lengh);


void Inserisci(unsigned char *mappa,unsigned long mem,unsigned long Pid[][MaxProc])
{unsigned long i,j;
 unsigned long BIni,BiniT,offset;
 unsigned long Lungh;
 unsigned char a=128;
 printf("Dai la memoria occupata dal Processo:");
 scanf("%d",&Lungh);
 BIni=CercaBloccoLibero(mappa,mem,Lungh);
 if( (BIni>mem) || (BIni+Lungh>mem)){
  printf("Blocco di memoria non consentito! \n");}
 else
 {a=128;BiniT=BIni/8; offset=BIni-(BiniT*8);
  a=a>>offset;j=BiniT;
  for(i=BIni;i<BIni+Lungh;i++) 
   {if( (i>BIni)&&(i%8)==0) {j++; a=128;}
	 mappa[j]=mappa[j]|a; a=a>>1;
   }
  for(i=0;i<=MaxProc && Pid[i][1]>0;i++);
  Pid[i][0]=BIni;Pid[i][1]=Lungh;
  visualizza(mappa,mem,Pid);
 }
}


void Elimina(unsigned char *mappa,unsigned long mem,unsigned long Pid[][MaxProc])
{unsigned long i,j;
 unsigned long BIni,BiniT,offset;
 unsigned long Proc;
 unsigned long Lungh;
 unsigned char b,a=128;
 printf("Dai il pid del Processo da eliminare:");
 scanf("%d",&Proc);
 BIni=Pid[Proc][0];Lungh=Pid[Proc][1];
 a=128;
 BiniT=BIni/8;
 offset=BIni-(BiniT*8);
 a=a>>offset;
 j=BiniT;
 for(i=BIni;i<BIni+Lungh;i++) 
 {if( (i>BIni)&&(i%8)==0) {j++; a=128;}
  b=255-a;mappa[j]=mappa[j]&b;a=a>>1;
 }
 Pid[Proc][1]=0;
 visualizza(mappa,mem,Pid);
}


unsigned long CercaBloccoLibero(unsigned char *mappa,unsigned long mem,unsigned long Lengh)
{unsigned long i,j,Bini,error,LenPar;
 unsigned char a=128;
 error=Bini=j=LenPar=0;
 for(i=0;i<mem&&LenPar<Lengh;i++)
 {if( (i>0)&&(i%8)==0) {j++; a=128;}
  if( (mappa[j]&a)>0)
	{Bini=i+1;LenPar=0;}
  else
	{LenPar++;}
  a=a>>1;
 }
 return(Bini);
}


void visualizza(unsigned char *mappa,unsigned long mem,unsigned long Pid[][MaxProc])
{unsigned long i,j;
 unsigned long memT=(mem/8)+1;
 for(i=0;i<memT;i++)
 {printf("mapp[%d-%d]",i*8,(i*8)+7);
  unsigned char a=128;
  for(j=0;j<=7;j++)
{ if( (mappa[i]&a)>0) printf("1");
	else printf("0");
     a=a>>1;	
  }
  printf("\n");
 }
 for(i=0;i<MaxProc;i++)
  printf(" Pid[%d]=%d,%d \n",i,Pid[i][0],Pid[i][1]);
 printf("\n");
}


int main(int argc, char* argv[])
{unsigned char *mappa;
 unsigned long Pid[MaxProc][MaxProc];
 unsigned long i,mem,memT;
printf("dai la quantità di memoria disponibile in k:");
 scanf("%d",&mem);
 memT=(mem/8)+1;
 mappa=(unsigned char *)malloc(sizeof(char)*memT);
 for(i=0;i<memT;i++) mappa[i]=0;
 for(i=0;i<MaxProc;i++) Pid[i][1]=0;
 char scelta[2];
 do
 {do{printf("Per inserire  un processo : I\nPer eliminare il  processo : E\nPer Uscire :s\nScelta:");
  scanf("%s",scelta);
  if( (scelta[0]!='I') && (scelta[0]!='E') && (scelta[0]!='s')) 
	printf("Scelta non consentita\n\n");
 }
 while( (scelta[0]!='I') && (scelta[0]!='E') && (scelta[0]!='s'));      
 if(scelta[0]=='I') Inserisci(mappa,mem,Pid);
 if(scelta[0]=='E') Elimina(mappa,mem,Pid);
 }while(scelta[0]!='s');
 return 0;
}


