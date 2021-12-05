#include <iostream>
#include <math.h>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <exception>
#include <vector>
#include <string>
#include <stdexcept>
#include <csignal>
#include <unistd.h>
#include <pthread.h>

using namespace std;

// #define DEBUG
#define MIN(a, b) (((a) < (b)) ? a : b)

#define MKSTR(x) #x
#define CONCAT(x, y) x##y

#define NUM_THREADS 5

struct Books
{
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
};

class Shape
{
protected:
    int width, height;

public:
    Shape(int a = 0, int b = 0)
    {
        width = a;
        height = b;
    }
    // 虚函数
    // virtual int area()
    // {
    //     cout << "Parent class area :" << endl;
    //     return 0;
    // }
    // 纯虚函数
    virtual int area() = 0;
};

class Rectangle : public Shape
{
public:
    Rectangle(int a = 0, int b = 0) : Shape(a, b)
    {
    }
    int area()
    {
        cout << "Rectangle class area :" << endl;
        return (width * height);
    }
};

class Triangle : public Shape
{
public:
    Triangle(int a = 0, int b = 0) : Shape(a, b)
    {
    }
    int area()
    {
        cout << "Triangle class area :" << endl;
        return (width * height / 2);
    }
};

struct MyException : public exception
{
    const char *what() const throw()
    {
        return "C++ Exception";
    }
};

struct thread_data
{
    int thread_id;
    char *message;
};

template <typename T>
inline T const &Max(T const &a, T const &b)
{
    return a < b ? a : b;
}

template <class T>
class Stack
{
private:
    vector<T> elems; // 元素

public:
    void push(T const &); // 入栈
    void pop();           // 出栈
    T top() const;        // 返回栈顶元素
    bool empty() const
    { // 如果为空则返回真。
        return elems.empty();
    }
};
template <class T>
void Stack<T>::push(T const &elem)
{
    // 追加传入元素的副本
    elems.push_back(elem);
}
template <class T>
void Stack<T>::pop()
{
    if (elems.empty())
    {
        throw out_of_range("Stack<>::pop(): empty stack");
    }
    // 删除最后一个元素
    elems.pop_back();
}
template <class T>
T Stack<T>::top() const
{
    if (elems.empty())
    {
        throw out_of_range("Stack<>::top(): empty stack");
    }
    // 返回最后一个元素的副本
    return elems.back();
}

void testSize();
void testTypedef();
void testVariableDeclaration();
void testGlobalVariable();
void testDefine();
void testModifierType();
void testStorageClass();
void testStorageClass_static();
void func2();
void testLambda();
void testComputation();
void testRandom();
void testString();
void testQuote();
int &testQuoteParam(int &);
void testDateAndTime();
void testAccessStructureMember();
void testStructAsFunctionParam();
void printBook(struct Books book);
void testPolymorphism();
void testReadAndWriteFile();
void testAbnormal();
void testDefineNewException();
void testFunctionTemplate();
void testClassTemplate();
void testConditionalCompilation();
void testOperator();
void testPredefinedMacro();
void testSignal();
void testRaise();
void testCreateAndFinishThread();
void testCreateAndFinishThreadWithParam();
void testCreateAndFinishThreadTransParam();
void testConnectDetachThreads();
void testSTL();

static int count = 10;

int main()
{
    // testSize();
    // testTypedef();
    // testVariableDeclaration();
    // testGlobalVariable();
    // testDefine();
    // testModifierType();
    // testStorageClass_static();
    // testLambda();
    // testComputation();
    // testRandom();
    // testString();
    // testQuote();
    // testDateAndTime();
    // testAccessStructureMember();
    // testStructAsFunctionParam();
    // testPolymorphism();
    // testReadAndWriteFile();
    // testAbnormal();
    // testDefineNewException();
    // testFunctionTemplate();
    // testClassTemplate();
    // testConditionalCompilation();
    // testOperator();
    // testPredefinedMacro();
    // testSignal();
    // testRaise();
    // testCreateAndFinishThread();
    // testCreateAndFinishThreadWithParam();
    // testCreateAndFinishThreadTransParam();
    // testConnectDetachThreads();
    testSTL();
    return 0;
}

