#include <iostream>
#include "Complex.h"
using namespace std;
int main(){
    setlocale(LC_ALL,"Russian");
    int choice = 1;
    string stringchoice;
    double data1,data2;
    ComplexAlg Aalg,Balg,tmp1;
    ComplexTrig Atrig,Btrig,tmp2;
    ComplexExp Aexp,Bexp;
    while (true){
        cout<<"Сделайте выбор:\n";
        cout<<"1)Установить значение ячейки\n";
        cout<<"2)A+B\n";
        cout<<"3)A-B\n";
        cout<<"4)A*B\n";
        cout<<"5)A/B\n";
        cout<<"6)Тригонометрические функции\n";
        cout<<"7)Логарифмы\n";
        cout<<"8)Возведение в степень\n";
        cout<<"9)Кв. Корень\n";
        cout<<"10)Показать все формы\n";
        cout<<"X)Выход\n";
        cout<<">>";cin>>choice;
        switch(choice){
            case 1:
                cout<<"----------------------------------------------------------------------\n";
                cout<<"В какую ячейку установить Значение(A - 1 \\ B - 2)?\n";
                cout<<">>";cin>>choice;
                if(choice == 1){
                    cout<<"В какой форме записать?\n1)Алг\n2)Триг.\n3)Эксп\n";
                    cout<<">>";cin>>choice;
                    if (choice == 2){
                        cout<<"Введите модуль и аргумент:\n";
                        cout<<"Mod:";
                        cin>>data1;
                        cout<<"Arg:";
                        cin>>data2;
                        Atrig.setNum(data1,data2);
                        Aalg = to_alg(Atrig);
                        Aexp = to_exp(Atrig);
                        cout<<"триг форма успешно записана в ячейку A!\n";
                        cout<<"----------------------------------------------------------------------\n";
                    }else if(choice == 3){
                        cout<<"Введите модуль и аргумент:\n";
                        cout<<"Mod:";
                        cin>>data1;
                        cout<<"Arg:";
                        cin>>data2;
                        Aexp.setNum(data1,data2);
                        Aalg = to_alg(Aexp);
                        Atrig = to_trig(Aexp);
                        cout<<"эксп форма успешно записана в ячейку A!\n";
                        cout<<"----------------------------------------------------------------------\n";
                    } else {
                        cout<<"Введите действ. и мнимую часть:\n";
                        cout<<"Re:";
                        cin>>data1;
                        cout<<"Im:";
                        cin>>data2;
                        Aalg.setNum(data1,data2);
                        Atrig = to_trig(Aalg);
                        Aexp = to_exp(Aalg);
                        cout<<"алг форма успешно записана в ячейку A!\n";
                        cout<<"----------------------------------------------------------------------\n";
                    }//if incl
                } else {
                    cout<<"В какой форме записать?\n1)Алг\n2)Триг.\n3)Эксп\n";
                    cout<<">>";cin>>choice;
                    if (choice == 2){
                        cout<<"Введите модуль и аргумент:\n";
                        cout<<"Mod:";
                        cin>>data1;
                        cout<<"Arg:";
                        cin>>data2;
                        Btrig.setNum(data1,data2);
                        Balg = to_alg(Btrig);
                        Bexp = to_exp(Btrig);
                        cout<<"триг форма успешно записана в ячейку B!\n";
                        cout<<"----------------------------------------------------------------------\n";
                    }else if(choice == 3){
                        cout<<"Введите модуль и аргумент:\n";
                        cout<<"Mod:";
                        cin>>data1;
                        cout<<"Arg:";
                        cin>>data2;
                        Bexp.setNum(data1,data2);
                        Balg = to_alg(Bexp);
                        Btrig = to_trig(Bexp);
                        cout<<"эксп форма успешно записана в ячейку B!\n";
                        cout<<"----------------------------------------------------------------------\n";
                    } else {
                        cout<<"Введите действ. и мнимую часть:\n";
                        cout<<"Re:";
                        cin>>data1;
                        cout<<"Im:";
                        cin>>data2;
                        Balg.setNum(data1,data2);
                        Btrig = to_trig(Balg);
                        Bexp = to_exp(Balg);
                        cout<<"алг форма успешно записана в ячейку B!\n";
                        cout<<"----------------------------------------------------------------------\n";
                    }//if incl
                }//if main
                break;
            case 2:
                tmp1 = Aalg + Balg;
                show_forms(tmp1);
                break;
            case 3:
                tmp1 = Aalg - Balg;
                show_forms(tmp1);
                break;
            case 4:
                tmp2 = Atrig * Btrig;
                show_forms(tmp2);
                break;
            case 5:
                tmp2 = Atrig / Btrig;
                show_forms(tmp2);
                break;
            case 6:
                cout<<"Какую ячейку использовать?(A - 1 \\ B - 2)\n";
                cout<<">>";cin>>choice;
                if(choice == 1){
                        cout<<"Какую триг функцию использовать?\n";
                        cout<<"1)sin()\n";
                        cout<<"2)cos()\n";
                        cout<<"3)tg()\n";
                        cout<<"4)ctg()\n";
                        cout<<">>";cin>>choice;
                        if(choice == 1){
                            tmp1 = Csin(Aalg);
                            show_forms(tmp1);
                        } else if(choice == 2){
                            tmp1 = Ccos(Aalg);
                            show_forms(tmp1);
                        }else if(choice == 3){
                            tmp1 = Ctg(Aalg);
                            show_forms(tmp1);
                        }else{
                            tmp1 = Cctg(Aalg);
                            show_forms(tmp1);
                        }//if incl
                } else{
                        cout<<"Какую триг функцию использовать?\n";
                        cout<<"1)sin()\n";
                        cout<<"2)cos()\n";
                        cout<<"3)tg()\n";
                        cout<<"4)ctg()\n";
                        cout<<">>";cin>>choice;
                        if(choice == 1){
                            tmp1 = Csin(Balg);
                            show_forms(tmp1);
                        } else if(choice == 2){
                            tmp1 = Ccos(Balg);
                            show_forms(tmp1);
                        }else if(choice == 3){
                            tmp1 = Ctg(Balg);
                            show_forms(tmp1);
                        }else{
                            tmp1 = Cctg(Balg);
                            show_forms(tmp1);
                        }//if incl
                }//if main
                break;
            case 7:
                cout<<"От какой ячейки взять логарифм?(A - 1 \\ B - 2)\n";
                cout<<">>";cin>>choice;
                if(choice == 1){
                    cout<<"Какой логарифм взять?\n";
                    cout<<"1)log(Осн 2)\n";
                    cout<<"2)lg\n";
                    cout<<"3)ln\n";
                    cout<<">>";cin>>choice;
                    if(choice == 1){
                        tmp1 = Clog(Aalg);
                        show_forms(tmp1);
                    }else if(choice == 2){
                        tmp1 = Clg(Aalg);
                        show_forms(tmp1);
                    }else{
                        tmp1 = Cln(Aalg);
                        show_forms(tmp1);
                    }//if incl
                }else{
                    cout<<"Какой логарифм взять?\n";
                    cout<<"1)log(Осн 2)\n";
                    cout<<"2)lg\n";
                    cout<<"3)ln\n";
                    cout<<">>";cin>>choice;
                    if(choice == 1){
                        tmp1 = Clog(Balg);
                        show_forms(tmp1);
                    }else if(choice == 2){
                        tmp1 = Clg(Balg);
                        show_forms(tmp1);
                    }else{
                        tmp1 = Cln(Balg);
                        show_forms(tmp1);
                    }//if incl
                }//if main
                break;
            case 8:
                cout<<"Какую ячейку возвести в степень?(A - 1 \\ B - 2)\n";
                cout<<">>";cin>>choice;
                if(choice == 1){
                    cout<<"В какую степень возвести?"<<endl;
                    cout<<">>";cin>>data1;
                    tmp2 = Atrig.calc_pow(data1);
                    show_forms(tmp2);
                }else{
                    cout<<"В какую степень возвести?"<<endl;
                    cout<<">>";cin>>data1;
                    tmp2 = Btrig.calc_pow(data1);
                    show_forms(tmp2);
                }
                break;
            case 9:
                cout<<"Кв. корень какой ячейки извлечь?(A - 1 \\ B - 2)\n";
                cout<<">>";cin>>choice;
                if(choice == 1){
                    tmp2 = Atrig;
                    tmp2 = tmp2.sqroot();
                    show_forms(tmp2);
                }else{
                    tmp2 = Btrig;
                    tmp2 = tmp2.sqroot();
                    show_forms(tmp2);
                }
                break;
            case 10:
                cout<<"Какую ячейку показать?(A - 1 \\ B - 2)\n";
                cout<<">>";cin>>choice;
                if(choice == 1){
                    show_forms(Aalg);
                } else {
                    show_forms(Balg);
                }
                break;
            default:
                cout<<"\n[!!!]Exiting[!!!]";
                getch();
                return 0;
                break;
        }//switch choice
    }//while true
    return 0;
}
