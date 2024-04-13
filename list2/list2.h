/* Copyright 2023 W192547975
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

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
int Ladd(struct PNODES *p,int number);
int Ldelete(struct PNODES *p,int nothing);

#ifdef	__cplusplus
}
#endif

#define	LNODE(p,number)	(Llook(p,number)>=0?	\
	(Ladd(p,0),Ladd(NULL,-1)!=0?(p)->pthis::NULL)	\
	:p->pthis)

#endif	//!defined(_LIST2_H)

