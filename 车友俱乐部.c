#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
struct student
{
	char cr[10];/*��Ա��*/
	char crr[10];/*�ǳ�*/
	char crrr[10];/*�Ա�*/
	char crrrr[10];/*ְҵ*/
	int c;/*����*/
	int r;/*����*/
	char a1[10];/*Ʒ��*/
	char a2[10];/*����*/
	char a3[10];/*��ɫ*/
	int a4;/*���ʱ��*/
};
typedef struct student student;
void Delete(student*x,int m)
{
	int i,j;
	char s[10];
	printf("������Ҫɾ����Ա���ǳ�\n");
	scanf("%s",s);
	for(i=0;strcmp(x[i].crr,s);i++);
	for(j=i;j<m-1;j++)
		x[j]=x[j+1];
}
/*�������ܣ�ͨ�������Ա�ǳ�����λɾ���ṹ���������ĳһ��*/
int readfile(student*x)
{
	FILE*fp;
	int i=0;
	if((fp=fopen("d:\\abc.txt","r"))==NULL)
	{
		printf("file does not exist,create it first:\n");
		return 0;
	}
	fscanf(fp,"%s%s%s%s%d%d%s%s%s%d\n",x[i].cr,x[i].crr,x[i].crrr,x[i].crrrr,&x[i].c,&x[i].r,x[i].a1,x[i].a2,x[i].a3,&x[i].a4);
	while(!feof(fp))
	{
		i++;
		fscanf(fp,"%s%s%s%s%d%d%s%s%s%d\n",x[i].cr,x[i].crr,x[i].crrr,x[i].crrrr,&x[i].c,&x[i].r,x[i].a1,x[i].a2,x[i].a3,&x[i].a4);
	}
	fclose(fp);
	return 0;
}
/*�������ܣ����ļ��е����ݶ�ȡ��������*/
void Output(student x[],int n)
{
	int i;
	    printf("��Ա��    �ǳ�    �Ա�    ְҵ    ����    ����    Ʒ��    ����    ��ɫ    ���ʱ��\n");
	     for(i=0;i<n;i++)
	{
		printf("%-10s%-8s%-8s%-8s%-8d%-8d%-8s%-8s%-8s%-20d\n",x[i].cr,x[i].crr,x[i].crrr,x[i].crrrr,x[i].c,x[i].r,x[i].a1,x[i].a2,x[i].a3,x[i].a4);
	}
		
}/*�������ܣ��������Ԫ�ص���Ļ��*/
int Input(student x[],int m)
{
	int i,n;
	do
	{
		printf("Enter the sum of �³���:\n");
		scanf("%d",&n);
	}while(n<=0||n>100);
	for(i=m;i<m+n;i++)
	{
		printf("Enter %d-th ���� :\n",i+1);
		printf("��Ա��    �ǳ�    �Ա�    ְҵ    ����    ����    Ʒ��    ����    ��ɫ    ���ʱ��\n");
		scanf("%s%s%s%s%d%d%s%s%s%d",x[i].cr,x[i].crr,x[i].crrr,x[i].crrrr,&x[i].c,&x[i].r,x[i].a1,x[i].a2,x[i].a3,&x[i].a4);
	}
	return i;
}/*�������ܣ��������ݵ������в��������鳤��*/
void createfile(student*x, int m)
{
	FILE*fp;
	int i;
	fp=fopen("d:\\abc.txt","w+");
	if(fp==0)
	{
		printf("can not open file!\n");
		exit(1);
	}
	for(i=0;i<m ;i++)
	{
		fprintf(fp,"%-10s%-8s%-8s%-8s%-8d%-8d%-8s%-8s%-8s%-20d\n",x[i].cr,x[i].crr,x[i].crrr,x[i].crrrr,x[i].c,x[i].r,x[i].a1,x[i].a2,x[i].a3,x[i].a4);
	}
	fclose(fp);
}/*����������д���ļ�*/
void caculate(student x[])                  
{	
	int age,i,j=0;
	printf("�������ѯ����\n");
	scanf("%d",&age);
	for(i=0;i<100;i++)		/*��λ����ѯ����*/			
	{	if(x[i].r==age)
       	{
			 j++;
		}
	}
	printf("������εĻ�Ա������\n");
	printf("%d",j);
}
/*�������ܣ��Ի�Ա������ɽ���ͳ�ƺ�չʾ*/
void Jiaru(student*x)
{
	int n,z,a=0;
	for(n=0;n<100;n++)
	{
		if(x[n].r!=0)
			a++;/*�ó�����*/
		else
			break;
	}
	z=Input(x,a);
	Output(x,z);
	caculate(x);
	printf("\n");
}/*�������ܣ������¼����Ա�����������������ݴ�ӡ����Ļ�ϣ�����ͳ����Ӧ����ε�����*/
void Shanchu(student*x)
{
	int n,a=0;
	for(n=0;n<100;n++)
	{
		if(x[n].r!=0)
			a++;
		else
			break;
	}
	Delete(x,n+1);
	createfile(x,n-1);
	readfile(x);
	Output(x,n-1);
	caculate(x);
	printf("\n");
}/*�������ܣ�ɾ��ĳһ��Ա���ң�������д���ļ�����ͳ����Ӧ����ε�����*/
void sortcar(student a[],int n)
{
	int k,l;student temp;
    for(k=0;k<n-1;k++)/*ð�ݷ�����*/
		for(l=n-1;l>k;l--)
		   {	
			   if(strcmp(a[l].a2,a[l-1].a2)>0)
				{
                     temp=a[l-1];
					 a[l-1]=a[l];
					 a[l]=temp;
				} 
			}
	for(l=0;l<n;l++)
		printf("%-10s%-8s%-8s%-8s%-8d%-8d%-8s%-8s%-8s%-20d\n",a[l].cr,a[l].crr,a[l].crrr,a[l].crrrr,a[l].c,a[l].r,a[l].a1,a[l].a2,a[l].a3,a[l].a4);
    
	
}	
	/*�������ܣ����ݳ��Ͷ������������*/
