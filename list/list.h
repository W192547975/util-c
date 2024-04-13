/* Copyright 2022 W192547975
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
If you want to delete a node or a list,
you should delete things that in this node or in this list at first.
You don't need to use function list_add.
Use typedef when you have a complex type!
*/

#ifndef	_LIST_H
#define	_LIST_H

#define	LIST_LAST	-1

struct NODE {
	void *value;
	struct NODE *next;
};

#ifdef	__cplusplus
extern "C"{
#endif

void **node_look(struct NODE *root,int number);
int node_add(struct NODE **root,int number,void *value);
int node_delete(struct NODE **root,int number);
struct NODE *list_add(void);
void list_delete(struct NODE *root);

#ifdef	__cplusplus
}
#endif

#define	TYPELIST(name,type)	\
	type **name##$node_look(struct NODE *root,int number)	\
		{return (type **)node_look(root,number);}	\
	int name##$node_add(struct NODE ** root,int number,type *value)	\
		{return node_add(root,number,value);}

#endif	//!defined(_LIST_H)

