class Stack {
public:
  Stack();

  Stack(const Stack& s);
  void push(int elem);
  int pop();
  void multiPop(int N);
  bool isEmpty();
  void show();
  Stack& operator = (const Stack& s);
  ~Stack();

private:
  int* sptr;
  int ssize;
};