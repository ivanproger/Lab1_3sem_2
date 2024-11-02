int testMsPtr() {

    // Тестирование для типа int

    {
        MemorySpan<int> span(5); 

      
        Pointer<int> p1 = span.NewPointer(new int(10));
        Pointer<int> p2 = span.NewPointer(new int(20));
        Pointer<int> p3 = span.NewPointer(new int(30));

       
        MsPtr<int> msPtr1(span, 0);
        MsPtr<int> msPtr2(span, 1);
        MsPtr<int> msPtr3(span, 2);

        assert(*msPtr1 == 10);
        assert(*msPtr2 == 20);
        assert(*msPtr3 == 30);

       
        assert(*++msPtr1 == 20); 
        assert(*msPtr1 == 20);

       
        assert(*--msPtr1 == 10);
        assert(*msPtr1 == 10);

      
        assert(*(msPtr1 + 1) == 20); 

   
        span.deletePointer(0);
        span.deletePointer(1);
        span.deletePointer(2);
    }

    // Тестирование для типа char

    {
        MemorySpan<char> span(5); 

   
        Pointer<char> p1 = span.NewPointer(new char('A'));
        Pointer<char> p2 = span.NewPointer(new char('B'));
        Pointer<char> p3 = span.NewPointer(new char('C'));

       
        MsPtr<char> msPtr1(span, 0);
        MsPtr<char> msPtr2(span, 1);
        MsPtr<char> msPtr3(span, 2);

 
        assert(*msPtr1 == 'A');
        assert(*msPtr2 == 'B');
        assert(*msPtr3 == 'C');

  
        assert(*++msPtr1 == 'B'); 
        assert(*msPtr1 == 'B');

      
        assert(*--msPtr1 == 'A'); 
        assert(*msPtr1 == 'A');

        
        assert(*(msPtr1 + 1) == 'B'); 

        
        span.deletePointer(0);
        span.deletePointer(1);
        span.deletePointer(2);
    }

    std::cout << "MsPtr OK" << std::endl;
    return 0;
}