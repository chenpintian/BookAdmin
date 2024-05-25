#include "/Users/chenpintian/CLionProjects/BookAdmin/BSTree.h"
#include "/Users/chenpintian/CLionProjects/BookAdmin/program.h"

void op_book_menu();  //图书操作界面功能函数

int main() {
    //补充代码，定义二叉排序树变量T表示图书数据对象
    BSTree T;
    int op;
    File_in_Tree(T); //导入图书数据到二叉排序树T
    while(1)
    {
        op_book_menu();//图书操作界面函数
        cin>>op;
        switch (op)
        {
            case 1:  //输入1，插入图书
                Insert_book(T); // 调用图书录入功能函数
                break;
            case 2:
                Delete_book(T); // 调用删除图书功能函数
                break;
            case 3:     //输入3，修改图书信息
                Modify_Info(T); // 调用修改图书信息功能函数
                break;
            case 4:       //输入4，查找图书
                Search_book(T); // 调用查找图书功能函数
                break;
            case 5:           //输入5，显示图书信息
                PrintInfo(T);  // 调用显示所有图书功能函数
                break;
            case 0:     //输入0，保存数据退出程序
                Tree_out_file(T);
                return 0;
            default:;
        }
    }
    return 0;
}

void op_book_menu()
{
    cout<<endl;
    cout<<"/***********************输入数字进行操作选择************************/"<<endl;
    cout<<"1.录入图书"<<endl;
    cout<<"2.删除图书"<<endl;
    cout<<"3.修改图书"<<endl;
    cout<<"4.查找图书"<<endl;
    cout<<"5.显示所有图书信息"<<endl;
    cout<<"0.保存并退出程序，"<<endl;
    cout<<endl;
    return ;
}