void testSTL()
{
    // 创建一个向量存储 int
    vector<int> vec;
    int i;

    // 现实 vec 的原始大小
    cout << "vector size = " << vec.size() << endl;

    // 推入 5 个值到向量中
    for (i = 0; i < 5; i++)
    {
        vec.push_back(i);
    }

    // 显示 vec 扩展后的大小
    cout << "extended vector size = " << vec.size() << endl;

    // 访问向量中的5个值
    for (i = 0; i<5; i++){
        cout << "value of vec ["<<i<<"] = "<<vec[i]<<endl;
    }

    // 使用迭代器 iterator 访问值
    vector<int>::iterator v = vec.begin();
    while(v != vec.end()){
        cout << "value of v = " << *v<<endl;
        v++;
    }
}

void *wait(void *t)
{
    int tid;

    tid = *((int *)t);
    sleep(1);
    cout << "Sleeping in thread " << endl;
    cout << "Thread with id : " << tid << "  ...exiting " << endl;
    pthread_exit(NULL);
}

void testConnectDetachThreads()
{
    int rc;
    int i;
    pthread_t threads[NUM_THREADS];
    pthread_attr_t attr;
    void *status;
    int indexs[NUM_THREADS];

    // 初始化并设置线程为可连接的（joinable）
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    for (i = 0; i < NUM_THREADS; i++)
    {
        cout << "main() : creating thread, " << i << endl;
        indexs[i] = i;
        rc = pthread_create(&threads[i], NULL, wait, (void *)&indexs[i]);
        if (rc)
        {
            cout << "Error:unable to create thread," << rc << endl;
            exit(-1);
        }
    }

    // 删除属性，并等待其他线程
    pthread_attr_destroy(&attr);
    for (i = 0; i < NUM_THREADS; i++)
    {
        rc = pthread_join(threads[i], &status);
        if (rc)
        {
            cout << "Error:unable to join," << rc << endl;
            exit(-1);
        }
        cout << "Main: completed thread id :" << i;
        cout << "  exiting with status :" << status << endl;
    }

    cout << "Main: program exiting." << endl;
    pthread_exit(NULL);
}

void *PrintHello2(void *threadarg)
{
    thread_data *my_data;
    my_data = (struct thread_data *)threadarg;
    cout << "Thread ID:" << my_data->thread_id << " ";
    cout << " Message:" << my_data->message << endl;
    pthread_exit(NULL);
}

void testCreateAndFinishThreadTransParam()
{
    pthread_t threads[NUM_THREADS];
    struct thread_data td[NUM_THREADS];
    int i = 0;
    int rc;
    for (i = 0; i < NUM_THREADS; i++)
    {
        cout << "main() : creating thread, " << i << endl;
        td[i].thread_id = i;
        td[i].message = "This world is ours";
        rc = pthread_create(&threads[i], NULL, PrintHello2, (void *)&td[i]);
        if (rc)
        {
            cout << "Error:unable to create thread," << rc << endl;
            exit(-1);
        }
    }
    pthread_exit(NULL);
}

void *PrintHello(void *threadid)
{
    // 对传入的参数进行强制类型转换，由无类型指针变为整形数指针，然后再读取
    int tid = *((int *)threadid);
    cout << "Hello Runnob! 编程 ID : " << tid << endl;
    pthread_exit(NULL);
}

void testCreateAndFinishThreadWithParam()
{
    pthread_t threads[NUM_THREADS];
    int indexs[NUM_THREADS]; // 用数组来保存i的值
    int rc;
    int i = 0;
    for (i = 0; i < NUM_THREADS; i++)
    {
        cout << "main() : 创建线程 : " << i << endl;
        indexs[i] = i; //先保存i的值
        // 传入的时候必须强制转换为void* 类型，即无类型指针
        rc = pthread_create(&threads[i], NULL, PrintHello,
                            (void *)&indexs[i]);
        if (rc)
        {
            cout << "ERROR: 无法创建线程, " << rc << endl;
            exit(-1);
        }
    }
    pthread_exit(NULL);
}

