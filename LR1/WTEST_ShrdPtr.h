void testShrdPtr() {
    ShrdPtr<int> p1(new int(5));
    assert(*p1 == 5);

    ShrdPtr<int> p2 = p1;
    assert(*p2 == 5);
    assert(p1.operator->() == p2.operator->());

    {
        ShrdPtr<int> p3 = p2;
        assert(*p3 == 5);
        assert(p2.operator->() == p3.operator->());
    }

    assert(*p1 == 5);
    assert(*p2 == 5);

    UnqPtr<int> uptr(new int(10));
    ShrdPtr<int> p4(std::move(uptr));
    assert(*p4 == 10);

    ShrdPtr<char> p5(new char('A'));
    assert(*p5 == 'A');

    ShrdPtr<char> p6 = p5;
    assert(*p6 == 'A');
    assert(p5.operator->() == p6.operator->());

    {
        ShrdPtr<char> p7 = p6;
        assert(*p7 == 'A');
        assert(p6.operator->() == p7.operator->());
    }

    assert(*p5 == 'A');
    assert(*p6 == 'A');

    UnqPtr<char> uptrChar(new char('B'));
    ShrdPtr<char> p8(std::move(uptrChar));
    assert(*p8 == 'B');

    ShrdPtr<float> p9(new float(3.14f));
    assert(*p9 == 3.14f);

    ShrdPtr<float> p10 = p9;
    assert(*p10 == 3.14f);
    assert(p9.operator->() == p10.operator->());

    {
        ShrdPtr<float> p11 = p10;
        assert(*p11 == 3.14f);
        assert(p10.operator->() == p11.operator->());
    }

    assert(*p9 == 3.14f);
    assert(*p10 == 3.14f);

    UnqPtr<float> uptrFloat(new float(2.71f));
    ShrdPtr<float> p12(std::move(uptrFloat));
    assert(*p12 == 2.71f);

    std::cout << "ShrdPtr OK" << std::endl;
}

void loadTestShrdPtr(int objectCount) {
    auto start = std::chrono::high_resolution_clock::now();

    std::vector<ShrdPtr<int>> ptrs;
    for (int i = 0; i < objectCount; ++i) {
        ptrs.emplace_back(new int(i));
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::cout << "Create " << objectCount << " objects ShrdPtr for " << duration.count() << " seconds." << std::endl;
}

void loadTestStdSharedPtr(int objectCount) {
    auto start = std::chrono::high_resolution_clock::now();

    std::vector<std::shared_ptr<int>> ptrs;
    for (int i = 0; i < objectCount; ++i) {
        ptrs.emplace_back(std::make_shared<int>(i));
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::cout << "Create " << objectCount << " objects std::shared_ptr for " << duration.count() << " seconds." << std::endl;
}