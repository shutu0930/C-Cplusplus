// library.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;
#include <conio.h>
double code=1;
class reader  //读者类
{
public:
    reader();
    ~reader(){}
    void manage();
    void creat();
    void rework();
	void lookfor();
    void delet();

private:
    string name;
    string no; 
	
};
class book    //图书类
{
public:
    book();
    ~book(){}
    void manage();  //图书管理（首页）
    void creat();
    void rework();
    void delet();
 	void lookfor();
private:
    string name;
    string no;
};



class mulclass//读者操作
{
public:
    mulclass();
    ~mulclass(){}
    void manage();//借阅首页
    void borrow();
    void retrun();
    void query_inter();//查询首页
    void book_query();//图书信息
    void reader_query();//读者借阅历史
    book get_abook(){return abook;}
    reader get_asuer(){return asuer;}
private:
    book abook;
    reader asuer;
};

book::book()
{

}
char inter_face4()
{
    system("cls");//清屏
    cout << endl << endl;
   cout << "     \t◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇" << endl
             << "\t                                                        " << endl
             << "\t              输入错误，按任意键继续                    " << endl
             << "\t                                                        " << endl
             << "\t◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇" << endl << endl;
        cout << "\t\t\t";

    return getch();
}
void book::manage()
{
    while (1)
    {
        system("cls");
        cout << endl;
        cout << "\t◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇" << endl
             << "\t                                                        " << endl
             << "\t            图书信息管理                                " << endl
             << "\t                                                        " << endl
             << "\t●            1.  新建                                  " << endl
             << "\t                                                        " << endl
             << "\t●            2.  修改                                  " << endl
             << "\t                                                        " << endl
             << "\t●            3.  删除                                  " << endl
             << "\t                                                        " << endl
			 << "\t●            4.  查询                                  " << endl
			 << "\t                                                        " << endl
             << "\t●            0.  返回                                  " << endl
             << "\t                                                        " << endl
             << "\t◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇" << endl << endl;
        cout << "\t\t\t";

        switch (getch())
        {
        case '1':
            creat();
            break;
        case '2':
            rework();
            break;
        case '3':
            delet();
            break;
		case '4':
            lookfor();
            break;
        case '0':
            return;
            break;
	default:inter_face4();
            break;
        }
    }
}

void book::creat()
{
    system("cls");
    cout << endl << "根据提示输入新的图书信息" << endl << endl;
   cout << endl << "    编号 : ";
    cin >> no;
	 cout << "图书名字 : ";
    cin >> name;
    
	ofstream bookfile("info\\book\\total.txt", ios::app);
    bookfile << setiosflags(ios::left) << no << " "
        << setw(20) << name << endl;
    bookfile.close();

    cout << endl << endl << "新图书信息已经保存!!!" << endl << endl;
    system("pause");
}

void book::rework()
{
    system("cls");
    string findno;
    cout << endl << "修图书信息" << endl << endl;
    cout << "请输入要修改的图书编号 : ";
    cin >> findno;

    ifstream bookfile("info\\book\\total.txt");   
    if (!bookfile)
    {
        cout << endl << "对不起信息库为空!!!" << endl << endl;
        return;
    }

    bool flag = false;
    ofstream temp("info\\book\\temp.txt");

    while (bookfile >>no>>name )
    {
        if (no == findno)
        {
            flag = true;
            cout << endl << "你想修改的图书信息如下 : " << endl << endl;
            cout << "    编号 : " << no << endl << endl << "图书名字 : " << name << endl << endl<< endl;

            cout << "请在下面输入新的信息 : " << endl << endl;
            cout << endl << "    编号 : ";
            cin >> no;
			 cout << "图书名字 : ";
            cin >> name;
            temp << setiosflags(ios::left) << no << " "
                << setw(20) << name << endl;
        }
        else
        {
            temp << setiosflags(ios::left)<< no <<" "
                 << setw(20) << name <<  endl;
        }
    }
    bookfile.close();
    temp.close();

    if (flag)
    {
        ofstream bookfile1("info\\book\\total.txt");
        ifstream temp1("info\\book\\temp.txt");

        bookfile1 << temp1.rdbuf() << endl;
        cout << endl << "新信息已经保存!!!" << endl << endl;
    }
    else
        cout << endl << "库中没有你想修改的图书!!!" << endl << endl;
    system("pause");
}

