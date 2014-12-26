/*
 * Reference are less powerful than pointer
 * 1)Must initialized when declared.
 * 2)Once initialized, it cannot reference to another obj.
 * 3)Cannot be null.
 *
 * But, it safer and easier to use.
 *
 * There are few places like copy constructor argument where
 *		pointer cannot be used.Reference must be used pass the 
 *		argument in copy constructor. Similarly reference must
 *		be used for overloading some operator like ++.
 */

#include<iostream>
using namespace std;

int& func(){
	static int x =10;
	return x;
}

/*
 * 调用时要传入int&对象,不能给int对象.
 * 不然会报下面的错误
 * "invalid initialization of non-const reference 
 * of type ‘int&’ from an rvalue of type ‘int’"
 */
int func2(int &x){
	return x;
}


int &func3(){
	int x =10;
	return x;
}

/*
 * the reference to pointer....
 * wasteful
 */
void swap(char *& s,char *& p){
	char * tmp = s;
	s = p;
	p = tmp;
}

int main(){
	func() = 19;
	cout<<func()<<endl;

	int a = 10;
	int &b = a;
	cout<<func2(a)<<endl;

	char *str1 = "aaa", *str2 = "bbb";
	cout<<str1<<str2<<endl;
	swap(str1,str2);
	cout<<str1<<str2<<endl;

	int x = 10;
	int *ptr = &x;
	/* cann't declare a pointer to reference
	int &*ptr1 = ptr;*/

	ptr=nullptr;
	int &ref = *ptr;
	/* cann't access memory at address 0x0
	cout<<ref<<endl;*/

	//Useless
	func3() = 3;
	cout<<func3()<<endl;
	
	return 0;
}
