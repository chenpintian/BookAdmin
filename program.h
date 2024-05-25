//
// Created by 陈品天 on 24-5-25.
//

void File_in_Tree(BSTree &T) // 将文件中的数据写入到二叉排序树
{
    Book e;
    fstream file;
    T=NULL;
    file.open("/Users/chenpintian/CLionProjects/BookAdmin/book.txt");
    if (!file) {
        cout << "错误！未找到文件！" << endl;
        exit(ERROR);
    }
    while (!file.eof()) {
        file >> e.id >> e.name >> e.price>> e.num;
        InsertBST(T,e);
    }
    cout << "输入 book.txt 信息完毕\n\n";
    file.close();
}

void Tree_to_Array(BSTree T,Book array[],int &n) // 二叉树的线性化处理
{
    //补充代码：实现利用先序遍历算法完成将T的数据写到数组array。已知array已分配空间，n的初始值为0。
    if (T != NULL) {
        // 将当前节点的书籍信息存入数组
        array[n]=T->data;
        n++;
        // 递归遍历左子树
        Tree_to_Array(T->lchild, array, n);
        // 递归遍历右子树
        Tree_to_Array(T->rchild, array, n);
    }
}

void Tree_out_file(BSTree T)  // 按照先序遍历将二叉排序中结点数据写回文件book.txt
{
    int n=0,i;
    Book *array=new Book[MAXSIZE];
    fstream file("/Users/chenpintian/CLionProjects/BookAdmin/book.txt", fstream::out | ios_base::trunc); // 打开时清空文件
    if (!file) {
        cout << "错误！未找到文件！" << endl;
        exit(ERROR);
    }
    Tree_to_Array(T,array,n); // 二叉排序树的数据写到数组array
    for (i=0;i<n-1;i++)
    {
        file << left << array[i].id << "\t" << left << array[i].name << "\t" << left << array[i].price<< "\t" << left << array[i].num<<endl;
    }
    file << left << array[i].id << "\t" << left << array[i].name << "\t" << left << array[i].price<< "\t" << left << array[i].num;
    file.close();
}

void PrintInfo(BSTree T) // 中序遍历
{
    if (T)
    {
        // 递归中序遍历输出左子树图书信息
        PrintInfo(T->lchild);
        cout<<left<<setw(20)<<T->data.id<<left<<setw(40)<<T->data.name<<left<<setw(15)<<T->data.price<<left<<setw(10)<<T->data.num<<endl;
        // 递归中序遍历输出右子树图书信息
        PrintInfo(T->rchild);
    }
    return;
}

void Search_book(BSTree T)
{
    // 输入图书isbn，利用二叉排序树的查找操作
    string isbn;
    cout<<"输入图书ISBN号进行查询："<<endl;
    cin>>isbn;
    BSTree p=SearchBST(T,isbn);
    if(p!=NULL){
        cout<<"书名："<<p->data.name<<endl;
        cout<<"价格："<<p->data.price<<endl;
        cout<<"库存："<<p->data.num<<endl;
    }
    else{
        cout<<"查找失败"<<endl;
    }
}

void Insert_book(BSTree &T)
{
    // 输入图书信息，利用二叉排序树的插入操作
    Book e;
    cout<<"输入图书信息进行录入："<<endl;
    cout<<"ISBN："<<endl;
    cin>>e.id;
    cout<<"书名："<<endl;
    cin>>e.name;
    cout<<"价格："<<endl;
    cin>>e.price;
    cout<<"库存："<<endl;
    cin>>e.num;
    InsertBST(T,e);
}

void Delete_book(BSTree &T)
{
    // 输入图书isbn，利用二叉排序树的删除操作
    string isbn;
    cout<<"输入图书ISBN号进行删除："<<endl;
    cin>>isbn;
    BSTree p=SearchBST(T,isbn);
    if(p!=NULL){
        DeleteBST(T,isbn);
    }
    else{
        cout<<"删除失败，无此书籍"<<endl;
    }
}

void Modify_Info(BSTree &T)
{
    // 输入图书isbn，利用二叉排序树的修改操作
    string isbn;
    cout<<"输入图书ISBN号进行修改："<<endl;
    cin>>isbn;
    BSTree p=SearchBST(T,isbn);
    if(p!=NULL){
        DeleteBST(T,isbn);
        Book e;
        cout<<"请输入新的信息："<<endl;
        cout<<"ISBN："<<endl;
        cin>>e.id;
        cout<<"书名："<<endl;
        cin>>e.name;
        cout<<"价格："<<endl;
        cin>>e.price;
        cout<<"库存："<<endl;
        cin>>e.num;
        InsertBST(T,e);
    }
}