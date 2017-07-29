// C++安全数组.cpp : 定义控制台应用程序的入口点。
//

#ifndef ARRAY_H
#define ARRAY_H

//#include <cstdarg>

#ifndef ARRAY_CHECK
#include <cassert>
#define ARRAY_CHECK(Exp) assert(Exp)
#endif

namespace std{
    struct random_access_iterator_tag;
}
namespace wwb{

template <typename T> struct const_imp{};

template <typename T>
struct const_imp<T*>
{
    typedef T type;
};

template <typename T>
struct const_imp<const T*>
{
    typedef T type;
};

template <typename T>
struct remove_const
{
    typedef typename const_imp<T*>::type type;
};





template<int N>
class _MakeHelper{
public:
    int sizes[N];
    _MakeHelper<N+1> operator[](int x){
        _MakeHelper<N+1> next;
        for(int i=0;i<N;i++)
            next.sizes[i]=sizes[i];
        next.sizes[N]=x;
        return next;
    }
};
template<>
class _MakeHelper<0>{
public:
    _MakeHelper<1> operator[](int x){
        _MakeHelper<1> next;
        next.sizes[0]=x;
        return next;
    }
};
_MakeHelper<0> _mkh;

template<class T,int DIM=1>
class FixedIterator{
    friend class FixedIterator<T,DIM+1>;
public:
    FixedIterator<T,DIM-1>& operator [](int index){
        ARRAY_CHECK(index>=0 && index<count);
        sub.first=first+index*offset;
        return sub;
    }
    FixedIterator():count(0),offset(0),first(0),sub(){}

protected:
    int count;//
    int offset;
    T* first;
    FixedIterator<T,DIM-1> sub;
    int getsize(int dim){
        if(dim==1)return count;
        else return sub.getsize(dim-1);
    }
    void setsize(int* psize){
        sub.setsize(psize+1);
        count=*psize;
        ARRAY_CHECK(count>0);
        offset=sub.count*sub.offset;
    }
    void setbound(T* begin,T* end){
        sub.setbound(begin,end);
    }

private:
    FixedIterator& operator =(const FixedIterator<T>& it1){}
};


template<class T> class FreeIterator;
template<class T>
class FixedIterator<T,1>{
    friend class FixedIterator<T,2>;
    friend class FreeIterator<T>;
    template<class U,int DIM2>friend class FixedIterator;

public:

    T& operator[](int index){
        ARRAY_CHECK(first!=0 && index>=0 && index<count);
        return first[index];
    }

    T& operator *(){
        ARRAY_CHECK(first!=end && first!=0);
        return *first;
    }
    T* operator ->(){
        ARRAY_CHECK(first!=end && first!=0);
        return first;
    }

    operator FixedIterator<const T>(){
        FixedIterator<const T> it;
        it.first=first;
        it.begin=begin;
        it.end=end;
        return it;
    }

    int operator -(const FixedIterator<T,1>& it1) const{
        return first-it1.first;
    }
    bool operator !=(const FixedIterator<T,1>& it1) const{
        return first!=it1.first;
    }
    bool operator ==(const FixedIterator<T,1>& it1) const{
        return first==it1.first;
    }
    bool operator >(const FixedIterator<T,1>& it1) const{
        return first>it1.first;
    }
    bool operator <(const FixedIterator<T,1>& it1) const{
        return first<it1.first;
    }
    bool operator >=(const FixedIterator<T,1>& it1) const{
        return first>=it1.first;
    }
    bool operator <=(const FixedIterator<T,1>& it1) const{
        return first<=it1.first;
    }

    FixedIterator():count(0),first(0),begin(0),end(0){}
protected:
    int count;//
    static const int offset=1;
    T* first,*begin,*end;

    int getsize(int dim){
        return count;
    }
    void setsize(int* psize){
        count=*psize;
        ARRAY_CHECK(count>0);
    }
    void setbound(T* pbegin,T *pend){
        begin=pbegin;
        end=pend;
    }

private:
    FixedIterator& operator =(const FixedIterator<T>& it1){
        count=0;
        begin=it1.begin;
        end=it1.end;
        first=it1.first;
        return *this;
    }
};
template<class T>
class FixedIterator<T,0>;

template<class T>
class FreeIterator:public FixedIterator<T,1>{
    template<class U,int DIM2> friend class FixedIterator;
    template<class U> friend class FreeIterator;
public:
    typedef std::random_access_iterator_tag iterator_category;
        typedef T value_type;
        typedef int difference_type;
        typedef T* pointer;
        typedef T& reference;
        typedef const T* const_pointer;
        typedef const T& const_reference;