void *sayHello(void *args)
{
    cout << "say hello" << endl;
}

// g++ test.cpp -lpthread -o test.o
void testCreateAndFinishThread()
{
    pthread_t tids[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++)
    {
        int ret = pthread_create(&tids[i], NULL, sayHello, NULL);
        if (ret != 0)
        {
            cout << "pthread_create error: error_code=" << ret << endl;
        }
    }
    pthread_exit(NULL);
}

void signalHandler(int signum)
{
    cout << "Interrupt signal (" << signum << ") received.\n";

    // 清理并关闭
    // 终止程序

    exit(signum);
}

void testRaise()
{
    // 注册信号 SIGINT 和信号处理程序
    signal(SIGINT, signalHandler);

    int i = 0;
    while (++i)
    {
        cout << "Going to sleep...." << endl;
        if (i == 3)
        {
            raise(SIGINT);
        }
        usleep(1);
    }
}

void testSignal()
{
    // 注册信号 SIGINT 和信号处理程序
    signal(SIGINT, signalHandler);

    while (1)
    {
        cout << "Going to sleep...." << endl;
        usleep(1);
    }
}

void testPredefinedMacro()
{
    cout << "Value of __LINE__ : " << __LINE__ << endl;
    cout << "Value of __FILE__ : " << __FILE__ << endl;
    cout << "Value of __DATE__ : " << __DATE__ << endl;
    cout << "Value of __TIME__ : " << __TIME__ << endl;
}

void testOperator()
{
    // #
    cout << MKSTR(HELLO C++) << endl; // 转换成了 cout << "HELLO C++" << endl;

    // ##
    int ab = 100;
    cout << CONCAT(a, b) << endl; // 转换成了 cout << xy;
}

void testConditionalCompilation()
{
    int i, j;
    i = 100;
    j = 30;
#ifdef DEBUG
    cerr << "Trace: Inside main function" << endl;
#endif
#if 0
    /* 这是注释部分 */
    cout << MKSTR(HELLO C++) << endl;
#endif
    cout
        << "The minimum is " << MIN(i, j) << endl;
#ifdef DEBUG
    cerr
        << "Trace: Coming out of main function" << endl;
#endif
}

void testClassTemplate()
{

    try
    {
        Stack<int> intStack;       // int 类型的栈
        Stack<string> stringStack; // string 类型的栈

        // 操作 int 类型的栈
        intStack.push(7);
        cout << intStack.top() << endl;

        // 操作 string 类型的栈
        stringStack.push("hello");
        cout << stringStack.top() << std::endl;
        stringStack.pop();
        stringStack.pop();
    }
    catch (exception const &ex)
    {
        cerr << "Exception: " << ex.what() << endl;
    }
}

void testFunctionTemplate()
{
    int i = 39;
    int j = 20;
    cout << "Max(i, j): " << Max(i, j) << endl;

    double f1 = 13.5;
    double f2 = 20.7;
    cout << "Max(f1, f2): " << Max(f1, f2) << endl;

    string s1 = "Hello";
    string s2 = "World";
    cout << "Max(s1, s2): " << Max(s1, s2) << endl;
}

void testDefineNewException()
{
    try
    {
        throw MyException();
    }
    catch (MyException &e)
    {
        std::cout << "MyException caught" << std::endl;
        std::cout << e.what() << std::endl;
    }
    catch (std::exception &e)
    {
        //其他的错误
    }
}

double division(int a, int b)
{
    if (b == 0)
    {
        throw "Division by zero condition!";
    }
    return (a / b);
}

void testAbnormal()
{
    int x = 50;
    int y = 0;
    double z = 0;

    try
    {
        z = division(x, y);
        cout << z << endl;
    }
    catch (const char *msg)
    {
        cerr << msg << endl;
    }
}

