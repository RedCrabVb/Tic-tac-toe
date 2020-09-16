import java.util.Scanner;
import java.util.Random;
import java.io.*;

public class Program{
  public static void main (String args[]){
        GameImplement gameImplement = new GameImplement();
        GameLogic gameLogic = new GameLogic();

        gameImplement.standart_setengs();
        while(gameLogic.game){
                gameImplement.show_tabl();
                gameImplement.control(gameImplement.pos, gameImplement.arr_tabl[gameImplement.pos]);
                gameLogic.Enemy_v();
        }
        gameImplement.EndTextAndFirst(gameLogic.endAndStart);
  }
}
