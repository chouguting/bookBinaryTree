#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

struct book
{
	char* bookName;  //�ѦW�� key �Ӥ���j�p
	char* authors;
	int price;
};


template <typename T>
struct treeNodeTP
{
	T data;
	treeNodeTP* leftPtr;
	treeNodeTP* rightPtr;
};






//���int��Ƥj�p
int compareFun(int a, int b)
{
	if(a>b)
	{
		return -1;
	}else if(a<b)
	{
		return  1;
	}else
	{
		return 0;
	}
}


//���float��Ƥj�p
int compareFun(float a, float b)
{
	if (a > b)
	{
		return -1;
	}
	else if (a < b)
	{
		return  1;
	}
	else
	{
		return 0;
	}
}


int compareFun(book a, book b)
{
	if(strcmp(a.bookName,b.bookName)>0)
	{
		return -1;
	}else if (strcmp(a.bookName, b.bookName) < 0)
	{
		return 1;
	}else
	{
		return 0;
	}
}


inline void printFun(book a)
{
	cout<< "�ѦW: "<<a.bookName<< "\t�@��: " << a.authors<< "\t����: "<<a.price<<endl;
}
																	

void printFun(int a)
{
	cout << a << "  ";
}
void printFun(float a)
{
	cout << a << "  ";
}



template <typename T>
void insertNodeTP(treeNodeTP<T>* & tree, T input)
{
	
	
	if (tree == nullptr)
	{
		
		tree = (treeNodeTP<T>*)malloc(sizeof(treeNodeTP<T>));
		tree->data = input;
		tree->leftPtr = nullptr;
		tree->rightPtr = nullptr;
	}else
	{
		
		if(compareFun(input, tree->data)==-1)
		{
			insertNodeTP(tree->rightPtr, input);
		}else if(compareFun(input, tree->data) == 1)
		{
			insertNodeTP(tree->leftPtr, input);
		}else
		{
			cout << "XX   " ;
		}
	}
}



template<typename T>
void inOrderTP(treeNodeTP<T>* tree)
{
	if (tree != NULL) {
		inOrderTP(tree->leftPtr);
		printFun(tree->data);
		inOrderTP(tree->rightPtr);
	}
}

template<typename T>
void preOrderTP(treeNodeTP<T>* tree)
{
	if (tree != NULL) {
		printFun(tree->data);
		preOrderTP(tree->leftPtr);
		preOrderTP(tree->rightPtr);
	}
}



template<typename T>
void postOrderTP(treeNodeTP<T>* tree)
{
	if (tree != NULL) {	
		postOrderTP(tree->leftPtr);
		postOrderTP(tree->rightPtr);
		printFun(tree->data);
	}
}


//test int btree
void testTemplateInt()
{
	treeNodeTP<int>* rootPtr = NULL;
	int i, item;
	/* insert random values between 1 and 15 in the tree */
	printf("The numbers being placed in the tree are:\n");
	for (i = 1; i <= 15; i++) {
		item = rand() % 15;
		std::cout << "  " << item ;
		insertNodeTP(rootPtr, item);
	}
	/* traverse the tree preOrder */
	printf("\n\nThe preOrder traversal is:\n");
	preOrderTP(rootPtr);
	/* traverse the tree inOrder */
	printf("\n\nThe inOrder traversal is:\n");
	inOrderTP(rootPtr);
	/* traverse the tree postOrder */
	printf("\n\nThe postOrder traversal is:\n");
	postOrderTP(rootPtr);
	std::cout << endl << endl;
}


//test int btree
void testTemplateFloat()
{
	treeNodeTP<float>* rootPtr = NULL;
	int i;
	float item;
	/* insert random values between 1 and 15 in the tree */
	printf("The numbers being placed in the tree are:\n");
	for (i = 1; i <= 15; i++) {
		item = 1.0 + (float)(rand() % 8) * 0.01f;
		std::cout << "  " << item ;
		insertNodeTP(rootPtr, item);
	}
	/* traverse the tree preOrder */
	printf("\n\nThe preOrder traversal is:\n");
	preOrderTP(rootPtr);
	/* traverse the tree inOrder */
	printf("\n\nThe inOrder traversal is:\n");
	inOrderTP(rootPtr);
	/* traverse the tree postOrder */
	printf("\n\nThe postOrder traversal is:\n");
	postOrderTP(rootPtr);
	std::cout << endl << endl;
}

void setBookData(book& item, const char* bookName, const char* authors, int price)
{
	item.bookName = (char*)bookName;
	item.authors = (char*)authors;
	item.price = price;
}


