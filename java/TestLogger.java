import java.util.logging.*;
import java.io.IOException;

public class TestLogger { 
    public static void main(String[] args) throws IOException { 
        Logger log = Logger.getLogger("lavasoft"); 
        log.setLevel(Level.INFO); 
        log.info("Info"); 
        log.warning("Warn");

        System.out.println("\033["+36+";4m" + "蓝绿-Tracef" + "\033[0m"); 
        System.out.println("\033[33;4m" + "黄色-Debugf" + "\033[0m"); 
        System.out.println("\033[32;4m" + "绿色-Infof" + "\033[0m"); 
        System.out.println("\033[91;4m" + "淡橙色-Warnf" + "\033[0m"); 
        System.out.println("\033[31;4m" + "红色-Errorf" + "\033[0m"); 
        System.out.println("\033[35;4m" + "我是什么色-Faltf" + "\033[0m"); 

        ColorOut(36,"测试一下","\033[",";4m","\033[0m");
    } 
    public static void ColorOut(int colorCode,String text, String colorFormatOne, String colorFormatTwo, String colorFormatAfter){
        System.out.println(""+colorFormatOne+""+colorCode+""+colorFormatTwo+""+text+""+colorFormatAfter+"");
    }
}