    FreeIterator():FixedIterator<T,1>(){}
    FreeIterator(const FixedIterator<T,1>& base){
        this->first=base.first;
        this->begin=base.begin;
        this->end=base.end;
    }
    FreeIterator& operator =(const FixedIterator<T,1>& base){
        this->first=base.first;
        this->begin=base.begin;
        this->end=base.end;
        return *this;
    }
    operator FreeIterator<const T>(){
        FreeIterator<const T> it;
        it.first=this->first;
        it.begin=this->begin;
        it.end=this->end;
        return it;
    }

    T& operator[](int index){
        ARRAY_CHECK(this->first+index>=this->begin && this->first+index<this->end);
        return this->first[index];
    }

    FreeIterator<T>& operator+=(int x){
        this->first+=x;
        ARRAY_CHECK(this->first<=this->end);
        return *this;
    }
    FreeIterator<T>& operator-=(int x){
        this->first-=x;
        ARRAY_CHECK(this->first>=this->begin);
        return *this;
    }

    FreeIterator<T>& operator++(){
        ++this->first;
        ARRAY_CHECK(this->first<=this->end);
        return *this;
    }
    FreeIterator<T> operator++(int){
        FreeIterator<T> temp=*this;
        this->first++;
        ARRAY_CHECK(this->first<=this->end);
        return temp;
    }

    FreeIterator<T>& operator--(){
        --this->first;
        ARRAY_CHECK(this->first>=this->begin);
        return *this;
    }
    FreeIterator<T> operator--(int){
        FreeIterator<T> temp=*this;
        this->first--;
        ARRAY_CHECK(this->first>=this->begin);
        return temp;
    }
};
template<class T>
inline FreeIterator<T> operator +(const FixedIterator<T,1>& it2,int x){
    return FreeIterator<T>(it2)+=x;
}
template<class T>
inline FreeIterator<T> operator +(int x,const FixedIterator<T,1>& it2){
    return FreeIterator<T>(it2)+=x;
}
template<class T>
inline FreeIterator<T> operator -(const FixedIterator<T,1>& it2,int x){
    return FreeIterator<T>(it2)-=x;
}

template<class T,int DIM=1>
class NormalArray:public FixedIterator<T,DIM>{
public:
    typedef FreeIterator<T> iterator;
    typedef FixedIterator<T,DIM> pointer;
    int size(){
        return this->count*this->offset;
    }
    int size(int x){
        ARRAY_CHECK(x>0 && x<=DIM);
        return this->getsize(x);
    }

    NormalArray():data(0),FixedIterator<T,DIM>(){}
    explicit NormalArray(int (&sizes)[DIM],T* input=0):data(0){
        init(sizes,input);
    }
    explicit NormalArray(_MakeHelper<DIM> mkh,T* input=0):data(0){
        init(mkh.sizes,input);
    }
    explicit NormalArray(int size1,T* input=0):data(0){
        int sizes[]={size1};
        init(sizes,input);
    }
    NormalArray(int size1,int size2,T* input=0):data(0){
        int sizes[]={size1,size2};
        init(sizes,input);
    }
    NormalArray(int size1,int size2,int size3,T* input=0):data(0){
        int sizes[]={size1,size2,size3};
        init(sizes,input);
    }
    NormalArray(int size1,int size2,int size3,int size4,T* input=0):data(0){
        int sizes[]={size1,size2,size3,size4};
        init(sizes,input);
    }
    NormalArray(int size1,int size2,int size3,int size4,int size5,T* input=0):data(0){
        int sizes[]={size1,size2,size3,size4,size5};
        init(sizes,input);
    }
    //NormalArray(T* data,...){
    //    va_list ap;
    //    va_start(ap, data);

    //    int sizes[DIM];
    //    for(int i=0;i<DIM;i++)
    //         sizes[i] = va_arg(ap, int);

    //    va_end(ap); 
    //    init(sizes,0);
    //}

    ~NormalArray(){
        delete[] data;
    }

