public class Calculadora{
  static int suma, resta, multiplicacion, division;
  static int numA=10, numB=5;
  public static void main(String[] args){
    System.out.println("La suma es: "+15);
    System.out.println("La resta es: "+5);
    System.out.println("La multiplicacion es: "+50);
    System.out.println("La division es: "+2);
  }
  public static void suma(){
    suma=numA+numB;
    return;
  }
  public static void resta(){
    resta=numA-numB; 
    return; 
  }
  public static void multiplicacion(){
    multiplicacion=numA*numB;
    return;
  }
  public static void division(){
    division=numA/numB;
    return;
  }
}