void sortage(student a[],int n)  
{
	int k,index,l;student temp;
    for(k=0;k<n-1;k++)/*ѡ������*/
	{		
			index=k;
			for(l=k+1;l<n;l++)
					if(a[l].r<a[index].r)
						index=l;
			if(index!=k)
			{
				temp=a[index];
				a[index]=a[k];
			    a[k]=temp;
            }
	}
	for(l=0;l<n;l++)
       printf("%-10s%-8s%-8s%-8s%-8d%-8d%-8s%-8s%-8s%-20d\n",a[l].cr,a[l].crr,a[l].crrr,a[l].crrrr,a[l].c,a[l].r,a[l].a1,a[l].a2,a[l].a3,a[l].a4);
	 
}/*�����������������*/
void sortname(student a[],int n) 
{					 
	int k,l;student temp;
	for(k=0;k<n-1;k++)/*ð�ݷ�����*/
		for(l=n-1;l>k;l--)
		{	
			if(strcmp(a[l].cr,a[l-1].cr)>0)
			 {
				temp=a[l-1];
			    a[l-1]=a[l];
				a[l]=temp;
			 } 
		}
	for(l=0;l<n;l++)
        printf("%-10s%-8s%-8s%-8s%-8d%-8d%-8s%-8s%-8s%-20d\n",a[l].cr,a[l].crr,a[l].crrr,a[l].crrrr,a[l].c,a[l].r,a[l].a1,a[l].a2,a[l].a3,a[l].a4);
	
}					/*�������ܣ����ݻ�Ա���������������*/
void sorttime(student a[],int n) 
{	
	int k,index,l;student temp;
	for(k=0;k<n-1;k++)/*ѡ������*/
		{		
			index=k;
			for(l=k+1;l<n;l++)
			     if(a[l].a4<a[index].a4)
					index=l;
			if(index!=k)
				{
					temp=a[index];
					a[index]=a[k];
				    a[k]=temp;
                 }
		 }
	for(l=0;l<n;l++)
			printf("%-10s%-8s%-8s%-8s%-8d%-8d%-8s%-8s%-8s%-20d\n",a[l].cr,a[l].crr,a[l].crrr,a[l].crrrr,a[l].c,a[l].r,a[l].a1,a[l].a2,a[l].a3,a[l].a4);
	
}
/*�������ܣ��������ʱ��������������*/
void sortcarage(student a[],int n)  
{ 
	int k,l;student temp;
	for(k=0;k<n-1;k++)/*ð�ݷ�����*/
	{	
		for(l=n-1;l>k;l--)
				if(a[l].c<a[l-1].c)
				{
					temp=a[l-1];
				    a[l-1]=a[l];
					a[l]=temp;
				} 				
	}
	for(l=0;l<n;l++)
			printf("%-10s%-8s%-8s%-8s%-8d%-8d%-8s%-8s%-8s%-20d\n",a[l].cr,a[l].crr,a[l].crrr,a[l].crrrr,a[l].c,a[l].r,a[l].a1,a[l].a2,a[l].a3,a[l].a4);
	
}/*�������ܣ����ݼ���������������*/
void Sort(student x[],int j)
{
	int number1;
	do
	{
		printf("1-���ݳ�������\n");
	printf("2-������������\n");
	printf("3-���ݻ�Ա������\n");
	printf("4-�������ʱ������\n");
	printf("5-���ݼ�������\n");
	printf("0-������һ��\n");
	scanf("%d",&number1);
		switch(number1)
		{
        case 1:sortcar(x,j);break;
		case 2:sortage(x,j);break;
		case 3:sortname(x,j);break;
		case 4:sorttime(x,j);break;
		case 5:sortcarage(x,j);break;
		case 0:break;
		}
	}while(number1);
}
/*������������ѡ����Ӧ�ĺ�����������*/