//test int btree
void testTemplateBoot()
{
	treeNodeTP<book>* rootPtr = NULL;
	book item;
	/* insert random values between 1 and 15 in the tree */
	printf("The books being placed in the tree are:\n");

	setBookData(item, "��q���ǿ��ѧ޳N�G����ABBYY FineReader 11 OCR", "�����q", 371);
	printFun(item);
	insertNodeTP(rootPtr, item);

	setBookData(item, "VISUAL FORTRAN�{���]�p�P�}�o", "�i�űj�B���E��", 400);
	printFun(item);
	insertNodeTP(rootPtr, item);

	setBookData(item, "�{���]�p�Шϥ�C++", "���خx", 420);
	printFun(item);
	insertNodeTP(rootPtr, item);

	setBookData(item, "��Ʈw�t�Ρ�MTA�{�Ҽv���о�", "���K��", 336);
	printFun(item);
	insertNodeTP(rootPtr, item);

	setBookData(item, "���P�d�wGoogle���ݧ޳N�GMaps.Android.App Engine.Cloud SQL�P�q�l�Ӱ�API��ҸѪR", "���@��", 560);
	printFun(item);
	insertNodeTP(rootPtr, item);

	setBookData(item, "�H�u���z�G���z���t�ξɽ�(�ĤT��) ", "���p�� ��ҹ�w �¬F��", 590);
	printFun(item);
	insertNodeTP(rootPtr, item);

	setBookData(item, "�q����������(�ĤG��)", "�����s", 420);
	printFun(item);
	insertNodeTP(rootPtr, item);

	setBookData(item, "���ں����P�q�l�Ӱ�(�ĤT��)", "������", 450);
	printFun(item);
	insertNodeTP(rootPtr, item);

	setBookData(item, "��Ʈw�t�βz�סШϥ�SQL Server 2008", "���K��", 650);
	printFun(item);
	insertNodeTP(rootPtr, item);

	setBookData(item, "�ʵe�ϸѸ�Ʈw�t�βz�סШϥ�Access 2010��@(�ĤG��)", "���K��", 600);
	printFun(item);
	insertNodeTP(rootPtr, item);

	////////////////////
	// test duplicate data
	setBookData(item, "��q���ǿ��ѧ޳N�G����ABBYY FineReader 11 OCR", "�����q", 371);
	printFun(item);
	insertNodeTP(rootPtr, item);

	setBookData(item, "VISUAL FORTRAN�{���]�p�P�}�o", "�i�űj�B���E��", 400);
	printFun(item);
	insertNodeTP(rootPtr, item);

	setBookData(item, "�{���]�p�Шϥ�C++", "���خx", 420);
	printFun(item);
	insertNodeTP(rootPtr, item);

	setBookData(item, "��Ʈw�t�Ρ�MTA�{�Ҽv���о�", "���K��", 336);
	printFun(item);
	insertNodeTP(rootPtr, item);

	setBookData(item, "���P�d�wGoogle���ݧ޳N�GMaps.Android.App Engine.Cloud SQL�P�q�l�Ӱ�API��ҸѪR", "���@��", 560);
	printFun(item);
	insertNodeTP(rootPtr, item);



	/* traverse the tree preOrder */
	printf("\n\nThe preOrder traversal is:\n");
	preOrderTP(rootPtr);
	/* traverse the tree inOrder */
	printf("\n\nThe inOrder traversal is:\n");
	inOrderTP(rootPtr);
	/* traverse the tree postOrder */
	printf("\n\nThe postOrder traversal is:\n");
	postOrderTP(rootPtr);
	std::cout << endl << endl;
}

template<typename T>
void doStuff(treeNodeTP<T>* &rootNode)
{
	int operation;
	while (true)
	{
		cout << "\n1.�s�W���\n2.�Ƨ�\n3.���}";
		cout << "input your operation:";
		cin >> operation;
		getchar();
		if (operation == 1)
		{
			book insertBook;
			insertBook.bookName = new char[500];
			insertBook.authors = new char[500];

			cout << "�ninsert���ѦW:";
			fgets(insertBook.bookName, 500, stdin);
			strtok(insertBook.bookName, "\r\n");
			cout << "�ninsert���Ѫ��@��:";
			fgets(insertBook.authors, 500, stdin);
			strtok(insertBook.authors, "\r\n");

			cout << "�ninsert���Ѫ�����:";
			cin >> insertBook.price;
			getchar();
			insertNodeTP(rootNode, insertBook);


		}
		else if (operation == 2)
		{
			cout << "\n\tin order:" << endl;
			inOrderTP(rootNode);
			cout << "\n\tpre order:" << endl;
			preOrderTP(rootNode);
			cout << "\n\tpost order:" << endl;
			postOrderTP(rootNode);
			cout << endl;
		}
		else if (operation == 3)
		{
			break;
		}

	}
}

int main()
{
	treeNodeTP<book>* rootNode = nullptr;
	testTemplateInt();
	system("pause");
	system("cls");
	testTemplateFloat();
	system("pause");
	system("cls");
	testTemplateBoot();
	system("pause");
	system("cls");
	doStuff(rootNode);
	
}


/*
 ����:
1
��q���ǿ��ѧ޳N�G����ABBYY FineReader 11 OCR
�����q
371
1
VISUAL FORTRAN�{���]�p�P�}�o
�i�űj�B���E��
400
1
�{���]�p�Шϥ�C++
���خx
420
1
��Ʈw�t�Ρ�MTA�{�Ҽv���о�
���K��
336
1
���P�d�wGoogle���ݧ޳N�GMaps.Android.App Engine.Cloud SQL�P�q�l�Ӱ�API��ҸѪR
���@��
560
1
�H�u���z�G���z���t�ξɽ�(�ĤT��)
���p�� ��ҹ�w �¬F��
590
1
�q����������(�ĤG��)
�����s
420
1
���ں����P�q�l�Ӱ�(�ĤT��)
������
450
1
��Ʈw�t�βz�סШϥ�SQL Server 2008
���K��
650
1
�ʵe�ϸѸ�Ʈw�t�βz�סШϥ�Access 2010��@(�ĤG��)
���K��
600
 */