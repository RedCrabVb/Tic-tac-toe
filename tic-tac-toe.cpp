//version 0.1
//version 0.2
/*Добавлена графическая состовляющия; Вызов не нужного метода*/
#include <iostream>
#include <string>
#include <math.h>

#include <stdio.h>
#include <unistd.h>
#include <termios.h>

using namespace std;

int n, m;
long res;
char opt;

string yes_no = "\x1b[0;30;47my(да)/n(нет): \x1b[0m";
string error = "Выйди и зайди нармально! некркетный ввод\n\n";

long double fact(int N)
{
    if (N == 0)
        return 1;
    else
        return N * fact(N - 1); // делаем рекурсию.
}
//bag??
void repeat_all_no(){
  opt == ' ';
  cout<<"Есть повтор? " << yes_no<<endl;
  cin>>opt;
  if(opt == 'y' || opt == 'Y'){
    //A(-(m_n)=n^m;
    cout<<"A(-(m_n)=n^m"<<endl;
    res = pow(n,m);
  }
  else if(opt == 'n' || opt == 'N'){
    //A=n!(n-m)!
    cout<<"A=n!(n-m)!"<<endl;
    res = fact(n)/fact(n-m);
  }
  else{
    cout<<error<<endl;
  }
}

//Bug!!
void repeat_all_yes(){
  opt == ' ';
  cout<<"Есть повтор? "<< yes_no <<endl;
  cin>>opt;
  if(opt == 'y' || opt == 'Y'){
    cout<<"P(n)=n!/(n1!*n2!...nm!)"<<endl;
    //P(n)=n!/(n1!*n2!...nm!)
    res = fact(n)/fact(9);                    //Problev!!
  }
  else if(opt == 'n' || opt == 'N'){
    cout<<"P(n)=n!"<<endl;
    res = fact(n);
    //P(n)=n!
  }
  else{
    cout<<error<<endl;
  }
}

void slect_all(){
  opt == ' ';
  cout<<"Нужноли выбрать все элементы? " << yes_no <<endl;
  cin>>opt;
  if(opt == 'y' || opt == 'Y'){
    repeat_all_yes();
  }
  else if(opt == 'n' || opt == 'N'){
    repeat_all_no();
  }
  else{
    cout<<error<<endl;
  }
}

//Bug?
void repeat(){
  opt == ' ';
  cout<<"Есть повтор? "<< yes_no <<endl;
  cin>>opt;
  if(opt == 'y' || opt == 'Y'){
    cout<<"c(-m_n)=(n+m-1)!/(m!(n-1))"<<endl;
    res = fact((n+m-1))/(fact(m)*fact((n-1)));
  }
  else if(opt == 'n' || opt == 'N'){
    cout<<"c(m_n)=n!/(m!(n-m)!)"<<endl;
    res = fact(n)/(fact(m)*fact((n-m)));
  }
  else{
    cout<<error<<endl;
  }
}

void order(){
  opt == ' ';
  cout<<"Важен порядок? "<< yes_no <<endl;
  system("sleep 2");
  cin>>opt;
  if(opt == 'y' || opt == 'Y'){
      slect_all();
  }
  else if(opt == 'n' || opt == 'N'){
      repeat();
  }
  else{
    cout<<error<<endl;
  }
}

int main(){
  system("clear");
  cout<<"Алгоритм:"<<endl;
  cout<<"\x1b[4;31mn - общие кал-во элементо: \x1b[0m"<<endl;
  cin>>n;
  cout<<"\x1b[4;32mm - сколько эл.в выбора: \x1b[0m"<<endl;
  cin>>m;
  order();
  //Ввозвращаем клавиатуру
  cout<<"Результат: "<<res<<endl;
  return 0;
}
