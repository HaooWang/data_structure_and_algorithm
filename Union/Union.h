/**
 * Created with Clion IDEA.
 * Description: 
 * 
 * User: haowang
 * Date: 2019-02-23
 * Time: 16:14
 */

#ifndef DATASTRUCTURECPP_UNION_H
#define DATASTRUCTURECPP_UNION_H


#include "SequenceList.h"	//** 线性表**//

/* 并集函数列表 */
void Union(SqList *La, SqList Lb);
/*━━━━━━━━━━━┓
┃(01)算法2.1：A=A∪B。 ┃
┗━━━━━━━━━━━*/

Status equal(LElemType_Sq e1, LElemType_Sq e2);
/*━━━━━━━━━━━━┓
┃(02)判断两元素是否相等。┃
┗━━━━━━━━━━━━*/


#endif //DATASTRUCTURECPP_UNION_H
