//This work © 2022 by W192547975 is licensed under Attribution 4.0 International.
//To view a copy of this license, visit http://creativecommons.org/licenses/by/4.0/

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

