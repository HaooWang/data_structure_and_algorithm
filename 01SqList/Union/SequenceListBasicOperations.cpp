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

#include "SequenceList.h" 				//**�� ���Ա�**//

/* �궨�� */
#define LIST_INIT_SIZE 100				//˳���洢�ռ�ĳ�ʼ������
#define LISTINCREMENT  10				//˳���洢�ռ�ķ�������

Status InitList_Sq(SqList *L)
{
	/*Initialization a sequence list
	 * OK��return the first address
	 * Else��Error
	 * */
	(*L).elem = (LElemType_Sq*)malloc(LIST_INIT_SIZE*sizeof(LElemType_Sq));
	if(!(*L).elem)
		exit(OVERFLOW); 				//�����ڴ�ʧ��

	(*L).length = 0;					//��ʼ��˳�����Ϊ0
	(*L).listsize = LIST_INIT_SIZE;		//˳����ʼ�ڴ������

	return OK;							//��ʼ���ɹ�
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

	(*L).elem = NULL;					//�ͷ��ڴ���ÿ�ָ��
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
		return ERROR;					//iֵ���Ϸ�
	else
		*e = L.elem[i-1];

	return OK;
}//GetElem_Sq


int LocateElem_Sq(SqList L, LElemType_Sq e, Status(Compare)(LElemType_Sq, LElemType_Sq))
{
	/*LocateElem_Sq*/
	int i = 1;							//i�ĳ�ֵΪ��һ��Ԫ�ص�λ��

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

	if(L.elem[0]!=cur_e)				//��һ�������ǰ��
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

	if(i<L.length-1)					//���һ������޺��
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
		return ERROR;					//iֵ���Ϸ�

	if((*L).length >= (*L).listsize)	//���洢�ռ��������迪���¿ռ�
	{
		newbase = (LElemType_Sq*)realloc((*L).elem, ((*L).listsize+LISTINCREMENT)*sizeof(LElemType_Sq));
		if(!newbase)
			exit(OVERFLOW);

		(*L).elem = newbase;
		(*L).listsize += LISTINCREMENT;
	}

	q = &(*L).elem[i-1];				//qΪ����λ��

	for(p=&(*L).elem[(*L).length-1]; p>=q; --p)
		*(p+1) = *p;					//����λ�ü�֮���Ԫ������

	*q = e;								//����e
	(*L).length++;						//����1

	return OK;
}//ListInsert_Sq


Status ListDelete_Sq(SqList *L, int i, LElemType_Sq *e)
{
	/*ListInsert_Sq*/
	LElemType_Sq *p, *q;

	if(i<1 || i>(*L).length)
		return ERROR;					//iֵ���Ϸ�

	p = &(*L).elem[i-1];				//pΪ��ɾ��Ԫ�ص�λ��
	*e = *p;
	q = (*L).elem+(*L).length-1; 		//��βԪ��λ��

	for(++p; p<=q; ++p)
		*(p-1) = *p;					//��ɾԪ��֮���Ԫ������

	(*L).length--;						//����1

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