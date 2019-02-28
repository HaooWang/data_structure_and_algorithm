/**
 * Created with Clion IDEA.
 * Description: 
 * 
 * User: haowang
 * Date: 2019-02-23
 * Time: 17:20
 */

#include <iostream>
#include "MergeList.h"                //**��02 ���Ա�**//
#include "../Union/SequenceList.h"

using namespace std;

void PrintElem(LElemType_Sq e);            //���Ժ�������ӡ����

int main(int argc, char **argv) {
	SqList La, Lb, Lc1, Lc2;
	LElemType_Sq a[4] = {3, 5, 8, 11};
	LElemType_Sq b[7] = {2, 6, 8, 9, 11, 15, 20};
	int i;

	InitList_Sq(&La);                    //��ʼ��La
	for (i = 1; i <= 4; i++)
		ListInsert_Sq(&La, i, a[i - 1]);
	InitList_Sq(&Lb);                    //��ʼ��Lb
	for (i = 1; i <= 7; i++)
		ListInsert_Sq(&Lb, i, b[i - 1]);

	cout << "La = " << endl;                    //���La
	ListTraverse_Sq(La, PrintElem);
	cout << '\n';
	cout << "Lb = " << endl;                    //���Lb
	ListTraverse_Sq(Lb, PrintElem);
	cout << '\n';

	MergeSqList_1(La, Lb, &Lc1);        //�ϲ�A��B,�㷨2.6
	cout << "la U lb = Lc1  " << endl;        //���Lc1
	ListTraverse_Sq(Lc1, PrintElem);
	cout << '\n';

	MergeSqList_2(La, Lb, &Lc2);        //�ϲ�A��B,�㷨2.7
	cout << "la U lb = Lc2" << endl;      //���Lc2
	ListTraverse_Sq(Lc2, PrintElem);
	cout << '\n';

	/*Destroy list la��lb and lc*/
	if(DestroyList_Sq(&La)){
		cout<<"La list has destroied."<<endl;
	}
	if(DestroyList_Sq(&Lb)){
		cout<<"Lb list has destroied."<<endl;
	}
	if(DestroyList_Sq(&Lc1)){
		cout<<"Lc1 list has destroied."<<endl;
	}
	if(DestroyList_Sq(&Lc2)){
		cout<<"Lc2 list has destroied."<<endl;
	}
	return 0;
}

