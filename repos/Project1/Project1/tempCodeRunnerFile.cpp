float WaitTime = 0;
    for (int i = 0; i < l.n; i++)
    {
        WaitTime += gantt.a[i].Txh - l1.a[i].Txh;
    }
    cout << "\n"
         << WaitTime / l1.n;