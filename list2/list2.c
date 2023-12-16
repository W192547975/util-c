//This work is licensed under Attribution 4.0 International.
//To view a copy of this license,
//visit http://creativecommons.org/licenses/by/4.0/

#if 0
#error 把编译器写废了
#endif
#include	"list2.h"
#ifdef	DEBUG
#include	<stdio.h>
#endif
#include	<stdlib.h>

//查找节点 
int Llook(struct PNODES *p,
	int number,int (*func)(struct PNODES *p,int n))
{
	int n;
	for(n=0;p->pthis!=NULL;n++)//检索（从0开始） 
	{
		if(n==number)return -1;//成功找到 
		if(func!=NULL&&func(p,n))continue;//调用处理函数 
		p->plast=p->pthis;//调整 
		p->pthis=p->pthis->next;
	}
	return n;//返回循环次数，此时p在最后一项上 
}

//添加节点 
list_exits Ladd(struct PNODES *p,int number)
{
	static int t=0;
	if(number<0)return t;
	if(number==0)t=0;
	struct NODE *n=(struct NODE *)malloc(sizeof(struct NODE));
	if(n!=NULL)
	{
		n->value=NULL;
		if(p->plast!=NULL)p->plast->next=n;//处理前一个节点 
		n->next=p->pthis;//处理后一个节点 
		p->pthis=n;
		t++;
	}
	return 1;
}

//删除节点 
int Ldelete(struct PNODES *p,int nothing)
{
	struct NODE *next=
		p->pthis==NULL?NULL:p->pthis->next;
	if(p->plast!=NULL)
		p->plast->next=next;//处理前一个节点 
	free(p->pthis);
	p->pthis=next;//处理后一个节点 
	return 1;
}

