//This work is licensed under Attribution 4.0 International.
//To view a copy of this license,
//visit http://creativecommons.org/licenses/by/4.0/

#if 0
#error 把编译器写废了
#endif
#include	"list.h"
#ifdef	DEBUG
#include	<stdio.h>
#endif
#include	<stdlib.h>
#include	<assert.h>

struct PNODES {
	struct NODE *pthis;
	struct NODE *plast; 
};
typedef enum {
	LE_SUCCESS,
//	LE_FAILURE,
	LE_NOT_FOUND,
	LE_EMPTY
}list_exits;

//查找节点的指针 
static list_exits node_find(struct NODE *root,
	int number,struct PNODES *pnode)
{
	assert(pnode!=NULL);//help debug
	pnode->pthis=root;//初始化 
	pnode->plast=NULL;
	int n;
	
	if(pnode->pthis==NULL)return LE_EMPTY;//处理空链表 
	for(n=0;n!=number;n++)//检索（从0开始） 
	{
		if(pnode->pthis->next==NULL)//到达列表末尾 
			if(number<0)return LE_SUCCESS;//返回最后一项 
			else return LE_NOT_FOUND;
		pnode->plast=pnode->pthis;//指针调整 
		pnode->pthis=pnode->pthis->next;
	}
	return LE_SUCCESS;
}

//查找节点 
void **node_look(struct NODE *root,int number)
{
	struct PNODES p;
	list_exits f;
	f=node_find(root,number,&p);
	if(f==LE_SUCCESS)return &p.pthis->value;
	return NULL;
}

//添加节点 
int node_add(struct NODE **root,int number,void *value)
{
	struct PNODES p;
	list_exits f;
	f=node_find(*root,number,&p);
	if(f==LE_NOT_FOUND||number<0)//超出范围就追加 
	{
		p.plast=p.pthis;
		p.pthis=NULL;
	}
	struct NODE *n=(struct NODE *)malloc(sizeof(struct NODE));
	if(n==NULL)return 0;//报错 
	if(f==LE_EMPTY||number==0)*root=n;//处理前一个节点 
	else p.plast->next=n;
	n->next=p.pthis;//处理后一个节点 
	n->value=value;//处理内容 
	return 1;
}

//删除节点 
int node_delete(struct NODE **root,int number)
{
	struct PNODES p;
	list_exits f;
	f=node_find(*root,number,&p);
	if(f!=LE_SUCCESS)return 0;
	if(number==0)*root=p.pthis->next;//处理前一个节点 
	else p.plast->next=p.pthis->next;
	free(p.pthis);
	return 1;
}

//新建列表 
struct NODE *list_add(void)
{
	return NULL;
}

//删除列表 
void list_delete(struct NODE *root)
{
	struct PNODES p;
	p.pthis=root;//初始化 
	p.plast=NULL;
	
	if(root==NULL)return;//空列表 
	do
	{
		p.plast=p.pthis;//推进 
		p.pthis=p.pthis->next;
		free(p.plast);//删除节点 
	}while(p.pthis!=NULL);
}

#ifdef	DEBUG
#define	DATA_LENTH	10
int main(void)
{
	struct NODE *list;
	int n=0,m=0,*p,**pp;
	int data[DATA_LENTH];
	while(1)
	{
		printf("1.nl,2.na,3.nd,4.la,5.ld\n>>>");
		scanf("%d",&n);
		while(getchar()!='\n');
		switch(n)
		{
			case 1:
				printf("number:");
				scanf("%d",&n);
				pp=(int **)node_look(list,n);
				if(pp==NULL)
				{
					printf("NULL(pp)!\n");
					break;
				}
				p=*pp;
				if(p==NULL)printf("NULL(p)!\n");
				else printf("data:%d\n",*p);
				break;
			case 2:
				printf("number:");
				scanf("%d",&n);
				printf("data:");
				scanf("%d",&m);
				printf("%d\n",node_add(&list,n,data+m));
				break;
			case 3:
				printf("number:");
				scanf("%d",&n);
				printf("%d\n",node_delete(&list,n));
				break;
			case 4:
				list=list_add();
				printf("OK");
				break;
			case 5:
				list_delete(list);
				printf("OK");
				break;
			case 6:
				for(p=data;p<data+DATA_LENTH;p++)
				{
					printf("%d\n",*p);
				}
				break;
			case 7:
				printf("number:");
				scanf("%d",&n);
				printf("data:");
				scanf("%d",&m);
				data[n]=m;
				break;
			default:
				printf("exit?type:0\n>>>");
				scanf("%d",&n);
				while(getchar()!='\n');
				if(n==0)goto exit;
				break;
		}
		while(getchar()!='\n');
	}
	exit:
	system("pause");
	return EXIT_SUCCESS;
}
#endif
