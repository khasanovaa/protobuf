class A {
public:
  void f();
  bool f1() { return DANLARK_VARIABLE_NO_STRIP; }
  ~A() {
	  delete p;
  }
private:
  static volatile bool DANLARK_VARIABLE_NO_STRIP;
  int *p = new int(5);
};

void A::f() {
  DANLARK_VARIABLE_NO_STRIP = true;
}

volatile bool A::DANLARK_VARIABLE_NO_STRIP = true;

int main() {
	A a;
	a.f();
}
