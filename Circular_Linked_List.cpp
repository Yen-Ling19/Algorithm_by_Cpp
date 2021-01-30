#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

class LinkedList;

class ListNode
{
    public:
        ListNode();
        ListNode(int a, int b);
        friend class LinkedList;
    private:
        int exp;
        int coef;
        ListNode *next;
};

class LinkedList
{
    public:
        LinkedList();
        void Push(); //新增資料
        void Print(); //輸出
        void Multi(LinkedList&A, LinkedList&B);
    private:
        ListNode *last;
};

LinkedList::LinkedList()
{
    last = NULL;
}

ListNode::ListNode(int a, int b)
{
    coef = a;
    exp = b;
    next = NULL;
}

void LinkedList::Push()
{
    int Exp, Coef;
    cin >> Coef >> Exp;
    //Coef = 1;
    //Exp = rand() % 500 + 1;
    ListNode *A = new ListNode(Coef, Exp);
    if(last==NULL){
        last = A;
        A->next = A;
    }
    A->next = last->next;
    last->next = A;
    last = A;
}

void LinkedList::Print()
{
    ListNode *ptr;
    ptr = last->next;
    int times = 0;
    while(ptr!=last){
        if((ptr->coef>=0)&&(times!=0)){
            cout << "+";
        }
        cout << ptr->coef << "x^" << ptr->exp;
        ptr = ptr->next;
        times++;
    }
    if((last->coef>=0)&&(times!=0)){
        cout << "+";
    }
    if(last->exp==0){
        cout << last->coef << endl;
    }else
        cout << last->coef << "x^" << last->exp << endl;
}

void LinkedList::Multi(LinkedList&A, LinkedList&B)
{
    int times = 0;
    ListNode *ptr_A;
    ptr_A = A.last->next;
    ListNode *ptr_B;
    ptr_B = B.last->next;
    ListNode *ptr_B_Last;
    ptr_B_Last = B.last;
    ListNode *now;
    bool first = true;
    int t = 0;
    while((ptr_A!=A.last->next)||(times==0)){
        int Coef = ptr_A->coef * ptr_B->coef;
        int Exp = ptr_A->exp + ptr_B->exp;
        if(first==false){
            while((now!=last)||(t==1)){
                if(Exp==last->exp){
                    last->coef = last->coef + Coef;
                    break;
                }
                if(Exp<last->exp){
                    ListNode *C = new ListNode(Coef, Exp);
                    C->next = last->next;
                    last->next = C;
                    last = C;
                    break;
                }
                if(Exp==now->exp){
                    now->coef = now->coef + Coef;
                    break;
                }
                if((Exp>now->next->exp)&&(Exp<now->exp)){
                    ListNode *C = new ListNode(Coef, Exp);
                    C->next = now->next;
                    now->next = C;
                    break;
                }
                now = now->next;
                t++;
            }
        }
        if(first==true){
            ListNode *C = new ListNode(Coef, Exp);
                last = C;
                C->next = C;
                now = C;
                first = false;
                t = 1;
        }
        if(ptr_B==ptr_B_Last){
            ptr_A = ptr_A->next;
            times++;
        }
        ptr_B = ptr_B->next;
        now = last -> next;
        t = 1;
    }
}

int main()
{
    //clock_t t1, t2;
    //float dif = 0.0;
    //srand(time(NULL));

    LinkedList Poly_1;
    int num1;
    cin >> num1;
    for (int i = 0; i < num1; i++){
        Poly_1.Push();
    }
    LinkedList Poly_2;
    int num2;
    cin >> num2;
    for (int i = 0; i < num2; i++){
        Poly_2.Push();
    }
    LinkedList Poly_3;

    //t1 = clock();
    Poly_3.Multi(Poly_1, Poly_2);
    //t2 = clock();
    
    Poly_3.Print();
    
    //dif = (float)(t2 - t1)/CLOCKS_PER_SEC;
    //cout << dif << endl;
}