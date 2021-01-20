#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
struct student
{
	char cr[10];/*会员名*/
	char crr[10];/*昵称*/
	char crrr[10];/*性别*/
	char crrrr[10];/*职业*/
	int c;/*驾龄*/
	int r;/*年龄*/
	char a1[10];/*品牌*/
	char a2[10];/*车款*/
	char a3[10];/*颜色*/
	int a4;/*入会时间*/
};
typedef struct student student;
void Delete(student*x,int m)
{
	int i,j;
	char s[10];
	printf("请输入要删除会员的昵称\n");
	scanf("%s",s);
	for(i=0;strcmp(x[i].crr,s);i++);
	for(j=i;j<m-1;j++)
		x[j]=x[j+1];
}
/*函数功能：通过输入会员昵称来定位删除结构体数组里的某一项*/
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
/*函数功能：把文件中的数据读取到数组中*/
void Output(student x[],int n)
{
	int i;
	    printf("会员名    昵称    性别    职业    驾龄    年龄    品牌    车款    颜色    入会时间\n");
	     for(i=0;i<n;i++)
	{
		printf("%-10s%-8s%-8s%-8s%-8d%-8d%-8s%-8s%-8s%-20d\n",x[i].cr,x[i].crr,x[i].crrr,x[i].crrrr,x[i].c,x[i].r,x[i].a1,x[i].a2,x[i].a3,x[i].a4);
	}
		
}/*函数功能：输出数组元素到屏幕上*/
int Input(student x[],int m)
{
	int i,n;
	do
	{
		printf("Enter the sum of 新车主:\n");
		scanf("%d",&n);
	}while(n<=0||n>100);
	for(i=m;i<m+n;i++)
	{
		printf("Enter %d-th 车主 :\n",i+1);
		printf("会员名    昵称    性别    职业    驾龄    年龄    品牌    车款    颜色    入会时间\n");
		scanf("%s%s%s%s%d%d%s%s%s%d",x[i].cr,x[i].crr,x[i].crrr,x[i].crrrr,&x[i].c,&x[i].r,x[i].a1,x[i].a2,x[i].a3,&x[i].a4);
	}
	return i;
}/*函数功能：输入数据到数组中并返回数组长度*/
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
}/*把数组数据写入文件*/
void caculate(student x[])                  
{	
	int age,i,j=0;
	printf("请输入查询年龄\n");
	scanf("%d",&age);
	for(i=0;i<100;i++)		/*定位到查询年龄*/			
	{	if(x[i].r==age)
       	{
			 j++;
		}
	}
	printf("此年龄段的会员人数：\n");
	printf("%d",j);
}
/*函数功能：对会员年龄组成进行统计和展示*/
void Jiaru(student*x)
{
	int n,z,a=0;
	for(n=0;n<100;n++)
	{
		if(x[n].r!=0)
			a++;/*得出长度*/
		else
			break;
	}
	z=Input(x,a);
	Output(x,z);
	caculate(x);
	printf("\n");
}/*函数功能：输入新加入会员个数，并将所有数据打印到屏幕上，并且统计相应年龄段的人数*/
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
}/*函数功能：删除某一成员并且，将数据写入文件，并统计相应年龄段的人数*/
void sortcar(student a[],int n)
{
	int k,l;student temp;
    for(k=0;k<n-1;k++)/*冒泡法排序*/
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
	/*函数功能：根据车型对数组进行排序*/
void sortage(student a[],int n)  
{
	int k,index,l;student temp;
    for(k=0;k<n-1;k++)/*选择法排序*/
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
	 
}/*根据年龄对数组排序*/
void sortname(student a[],int n) 
{					 
	int k,l;student temp;
	for(k=0;k<n-1;k++)/*冒泡法排序*/
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
	
}					/*函数功能：根据会员名对数组进行排名*/
void sorttime(student a[],int n) 
{	
	int k,index,l;student temp;
	for(k=0;k<n-1;k++)/*选择法排序*/
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
/*函数功能：根据入会时间对数组进行排名*/
void sortcarage(student a[],int n)  
{ 
	int k,l;student temp;
	for(k=0;k<n-1;k++)/*冒泡法排序*/
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
	
}/*函数功能：根据驾龄对数组进行排名*/
void Sort(student x[],int j)
{
	int number1;
	do
	{
		printf("1-根据车款排序\n");
	printf("2-根据年龄排序\n");
	printf("3-根据会员名排序\n");
	printf("4-根据入会时间排序\n");
	printf("5-根据驾龄排序\n");
	printf("0-返回上一级\n");
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
/*根据输入的序号选择相应的函数进行排序*/

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
/*函数功能：将数组写入文件*/
void Chaxun(student*x)
{
	int n;
	int number,i,l,j=0,age,k,index,time;
	char name[50],sex[10],a2[10],car[10];
	student temp;/*student为结构体名，findxxx是在每个查询条件新建的数组名，name为姓名，sex性别。age年龄，car车款，time入会时间*/

	printf("输入1按姓名查询，输入2按性别查询，输入3按年龄查询，4按车款查询，5按入会时间查询\n");	
	do
	{
		scanf("%d",&number);	
		switch(number)	
	{	        
            case 1:		     /*根据姓名进行查找*/	  
	                 {   
						 student findname[100];	   
						 scanf("%s",name);		      
						 for(i=0;i<100;i++)				 
							 if (!strcmp(x[i].cr,name))					 
								{ 
									findname[j]=x[i];			  /*用新数组储存查询到的数据*/       					 
								    j++;
							    }
							zhantie(findname,j);
							 if(j)       /*如果查询到则进行排序否则查无此人*/
								 
							 {
                         Sort(findname,j);
						

							 }
						 else
							 printf("查无此人");
							 break;
					 }

            case 2:           /*根据性别进行查找*/
					{                     
						student findsex1[100];				  
						scanf("%s",sex);			      
						for(i=0;i<100;i++)               
						{
							if(!strcmp(x[i].crrr,sex))					  
							{
								findsex1[j]=x[i];              /*用新数组储存查询到的数据*/ 
								j++;
							}
						}
						zhantie(findsex1,j);
				if(j)                                       /*如果查询到则进行排序否则查无此人*/
                         Sort(findsex1,j);
						 else
							 printf("查无此人");
				break;

					}
            case 3:	/*根据年龄进行查询*/		
                  {				
					   student findage[100];			    
				        scanf("%d",&age);				
						for(i=0;i<100;i++)					
						{	if(x[i].r==age)
							{
							  findage[j]=x[i];/*用新数组储存查询到的数据*/ 
							    j++;
						     }
						}
						zhantie(findage,j);
						if(j)                  /*如果查询到则进行排序否则查无此人*/
                         Sort(findage,j);
						 else
							 printf("查无此人");
						break;
				  }
			case 4:/*根据车型进行查询*/
			{
				student findcar[100];
				scanf("%s",car);
				for(i=0;i<100;i++)				 
					{		 if (!strcmp(x[i].a2,car))					 
								{ 
									findcar[j]=x[i];			    /*用新数组储存查询到的数据*/      					 
								    j++;
							    }
				    }
				zhantie(findcar,j);
				if(j)                            /*如果查询到则进行排序否则查无此人*/
                         Sort(findcar,j);
						 else
							 printf("查无此人");
				break;

			}
			case 5:/*驾龄*/
						 
				{
							student findtime[100];
							 scanf("%d",&time);				
						for(i=0;i<100;i++)					
							
								if(x[i].a4==time)
								{
									findtime[j]=x[i];/*用新数组储存查询到的数据*/ 
							        j++;
						         }
								zhantie(findtime,j);
						    if(j)                /*如果查询到则进行排序否则查无此人*/
                         Sort(findtime,j);
						 else
							 printf("查无此人");
							break;
				}
			case 0:break;
				}
		}while(number);
}/*选择相应的序号进行信息查询*/
void Mima()
{
	char mima[100];int i;
	while(1)
	{
	    printf("请输入登陆密码\n");    
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
    printf("登陆成功！\n");

}
/*函数功能：输入登陆密码并用星号表示输入错误则不能进入系统*/
void Baoming(student*x)
{
	int i;
	char k[10];
	FILE*fp;
	fp=fopen("d:\\ab.txt","a+");
	printf("请输入您的昵称：\n");
	scanf("%s",k);
	for(i=0;strcmp(x[i].crr,k);i++);
	fprintf(fp,"%-10s%-8s%-8s%-8s%-8d%-8d%-8s%-8s%-8s%-20d\n",x[i].cr,x[i].crr,x[i].crrr,x[i].crrrr,x[i].c,x[i].r,x[i].a1,x[i].a2,x[i].a3,x[i].a4);
	printf("报名成功！");
	fclose(fp);
	printf("\n");
}/*函数功能：对成员报名信息进行统计并且写入文件*/
void Diaocha()
{
	FILE *fp;
	int x,num,i,n;
	double sum=0,ave;
	fp=fopen("d:\\test.txt","w+");
	printf("请输入参加评分的车友人数:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	printf("输入车友的评分:\n");
	scanf("%d",&num);
	x=num;
	sum+=x;
	fprintf(fp,"%d   ",x);
	}
	fclose(fp);
	ave=sum/n;
	printf("车友的评分为:");
	printf("%f\n",ave);
	fp=fopen("d:\\test.txt","a+");
	fprintf(fp,"%f    ",ave);
}/*对成员满意度进行调查并计算出其平均值*/
void Caidan()/*进入系统界面*/
{
	printf("1-加入会员");
	printf("2-退出会员");
	printf("3-查询信息");
	printf("4-自驾报名");
	printf("5-用户调查");
	printf("0-退出系统");
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
}/*函数功能：通过选择相应的数字进入加入、删除、查询、报名、调查系统*/
int main()/*建立数据库*/
{
	int choice,n,m=0;
	student x[100]={{"马丽","马丽","女","学生",1,19,"奔驰","G","black",20170128},
	{"王梦杰","王梦杰","女","学生",1,21,"宝马","x","red",20160321},
	{"仲昱蓓","仲昱蓓","女","学生",3,20,"宝马","f","red",20160321},
	{"祁佳怡","祁佳怡","女","学生",2,20,"奔驰","x","blue",20180326},
	{"李湘喆","李湘喆","女","学生",3,21,"雪佛兰","y","red",20160321},
	{"张雨圻","张雨圻","女","学生",1,19,"路虎","f","black",20160205},
    {"陈锐","陈瑜洁","女","学生",2,20,"法拉利","m","red",20170523},
    {"周静","周静","女","学生",2,20,"奔驰","a","black",20180102},
    {"徐钎鸿","徐钎鸿","女","学生",1,20,"路虎","x","red",20170612},
    {"嵇友晴","嵇友晴","女","学生",3,21,"奇瑞","s","white",20150421},
    {"董晨","董晨","女","学生",3,20,"奔驰","x","red",20170901},
    {"丁亚楠","丁亚楠","男","学生",2,20,"宝马","w","red",20180905},
    {"王旭","王旭","男","学生",1,20,"奔驰","x","red",20171112},
    {"王琛琦","王琛琦","男","学生",2,20,"大众","x","red",20161211},
    {"陈锐","孔维政","男","学生",3,22,"奔驰","b","red",20160321},
    {"付宇","付宇","男","学生",1,20,"法拉利","x","red",20180106},
    {"朱宇","朱宇","男","学生",2,20,"奔驰","x","red",20161223},
    {"刘海琦","刘海琦","男","学生",3,20,"奇瑞","a","red",20151108},
    {"许英杰","许英杰","男","学生",3,20,"大众","x","white",20150312},
    {"李昊屿","李昊屿","男","学生",1,21,"路虎","s","red",20170624},
    {"李熠轩","李熠轩","男","学生",2,20,"宝马","x","black",20160814},
    {"肖竣文","肖竣文","男","学生",2,21,"法拉利","x","red",20160324},
    {"陈锐","张二林","男","学生",1,20,"奔驰","c","blue",20170912},
    {"张晓伟","张晓伟","男","学生",3,20,"宝马","x","red",20181001},
    {"张阔","张阔","男","学生",1,20,"雪佛兰","x","red",20180731},
    {"陈锐","陈安","男","学生",2,20,"大众","f","black",20170731},
    {"陈锐","陈锐","男","学生",2,20,"奔驰","x","red",20160831},
    {"金同中","金同中","男","学生",1,20,"法拉利","g","red",20170831},
    {"鱼志航","鱼志航","男","学生",3,20,"路虎","x","blue",20180831},
    {"赵作彦","赵作彦","男","学生",2,20,"宝马","j","red",20160321},
    {"秦银川","秦银川","男","学生",3,21,"奔驰","x","red",20151231},
    {"唐金泽","唐金泽","男","学生",1,20,"大众","g","black",20170425},
    {"唐浩宇","唐浩宇","男","学生",2,21,"奔驰","f","red",20160321},
    {"陈锐","蒋成睿","男","学生",2,20,"雪佛兰","a","blue",20160514}};
	createfile(x,34);
	Mima();
	do
	{
		Caidan();
		printf("请输入您的选择：\n");
		scanf("%d",&choice);
		if(choice>=0&&choice<=5)
			Runmain(x,choice);
		else
			printf("输入错误！\n");
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