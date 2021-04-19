public class Carro{
  private static String color;
  private static String marca;
  private static String modelo;

  public static void main(String[] argv){
    Valores("verde","subaru","2021");
    System.out.print("Este es un carro de color "+color+" de marca "+marca+" de modelo "+modelo);
  }
  public static void Valores(String col, String marc, String mod){
    color=col;
    marca=marc;
    modelo=mod;
  }
}