    void init(int (&sizes)[DIM],T* input=0){
        ARRAY_CHECK(data==0);

        this->setsize(sizes);
        int allsize=this->count*this->offset;
        NCT* data1=new NCT[allsize];
        this->data=data1;
        this->first=data;
        this->setbound(data,data+allsize);

        if(input){
            for(int i=0;i<allsize;i++)
                data1[i]=input[i];
        }
    }

private:
    typedef typename remove_const<T>::type NCT;
    T* data;
    NormalArray(const NormalArray& arr){};
    NormalArray& operator=(const NormalArray& arr){};

};
template<class T>
class NormalArray<T,0>;

template<class T,int N>
class Pointer{
public:
    typedef typename Pointer<T,N-1>::type* const type; 
};
template<class T>
class Pointer<T,0>{
public:
    typedef T type;
};

template<class T,int DIM=1>
class FastArray{
public:
    typedef T* iterator;
    typedef typename Pointer<T,DIM>::type pointer;

    int size(){
        return m_size;
    }
    int size(int x){
        ARRAY_CHECK(x>0 && x<=DIM);
        return m_sizes[x-1];
    }

    operator pointer(){
        return (pointer)pnt;
    }
    pointer operator ->(){
        return (pointer)pnt;
    }

    FastArray():data(0),pnt(0),m_size(0){
        for(int i=0;i<DIM;i++)
            m_sizes[i]=0;
    }
    explicit FastArray(int (&sizes)[DIM],T* input=0):data(0){
        init(sizes,input);
    }
    explicit FastArray(_MakeHelper<DIM> mkh,T* input=0):data(0){
        init(mkh.sizes,input);
    }
    explicit FastArray(int size1,T* input=0):data(0){
        int sizes[]={size1};
        init(sizes,input);
    }
    FastArray(int size1,int size2,T* input=0):data(0){
        int sizes[]={size1,size2};
        init(sizes,input);
    }
    FastArray(int size1,int size2,int size3,T* input=0):data(0){
        int sizes[]={size1,size2,size3};
        init(sizes,input);
    }
    FastArray(int size1,int size2,int size3,int size4,T* input=0):data(0){
        int sizes[]={size1,size2,size3,size4};
        init(sizes,input);
    }
    FastArray(int size1,int size2,int size3,int size4,int size5,T* input=0):data(0){
        int sizes[]={size1,size2,size3,size4,size5};
        init(sizes,input);
    }

    ~FastArray(){
        if((T*)pnt!=data)
            delete[] pnt;
        delete[] data;
    }

    void init(int (&sizes)[DIM],T* input){
        ARRAY_CHECK(data==0);

        int sizep=0;
        m_size=1;
        for(int i=0;i<DIM;i++){
            ARRAY_CHECK(sizes[i]>0);
            m_sizes[i]=sizes[i];
            m_size*=sizes[i];
            if(i<DIM-1)
                sizep+=m_size;
        }

        NCT* data1=new NCT[m_size];
        this->data=data1;
        if(sizep==0)pnt=(void**)data;
        else pnt=new void*[sizep];

        int temp=1;
        void** p1=pnt;
        for(int i=0;i<DIM-1;i++){
            temp*=sizes[i];
            if(i<DIM-2){
                void** p2=p1+temp;
                for(int j=0;j<temp;j++){
                    *p1=(void*)p2;
                    p1++;
                    p2+=sizes[i+1];
                }
            }
            else{
                T* p3=data;
                for(int j=0;j<temp;j++){
                    *p1=(void*)p3;
                    p1++;
                    p3+=sizes[i+1];
                }
            }
        }

        if(input){
            for(int i=0;i<m_size;i++)
                data1[i]=input[i];
        }
    }

private:
    int m_sizes[DIM];
    int m_size;
    T* data;
    void** pnt;
    typedef typename remove_const<T>::type NCT;

    FastArray(const FastArray& arr){};
    FastArray& operator=(const FastArray& arr){};
};
template<class T> class FastArray<T,0>;


}

#ifdef ARRAY_FAST
    #define array wwb::FastArray
#else
    #define array wwb::NormalArray
#endif 

#ifdef ARRAY_STATIC
    #define IArray(Type) Type*
    #define PArray(Type,Name,Sizes) Type (* const Name)Sizes
    #define MakeArray(Type,Name,Sizes) Type Name Sizes;
