int size ,pos;
    cout<<"Enter the size of the array:";
    cin>>size;

    int a[size];
    cout<<"Enter the elements of the array:"<<endl;
    for(int i=0;i<size;++i){
        cin>>a[i];
    }

    cout<<"Enter the position to be removed: ";
    cin >>pos;

    deleteElement(a,size,pos);