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
#include "../Union/SequenceList.h"		//**▲02 线性表**//


/* 顺序表归并函数列表 */
void MergeSqList_1(SqList La, SqList Lb, SqList *Lc);
/*━━━━━━━━━━━━━━━━━━━━━┓
┃(01)算法2.2：求C=A+B，A,B,C均为非递减序列 ┃
┗━━━━━━━━━━━━━━━━━━━━━*/

void MergeSqList_2(SqList La, SqList Lb, SqList *Lc);
/*━━━━━━━━━━━━━━━━━━━━━┓
┃(02)算法2.7：求C=A+B，A,B,C均为非递减序列 ┃
┗━━━━━━━━━━━━━━━━━━━━━*/



#endif //DATASTRUCTURECPP_MERGELIST_H
