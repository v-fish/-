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
  printf("|               石头剪刀布                  |\n");
  printf("| 游戏介绍:                                 |\n");
  printf("|        如果石头vs剪刀,则石头胜利          |\n");
  printf("|         如果布vs剪刀,则剪刀胜利           |\n");
  printf("|          如果石头vs布,则布胜利            |\n");
  printf("|                                           |\n");
  printf("|          1-石头  2-剪刀  3-布             |\n");
  printf("|               enter-确定                  |\n");
  printf("|-------------------------------------------|\n");
  printf("|           输入a-进入练习模式              |\n");
  printf("|           输入b-进入实名对战模式          |\n");
 
int n,j;
char k,a,b;
struct WANJIA wj[100];
int pratise();
void competition();
int choice();
void input_player(struct WANJIA *wj,int j);
void sort_player(struct WANJIA wj[],int n);
void output_player(struct WANJIA wj[],int n);

srand(time(NULL));/*用系统时间来初始化随机数发生器*/  

do{

	k=choice();
	if (k=='a'){
			 printf("            欢迎来到练习模式\n");
  pratise();

  }
	else if (k=='b'){
		     printf("            欢迎来到实战模式:\n");
	         printf("            请输入玩家的人数:\n");
			 scanf("%d",&n);
	         printf("            游戏开始\n");
	for(j=0;j<n;j++){
		competition(); input_player(wj,j);
	}
	sort_player(wj,n);
	printf(" -------------\n");
	printf("|   排行榜    |\n");
	output_player(wj,n);
	}}while(k=='a'||k=='b');
		
}

int pratise()
{
   int i,people,Computer,win=0,lose=0,ping=0,sum=0; 
   for(i=0;i<5;i++)
     {
          printf("你的出拳选择(1、2、3):");
		  
               scanf("%d",&people);
               if(people==1||people==2||people==3)
               { //这里对输入做了限制，只能输入1到3之间的整数
                    printf("%d\t",people);
               }
          
      
        if(people==1)
      printf("石头 VS ");
        else if(people==2) 
      printf("剪刀 VS ");
        else      
	  printf("布 VS ");
     
          Computer = rand()%3+1;
         
          if(Computer==1)
      printf("石头");
		  else if(Computer==2)
      printf("剪刀");
          else
      printf("布"); 
          switch(people-Computer)
          {
               case 0:
         printf("\t平手！你的战斗力足以跟电脑抗衡，继续保持\n");
      ping++; break;
               case -1: case 2:
      printf("\t你赢了！功夫不负有心人，电脑被你虐了一波\n");
      win++;
       break;
               case 1: case -2:
      printf("\t你输了！看来你还不够格，回去多练几年吧\n");
      lose++;
      break;
          }
     }
	 sum=win+lose+ping;
  printf("\n");
  printf(" ------------------------------------------\n");
  printf("|                 你一共玩了%d盘            |\n",sum);
  printf(" ---------------------|-------------------- \n");
  printf("|        胜利         |         %d 盘       |\n",win);
  printf(" ---------------------|-------------------- \n");
  printf("|        失败         |         %d 盘       |\n",lose);
  printf(" ---------------------|-------------------- \n");
  printf("|        平手         |         %d 盘       |\n",ping);
  printf(" ---------------------|-------------------- \n");

  if(win>lose){
	  printf("最终结果:你赢得了本场剪刀石头布大战练习模式的最终胜利\n");
  }
  else if(win<lose){
	  printf("最终结果:很遗憾，你在本场剪刀石头布大战练习模式中失败了\n");
  }
  else if(win==lose){
	  printf("最终结果:你在本场剪刀石头布大战练习模式中与电脑战成平手，不如再来一盘？\n");
  }
return 0;
}
void competition()
{
	int i,people,Computer,win=0,lose=0,ping=0,sum=0; 
   for(i=0;i<5;i++)
     {
          printf("你的出拳选择(1、2、3):");
		  
               scanf("%d",&people);
               if(people==1||people==2||people==3)
               { 
                    printf("%d\t",people);
               }
          
      
        if(people==1)
      printf("石头 VS ");
        else if(people==2) 
      printf("剪刀 VS ");
        else      
	  printf("布 VS ");
     
          Computer = rand()%3+1;
         
          if(Computer==1)
      printf("石头");
		  else if(Computer==2)
      printf("剪刀");
          else
      printf("布"); 
          switch(people-Computer)
          {
               case 0:
         printf("\t平手！你的战斗力足以跟电脑抗衡，继续保持\n");
      ping++; break;
               case -1: case 2:
      printf("\t你赢了！功夫不负有心人，电脑被你虐了一波\n");
      win++;
       break;
               case 1: case -2:
      printf("\t你输了！看来你还不够格，回去多练几年吧\n");
      lose++;
      break;
          }
     }sum=win-lose;printf("得分为%d\n",sum);
		  return;
}
void input_player(struct WANJIA *wj,int j)
{
	printf("请输入玩家信息: 姓名 和 得分\n");
	scanf("%s%d",&wj[j].name,&wj[j].sum);	
}

int choice()
{
	char k;
	printf("\n请选择游戏模式: \n");
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
printf("|姓名 |  得分|\n");
printf(" -----|-------\n");
for(j=0;j<n;j++){
printf("|%s       %d   |\n",wj[j].name,wj[j].sum);
printf(" -------------\n");
}
}
