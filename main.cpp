#include <iostream>

using namespace std;
class CallbackInterface {
public:
    virtual int cbiCallbackFunction(int) = 0;
};

class Callee: public CallbackInterface {
public:
    int cbiCallbackFunction(int i) {
        cout << "Callee:cbiCallbackFunction";
        return 2*i;
    }
};

class Caller {
public:
    void connectCallback(CallbackInterface *cb) {
        m_cb = cb;
    }

    void test() {
        cout << "Caller::test" << endl;
        int i = m_cb->cbiCallbackFunction(10);
        cout << "Result (20):" << i << endl;
    }

private:
    CallbackInterface *m_cb;
};

int main() {
    Caller caller;
    Callee callee;

    caller.connectCallback(&callee);

    caller.test();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
