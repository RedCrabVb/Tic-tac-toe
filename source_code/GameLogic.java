import java.util.Scanner;
import java.util.Random;
import java.io.*;

public class GameLogic{
  GameImplement gameImplement = new GameImplement();
  Random rnd = new Random(System.currentTimeMillis());

  public static boolean game = true;
  public static String endAndStart;

  boolean check_endBad(char[] arr_tabl){
         boolean gameBad = false;
         for(int i = 0; i < 9; i++){
              if(arr_tabl[i] == ' '){gameBad = true;}
              else if(arr_tabl[i] == '+'){endAndStart = "Bug";}
          }
          if(game == false){
                  gameBad = false;
          }
          else if(game == true && gameBad == false){
                  gameImplement.show_tabl();
                  gameBad = false;
                  endAndStart = "ничья!";
          }
          return gameBad;
  }

  void win(char[] arr_tabl){
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
                  game = check_endBad(gameImplement.arr_tabl);
          }

          if(win != ' '){
            GameImplement.show_tabl();
            endAndStart = "Победил " + win + "!!!";
          }
        }

        public void Enemy_v(){
                boolean k = check_endBad(GameImplement.arr_tabl);
                while(k){
                        int ran = 0 + rnd.nextInt(8 + 1);
                        if((GameImplement.arr_tabl[ran] != GameImplement.Player) && (GameImplement.arr_tabl[ran] != GameImplement.Enemy)){
                                GameImplement.arr_tabl[ran] = GameImplement.Enemy;
                                k = false;
                                win(gameImplement.arr_tabl);
                                }
                }
        }

}