void zhantie(student*x, int m)
{
	FILE*fp;
	int i;
	fp=fopen("d:\\c.txt","w+");
	if(fp==0)
	{
		printf("can not open file!\n");
		exit(1);
	}
	for(i=0;i<m ;i++)
	{
		fprintf(fp,"%-10s%-8s%-8s%-8s%-8d%-8d%-8s%-8s%-8s%-20d\n",x[i].cr,x[i].crr,x[i].crrr,x[i].crrrr,x[i].c,x[i].r,x[i].a1,x[i].a2,x[i].a3,x[i].a4);
	}
	fclose(fp);
}
/*�������ܣ�������д���ļ�*/
void Chaxun(student*x)
{
	int n;
	int number,i,l,j=0,age,k,index,time;
	char name[50],sex[10],a2[10],car[10];
	student temp;/*studentΪ�ṹ������findxxx����ÿ����ѯ�����½�����������nameΪ������sex�Ա�age���䣬car���time���ʱ��*/

	printf("����1��������ѯ������2���Ա��ѯ������3�������ѯ��4�������ѯ��5�����ʱ���ѯ\n");	
	do
	{
		scanf("%d",&number);	
		switch(number)	
	{	        
            case 1:		     /*�����������в���*/	  
	                 {   
						 student findname[100];	   
						 scanf("%s",name);		      
						 for(i=0;i<100;i++)				 
							 if (!strcmp(x[i].cr,name))					 
								{ 
									findname[j]=x[i];			  /*�������鴢���ѯ��������*/       					 
								    j++;
							    }
							zhantie(findname,j);
							 if(j)       /*�����ѯ����������������޴���*/
								 
							 {
                         Sort(findname,j);
						

							 }
						 else
							 printf("���޴���");
							 break;
					 }

            case 2:           /*�����Ա���в���*/
					{                     
						student findsex1[100];				  
						scanf("%s",sex);			      
						for(i=0;i<100;i++)               
						{
							if(!strcmp(x[i].crrr,sex))					  
							{
								findsex1[j]=x[i];              /*�������鴢���ѯ��������*/ 
								j++;
							}
						}
						zhantie(findsex1,j);
				if(j)                                       /*�����ѯ����������������޴���*/
                         Sort(findsex1,j);
						 else
							 printf("���޴���");
				break;

					}
            case 3:	/*����������в�ѯ*/		
                  {				
					   student findage[100];			    
				        scanf("%d",&age);				
						for(i=0;i<100;i++)					
						{	if(x[i].r==age)
							{
							  findage[j]=x[i];/*�������鴢���ѯ��������*/ 
							    j++;
						     }
						}
						zhantie(findage,j);
						if(j)                  /*�����ѯ����������������޴���*/
                         Sort(findage,j);
						 else
							 printf("���޴���");
						break;
				  }
			case 4:/*���ݳ��ͽ��в�ѯ*/
			{
				student findcar[100];
				scanf("%s",car);
				for(i=0;i<100;i++)				 
					{		 if (!strcmp(x[i].a2,car))					 
								{ 
									findcar[j]=x[i];			    /*�������鴢���ѯ��������*/      					 
								    j++;
							    }
				    }
				zhantie(findcar,j);
				if(j)                            /*�����ѯ����������������޴���*/
                         Sort(findcar,j);
						 else
							 printf("���޴���");
				break;

			}
			case 5:/*����*/
						 
				{
							student findtime[100];
							 scanf("%d",&time);				
						for(i=0;i<100;i++)					
							
								if(x[i].a4==time)
								{
									findtime[j]=x[i];/*�������鴢���ѯ��������*/ 
							        j++;
						         }
								zhantie(findtime,j);
						    if(j)                /*�����ѯ����������������޴���*/
                         Sort(findtime,j);
						 else
							 printf("���޴���");
							break;
				}
			case 0:break;
				}
		}while(number);
}/*ѡ����Ӧ����Ž�����Ϣ��ѯ*/
void Mima()
{
	char mima[100];int i;
	while(1)
	{
	    printf("�������½����\n");    
		for(i=0;i<100;i++)
	        {
		       mima[i]=getch();
		       if(mima[i]=='\r')
			     break;
		       printf("*");
	         }
		if(mima[0]=='1'&&mima[1]=='2'&&mima[2]=='3'&&mima[3]=='4')
			break;
	}
    printf("��½�ɹ���\n");

}
/*�������ܣ������½���벢���Ǻű�ʾ����������ܽ���ϵͳ*/
void Baoming(student*x)
{
	int i;
	char k[10];
	FILE*fp;
	fp=fopen("d:\\ab.txt","a+");
	printf("�����������ǳƣ�\n");
	scanf("%s",k);
	for(i=0;strcmp(x[i].crr,k);i++);
	fprintf(fp,"%-10s%-8s%-8s%-8s%-8d%-8d%-8s%-8s%-8s%-20d\n",x[i].cr,x[i].crr,x[i].crrr,x[i].crrrr,x[i].c,x[i].r,x[i].a1,x[i].a2,x[i].a3,x[i].a4);
	printf("�����ɹ���");
	fclose(fp);
	printf("\n");
}/*�������ܣ��Գ�Ա������Ϣ����ͳ�Ʋ���д���ļ�*/
void Diaocha()
{
	FILE *fp;
	int x,num,i,n;
	double sum=0,ave;
	fp=fopen("d:\\test.txt","w+");
	printf("������μ����ֵĳ�������:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	printf("���복�ѵ�����:\n");
	scanf("%d",&num);
	x=num;
	sum+=x;
	fprintf(fp,"%d   ",x);
	}
	fclose(fp);
	ave=sum/n;
	printf("���ѵ�����Ϊ:");
	printf("%f\n",ave);
	fp=fopen("d:\\test.txt","a+");
	fprintf(fp,"%f    ",ave);
}/*�Գ�Ա����Ƚ��е��鲢�������ƽ��ֵ*/
void Caidan()/*����ϵͳ����*/
{
	printf("1-�����Ա");
	printf("2-�˳���Ա");
	printf("3-��ѯ��Ϣ");
	printf("4-�Լݱ���");
	printf("5-�û�����");
	printf("0-�˳�ϵͳ");
}
void Runmain(student*x,int choice)
{
	switch(choice)
	{
	case 1:Jiaru(x);
		break;
	case 2:Shanchu(x);
		break;
	case 3:Chaxun(x);
		break;
	case 4:Baoming(x);
		break;
	case 5:Diaocha();
		break;
	case 0:break;
	}
}/*�������ܣ�ͨ��ѡ����Ӧ�����ֽ�����롢ɾ������ѯ������������ϵͳ*/
int main()/*�������ݿ�*/
{
	int choice,n,m=0;
	student x[100]={{"����","����","Ů","ѧ��",1,19,"����","G","black",20170128},
	{"���ν�","���ν�","Ů","ѧ��",1,21,"����","x","red",20160321},
	{"������","������","Ů","ѧ��",3,20,"����","f","red",20160321},
	{"�����","�����","Ů","ѧ��",2,20,"����","x","blue",20180326},
	{"���憴","���憴","Ů","ѧ��",3,21,"ѩ����","y","red",20160321},
	{"������","������","Ů","ѧ��",1,19,"·��","f","black",20160205},
    {"����","��褽�","Ů","ѧ��",2,20,"������","m","red",20170523},
    {"�ܾ�","�ܾ�","Ů","ѧ��",2,20,"����","a","black",20180102},
    {"��ǥ��","��ǥ��","Ů","ѧ��",1,20,"·��","x","red",20170612},
    {"������","������","Ů","ѧ��",3,21,"����","s","white",20150421},
    {"����","����","Ů","ѧ��",3,20,"����","x","red",20170901},
    {"�����","�����","��","ѧ��",2,20,"����","w","red",20180905},
    {"����","����","��","ѧ��",1,20,"����","x","red",20171112},
    {"�����","�����","��","ѧ��",2,20,"����","x","red",20161211},
    {"����","��ά��","��","ѧ��",3,22,"����","b","red",20160321},
    {"����","����","��","ѧ��",1,20,"������","x","red",20180106},
    {"����","����","��","ѧ��",2,20,"����","x","red",20161223},
    {"������","������","��","ѧ��",3,20,"����","a","red",20151108},
    {"��Ӣ��","��Ӣ��","��","ѧ��",3,20,"����","x","white",20150312},
    {"�����","�����","��","ѧ��",1,21,"·��","s","red",20170624},
    {"������","������","��","ѧ��",2,20,"����","x","black",20160814},
    {"Ф����","Ф����","��","ѧ��",2,21,"������","x","red",20160324},
    {"����","�Ŷ���","��","ѧ��",1,20,"����","c","blue",20170912},
    {"����ΰ","����ΰ","��","ѧ��",3,20,"����","x","red",20181001},
    {"����","����","��","ѧ��",1,20,"ѩ����","x","red",20180731},
    {"����","�°�","��","ѧ��",2,20,"����","f","black",20170731},
    {"����","����","��","ѧ��",2,20,"����","x","red",20160831},
    {"��ͬ��","��ͬ��","��","ѧ��",1,20,"������","g","red",20170831},
    {"��־��","��־��","��","ѧ��",3,20,"·��","x","blue",20180831},
    {"������","������","��","ѧ��",2,20,"����","j","red",20160321},
    {"������","������","��","ѧ��",3,21,"����","x","red",20151231},
    {"�ƽ���","�ƽ���","��","ѧ��",1,20,"����","g","black",20170425},
    {"�ƺ���","�ƺ���","��","ѧ��",2,21,"����","f","red",20160321},
    {"����","�����","��","ѧ��",2,20,"ѩ����","a","blue",20160514}};
	createfile(x,34);
	Mima();
	do
	{
		Caidan();
		printf("����������ѡ��\n");
		scanf("%d",&choice);
		if(choice>=0&&choice<=5)
			Runmain(x,choice);
		else
			printf("�������\n");
	}while(choice);
	for(n=0;n<100;n++)
	{
		if(x[n].r!=0)
			m++;
		else
			break;
	}
	createfile(x,m);
     return 0;
}