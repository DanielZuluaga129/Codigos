import java.util.Scanner;
public class Numeros{
  private static int numA, numB, i;
  
  public static void main(String [] args){
    Scanner leer = new Scanner(System.in);
    
    System.out.println("Elija el limite inferior");
    int numA = leer.nextInt();

    System.out.println("Elija el limite superior");
    int numB = leer.nextInt();
    Numeros(numA,numB,i);
  }
  public static void Numeros(int i,int numA,int numB){
    for(i=numA;i<=numB;i+=2){
      System.out.println(i+",");
    }
    i=numA;

    while(i<numB){
      System.out.print(i+",");
      i+=2;
    }  
  }
}
