
void testMemorySpan() {

    //int:

    MemorySpan<int> intSpan(5);

    int* num1 = new int(10);
    Pointer<int> p1 = intSpan.NewPointer(num1);
    assert(p1.getValue() == 10);

    int* num2 = new int(20);
    Pointer<int> p2 = intSpan.NewPointer(num2);
    assert(p2.getValue() == 20);

    int* num3 = new int(30);
    Pointer<int> p3 = intSpan.NewPointer(num3);
    assert(p3.getValue() == 30);

    assert(*intSpan.getElement(0) == 10);
    assert(*intSpan.getElement(1) == 20);
    assert(*intSpan.getElement(2) == 30);

    assert(intSpan.getCounter(0) == 1);
    assert(intSpan.getCounter(1) == 1);
    assert(intSpan.getCounter(2) == 1);

    Pointer<int> p4 = intSpan.NewPointer(num1);
    assert(p4.getValue() == 10);
    assert(intSpan.getCounter(0) == 2);

    p1.~Pointer();
    assert(intSpan.getCounter(0) == 1);

    p2.~Pointer();
    assert(intSpan.getCounter(1) == 0);

    assert(*intSpan.getElement(2) == 30);

    p3.~Pointer();
    assert(intSpan.getCounter(2) == 0);

    int* num4 = new int(40);
    Pointer<int> p5 = intSpan.NewPointer(num4);
    assert(p5.getValue() == 40);
    
    assert(intSpan.getCounter(2) == 1);

    p5.~Pointer();

    //char:

    MemorySpan<char> charSpan(5);
    char* char1 = new char('e');
    Pointer<char> c = charSpan.NewPointer(char1);
    assert(c.getValue() == 'e');


    std::cout << "MemorySpan OK" << std::endl;

}
