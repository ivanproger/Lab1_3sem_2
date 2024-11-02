void testUnqPtr() {
    {
        UnqPtr<int> uptr(new int(5));
        assert(*(uptr.get()) == 5);
    }

    {
        UnqPtr<int> uptr1(new int(10));
        UnqPtr<int> uptr2(std::move(uptr1));
        assert(uptr1.get() == nullptr);
        assert(*(uptr2.get()) == 10);
    }

    {
        UnqPtr<int> uptr1(new int(20));
        UnqPtr<int> uptr2;
        uptr2 = std::move(uptr1);
        assert(uptr1.get() == nullptr);
        assert(*(uptr2.get()) == 20);
    }

    {
        UnqPtr<char> uptr(new char('A'));
        assert(*(uptr.get()) == 'A');
    }

    {
        UnqPtr<char> uptr1(new char('B'));
        UnqPtr<char> uptr2(std::move(uptr1));
        assert(uptr1.get() == nullptr);
        assert(*(uptr2.get()) == 'B');
    }

    {
        UnqPtr<char> uptr1(new char('C'));
        UnqPtr<char> uptr2;
        uptr2 = std::move(uptr1);
        assert(uptr1.get() == nullptr);
        assert(*(uptr2.get()) == 'C');
    }

    {
        UnqPtr<float> uptr(new float(3.14f));
        assert(*(uptr.get()) == 3.14f);
    }

    {
        UnqPtr<float> uptr1(new float(2.71f));
        UnqPtr<float> uptr2(std::move(uptr1));
        assert(uptr1.get() == nullptr);
        assert(*(uptr2.get()) == 2.71f);
    }

    {
        UnqPtr<float> uptr1(new float(1.61f));
        UnqPtr<float> uptr2;
        uptr2 = std::move(uptr1);
        assert(uptr1.get() == nullptr);
        assert(*(uptr2.get()) == 1.61f);
    }

    std::cout << "UniqPtr OK" << std::endl;
}

void loadTestUnqPtr(int objectCount) {
    UnqPtr<int>* ptrs = new UnqPtr<int>[objectCount];
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < objectCount; ++i) {
        UnqPtr<int> p(new int(10));
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::cout << "Create " << objectCount << " objects UnqPtr for " << duration.count() << " seconds." << std::endl;

    delete[] ptrs;
}

void loadTestStdUniquePtr(int objectCount) {
    std::unique_ptr<int>* ptrs = new std::unique_ptr<int>[objectCount];
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < objectCount; ++i) {
        std::unique_ptr<int> p = std::make_unique<int>(5);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::cout << "Create " << objectCount << " objects std::unique_ptr for " << duration.count() << " seconds." << std::endl;

    delete[] ptrs;
}