/**
 * Created with Clion IDEA.
 * Description: 
 * 
 * User: haowang
 * Date: 2019-02-23
 * Time: 17:13
 */

#ifndef DATASTRUCTURECPP_MERGELIST_H
#define DATASTRUCTURECPP_MERGELIST_H

#include <stdlib.h>
#include "../Union/SequenceList.h"		//**��02 ���Ա�**//


/* ˳���鲢�����б� */
void MergeSqList_1(SqList La, SqList Lb, SqList *Lc);
/*��������������������������������������������
��(01)�㷨2.2����C=A+B��A,B,C��Ϊ�ǵݼ����� ��
��������������������������������������������*/

void MergeSqList_2(SqList La, SqList Lb, SqList *Lc);
/*��������������������������������������������
��(02)�㷨2.7����C=A+B��A,B,C��Ϊ�ǵݼ����� ��
��������������������������������������������*/



#endif //DATASTRUCTURECPP_MERGELIST_H