void book::delet()
{
    string delno;
    system("cls");
    cout << endl << "删除信息 " << endl << endl;
    cout << "输入你想删除图书的编号 : ";
    cin >> delno;

    ofstream temp("info\\book\\temp.txt");


    bool flag = false;
    ifstream bookfile("info\\book\\total.txt");
    while (bookfile >> no  >>name)
    {
        if (delno == no)
        {
            flag = true;
            cout << endl << "你想删除的图书信息如下 : " << endl << endl;
            
            cout << "    编号 : " << no << endl << endl;
			cout << "图书名字 : " << name << endl << endl;
            cout << "你确定要删除它吗(y/n) : ";
            if (getch() == 'n')
            {
                cout << endl << endl << "图书信息没有删除!!" << endl << endl;
                system("pause");
                return;
            }
        }
        else
        {
            temp << setiosflags(ios::left)<< no <<" "
                  << setw(20) << name << endl;
        }
    }
    temp.close();
    bookfile.close();

    if (flag)
    {
        ofstream bookfile1("info\\book\\total.txt");
        ifstream temp1("info\\book\\temp.txt");
        bookfile1 << temp1.rdbuf() << endl;
        bookfile1.close();
        temp1.close();
        cout << endl << endl << "图书信息已经成功删除!!" << endl << endl;
    }
    else
        cout << endl << "库中没有这个图书的信息!!!" << endl << endl;
    system("pause");
}
void book::lookfor()
{
	system("cls");
	cout<<endl<<"请输入图书编号："<<endl<<endl;
    string findno;
	 cin >> findno;
	  ifstream bookfile("info\\book\\total.txt");
	    bool flag = false;

    ofstream temp("info\\book\\temp.txt");
    while (bookfile >>  no>>name )
    {
        if (no == findno)
        {
            flag = true;
            cout << "    编号 : " << no << endl << endl << "图书名字 : " << name << endl << endl<< endl;
        }
        else
        {
            temp << setiosflags(ios::left)<< no <<" "
                 << setw(20) << name <<  endl;
        }
    }
    bookfile.close();
    temp.close();

    if (flag)
    {
        ofstream bookfile1("info\\book\\total.txt");
        ifstream temp1("info\\book\\temp.txt");

        bookfile1 << temp1.rdbuf() << endl;
    }
    else
        cout << endl << "库中没有你想查询的图书!!!" << endl << endl;
    system("pause");
}

mulclass::mulclass()
{
}

void mulclass::manage()
{
    while (1)
    {
        system("cls");
        cout << endl << endl;
        cout << "\t图书借阅/归还" << endl << endl;
        cout << "\t●    1.  借图书" << endl << endl
             << "\t●    2.  还图书" << endl << endl
             << "\t●    3.  返回" << endl << endl;
        cout << "\t\t";
       
        switch (getch())
        {
        case '1':
            borrow();
            break;
        case '2':
            retrun();
            break;
        case '3':
            return;
            break;
       	default:inter_face4();
            break;
        }
    }
}

