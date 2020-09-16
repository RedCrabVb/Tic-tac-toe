import java.util.Scanner;
import java.util.Random;
import java.io.*;

public class GameImplement{
  public static char[] arr_tabl = new char[] {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};//{'1', '2', '3', '4', '5', '6', '7', '8', '9'};
  public static char Player, Enemy, dikor, con;

  int pos;
  Scanner scanner = new Scanner(System.in);

  public static void show_tabl(){
          System.out.print("\033[H\033[2J");
          System.out.flush();
          for(int j = 1; j <= 1; j++){
                  System.out.println("\n " + arr_tabl[j-1] + " | " + arr_tabl[j] + " | " + arr_tabl[j+1] + " \n" + " - | - | - ");
                  System.out.println(" " + arr_tabl[j+2] + " | " + arr_tabl[j+3] + " | " + arr_tabl[j+4] + " \n" + " - | - | - ");
                  System.out.println(" " + arr_tabl[j+5] + " | " + arr_tabl[j+6] + " | " + arr_tabl[j+7] + " \n");
                  System.out.println(" ");
         }
  }

  public void EndTextAndFirst(String str){
      System.out.println(str);
  }
  public int control(int i, char temp){
                temp = arr_tabl[i];
                arr_tabl[i] = dikor;
                 show_tabl();
                con = scanner.next().charAt(0);
                switch(con){
                        case 'd':
                                arr_tabl[i] = temp;
                                i++;
                                if((i >= 9) || (i < 0))
                                         i--;
                                break;
                        case 'a':
                                arr_tabl[i] = temp;
                                i--;
                                if((i >= 9) || (i < 0))
                                         i++;
                                break;
                        case 'r':
                                if(temp == ' '){
                                        arr_tabl[i] = Player;
                                        show_tabl();
                                        GameLogic gameLogic = new GameLogic();
                                        gameLogic.win(arr_tabl);
                                        return 1;

                                }
                        else{
                                        EndTextAndFirst("Нет");
                                        arr_tabl[i] = temp;
                                        i = 0;
                                        try {
                                            Thread.sleep(1500);
                                        } catch (InterruptedException e) {
                                            e.printStackTrace();
                                        }
                                }
                                break;
                        case 's':
                                arr_tabl[i] = temp;
                                i+=3;
                                if(i >= 9)
                                         i-=3;
                                break;
                        case 'w':
                                arr_tabl[i] = temp;
                                i-=3;
                                if(i<0)
                                        i+=3;
                                break;
                        default:
                                arr_tabl[i] = temp;
                                i = 0;
                                try {
                                    Thread.sleep(2000);
                                } catch (InterruptedException e) {
                                    e.printStackTrace();
                                }
                                break;
                }
                control(i, temp);
                return 0;
  }

  public void standart_setengs(){
          dikor = '@';
          pos = 0;

          EndTextAndFirst("Контроль: a, w, s, d - перемещение r-запесь\n Кого выберете? 0 или X или ...? ");
          Player = scanner.next().charAt(0);
          if(Player == 'X' || Player == 'x')
                  Enemy = '0';
          else
                  Enemy = 'X';
  }

}
