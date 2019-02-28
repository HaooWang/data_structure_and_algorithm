/**
 * Created with Clion IDEA.
 * Description: union function test
 * 
 * User: haowang
 * Date: 2019-02-23
 * Time: 16:19
 */


#include <iostream>
#include <cstdio.h>
#include "Union.h"                    //**��02 ���Ա�**//



using namespace std;

void PrintElem(LElemType_Sq e);        //���Ժ�������ӡ����

int main(int argc, char **argv) {
	SqList La, Lb;
	LElemType_Sq a[5] = {5, 2, 1, 3, 9};
	LElemType_Sq b[7] = {7, 2, 6, 9, 11, 3, 10};
	int i;

	InitList_Sq(&La);                    //��ʼ��La
	for (i = 1; i <= 5; i++)
		ListInsert_Sq(&La, i, a[i - 1]);
	InitList_Sq(&Lb);                    //��ʼ��Lb
	for (i = 1; i <= 7; i++)
		ListInsert_Sq(&Lb, i, b[i - 1]);

	cout << "La =   " << endl;                    //���La
	ListTraverse_Sq(La, PrintElem);
	cout<<'\n';

	cout << "Lb =   " << endl;                   //���Lb
	ListTraverse_Sq(Lb, PrintElem);
	cout<<'\n';

	cout<<"La = La U Lb = "<<endl;            //����±�La������
	Union(&La, Lb);
	ListTraverse_Sq(La, PrintElem);

	return 0;
}



void Union(SqList *La, SqList Lb)
{
	int La_len, Lb_len;
	int i;
	LElemType_Sq e;

	La_len = ListLength_Sq(*La);			//��˳�����
	Lb_len = ListLength_Sq(Lb);

	for(i=1; i<=Lb_len; i++)
	{
		GetElem_Sq(Lb, i, &e);				//ȡLb�е�i��Ԫ�ظ���e
		if(!LocateElem_Sq(*La, e, equal)) 	//��e����La�������
			ListInsert_Sq(La, ++La_len, e);
	}
}

Status equal(LElemType_Sq e1, LElemType_Sq e2)
{
	return e1==e2 ? TRUE : FALSE;
}
