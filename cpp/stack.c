#include<iostream>
using namespace std;
class stack {
	int m_size;      //스택 크기
	int m_top_index; //스택 맨위의 변수
	int m_total;	 //스택 합계
	int* p;			 //스택을 동적으로 생성하는데 필요한 포인터 변수
public:
	stack();
	stack(int size);
	stack(const stack& s);
	~stack();
	void push(int data);
	int pop();
	int peek();
	void init_stack();
	int compute_total();
	int get_top_index();
	int* get_stack_pointer();
};
stack::stack() {
	cout << "인수 없는 생성자 함수 호출" << endl;
	m_size = 4;
	p = new int[m_size];
	m_top_index = 0;
	m_total = 0;
	
}
stack::stack(int size) {
	m_top_index =0;
	m_total = 0;
	cout << "인수 있는 생성자 함수 호출" << endl;
	m_size = size;
	p = new int[m_size];
	if (p == NULL) {
		cout << "에러메세지 : Memory Allocation Error" << endl;
		exit(0);
	}
}
stack::stack(const stack& s) {
	cout << "복사 생성자 함수 호출" << endl;
	m_size = s.m_size;
	m_top_index = s.m_top_index;
	m_total = s.m_total;
	p = new int[m_size];
	for (int i = 0; i < m_top_index; i++) {
		p[i] = s.p[i];
	}
}
stack::~stack() {
	cout << "소멸자 함수 호출";
	delete(p);
}
void stack::push(int data) {
	if (m_top_index >= m_size) {
		cout << "에러메세지 : Stack is full" << endl;
		return;
	}
	else {
		p[m_top_index++] = data;
	}
}
int stack::pop() {
	if (m_top_index <= 0) {
		cout << "에러메세지 : Stack is empty" << endl;
		return 0;
	}
	else {
		return p[--m_top_index];
	}
}
int stack::peek() {
	if (m_top_index <= 0) {
		cout << "에러메세지 : Stack is empty" << endl;
		return 0;
	}
	else {
		int i = m_top_index -1;
		return p[i];
	}
}
void stack::init_stack(){
	m_top_index = 0;
}
int stack::get_top_index() {
	return m_top_index;
}
int* stack::get_stack_pointer() {
	return p;
}
int stack::compute_total() {
	for (int i = 0; i < m_top_index; i++) {
		m_total = m_total + p[i];
	}
	return m_total;
}
void print_stack(stack s) {
	for (int i = 0; i < s.get_top_index(); i ++ ) {
		cout << *(s.get_stack_pointer() + i) << " ";
	}
	cout << endl;
}
int main() {
	stack s1;
	stack s2(6);
	s1.init_stack();
	s2.init_stack();
	s1.pop();
	s1.push(80);
	s1.push(70);
	s1.push(60);
	s1.push(50);
	cout << "s1 스택 맨위의 데이터는 " << s1.peek() << endl;
	s2.push(95);
	s2.push(85);
	s2.push(75);
	s2.push(65);
	s2.push(55);
	stack s3(s2);
	s3.push(70);
	s3.push(80);
	cout << "--- s1 ---" << endl;
	print_stack(s1);
	cout << endl;
	cout << "--- s2 ---" << endl;
	print_stack(s2);
	cout << endl <<endl;
	cout << "--- s3 ---" << endl;
	print_stack(s3);
	cout << endl <<endl;
	cout << "s3 스택 맨 위의 데이터는 " << s3.peek() << endl;
	cout << "s3의 합계는 " << s3.compute_total() << endl;

	return 0;
}