void mulclass::borrow()
{
    system("cls");
    string findbook;
    cout << endl << "借阅图书" << endl << endl;
    cout << "请输入你想借阅图书的名字或编号 : ";
    cin >> findbook;
   
    string name;
    string no;
   
    bool flag1 = false;
    bool flag = false;
    ifstream bookfile("info\\book\\total.txt");
    ofstream temp("info\\book\\temp.txt");
   
    while (bookfile >> no>> name)
    {
        if ( no == findbook|| name == findbook)
        {
            flag1 = true;
            cout << endl << "你想借阅的图书信息如下 : " << endl << endl;
           cout << "  编号 : " << no << endl << endl;
		    cout << "图书名 : " << name << endl << endl;
           
            string readerno;
            string readername;
            string findno;
            cout << endl << endl << "请输入你的用户编号,确定你是否有权限借走图书, 输入 :  ";
            cin >> findno;
           
            ifstream readerfile("info\\reader\\total.txt");
            while (readerfile >> readerno >> readername)
            {
                if (readerno == findno)
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
            {
			    string readerinfo = "info\\reader\\" + findno + ".txt";
                ofstream readerinfofile(readerinfo.c_str(), ios::app);
                readerinfofile << setiosflags(ios::left)<< setw(15) << no <<  " "
                     << setw(20) << name <<endl;
                readerinfofile.close();
                cout << endl << "这个图书，你已经成功借阅!!!" << endl << endl;
		
            }
            else
            {
                cout << endl << "用户信息中没有你的信息，你不能借走该图书!!!" << endl << endl;
                break;
            }
        }
        else
        {
            temp << setiosflags(ios::left)  << no << " "
              << setw(20) << name <<  endl;
        }
    }
    temp.close();
    bookfile.close();
   
    if (flag)
    {
        ofstream bookfile1("info\\book\\total.txt");
        ifstream temp1("info\\book\\temp.txt");
        bookfile1 << temp1.rdbuf() << endl;
        bookfile1.close();
        temp1.close();
    }
    if (!flag1)
    {
        cout << endl << "对不起,库中没有这本图书!!!" << endl << endl;
    }
    system("pause");
}

void mulclass::retrun()
{
    system("cls");
    cout << endl << "还图书" << endl << endl;
    cout << "请输入你的编号 : ";
    string readerno;
    cin >> readerno;
   
    ifstream reader("info\\reader\\total.txt");
    if (!reader)
    {
        cout << endl << "对不起，该用户不存在!!!" << endl << endl;
        system("pause");
        return;
    }
    string readername;
    string readerno1;
    bool flag1 = false;
    while (reader >> readerno1 >> readername)
    {
        if (readerno1 == readerno)
        {
            cout << endl << "请输入你想还的图书编号 : ";
            string retrunno;
            cin >> retrunno;
            flag1 = true;
            string bookname;
            string bookno;
            string time;
            bool flag = false;
            string readerfile = "info\\reader\\"+readerno+".txt";
            ifstream readerinfofile(readerfile.c_str());
           
            ofstream temp("info\\reader\\temp.txt");
            while (readerinfofile >>bookno >> bookname )
            {
                getline(readerinfofile, time);
                if (bookno == retrunno)
                {
                    flag = true;
                    ofstream bookfile("info\\book\\total.txt", ios::app);
                    bookfile << setiosflags(ios::left) << bookno<< " "
                         << setw(20) << bookname << endl;       
                 bookfile.close();
                }
                else
                {
                    temp << setiosflags(ios::left)<< setw(20) << bookno << " "
                        << setw(20) << bookname  << endl;
                }
            }
            temp.close();
            readerinfofile.close();
            if (flag)
            {
                ofstream reader1(readerfile.c_str());
                ifstream temp1("info\\reader\\temp.txt");
                reader1 << temp1.rdbuf() << endl;
                reader1.close();
                temp1.close();
                cout << endl << "还书操作完成!!!" << endl << endl;
                break;
            }
            else
            {
                cout << endl << "对不起,你没有借这个图书或者你输入的编号错误!!!" << endl << endl;
                break;
            }
        }
    }
    reader.close();
   
    if (!flag1)
    {
        cout << endl << "对不起，该用户不存在!!!" << endl << endl;
    }
    system("pause");
}

void mulclass::query_inter()
{
    while (1)
    {
        system("cls");
        cout << endl << endl << "\t信息查询 " << endl << endl
            << "\t●    1.  图书信息查询" << endl << endl
            << "\t●    2.  用户的借阅历史" << endl << endl
            << "\t●    3.  返回" << endl << endl;
        cout << "\t\t";
       
        switch (getch())
        {
        case '1':
            book_query();
            break;
        case '2':
            reader_query();
            break;
        case '3':
            return;
            break;
        	default:inter_face4();
            break;
        }
    }
}

void mulclass::book_query()
{
    system("cls");
    cout << endl << "图书信息查询" << endl << endl;
    cout << "请输入你想查询的图书编号 : ";
    string bookno;
    cin >> bookno;
   
    ifstream bookfile("info\\book\\total.txt");
    if (!bookfile)
    {
        cout << endl << "对不起,库存为空!!!" << endl << endl;
        system("pause");
        return;
    }
   
    string bookname;
    string bookno1;
    while (bookfile >>  bookno1  >>bookname)
    {
        if (bookno == bookno1)
        {
            cout << endl << "你要查询的图书信息如下 : " << endl << endl;
           
            cout << "  编号 : " << bookno << endl << endl;
			 cout << "图书名 : " << bookname << endl << endl;
            break;
        }
    }
    system("pause");
}

void mulclass::reader_query()
{
    system("cls");
    cout << endl << "用户的借阅历史" << endl << endl;
    cout << "请输入用户编号 : ";
    string readerno;
    cin >> readerno;
   
    string readername;
    string readerno1;
    ifstream reader1("info\\reader\\total.txt");
    if (!reader1)
    {
        cout << endl << "对不起, 该用户不存在!!" << endl << endl;
        system("pause");
        return;
    }
    while (reader1 >> readerno1>>  readername)
    {
        if (readerno == readerno1)
        {
            cout << endl  << "编号 : " << readerno <<"\t"  << "用户 : " << readername <<endl << endl;
            cout << setiosflags(ios::left) << setw(20) << "图书编号"
                << setw(20) << "图书名" << endl << endl;
            string readerfile = "info\\reader\\"+readerno+".txt";
            ifstream reader(readerfile.c_str());
            if (!reader)
            {
                cout << endl << "该用户还未借过书!!!" << endl << endl;
                system("pause");
                return;
            }
            cout << reader.rdbuf() << endl << endl;
            reader.close();
            break;
        }
    }
    system("pause");
}

reader::reader()
{
}

void reader::manage()
{
    while (1)
    {
        system("cls");

        cout << endl;
        cout << "\t◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇" << endl
             << "\t                                                        " << endl
             << "\t            用户信息管理                                " << endl
             << "\t                                                        " << endl
             << "\t●            1.  新建                                  " << endl
             << "\t                                                        " << endl
             << "\t●            2.  修改                                  " << endl
             << "\t                                                        " << endl
             << "\t●            3.  删除                                  " << endl
			 << "\t                                                        " << endl
			 << "\t●            4.  查询                                  " << endl
             << "\t                                                        " << endl
             << "\t●            0.  返回                                  " << endl
             << "\t                                                        " << endl
             << "\t◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇" << endl << endl;
        cout << "\t\t\t";

        switch (getch())
        {
        case '1':
            creat();
            break;
        case '2':
            rework();
            break;
        case '3':
            delet();
            break;
	   case '4':
            lookfor();
            break;
        case '0':
            return;
            break;
       	default:inter_face4();
            break;
        }
    }
}

void reader::creat()
{
    system("cls");
    cout << endl << "新建用户" << endl << endl;

    cout << "请根据提示输入新的用户信息 : " << endl << endl;
   
    cout << endl << "  编号 : ";
    cin >> no;
	 cout << "用户名 : ";
    cin >> name;

    ofstream readerfile("info\\reader\\total.txt", ios::app);
    readerfile << setiosflags(ios::left) << no <<  " "
       << setw(20) << name << endl;
    readerfile.close();

    cout << endl << "新用户信息已经保存!!!" << endl << endl;
    system("pause");
}

void reader::rework()
{
    system("cls");
    string findno;
    cout << endl << "修改用户信息" << endl << endl;
    cout << "输入想修改的用户编号 : ";
    cin >> findno;

    ifstream readerfile("info\\reader\\total.txt");
    if (!readerfile)
    {
        cout << endl << "对不起，没有这个用户的信息!!!" << endl << endl;
        system("pause");
        return;
    }
    bool flag = false;

    ofstream temp("info\\reader\\temp.txt");
    while (readerfile >> no >>name )
    {
        if (no == findno)
        {
            flag = true;
            cout << endl << "你想修改的用户信息如下 : " << endl << endl;
            cout << "编号 : " << no << endl << endl;
			cout << "姓名 : " << name << endl << endl;

            cout << "请在下面输入新的信息 : " << endl << endl;
           cout << endl << "  编号 : ";
            cin >> no;
			 cout << "用户名 : ";
            cin >> name;
            temp << setiosflags(ios::left) << no << " "
                << setw(20) << name << endl;
        }
        else
        {
            temp << setiosflags(ios::left) << no <<" "
                 << setw(20) << name << endl;
        }
    }
    temp.close();
    readerfile.close();             
   
    if (flag)
    {
        ofstream readerfile1("info\\reader\\total.txt");
        ifstream temp1("info\\reader\\temp.txt");
        readerfile1 << temp1.rdbuf() << endl;
        readerfile1.close();
        temp1.close();
        cout << endl << "新信息已经成功保存!!" << endl << endl;
    }
    else
        cout << endl << "对不起，没有这个用户的信息!!!" << endl << endl;
    system("pause");
}

void reader::lookfor()
{
	system("cls");
	cout<<endl<<"请输入读者编号："<<endl<<endl;
    string findno;
	 cin >> findno;
	  ifstream readerfile("info\\reader\\total.txt");
	    bool flag = false;

    ofstream temp("info\\reader\\temp.txt");
    while (readerfile >>no >> name)
    {
        if (no == findno)
        {
            flag = true;
            cout << "    编号 : " << no << endl << endl << "图者姓名 : " << name << endl << endl<< endl;
        }
        else
        {
            temp << setiosflags(ios::left)<< no <<" "
                 << setw(20) << name <<  endl;
        }
    }
    readerfile.close();
    temp.close();

    if (flag)
    {
        ofstream readerfile1("info\\reader\\total.txt");
        ifstream temp1("info\\reader\\temp.txt");

        readerfile1 << temp1.rdbuf() << endl;
    }
    else
        cout << endl << "库中没有你想查询的读者!!!" << endl << endl;
    system("pause");
}

		void reader::delet()
{
    system("cls");
    cout << endl << "删除用户信息" << endl << endl;
    string findno;
    cout << "请输入你想删的用户编号 : ";
    cin >> findno;

    ofstream temp("info\\reader\\temp.txt");
    ifstream readerfile("info\\reader\\total.txt");
    if (!readerfile)
    {
        cout << endl << "对不起，用户信息库为空!!!" << endl << endl;
        system("pause");
        return;
    }
    bool flag = false;
    while (readerfile >>no  >> name)
    {
        if (no == findno)
        {
            flag = true;
            cout << endl << "你想删除的用户信息如下 : " << endl << endl;
            
            cout << "编号 : " << no << endl << endl;
			cout << "姓名 : " << name << endl << endl;

            cout << "你确定在删除吗(y/n) : ";
            if (getch() == 'n')
            {
                temp.close();
                readerfile.close();
                cout << endl << "信息没有更改!!!" << endl << endl;
                system("pause");
                return;
            }
        }
        else
        {
            temp << setiosflags(ios::left)<< no << " "
                << setw(20) << name <<  endl;
        }
    }
    temp.close();
    readerfile.close();

    if (flag)
    {
        ofstream readerfile1("info\\reader\\total.txt");
        ifstream temp1("info\\reader\\temp.txt");
        readerfile1 << temp1.rdbuf() << endl;
        readerfile1.close();
        temp1.close();
        cout << endl << endl << "该用户信息已经删除!!" << endl << endl;
    }
    else
        cout << endl << endl << "对不起, 没有该用户的信息 !!" << endl << endl;
    system("pause");
}


char inter_face1()
{
    system("cls");
   cout << endl << endl;
    cout << "\t◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆" << endl
         << "\t◆                                                          ◆" << endl
         << "\t◆                   图 书 管 理 系 统                      ◆" << endl
		 << "\t◆            ................................              ◆" << endl
         << "\t◆                                                          ◆" << endl
         << "\t◆                                                          ◆" << endl
         << "\t◆                   1.图书管理员                           ◆" << endl
         << "\t◆                                                          ◆" << endl
         << "\t◆                   2.读者                                 ◆" << endl
         << "\t◆                                                          ◆" << endl
         << "\t◆                   0.退出系统                             ◆" << endl
         << "\t◆                                                          ◆" << endl
         << "\t◆                                                          ◆" << endl
         << "\t◆                                                          ◆" << endl
         << "\t◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆" << endl << endl;
    cout << "\t请选择你的身份（1或2）：";
    return getch();
}
	char inter_face2()
{
    system("cls");
    cout << endl << endl;
   cout << "     \t◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇" << endl
             << "\t                                                        " << endl
             << "\t                                                        " << endl
             << "\t●            1.  用户信息管理                          " << endl
             << "\t                                                        " << endl
             << "\t●            2.  图书信息管理                          " << endl
			 << "\t                                                        " << endl
             << "\t●            3.  修改密码                              " << endl
             << "\t                                                        " << endl
             << "\t●            0.  返回                                  " << endl
             << "\t                                                        " << endl
             << "\t◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇" << endl << endl;
        cout << "\t\t\t";

    return getch();
}

	char inter_face3()
{
    system("cls");
    cout << endl << endl;
   cout << "     \t◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇" << endl
             << "\t                                                        " << endl
             << "\t                                                        " << endl
             << "\t●            1. 借阅（归还）图书                       " << endl
             << "\t                                                        " << endl
             << "\t●            2. 信息查询                               " << endl
             << "\t                                                        " << endl
             << "\t●            0. 返回                                   " << endl
             << "\t                                                        " << endl
             << "\t◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇" << endl << endl;
        cout << "\t\t\t";

    return getch();
}
	char inter_face5()
{
    system("cls");
    cout << endl << endl;
	cout<<"********************************************************************************"<<endl<<endl;
  cout<<"\t\t\t  谢  谢  使  用\n\n\t\t...................................\n\n\t\t\t  欢迎再次使用\n\n"<<endl<<endl;
cout<<"********************************************************************************"<<endl<<endl;
    return getch();
}
char inter_face6()
{
    system("cls");
    cout << endl << endl;
   cout << "     \t◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇" << endl
             << "\t                                                        " << endl
             << "\t                                                        " << endl
             << "\t●            1. 老师                                   " << endl
             << "\t                                                        " << endl
             << "\t●            2. 研究生                                 " << endl
             << "\t                                                        " << endl
             << "\t●            3. 本科生                                 " << endl
             << "\t                                                        " << endl
			 << "\t●            0. 返回                                   " << endl
			 << "\t                                                        " << endl
			 << "\t                                                        " << endl
             << "\t◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇" << endl << endl;
        cout << "\t";
cout<<"请选择您的身份（1～3）：";

    return getch();
}
	
	
char inter_face9()
{
    system("cls");
    cout << endl << endl;
   cout << "     \t◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇" << endl
             << "\t                                                        " << endl
			 << "\t       系统提示：                                       " << endl
             << "\t             您最多可借10本书，按任意键继续             " << endl
             << "\t                                                        " << endl
             << "\t◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇" << endl << endl;
        cout << "\t\t\t";

    return getch();
}
char inter_face10()
{
    system("cls");
    cout << endl << endl;
   cout << "     \t◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇" << endl
             << "\t                                                        " << endl
             << "\t       系统提示：                                       " << endl
             << "\t             您最多可借8本书，按任意键继续             " << endl
             << "\t                                                        " << endl
             << "\t◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇" << endl << endl;
        cout << "\t\t\t";

    return getch();
}
char inter_face11()
{
    system("cls");
    cout << endl << endl;
   cout << "     \t◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇" << endl
             << "\t                                                        " << endl
             << "\t       系统提示：                                       " << endl
             << "\t             您最多可借5本书，按任意键继续              " << endl
             << "\t                                                        " << endl
             << "\t◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇" << endl << endl;
        cout << "\t\t\t";

    return getch();
}

double inter_face7()
	{double a;
		system("cls");
    cout << endl<<endl ;
   cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<< endl << endl << endl;
   cout<<" \n\n\t\t     系统提示：请输入密码：";

			   cin>>a;
		   return a;}

	char inter_face8 ()
	{system("cls");
    cout << endl<<endl ;
   cout << "********************************************************************************"<< endl << endl << endl;
	   cout<<" \n\n\n\t\t\t您的密码不正确，请重新输入：\n\n\t\t\t    按任意键继续...."<< endl << endl<< endl << endl;
       cout << "********************************************************************************\n\n";
    return getch();
	}

		int mima()
{
	while(inter_face7()!=code){inter_face8();}
       return 1;
}

		double inter_face12 ()
		{ double b,c;
			system("cls");
    cout << endl<<endl ;
   cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"<< endl << endl << endl;
	   cout<<" \n\n\n\t\t\t输入新密码：";
	   cin>>b;
	 cout<<"\t\t\t再次输入密码：";
	cin>>c;
	if(b==c) 
	{code=b;
	return 1;}
	else {return 0;}
	}
void xiugai()
{

	if(inter_face12()==1){ cout<<"\n\n\t\t\t密码修改成功!\n\n";system("pause");}
	
else {cout<<"\n\n\t\t\t密码输入错误，请重新输入!\n\n";system("pause");xiugai();}


}

int main()
{

    mulclass object;
	
	while (1)
    {
        switch (inter_face1())
        {
        case '1':
			mima();
           	while(1)
		  {
        switch (inter_face2())
        {
        case '1':
           object.get_asuer().manage();
            break;
        case '2':
            object.get_abook().manage();
            break;
		case '3':
			xiugai();
			break;
        case '0':
          return main();
            break;
      	default:inter_face4();
            break;
        }
    }

        case '2':

           while(1)
		  {
        switch (inter_face6())
        {
        case '1':
            inter_face9();
           while(1)
		  {
        switch (inter_face3())
        {
        case '1':
            object.manage();
            break;
        case '2':
            object.query_inter();
            break;
        case '0':
           return main();
            break;
        	default:inter_face4();
            break;
        }
    }
        case '2':
            inter_face10();
           while(1)
		  {
        switch (inter_face3())
        {
        case '1':
            object.manage();
            break;
        case '2':
            object.query_inter();
            break;
        case '0':
           return main();
            break;
        	default:inter_face4();
            break;
        }
    }
		   case '3':
            inter_face11();
           while(1)
		  {
        switch (inter_face3())
        {
        case '1':
            object.manage();
            break;
        case '2':
            object.query_inter();
            break;
        case '0':
            return main();
            break;
        	default:inter_face4();
            break;
        }
    }
        case '0':
            return main();
            break;
        	default:inter_face4();
            break;
        }
    }
            break;
        case '0':
           inter_face5();
            break;
        default:inter_face4();
            break;
        }
    }
  return 0;
} 