void testReadAndWriteFile()
{
    char data[100];

    // 以写模式打开文件
    ofstream outfile;
    outfile.open("afile.dat");
    cout << "Writing to the file" << endl;
    cout << "Enter your name: ";
    cin.getline(data, 100);

    // 向文件写入用户输入的数据
    outfile << data << endl;

    cout << "Enter your age: ";
    cin >> data;
    cin.ignore(); // ignore() 函数会忽略掉之前读语句留下的多余字符

    // 再次向文件写入用户输入的数据
    outfile << data << endl;

    // 关闭打开的文件
    outfile.close();

    // 以读模式打开文件
    ifstream infile;
    infile.open("afile.dat");

    cout << "Reading from the file" << endl;
    infile >> data;

    // 在屏幕上写入数据
    cout << data << endl;

    // 再次从文件读取数据，并显示它
    infile >> data;
    cout << data << endl;

    // 关闭打开的文件
    infile.close();
}

void testPolymorphism()
{
    Shape *shape;
    Rectangle rec(10, 7);
    Triangle tri(10, 5);

    shape = &rec;
    cout << shape->area() << endl;

    shape = &tri;
    cout << shape->area() << endl;
}

void printBook(struct Books book)
{
    cout << "书标题 : " << book.title << endl;
    cout << "书作者 : " << book.author << endl;
    cout << "书类目 : " << book.subject << endl;
    cout << "书 ID : " << book.book_id << endl;
}

void testStructAsFunctionParam()
{
    Books Book1; // 定义结构体类型 Books 的变量 Book1
    Books Book2; // 定义结构体类型 Books 的变量 Book2

    // Book1 详述
    strcpy(Book1.title, "C++ 教程");
    strcpy(Book1.author, "Runoob");
    strcpy(Book1.subject, "编程语言");
    Book1.book_id = 12345;
    // Book2 详述
    strcpy(Book2.title, "CSS 教程");
    strcpy(Book2.author, "Runoob");
    strcpy(Book2.subject, "前端技术");
    Book2.book_id = 12346;
    // 输出 Book1 信息
    printBook(Book1);
    // 输出 Book2 信息
    printBook(Book2);
}

void testAccessStructureMember()
{
    Books Book1; // 定义结构体类型 Books 的变量 Book1
    Books Book2; // 定义结构体类型 Books 的变量 Book2

    // Book1 详述
    strcpy(Book1.title, "C++ 教程");
    strcpy(Book1.author, "Runoob");
    strcpy(Book1.subject, "编程语言");
    Book1.book_id = 12345;
    // Book2 详述
    strcpy(Book2.title, "CSS 教程");
    strcpy(Book2.author, "Runoob");
    strcpy(Book2.subject, "前端技术");
    Book2.book_id = 12346;
    // 输出 Book1 信息
    cout << "第一本书标题 : " << Book1.title << endl;
    cout << "第一本书作者 : " << Book1.author << endl;
    cout << "第一本书类目 : " << Book1.subject << endl;
    cout << "第一本书 ID : " << Book1.book_id << endl;
    // 输出 Book2 信息
    cout << "第二本书标题 : " << Book2.title << endl;
    cout << "第二本书作者 : " << Book2.author << endl;
    cout << "第二本书类目 : " << Book2.subject << endl;
    cout << "第二本书 ID : " << Book2.book_id << endl;
}

void testDateAndTime()
{
    cout << "testDateAndTime" << endl;

    // // 基于当前系统的当前日期/时间
    // time_t now = time(0);

    // // 把 now 转换为字符串形式
    // char *dt = ctime(&now);

    // cout << "本地日期和时间：" << dt << endl;

    // // 把 now 转换为 tm 结构
    // tm *gmtm = gmtime(&now);
    // dt = asctime(gmtm);
    // cout << "UTC 日期和时间：" << dt << endl;

    // ------------------------------------

    // 基于当前系统的当前日期/时间
    time_t now = time(0);

    cout << "Number of sec since January 1,1970:" << now << endl;

    tm *ltm = localtime(&now);

    // 输出 tm 结构的各个组成部分
    cout << "Year: " << 1900 + ltm->tm_year << endl;
    cout << "Month: " << 1 + ltm->tm_mon << endl;
    cout << "Day: " << ltm->tm_mday << endl;
    cout << "Time: " << 1 + ltm->tm_hour << ":";
    cout << 1 + ltm->tm_min << ":";
    cout << 1 + ltm->tm_sec << endl;
}

