#include<stdio.h>
#include<stdlib.h>
#include<String.h>
//函数入口
/*
*运行的时候输入在项目文件下面找到/Debug文件夹，打开cmd在此目录下，执行该文件下的WordCount.exe：
*WordCount.exe  -[c][w] [文件全路径]  
 */
int main(int   argc,   char*   argv[])
{
	int i=0;
	char model=NULL;
	char *addr;
	FILE* f;
	int count=0;//统计结果
	char buf[1024]={0};
	for(i=0;i<argc;i++)
		{
			if(i==1)
			{
				if(strcmp(argv[i],"-c")==0||strcmp(argv[i],"-C")==0)
					{
						model='c';
					}
				else if(strcmp(argv[i],"-w")==0||strcmp(argv[i],"-W")==0)
					{	
						model='w';
					}
				else
					{
					}
			}
			if(i==2)
				{
				addr=argv[i];
				}
				
		}

	//get_statisticnum(model,*addr);
	
	printf("model=%c\taddr=%s\n",model,addr);
	if((f=fopen(addr,"r"))==NULL) //如果存在这个文件
		{
           printf("没有这个文件.......");
           exit(0); //关闭所有文件，终止正在执行的程序
		}
	else//
	{
		
		//若选择的是求文件中的字符个数：
		if (model=='c')
			{
				int len=0;
				int i=0;
				while(fgets(buf,1024,f) != '\0')
					{
						len=strlen(buf);
					    i=0;
						while(i<len)
							{
								//putchar(buf[i]);
//找出英文字母
	if((buf[i]>='a'&&buf[i]<='z')||(buf[i]>='A'&&buf[i]<='Z'))
									{
										count+=1;//统计字母数目加1
									}
								i++;
							}
					}
		printf("有 %d 个英文字符\n",count );
		printf("--------------------------------------------\n");
			}
		//若选择的是求文件中的单词的个数
		else if(model=='w')
			{
				int len=0;
				int i=0;
				while(fgets(buf,1024,f) != '\0')
					{
						len=strlen(buf);
					    i=0;
						while(i<len)
							{
								//putchar(buf[i]);
								if(buf[i]==' '||(buf[i])==',')
									{
										if(buf[i-1]!=buf[i])//避免有多个空格的发生，有多个空格只当作一个分割线
											{
													//printf("char=%c\ti=%d\n",buf[i],i);
													count+=1;//统计单词数目加1
											}
											
									}
								else if((buf[i]>='a'&&buf[i]<='z')||(buf[i]>='A'&&buf[i]<='Z'))
									{
									 
									}
								i++;
							}
					}
				printf("有 %d 个单词\n",count );
				printf("--------------------------------------------\n");
			}
		else
			{
			printf("输入选择读取模式错误");
			}
	}

	fclose(f);
	
	return 0;
}