#else
    #define IArray(Type) array<Type>::iterator
    #define PArray(Type,Name,Sizes) \
    array<Type,sizeof(wwb::_mkh[1]Sizes.sizes)/sizeof(int)>::pointer Name
    #define MakeArray(Type,Name,Sizes) \
    array<Type,sizeof(wwb::_mkh Sizes.sizes)/sizeof(int)> Name(wwb::_mkh Sizes)
#endif

#endif



int error=0;
//#define ARRAY_CHECK(exp) if(!(exp))error++
//#define ARRAY_FAST
//#define ARRAY_STATIC
#define ARRAY_FAST
#include "array.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>
#include <ctime>
using namespace std;


array<int,2> arr0;
void test_create(){
    error=0;

    //int x=arr0[0][0];
    cout<<arr0.size()<<","<<arr0.size(1)<<","<<arr0.size(2)<<endl;
    int size0[2];
    size0[0]=size0[1]=10;
    arr0.init(size0,0);
    cout<<arr0.size()<<","<<arr0.size(1)<<","<<arr0.size(2)<<endl;
    //arr0.init(size0,0);

    //array<int,3> arr;
    array<int,3> arr(3,4,5);
    //array<int,3> arr2(arr);
    int sizes[]={3,4,5};
    array<string,3> arr2(sizes);
    //arr2=arr;
    MakeArray(bool,arr3,[3][4][5]);

    //array<int,3> arrx={2,3};
    //array<int,3> arrx1(-3,4,5);
    //sizes[1]=-4;
    //array<string,3> arrx2(sizes);
    //MakeArray(bool,arrx3,[3][4][-5]);

#ifdef ARRAY_FAST
    //for(int i=0;i<3;i++)
    //    cout<<i<<":"<<(void**)*(arr2.pnt+i)-arr2.pnt-3<<endl;
    //for(int i=3;i<15;i++)
    //    cout<<i-3<<":"<<(string*)*(arr2.pnt+i)-arr2.data<<endl;
#endif

    cout<<"error:"<<error<<endl;
}

void test_init(){
    double data[7]={1,2,3,4,5}; 
    array<double,2> arr4(3,3,data);
    int sizes2[]={3,3};
    array<double,2> arr5(sizes2,data);
    //for(int i=0;i<9;i++)
    //    cout<<*(arr5.data+i)<<",";
    cout<<arr5.size()<<","<<arr5.size(1)<<","<<arr5.size(2)<<endl;//1->0,3

    cout<<"error:"<<error<<endl;
}

void test_use(){
    int fa[]={2,2,2,2,2};
    array<char,5> far1(fa);
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            for(int k=0;k<2;k++)
                for(int l=0;l<2;l++)
                    for(int m=0;m<2;m++)
                        far1[i][j][k][l][m]=65+i*16+j*8+k*4+l*2+m;

    //int x1=far1[-1][0][0][0][0];
    //int x2=far1[0][2][0][0][0];
    //int x3=far1[0][0][-10][0][0];
    //int x4=far1[0][0][0][3][0];
    //int x5=far1[0][0][0][0][2];
    //int x6=far1[0][0][0][0][-1];

    array<char,2>::pointer p1=far1[1][1][1];//2->3
    array<char,2>::pointer p2=p1;
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            p1[i][j]=97+2*i+j;

    //for(int i=0;i<32;i++)
    //    cout<<i<<"::"<<*(far1.data+i)<<endl;

#ifdef ARRAY_FAST
    //for(int i=0;i<14;i++)
    //    cout<<i<<":"<<(void**)*(far1.pnt+i)-far1.pnt-2<<endl;
    //for(int i=14;i<30;i++)
    //    cout<<i-14<<":"<<(char*)*(far1.pnt+i)-far1.data<<endl;
#endif

    cout<<"error:"<<error<<endl;
}

