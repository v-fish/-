#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
struct WANJIA
{
	char name[100];
	int sum;
};
void main()
{
  printf("|-------------------------------------------|\n");
  printf("|               ʯͷ������                  |\n");
  printf("| ��Ϸ����:                                 |\n");
  printf("|        ���ʯͷvs����,��ʯͷʤ��          |\n");
  printf("|         �����vs����,�����ʤ��           |\n");
  printf("|          ���ʯͷvs��,��ʤ��            |\n");
  printf("|                                           |\n");
  printf("|          1-ʯͷ  2-����  3-��             |\n");
  printf("|               enter-ȷ��                  |\n");
  printf("|-------------------------------------------|\n");
  printf("|           ����a-������ϰģʽ              |\n");
  printf("|           ����b-����ʵ����սģʽ          |\n");
 
int n,j;
char k,a,b;
struct WANJIA wj[100];
int pratise();
void competition();
int choice();
void input_player(struct WANJIA *wj,int j);
void sort_player(struct WANJIA wj[],int n);
void output_player(struct WANJIA wj[],int n);

srand(time(NULL));/*��ϵͳʱ������ʼ�������������*/  

do{

	k=choice();
	if (k=='a'){
			 printf("            ��ӭ������ϰģʽ\n");
  pratise();

  }
	else if (k=='b'){
		     printf("            ��ӭ����ʵսģʽ:\n");
	         printf("            ��������ҵ�����:\n");
			 scanf("%d",&n);
	         printf("            ��Ϸ��ʼ\n");
	for(j=0;j<n;j++){
		competition(); input_player(wj,j);
	}
	sort_player(wj,n);
	printf(" -------------\n");
	printf("|   ���а�    |\n");
	output_player(wj,n);
	}}while(k=='a'||k=='b');
		
}

int pratise()
{
   int i,people,Computer,win=0,lose=0,ping=0,sum=0; 
   for(i=0;i<5;i++)
     {
          printf("��ĳ�ȭѡ��(1��2��3):");
		  
               scanf("%d",&people);
               if(people==1||people==2||people==3)
               { //����������������ƣ�ֻ������1��3֮�������
                    printf("%d\t",people);
               }
          
      
        if(people==1)
      printf("ʯͷ VS ");
        else if(people==2) 
      printf("���� VS ");
        else      
	  printf("�� VS ");
     
          Computer = rand()%3+1;
         
          if(Computer==1)
      printf("ʯͷ");
		  else if(Computer==2)
      printf("����");
          else
      printf("��"); 
          switch(people-Computer)
          {
               case 0:
         printf("\tƽ�֣����ս�������Ը����Կ��⣬��������\n");
      ping++; break;
               case -1: case 2:
      printf("\t��Ӯ�ˣ����򲻸������ˣ����Ա���Ű��һ��\n");
      win++;
       break;
               case 1: case -2:
      printf("\t�����ˣ������㻹�����񣬻�ȥ���������\n");
      lose++;
      break;
          }
     }
	 sum=win+lose+ping;
  printf("\n");
  printf(" ------------------------------------------\n");
  printf("|                 ��һ������%d��            |\n",sum);
  printf(" ---------------------|-------------------- \n");
  printf("|        ʤ��         |         %d ��       |\n",win);
  printf(" ---------------------|-------------------- \n");
  printf("|        ʧ��         |         %d ��       |\n",lose);
  printf(" ---------------------|-------------------- \n");
  printf("|        ƽ��         |         %d ��       |\n",ping);
  printf(" ---------------------|-------------------- \n");

  if(win>lose){
	  printf("���ս��:��Ӯ���˱�������ʯͷ����ս��ϰģʽ������ʤ��\n");
  }
  else if(win<lose){
	  printf("���ս��:���ź������ڱ�������ʯͷ����ս��ϰģʽ��ʧ����\n");
  }
  else if(win==lose){
	  printf("���ս��:���ڱ�������ʯͷ����ս��ϰģʽ�������ս��ƽ�֣���������һ�̣�\n");
  }
return 0;
}
void competition()
{
	int i,people,Computer,win=0,lose=0,ping=0,sum=0; 
   for(i=0;i<5;i++)
     {
          printf("��ĳ�ȭѡ��(1��2��3):");
		  
               scanf("%d",&people);
               if(people==1||people==2||people==3)
               { 
                    printf("%d\t",people);
               }
          
      
        if(people==1)
      printf("ʯͷ VS ");
        else if(people==2) 
      printf("���� VS ");
        else      
	  printf("�� VS ");
     
          Computer = rand()%3+1;
         
          if(Computer==1)
      printf("ʯͷ");
		  else if(Computer==2)
      printf("����");
          else
      printf("��"); 
          switch(people-Computer)
          {
               case 0:
         printf("\tƽ�֣����ս�������Ը����Կ��⣬��������\n");
      ping++; break;
               case -1: case 2:
      printf("\t��Ӯ�ˣ����򲻸������ˣ����Ա���Ű��һ��\n");
      win++;
       break;
               case 1: case -2:
      printf("\t�����ˣ������㻹�����񣬻�ȥ���������\n");
      lose++;
      break;
          }
     }sum=win-lose;printf("�÷�Ϊ%d\n",sum);
		  return;
}
void input_player(struct WANJIA *wj,int j)
{
	printf("�����������Ϣ: ���� �� �÷�\n");
	scanf("%s%d",&wj[j].name,&wj[j].sum);	
}

int choice()
{
	char k;
	printf("\n��ѡ����Ϸģʽ: \n");
	k=getch();
	return k;
}
void sort_player(struct WANJIA wj[],int n)
{
int i,j,k,index;
struct WANJIA temp;
for(j=0;j<n-1;j++)
{
index=j;
for(k=j;k<n;k++)
{
if(wj[k].sum>wj[index].sum) index=k;
temp=wj[j];wj[j]=wj[index];wj[index]=temp;
}
}
for(i=0;i<n;i++){printf("%d\n",wj[j].sum);
}
}
void output_player(struct WANJIA wj[],int n)
{
int j;
printf(" -------------\n");
printf("|���� |  �÷�|\n");
printf(" -----|-------\n");
for(j=0;j<n;j++){
printf("|%s       %d   |\n",wj[j].name,wj[j].sum);
printf(" -------------\n");
}
}
