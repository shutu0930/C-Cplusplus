// library.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;
#include <conio.h>
double code=1;
class reader  //������
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
class book    //ͼ����
{
public:
    book();
    ~book(){}
    void manage();  //ͼ�������ҳ��
    void creat();
    void rework();
    void delet();
 	void lookfor();
private:
    string name;
    string no;
};



class mulclass//���߲���
{
public:
    mulclass();
    ~mulclass(){}
    void manage();//������ҳ
    void borrow();
    void retrun();
    void query_inter();//��ѯ��ҳ
    void book_query();//ͼ����Ϣ
    void reader_query();//���߽�����ʷ
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
    system("cls");//����
    cout << endl << endl;
   cout << "     \t�����������������������������" << endl
             << "\t                                                        " << endl
             << "\t              ������󣬰����������                    " << endl
             << "\t                                                        " << endl
             << "\t�����������������������������" << endl << endl;
        cout << "\t\t\t";

    return getch();
}
void book::manage()
{
    while (1)
    {
        system("cls");
        cout << endl;
        cout << "\t�����������������������������" << endl
             << "\t                                                        " << endl
             << "\t            ͼ����Ϣ����                                " << endl
             << "\t                                                        " << endl
             << "\t��            1.  �½�                                  " << endl
             << "\t                                                        " << endl
             << "\t��            2.  �޸�                                  " << endl
             << "\t                                                        " << endl
             << "\t��            3.  ɾ��                                  " << endl
             << "\t                                                        " << endl
			 << "\t��            4.  ��ѯ                                  " << endl
			 << "\t                                                        " << endl
             << "\t��            0.  ����                                  " << endl
             << "\t                                                        " << endl
             << "\t�����������������������������" << endl << endl;
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
    cout << endl << "������ʾ�����µ�ͼ����Ϣ" << endl << endl;
   cout << endl << "    ��� : ";
    cin >> no;
	 cout << "ͼ������ : ";
    cin >> name;
    
	ofstream bookfile("info\\book\\total.txt", ios::app);
    bookfile << setiosflags(ios::left) << no << " "
        << setw(20) << name << endl;
    bookfile.close();

    cout << endl << endl << "��ͼ����Ϣ�Ѿ�����!!!" << endl << endl;
    system("pause");
}

void book::rework()
{
    system("cls");
    string findno;
    cout << endl << "��ͼ����Ϣ" << endl << endl;
    cout << "������Ҫ�޸ĵ�ͼ���� : ";
    cin >> findno;

    ifstream bookfile("info\\book\\total.txt");   
    if (!bookfile)
    {
        cout << endl << "�Բ�����Ϣ��Ϊ��!!!" << endl << endl;
        return;
    }

    bool flag = false;
    ofstream temp("info\\book\\temp.txt");

    while (bookfile >>no>>name )
    {
        if (no == findno)
        {
            flag = true;
            cout << endl << "�����޸ĵ�ͼ����Ϣ���� : " << endl << endl;
            cout << "    ��� : " << no << endl << endl << "ͼ������ : " << name << endl << endl<< endl;

            cout << "�������������µ���Ϣ : " << endl << endl;
            cout << endl << "    ��� : ";
            cin >> no;
			 cout << "ͼ������ : ";
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
        cout << endl << "����Ϣ�Ѿ�����!!!" << endl << endl;
    }
    else
        cout << endl << "����û�������޸ĵ�ͼ��!!!" << endl << endl;
    system("pause");
}

void book::delet()
{
    string delno;
    system("cls");
    cout << endl << "ɾ����Ϣ " << endl << endl;
    cout << "��������ɾ��ͼ��ı�� : ";
    cin >> delno;

    ofstream temp("info\\book\\temp.txt");


    bool flag = false;
    ifstream bookfile("info\\book\\total.txt");
    while (bookfile >> no  >>name)
    {
        if (delno == no)
        {
            flag = true;
            cout << endl << "����ɾ����ͼ����Ϣ���� : " << endl << endl;
            
            cout << "    ��� : " << no << endl << endl;
			cout << "ͼ������ : " << name << endl << endl;
            cout << "��ȷ��Ҫɾ������(y/n) : ";
            if (getch() == 'n')
            {
                cout << endl << endl << "ͼ����Ϣû��ɾ��!!" << endl << endl;
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
        cout << endl << endl << "ͼ����Ϣ�Ѿ��ɹ�ɾ��!!" << endl << endl;
    }
    else
        cout << endl << "����û�����ͼ�����Ϣ!!!" << endl << endl;
    system("pause");
}
void book::lookfor()
{
	system("cls");
	cout<<endl<<"������ͼ���ţ�"<<endl<<endl;
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
            cout << "    ��� : " << no << endl << endl << "ͼ������ : " << name << endl << endl<< endl;
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
        cout << endl << "����û�������ѯ��ͼ��!!!" << endl << endl;
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
        cout << "\tͼ�����/�黹" << endl << endl;
        cout << "\t��    1.  ��ͼ��" << endl << endl
             << "\t��    2.  ��ͼ��" << endl << endl
             << "\t��    3.  ����" << endl << endl;
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
    cout << endl << "����ͼ��" << endl << endl;
    cout << "�������������ͼ������ֻ��� : ";
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
            cout << endl << "������ĵ�ͼ����Ϣ���� : " << endl << endl;
           cout << "  ��� : " << no << endl << endl;
		    cout << "ͼ���� : " << name << endl << endl;
           
            string readerno;
            string readername;
            string findno;
            cout << endl << endl << "����������û����,ȷ�����Ƿ���Ȩ�޽���ͼ��, ���� :  ";
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
                cout << endl << "���ͼ�飬���Ѿ��ɹ�����!!!" << endl << endl;
		
            }
            else
            {
                cout << endl << "�û���Ϣ��û�������Ϣ���㲻�ܽ��߸�ͼ��!!!" << endl << endl;
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
        cout << endl << "�Բ���,����û���Ȿͼ��!!!" << endl << endl;
    }
    system("pause");
}

void mulclass::retrun()
{
    system("cls");
    cout << endl << "��ͼ��" << endl << endl;
    cout << "��������ı�� : ";
    string readerno;
    cin >> readerno;
   
    ifstream reader("info\\reader\\total.txt");
    if (!reader)
    {
        cout << endl << "�Բ��𣬸��û�������!!!" << endl << endl;
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
            cout << endl << "���������뻹��ͼ���� : ";
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
                cout << endl << "����������!!!" << endl << endl;
                break;
            }
            else
            {
                cout << endl << "�Բ���,��û�н����ͼ�����������ı�Ŵ���!!!" << endl << endl;
                break;
            }
        }
    }
    reader.close();
   
    if (!flag1)
    {
        cout << endl << "�Բ��𣬸��û�������!!!" << endl << endl;
    }
    system("pause");
}

void mulclass::query_inter()
{
    while (1)
    {
        system("cls");
        cout << endl << endl << "\t��Ϣ��ѯ " << endl << endl
            << "\t��    1.  ͼ����Ϣ��ѯ" << endl << endl
            << "\t��    2.  �û��Ľ�����ʷ" << endl << endl
            << "\t��    3.  ����" << endl << endl;
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
    cout << endl << "ͼ����Ϣ��ѯ" << endl << endl;
    cout << "�����������ѯ��ͼ���� : ";
    string bookno;
    cin >> bookno;
   
    ifstream bookfile("info\\book\\total.txt");
    if (!bookfile)
    {
        cout << endl << "�Բ���,���Ϊ��!!!" << endl << endl;
        system("pause");
        return;
    }
   
    string bookname;
    string bookno1;
    while (bookfile >>  bookno1  >>bookname)
    {
        if (bookno == bookno1)
        {
            cout << endl << "��Ҫ��ѯ��ͼ����Ϣ���� : " << endl << endl;
           
            cout << "  ��� : " << bookno << endl << endl;
			 cout << "ͼ���� : " << bookname << endl << endl;
            break;
        }
    }
    system("pause");
}

void mulclass::reader_query()
{
    system("cls");
    cout << endl << "�û��Ľ�����ʷ" << endl << endl;
    cout << "�������û���� : ";
    string readerno;
    cin >> readerno;
   
    string readername;
    string readerno1;
    ifstream reader1("info\\reader\\total.txt");
    if (!reader1)
    {
        cout << endl << "�Բ���, ���û�������!!" << endl << endl;
        system("pause");
        return;
    }
    while (reader1 >> readerno1>>  readername)
    {
        if (readerno == readerno1)
        {
            cout << endl  << "��� : " << readerno <<"\t"  << "�û� : " << readername <<endl << endl;
            cout << setiosflags(ios::left) << setw(20) << "ͼ����"
                << setw(20) << "ͼ����" << endl << endl;
            string readerfile = "info\\reader\\"+readerno+".txt";
            ifstream reader(readerfile.c_str());
            if (!reader)
            {
                cout << endl << "���û���δ�����!!!" << endl << endl;
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
        cout << "\t�����������������������������" << endl
             << "\t                                                        " << endl
             << "\t            �û���Ϣ����                                " << endl
             << "\t                                                        " << endl
             << "\t��            1.  �½�                                  " << endl
             << "\t                                                        " << endl
             << "\t��            2.  �޸�                                  " << endl
             << "\t                                                        " << endl
             << "\t��            3.  ɾ��                                  " << endl
			 << "\t                                                        " << endl
			 << "\t��            4.  ��ѯ                                  " << endl
             << "\t                                                        " << endl
             << "\t��            0.  ����                                  " << endl
             << "\t                                                        " << endl
             << "\t�����������������������������" << endl << endl;
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
    cout << endl << "�½��û�" << endl << endl;

    cout << "�������ʾ�����µ��û���Ϣ : " << endl << endl;
   
    cout << endl << "  ��� : ";
    cin >> no;
	 cout << "�û��� : ";
    cin >> name;

    ofstream readerfile("info\\reader\\total.txt", ios::app);
    readerfile << setiosflags(ios::left) << no <<  " "
       << setw(20) << name << endl;
    readerfile.close();

    cout << endl << "���û���Ϣ�Ѿ�����!!!" << endl << endl;
    system("pause");
}

void reader::rework()
{
    system("cls");
    string findno;
    cout << endl << "�޸��û���Ϣ" << endl << endl;
    cout << "�������޸ĵ��û���� : ";
    cin >> findno;

    ifstream readerfile("info\\reader\\total.txt");
    if (!readerfile)
    {
        cout << endl << "�Բ���û������û�����Ϣ!!!" << endl << endl;
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
            cout << endl << "�����޸ĵ��û���Ϣ���� : " << endl << endl;
            cout << "��� : " << no << endl << endl;
			cout << "���� : " << name << endl << endl;

            cout << "�������������µ���Ϣ : " << endl << endl;
           cout << endl << "  ��� : ";
            cin >> no;
			 cout << "�û��� : ";
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
        cout << endl << "����Ϣ�Ѿ��ɹ�����!!" << endl << endl;
    }
    else
        cout << endl << "�Բ���û������û�����Ϣ!!!" << endl << endl;
    system("pause");
}

void reader::lookfor()
{
	system("cls");
	cout<<endl<<"��������߱�ţ�"<<endl<<endl;
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
            cout << "    ��� : " << no << endl << endl << "ͼ������ : " << name << endl << endl<< endl;
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
        cout << endl << "����û�������ѯ�Ķ���!!!" << endl << endl;
    system("pause");
}

		void reader::delet()
{
    system("cls");
    cout << endl << "ɾ���û���Ϣ" << endl << endl;
    string findno;
    cout << "����������ɾ���û���� : ";
    cin >> findno;

    ofstream temp("info\\reader\\temp.txt");
    ifstream readerfile("info\\reader\\total.txt");
    if (!readerfile)
    {
        cout << endl << "�Բ����û���Ϣ��Ϊ��!!!" << endl << endl;
        system("pause");
        return;
    }
    bool flag = false;
    while (readerfile >>no  >> name)
    {
        if (no == findno)
        {
            flag = true;
            cout << endl << "����ɾ�����û���Ϣ���� : " << endl << endl;
            
            cout << "��� : " << no << endl << endl;
			cout << "���� : " << name << endl << endl;

            cout << "��ȷ����ɾ����(y/n) : ";
            if (getch() == 'n')
            {
                temp.close();
                readerfile.close();
                cout << endl << "��Ϣû�и���!!!" << endl << endl;
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
        cout << endl << endl << "���û���Ϣ�Ѿ�ɾ��!!" << endl << endl;
    }
    else
        cout << endl << endl << "�Բ���, û�и��û�����Ϣ !!" << endl << endl;
    system("pause");
}


char inter_face1()
{
    system("cls");
   cout << endl << endl;
    cout << "\t��������������������������������������������������������������" << endl
         << "\t��                                                          ��" << endl
         << "\t��                   ͼ �� �� �� ϵ ͳ                      ��" << endl
		 << "\t��            ................................              ��" << endl
         << "\t��                                                          ��" << endl
         << "\t��                                                          ��" << endl
         << "\t��                   1.ͼ�����Ա                           ��" << endl
         << "\t��                                                          ��" << endl
         << "\t��                   2.����                                 ��" << endl
         << "\t��                                                          ��" << endl
         << "\t��                   0.�˳�ϵͳ                             ��" << endl
         << "\t��                                                          ��" << endl
         << "\t��                                                          ��" << endl
         << "\t��                                                          ��" << endl
         << "\t��������������������������������������������������������������" << endl << endl;
    cout << "\t��ѡ�������ݣ�1��2����";
    return getch();
}
	char inter_face2()
{
    system("cls");
    cout << endl << endl;
   cout << "     \t�����������������������������" << endl
             << "\t                                                        " << endl
             << "\t                                                        " << endl
             << "\t��            1.  �û���Ϣ����                          " << endl
             << "\t                                                        " << endl
             << "\t��            2.  ͼ����Ϣ����                          " << endl
			 << "\t                                                        " << endl
             << "\t��            3.  �޸�����                              " << endl
             << "\t                                                        " << endl
             << "\t��            0.  ����                                  " << endl
             << "\t                                                        " << endl
             << "\t�����������������������������" << endl << endl;
        cout << "\t\t\t";

    return getch();
}

	char inter_face3()
{
    system("cls");
    cout << endl << endl;
   cout << "     \t�����������������������������" << endl
             << "\t                                                        " << endl
             << "\t                                                        " << endl
             << "\t��            1. ���ģ��黹��ͼ��                       " << endl
             << "\t                                                        " << endl
             << "\t��            2. ��Ϣ��ѯ                               " << endl
             << "\t                                                        " << endl
             << "\t��            0. ����                                   " << endl
             << "\t                                                        " << endl
             << "\t�����������������������������" << endl << endl;
        cout << "\t\t\t";

    return getch();
}
	char inter_face5()
{
    system("cls");
    cout << endl << endl;
	cout<<"********************************************************************************"<<endl<<endl;
  cout<<"\t\t\t  л  л  ʹ  ��\n\n\t\t...................................\n\n\t\t\t  ��ӭ�ٴ�ʹ��\n\n"<<endl<<endl;
cout<<"********************************************************************************"<<endl<<endl;
    return getch();
}
char inter_face6()
{
    system("cls");
    cout << endl << endl;
   cout << "     \t�����������������������������" << endl
             << "\t                                                        " << endl
             << "\t                                                        " << endl
             << "\t��            1. ��ʦ                                   " << endl
             << "\t                                                        " << endl
             << "\t��            2. �о���                                 " << endl
             << "\t                                                        " << endl
             << "\t��            3. ������                                 " << endl
             << "\t                                                        " << endl
			 << "\t��            0. ����                                   " << endl
			 << "\t                                                        " << endl
			 << "\t                                                        " << endl
             << "\t�����������������������������" << endl << endl;
        cout << "\t";
cout<<"��ѡ��������ݣ�1��3����";

    return getch();
}
	
	
char inter_face9()
{
    system("cls");
    cout << endl << endl;
   cout << "     \t�����������������������������" << endl
             << "\t                                                        " << endl
			 << "\t       ϵͳ��ʾ��                                       " << endl
             << "\t             �����ɽ�10���飬�����������             " << endl
             << "\t                                                        " << endl
             << "\t�����������������������������" << endl << endl;
        cout << "\t\t\t";

    return getch();
}
char inter_face10()
{
    system("cls");
    cout << endl << endl;
   cout << "     \t�����������������������������" << endl
             << "\t                                                        " << endl
             << "\t       ϵͳ��ʾ��                                       " << endl
             << "\t             �����ɽ�8���飬�����������             " << endl
             << "\t                                                        " << endl
             << "\t�����������������������������" << endl << endl;
        cout << "\t\t\t";

    return getch();
}
char inter_face11()
{
    system("cls");
    cout << endl << endl;
   cout << "     \t�����������������������������" << endl
             << "\t                                                        " << endl
             << "\t       ϵͳ��ʾ��                                       " << endl
             << "\t             �����ɽ�5���飬�����������              " << endl
             << "\t                                                        " << endl
             << "\t�����������������������������" << endl << endl;
        cout << "\t\t\t";

    return getch();
}

double inter_face7()
	{double a;
		system("cls");
    cout << endl<<endl ;
   cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<< endl << endl << endl;
   cout<<" \n\n\t\t     ϵͳ��ʾ�����������룺";

			   cin>>a;
		   return a;}

	char inter_face8 ()
	{system("cls");
    cout << endl<<endl ;
   cout << "********************************************************************************"<< endl << endl << endl;
	   cout<<" \n\n\n\t\t\t�������벻��ȷ�����������룺\n\n\t\t\t    �����������...."<< endl << endl<< endl << endl;
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
	   cout<<" \n\n\n\t\t\t���������룺";
	   cin>>b;
	 cout<<"\t\t\t�ٴ��������룺";
	cin>>c;
	if(b==c) 
	{code=b;
	return 1;}
	else {return 0;}
	}
void xiugai()
{

	if(inter_face12()==1){ cout<<"\n\n\t\t\t�����޸ĳɹ�!\n\n";system("pause");}
	
else {cout<<"\n\n\t\t\t���������������������!\n\n";system("pause");xiugai();}


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

