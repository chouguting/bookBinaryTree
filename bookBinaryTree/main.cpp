#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

struct book
{
	char* bookName;  //書名當成 key 來比較大小
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






//比較int資料大小
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


//比較float資料大小
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
	cout<< "書名: "<<a.bookName<< "\t作者: " << a.authors<< "\t價錢: "<<a.price<<endl;
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

	setBookData(item, "精通光學辨識技術：應用ABBYY FineReader 11 OCR", "黃敦義", 371);
	printFun(item);
	insertNodeTP(rootPtr, item);

	setBookData(item, "VISUAL FORTRAN程式設計與開發", "張嘉強、陳鴻智", 400);
	printFun(item);
	insertNodeTP(rootPtr, item);

	setBookData(item, "程式設計－使用C++", "黃建庭", 420);
	printFun(item);
	insertNodeTP(rootPtr, item);

	setBookData(item, "資料庫系統－MTA認證影音教學", "李春雄", 336);
	printFun(item);
	insertNodeTP(rootPtr, item);

	setBookData(item, "輕鬆搞定Google雲端技術：Maps.Android.App Engine.Cloud SQL與電子商務API實例解析", "陳世興", 560);
	printFun(item);
	insertNodeTP(rootPtr, item);

	setBookData(item, "人工智慧：智慧型系統導論(第三版) ", "李聯旺 廖珗洲 謝政勳", 590);
	printFun(item);
	insertNodeTP(rootPtr, item);

	setBookData(item, "電腦網路概論(第二版)", "陳雲龍", 420);
	printFun(item);
	insertNodeTP(rootPtr, item);

	setBookData(item, "網際網路與電子商務(第三版)", "朱正忠", 450);
	printFun(item);
	insertNodeTP(rootPtr, item);

	setBookData(item, "資料庫系統理論－使用SQL Server 2008", "李春雄", 650);
	printFun(item);
	insertNodeTP(rootPtr, item);

	setBookData(item, "動畫圖解資料庫系統理論－使用Access 2010實作(第二版)", "李春雄", 600);
	printFun(item);
	insertNodeTP(rootPtr, item);

	////////////////////
	// test duplicate data
	setBookData(item, "精通光學辨識技術：應用ABBYY FineReader 11 OCR", "黃敦義", 371);
	printFun(item);
	insertNodeTP(rootPtr, item);

	setBookData(item, "VISUAL FORTRAN程式設計與開發", "張嘉強、陳鴻智", 400);
	printFun(item);
	insertNodeTP(rootPtr, item);

	setBookData(item, "程式設計－使用C++", "黃建庭", 420);
	printFun(item);
	insertNodeTP(rootPtr, item);

	setBookData(item, "資料庫系統－MTA認證影音教學", "李春雄", 336);
	printFun(item);
	insertNodeTP(rootPtr, item);

	setBookData(item, "輕鬆搞定Google雲端技術：Maps.Android.App Engine.Cloud SQL與電子商務API實例解析", "陳世興", 560);
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
		cout << "\n1.新增資料\n2.排序\n3.離開";
		cout << "input your operation:";
		cin >> operation;
		getchar();
		if (operation == 1)
		{
			book insertBook;
			insertBook.bookName = new char[500];
			insertBook.authors = new char[500];

			cout << "要insert的書名:";
			fgets(insertBook.bookName, 500, stdin);
			strtok(insertBook.bookName, "\r\n");
			cout << "要insert的書的作者:";
			fgets(insertBook.authors, 500, stdin);
			strtok(insertBook.authors, "\r\n");

			cout << "要insert的書的價錢:";
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
 測資:
1
精通光學辨識技術：應用ABBYY FineReader 11 OCR
黃敦義
371
1
VISUAL FORTRAN程式設計與開發
張嘉強、陳鴻智
400
1
程式設計－使用C++
黃建庭
420
1
資料庫系統－MTA認證影音教學
李春雄
336
1
輕鬆搞定Google雲端技術：Maps.Android.App Engine.Cloud SQL與電子商務API實例解析
陳世興
560
1
人工智慧：智慧型系統導論(第三版)
李聯旺 廖珗洲 謝政勳
590
1
電腦網路概論(第二版)
陳雲龍
420
1
網際網路與電子商務(第三版)
朱正忠
450
1
資料庫系統理論－使用SQL Server 2008
李春雄
650
1
動畫圖解資料庫系統理論－使用Access 2010實作(第二版)
李春雄
600
 */