#include <iostream>
#include <ctime>
#include <stdio.h>
#include <unistd.h>
#include <termios.h>

using namespace std;

char arr_tabl[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
char I, ai, vis;// см standart_setengs
int g;//см standart_setengs
bool game = true;

struct termios old_tio, new_tio;//для каретной работы клавиш
unsigned char con; //con - control

void show_tabl(){
        system("clear");
        for(int j = 1; j <= 1; j++){
                printf("\x1b[7;37m\n %c | %c | %c \n - | - | - \x1b[0m", arr_tabl[j-1], arr_tabl[j], arr_tabl[j+1]);
                printf("\x1b[7;37m\n %c | %c | %c \n - | - | - \x1b[0m", arr_tabl[j+2], arr_tabl[j+3], arr_tabl[j+4]);
                printf("\x1b[7;37m\n %c | %c | %c \x1b[0m\n", arr_tabl[j+5], arr_tabl[j+6], arr_tabl[j+7]);
                printf("\n");
        }
}

//ничья
bool check_endBad(){

       bool eb = false;
       for(int i = 0; i < 9; i++){
            if(arr_tabl[i] == ' '){eb = true;}
            else if(arr_tabl[i] == '+'){cout<<"bag\a";}
        }
        if(game == false){
                eb = false;
        }
        else if(game == true && eb == false){
                show_tabl();
                eb == false;
                cout<<"ничья!\n";
        }
        return eb;
}

//проверка на победу
void win(){
        char win = ' ';
  //---
        if(arr_tabl[0] == arr_tabl[1] && arr_tabl[1] == arr_tabl[2] && arr_tabl[0] != ' '){
                win = arr_tabl[0];
                game = false;
        }
        else if(arr_tabl[3] == arr_tabl[4] && arr_tabl[4] == arr_tabl[5] && arr_tabl[3] != ' '){
                win = arr_tabl[3];
                game = false;
              }
        else  if(arr_tabl[6] == arr_tabl[7] && arr_tabl[7] == arr_tabl[8] && arr_tabl[8] != ' '){
                win = arr_tabl[6];
                game = false;
        }
  //|||
        else if(arr_tabl[0] == arr_tabl[3] && arr_tabl[3] == arr_tabl[6] &&  arr_tabl[6] != ' '){
                win = arr_tabl[0];
                game = false;
        }
        else if(arr_tabl[1] == arr_tabl[4] && arr_tabl[4] == arr_tabl[7] && arr_tabl[1] != ' '){
                win = arr_tabl[1];
                game = false;
        }
        else if(arr_tabl[2] == arr_tabl[5] && arr_tabl[5] == arr_tabl[8] && arr_tabl[5] != ' '){
                win = arr_tabl[2];
                game = false;
        }
  //\/
        else if(arr_tabl[0] == arr_tabl[4] && arr_tabl[4] == arr_tabl[8] && arr_tabl[4] != ' '){
                win = arr_tabl[0];
                game = false;
        }
        else if(arr_tabl[2] == arr_tabl[4] && arr_tabl[4] == arr_tabl[6] && arr_tabl[4] != ' '){
                win = arr_tabl[2];
                game = false;
        }
        else{
                game = check_endBad();
        }

        if(win != ' '){
          show_tabl();
          printf("\x1b[7;34mПобедил  %c!\x1b[0m\n", win);
        }
}

//стандартное управление wasd, запись r + не требуется нажатие enter решение подсмотрел
int control(int i, char swapp){
        swapp = arr_tabl[i];
        arr_tabl[i] = vis;
        show_tabl();

        con=getchar();
//      cin>>con;
        switch(con){
                case 'd':
                        arr_tabl[i] = swapp;
                        i++;
                        if((i >= 9) || (i < 0))
                                 i--;
                        break;
                case 'a':
                        arr_tabl[i] = swapp;
                        i--;
                        if((i >= 9) || (i < 0))
                                 i++;
                        break;
                case 'r':
                        if(swapp == ' '){
                                arr_tabl[i] = I;
                                show_tabl();
                                cout<<"\a";
                                win();
                                return 1;

                        }
                else{
                                cout<<"\x1b[5;37mNo\n\a\x1b[0m";
                                arr_tabl[i] = swapp;
                                i = 0;
                                system("sleep 0.9");
                        }
                        break;
                case 's':
                        arr_tabl[i] = swapp;
                        i+=3;
                        if(i >= 9)
                                 i-=3;
                        break;
                case 'w':
                        arr_tabl[i] = swapp;
                        i-=3;
                        if(i<0)
                                i+=3;
                        break;
                default:
                        arr_tabl[i] = swapp;
                        i = 0;
                        system("sleep 0.3");
                        break;
        }
        control(i, swapp);
        return 0;
}

//симулирует играка
void ai_v(){
        bool k = check_endBad();
        while(k){
                int ran = rand() % 8;
                if((arr_tabl[ran] != I) && (arr_tabl[ran] != ai)){
                        arr_tabl[ran] = ai;
                        k = false;
                        win();
                        }
        }
}

void standart_setengs(){
        vis = '@';
        g = 0;//стандартная позиция
        cout<<"\x1b[5;32mКонтроль: a, w, s, d - перемещение r-запесь\x1b[0m";
        cout<<"\n\vКого выберете? 0 или X или ...? ";
        cin>>I;
        if(I == 'X' || I == 'x')
                ai = '0';
        else
                ai = 'X';
}

int main(){
        //для клавиш
        tcgetattr(STDIN_FILENO,&old_tio);
        new_tio=old_tio;
        new_tio.c_lflag &=(~ICANON & ~ECHO);
        tcsetattr(STDIN_FILENO,TCSANOW,&new_tio);

        standart_setengs();
        srand(time(0));
        while(game){
                show_tabl();
                control(g, arr_tabl[g]);
                system("sleep 0.3");
                ai_v();
        }
        //Ввозвращаем клавиатуру
        tcsetattr(STDIN_FILENO,TCSANOW,&old_tio);
        return 0;
}
