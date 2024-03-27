class Test
{
    Test(int i){}
    Test(){}
    void func(){}
};

int main()
{
    /*Test a(10);
    a.func();*/
    // 默认构造函数定义对象，不需要加括号，否则编译器会认为是函数声明
    Test b();
    b.func();
    //new创新新对象时，如果是内置类型，例如：int，是否添加括号都可以，添加括号会进行初始化，不添加则只是开辟空间。例如：

    //int* T = new int;//创建新对象，只是开辟空间
    //int* T = new int();//创建新对象并初始化
    return 0;
}