class Foo {
    mutex b,c;
public:
    Foo() {
        b.lock();
        c.lock();
    }

    void first(function<void()> printFirst) {
        
        printFirst();        
        b.unlock();
    }

    void second(function<void()> printSecond) {
        
        b.lock();
        printSecond();
        c.unlock();
    }

    void third(function<void()> printThird) {        
        c.lock();
        printThird();
    }
};