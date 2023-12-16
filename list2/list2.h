//This work is licensed under Attribution 4.0 International.
//To view a copy of this license,
//visit http://creativecommons.org/licenses/by/4.0/

/*
Remember:
We won't delete the data!
Never use NULL on "p" when it works!
*/

#ifndef	_LIST2_H
#define	_LIST2_H

#ifndef	_LIST_H
#define	LIST_LAST	-1
struct NODE {
	void *value;
	struct NODE *next;
};
#endif

struct PNODES {
	struct NODE *pthis;
	struct NODE *plast; 
};

#ifdef	__cplusplus
extern "C"{
#endif

int Llook(struct PNODES *p,
	int number,
	int (*func)(struct PNODES *p,int n));
list_exits Ladd(struct PNODES *p,int number);
int Ldelete(struct PNODES *p,int nothing);

#ifdef	__cplusplus
}
#endif

#define	LNODE(p,number)	(Llook(p,number)>=0?	\
	(Ladd(p,0),Ladd(NULL,-1)!=0?(p)->pthis::NULL)	\
	:p->pthis)

#endif	//!defined(_LIST2_H)