void test_iter(){
    array<int>::iterator it1;
    //*it1;
    //it1[0];
    it1=arr0[0];
    array<int>::iterator it2=arr0[1];
    cout<<(it2-it1==10);
    cout<<(it1+10==it2);
    cout<<(10+it1==it2);
    cout<<(it1==it2-10);
    cout<<(it1+9!=it2);
    cout<<(it1<it2);
    cout<<(it1+10>=it2);
    cout<<(it1+11>=it2);
    cout<<(arr0[2]-11<=it2);
    cout<<(arr0[2]-10<=it2);
    cout<<(arr0[2]>9+it2);

    array<int>::iterator it3=it2=arr0[1];
    cout<<((it3++)-it2==0);
    cout<<(it2-(++it3)==-2);
    cout<<((--it3)==it2+1);
    cout<<(1+it2==it3--);
    cout<<(it2+2==(it3+=2));
    cout<<(arr0[1]==(it3-=2));

    //arr0[1]++;
    //--arr0[0];
    //arr0[0]-=0;
    //arr0[0]=it1;

    it2+=89;*it2;it2[0];
    //*(it1-1);
    //it1[-1];
    //it1--;
    //it2[1];
    //*(++it2);
    //it2[0];

    array<string> arr(1);
    arr[0]="abc";
    cout<<arr->length()<<arr[0].length();
    array<string*> arr2(1);
    arr2[0]=&arr[0];
    cout<<arr2[0]->length();

    cout<<"error:"<<error<<endl;
}

void print(string &s){s+="|";cout<<s;}
void test_algo(){
    ostream_iterator<string> oit(cout,",");
    string ss[9]={"a","b","3","4.0","A","b2","c"};
    string::iterator iter=ss[0].begin();
    string::iterator iter2=1+iter;
    
    array<string,2> arr(3,3,ss);
    copy(arr[0]+0,arr[0]+9,oit);cout<<endl;

    cout<<*max_element(arr[0]+0,arr[0]+9)<<endl;
    cout<<count_if(arr[0]+0,arr[0]+9,bind2nd(not_equal_to<string>(),"3"))<<endl;

    stable_partition(arr[0]+0,arr[0]+9,bind2nd(greater<string>(),"B"));
    copy(arr[0]+0,arr[0]+9,oit);cout<<endl;

    sort(arr[0]+0,arr[0]+9);
    copy(arr[0]+0,arr[0]+9,oit);cout<<endl;

    reverse_iterator<array<string>::iterator> rit(arr[0]+9);
    copy(rit,rit+9,oit);cout<<endl;

    for_each(rit,rit+9,print);cout<<endl;

    cout<<"error:"<<error<<endl;
}

void testfun(IArray(const int) pcx){}
void testfun2(IArray(int) px){}
void test_convert(){
    MakeArray(int,x,[1]);
    IArray(int) px=x;
    PArray(int,cpx,)=px;
    px=cpx;
    IArray(int)  px2=cpx;
    PArray(const int,cpcx,)=px;
    IArray(const int) pcx;//=cpx;
    pcx=cpx;  
    testfun(px);
    testfun2(cpx);

    //array<int> x2=x;

    //cpx=px;
    //x=px;
    //x=cpx;
    //cpcx=px;
    //cpcx=cpx;
    //cpcx=pcx;
    //PArray(int,cpx2,) =cpcx;
    //IArray(int) px3=pcx;

    MakeArray(int,xx,[2][2]);
    IArray(int) pxx=xx[0];
    PArray(int,cpxx,)=xx[1];
    PArray(int,cpxx2,[2])=xx;
    //xx[0]=pxx;
    //xx[1]=cpxx;
    //array<int,2> xx2=xx;
    //xx=cpxx2;
}

wwb::NormalArray<int,3> arrn(100,100,100);
wwb::FastArray<int,3> arrf(100,100,100);
int arrs[100][100][100];
void test_speed(){

    clock_t t0=clock();

    for(int t=0;t<100;t++)
        for(int i=0;i<100;i++)
            for(int j=0;j<100;j++)
                for(int k=0;k<100;k++)
                    arrn[i][j][k]=k;
    clock_t t1=clock();

    for(int t=0;t<100;t++)
        for(int i=0;i<100;i++)
            for(int j=0;j<100;j++)
                for(int k=0;k<100;k++)
                    arrf[i][j][k]=k;
    clock_t t2=clock();

    for(int t=0;t<100;t++)
        for(int i=0;i<100;i++)
            for(int j=0;j<100;j++)
                for(int k=0;k<100;k++)
                    arrs[i][j][k]=k;
    clock_t t3=clock();

    cout<<t1-t0<<","<<t2-t1<<","<<t3-t2<<endl;
}
int main(){
    test_create();
    test_init();
    test_use();
    test_iter();
    test_algo();
    test_convert();
    test_speed();
    return 0;
}
