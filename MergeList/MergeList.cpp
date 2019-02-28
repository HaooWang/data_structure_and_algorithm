/**
 * Created with Clion IDEA.
 * Description: 
 * 
 * User: haowang
 * Date: 2019-02-23
 * Time: 17:19
 */

#ifndef MERGELIST_CPP
#define MERGELIST_CPP

#include "MergeList.h"					//**��02 ���Ա�**//

/*?????
? �㷨2.2?
?????*/
void MergeSqList_1(SqList La, SqList Lb, SqList *Lc)	//����˳��������кϲ�
{
	int La_len, Lb_len;
	int i, j, k;
	LElemType_Sq ai, bj;

	i = j = 1;
	k = 0;

	InitList_Sq(Lc);					//��ʼ��Lc
	La_len = ListLength_Sq(La);			//��ȡLa��Lb����
	Lb_len = ListLength_Sq(Lb);

	while(i<=La_len && j<=Lb_len)		//La��Lb��δɨ����
	{
		GetElem_Sq(La, i, &ai);
		GetElem_Sq(Lb, j, &bj);

		if(ai<=bj)
		{
			ListInsert_Sq(Lc, ++k, ai);
			i++;
		}
		else
		{
			ListInsert_Sq(Lc, ++k, bj);
			j++;
		}
	}

	while(i<=La_len)					//��La��δɨ����
	{
		GetElem_Sq(La, i++, &ai);
		ListInsert_Sq(Lc, ++k, ai);
	}

	while(j<=Lb_len)					//��Lb��δɨ����
	{
		GetElem_Sq(Lb, j++, &bj);
		ListInsert_Sq(Lc, ++k, bj);
	}
}

/*?????
? �㷨2.7?
?????*/
void MergeSqList_2(SqList La, SqList Lb, SqList *Lc)
{
	LElemType_Sq *pa, *pb, *pc;
	LElemType_Sq *pa_last, *pb_last;

	pa = La.elem;						//ָ��La��һ��Ԫ��
	pb = Lb.elem;						//ָ��Lb��һ��Ԫ��

	//����InitList_Sq����Lc
	(*Lc).listsize = (*Lc).length = La.length + Lb.length;
	pc = (*Lc).elem = (LElemType_Sq *)malloc((*Lc).listsize*sizeof(LElemType_Sq));
	if(!pc)
		exit(OVERFLOW);

	pa_last = La.elem + La.length - 1;	//ָ��La���һ��Ԫ��
	pb_last = Lb.elem + Lb.length - 1;	//ָ��Lb���һ��Ԫ��

	while(pa<=pa_last && pb<=pb_last) 	//La��Lb��δɨ����
	{
		if(*pa <= *pb)
			*pc++ = *pa++;
		else
			*pc++ = *pb++;
	}

	while(pa <= pa_last)				//��Laδɨ����
		*pc++ = *pa++;					//����La��ʣ��Ԫ��

	while(pb <= pb_last)				//��Lbδɨ����
		*pc++ = *pb++;					//����Lb��ʣ��Ԫ��
}

#endif
