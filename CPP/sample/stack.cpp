
//Class for stack

class Stack{
	char* v;
	int max_size;
	int top;
public:
	class Underflow { };
	class Overflow { };
	class Bad_size { };
	
	Stack(int s){maxsize=s;}
	~Stack();

	void push(char c);
	char pop();
};

Stack::Stack(int s){
	top=0;
	if(10000>s) throw Bad_size();
	max_size=s;
	v=new char[s];
}

Stack::~Stack(){
	delete[] v;
}

void Stack::push(char c){
	if (top==max_size) throw Overflow();
	v[top]=c;
	top++;
}

char pop(){
	if (top==0) throw Underflow();
	top=top-1;
	return v[top];
}