int &testQuoteParam(int &a)
{
    a = 777;
    int &b = a;
    return b;
}

void testQuote()
{
    int abc = 100;
    cout << "abc:" << abc << endl;
    int &c = testQuoteParam(abc);
    cout << "abc:" << abc << endl;
    cout << "c:" << c << endl;
    c = 1001;
    cout << "abc:" << abc << endl;
    cout << "c:" << c << endl;
    // // 声明简单的变量
    // int i;
    // double d;

    // // 声明引用变量
    // int &r = i;
    // double &s = d;

    // i = 5;
    // cout << "Value of i : " << i << endl;
    // cout << "Value of i reference : " << r << endl;

    // d = 11.7;
    // cout << "Value of d : " << d << endl;
    // cout << "Value of d reference : " << s << endl;
}

void testString()
{
    char greeting[6] = {'H', 'e', 'l', 'l', 'o'};
    cout << "Greeting message: ";
    cout << greeting << endl;
    cout << sizeof(greeting) << endl;
}

void testRandom()
{
    int i, j;
    // 设置种子
    srand((unsigned)time(NULL));

    /* 生成 10 个随机数 */
    for (i = 0; i < 10; i++)
    {
        // 生成实际的随机数
        j = rand();
        cout << "随机数： " << j << endl;
    }
}

void testComputation()
{
    // 数字定义
    short s = 10;
    int i = -1000;
    long l = 100000;
    float f = 230.47;
    double d = 200.374;

    // 数学运算
    cout << "sin(d) :" << sin(d) << endl;
    cout << "abs(i)  :" << abs(i) << endl;
    cout << "floor(d) :" << floor(d) << endl;
    cout << "sqrt(f) :" << sqrt(f) << endl;
    cout << "pow( d, 2) :" << pow(d, 2) << endl;
}

void testLambda()
{
    int x = 2;
    int y = 3;
    cout << x << endl;
    // int res = [x, y](int x, int y) -> int { int z = x + y; return z + x; };
    // cout<<res<<endl;
}

void func2()
{
    static int i = 5; // 局部静态变量
    i++;
    std::cout << "变量 i 为 " << i;
    std::cout << " , 变量 count 为 " << count << std::endl;
}

void testStorageClass_static()
{
    while (count--)
    {
        func2();
    }
}

void testStorageClass()
{
    auto f = 3.14;        //double
    auto s("hello");      //const char
    auto z = new auto(9); // int
    // auto x1 = 5, x2 = 5.0, x3='r';//错误，必须是初始化为同一类型
    cout << typeid(f).name() << endl;
    cout << typeid(s).name() << endl;
    cout << typeid(z).name() << endl;
}

void testModifierType()
{
    short int i;
    short unsigned int j;
    j = 50000;
    i = j;
    cout << i << " " << j << endl;
}

void testDefine()
{
#define LENGTH 10
#define WIDTH 5
#define NEWLINE '\n'
    int area;
    area = LENGTH * WIDTH;
    cout << area;
    cout << NEWLINE;
}

void testGlobalVariable()
{
    // 这里局部变量也会自动初始化
    int a;
    char b;
    float c;
    double d;
    int *e;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << d << endl;
    cout << e << endl;
}

int func()
{
    return 1;
}

void testVariableDeclaration()
{
    int aFunc = func();
    cout << aFunc << endl;
    ;
}

void testTypedef()
{
    enum color
    {
        red,
        green = 5,
        blue,
    } c;
    cout << "red:" << red << endl;
    cout << "green:" << green << endl;
    cout << "blue:" << blue << endl;
}

void testSize()
{
    cout << "Size of char : " << sizeof(char) << endl;
    cout << "Size of int : " << sizeof(int) << endl;
    cout << "Size of short int : " << sizeof(short int) << endl;
    cout << "Size of long int : " << sizeof(long int) << endl;
    cout << "Size of float : " << sizeof(float) << endl;
    cout << "Size of double : " << sizeof(double) << endl;
    cout << "Size of wchar_t : " << sizeof(wchar_t) << endl;
}
