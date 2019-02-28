/**
 * Created with Clion IDEA.
 * Description: SequenceListBasicOperations
 *  Sq = Sequence List
 *  C/Cpp
 * User: haowang
 * Date: 2019-02-23
 * Time: 15:08
 */

/*Basic Operations :
 * 1.Status InitList_Sq(SqList *L)
 * 2.void ClearList_Sq(SqList *L)
 * 3.void DestroyList_Sq(SqList *L)
 * 4.Status ListEmpty_Sq(SqList L)
 * 5.int ListLength_Sq(SqList L)
 * 6.Status GetElem_Sq(SqList L, int i, LElemType_Sq *e)
 * 7.int LocateElem_Sq(SqList L, LElemType_Sq e, Status(Compare)(LElemType_Sq, LElemType_Sq))
 * 8.Status PriorElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq *pre_e)
 * 9.Status NextElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq *next_e)
 * 10.Status ListInsert_Sq(SqList *L, int i, LElemType_Sq e)
 * 11.Status ListDelete_Sq(SqList *L, int i, LElemType_Sq *e)
 * 12.Status ListTraverse_Sq(SqList L, void(Visit)(LElemType_Sq))
 * */

#include "SequenceList.h" 				//**▲ 线性表**//

/* 宏定义 */
#define LIST_INIT_SIZE 100				//顺序表存储空间的初始分配量
#define LISTINCREMENT  10				//顺序表存储空间的分配增量

Status InitList_Sq(SqList *L)
{
	/*Initialization a sequence list
	 * OK：return the first address
	 * Else：Error
	 * */
	(*L).elem = (LElemType_Sq*)malloc(LIST_INIT_SIZE*sizeof(LElemType_Sq));
	if(!(*L).elem)
		exit(OVERFLOW); 				//分配内存失败

	(*L).length = 0;					//初始化顺序表长度为0
	(*L).listsize = LIST_INIT_SIZE;		//顺序表初始内存分配量

	return OK;							//初始化成功
} //InitList_Sq


void ClearList_Sq(SqList *L)
{
	/*Clear a sequence list*/

	(*L).length = 0;
} //ClearList_Sq


Status DestroyList_Sq(SqList *L)
{
	/*DestroyList_Sq */

	free((*L).elem);

	(*L).elem = NULL;					//释放内存后置空指针
	(*L).length = 0;
	(*L).listsize = 0;

	if (!ListEmpty_Sq( *L)){
		return ERROR;
	}

	return OK;

} //DestroyList_Sq


Status ListEmpty_Sq(SqList L)
{
	/*ListEmpty_Sq*/

	return 	L.length==0 ? TRUE : FALSE;
}//ListEmpty_Sq


int ListLength_Sq(SqList L)
{
	/*ListLength_Sq*/

	return L.length;
}//ListLength_Sq


Status GetElem_Sq(SqList L, int i, LElemType_Sq *e)
{
	/*GetElem_Sq*/
	if(i<1 || i>L.length)
		return ERROR;					//i值不合法
	else
		*e = L.elem[i-1];

	return OK;
}//GetElem_Sq


int LocateElem_Sq(SqList L, LElemType_Sq e, Status(Compare)(LElemType_Sq, LElemType_Sq))
{
	/*LocateElem_Sq*/
	int i = 1;							//i的初值为第一个元素的位序

	while(i<=L.length && !Compare(e, L.elem[i-1]))
		++i;

	if(i<=L.length)
		return i;
	else
		return 0;
}//LocateElem_Sq

Status PriorElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq *pre_e)
{
	/*PriorElem_Sq*/
	int i = 1;

	if(L.elem[0]!=cur_e)				//第一个结点无前驱
	{
		while(i<L.length && L.elem[i]!=cur_e)
			++i;

		if(i<L.length)
		{
			*pre_e = L.elem[i-1];
			return OK;
		}
	}

	return ERROR;
}//PriorElem_Sq

Status NextElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq *next_e)
{
	/*NextElem_Sq*/
	int i = 0;

	while(i<L.length && L.elem[i]!=cur_e)
		++i;

	if(i<L.length-1)					//最后一个结点无后继
	{
		*next_e = L.elem[i+1];
		return OK;
	}

	return ERROR;
}//NextElem_Sq


Status ListInsert_Sq(SqList *L, int i, LElemType_Sq e)
{
	/*ListInsert_Sq*/
	LElemType_Sq *newbase;
	LElemType_Sq *p, *q;

	if(i<1 || i>(*L).length+1)
		return ERROR;					//i值不合法

	if((*L).length >= (*L).listsize)	//若存储空间已满，需开辟新空间
	{
		newbase = (LElemType_Sq*)realloc((*L).elem, ((*L).listsize+LISTINCREMENT)*sizeof(LElemType_Sq));
		if(!newbase)
			exit(OVERFLOW);

		(*L).elem = newbase;
		(*L).listsize += LISTINCREMENT;
	}

	q = &(*L).elem[i-1];				//q为插入位置

	for(p=&(*L).elem[(*L).length-1]; p>=q; --p)
		*(p+1) = *p;					//插入位置及之后的元素右移

	*q = e;								//插入e
	(*L).length++;						//表长增1

	return OK;
}//ListInsert_Sq


Status ListDelete_Sq(SqList *L, int i, LElemType_Sq *e)
{
	/*ListInsert_Sq*/
	LElemType_Sq *p, *q;

	if(i<1 || i>(*L).length)
		return ERROR;					//i值不合法

	p = &(*L).elem[i-1];				//p为被删除元素的位置
	*e = *p;
	q = (*L).elem+(*L).length-1; 		//表尾元素位置

	for(++p; p<=q; ++p)
		*(p-1) = *p;					//被删元素之后的元素左移

	(*L).length--;						//表长减1

	return OK;
}//ListInsert_Sq

Status ListTraverse_Sq(SqList L, void(Visit)(LElemType_Sq))
{
	/*ListTraverse_Sq*/
	int i;

	for(i=0; i<L.length; i++)
		Visit(L.elem[i]);

	return OK;
}//ListTraverse_Sq

void PrintElem(LElemType_Sq e) {
	std::cout << e;
}