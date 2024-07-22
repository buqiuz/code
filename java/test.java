import java.util.Scanner;

public class test {
    public static void main(String[] args) {
        // byte a = 5;
        // byte b = 3;
        // byte c = (byte)(a + b);
        // System.out.println(c);
        
        // System.out.println(Byte.MAX_VALUE);
        // System.out.println(Byte.MIN_VALUE);
        // System.out.println(Integer.MAX_VALUE);
        // System.out.println(Integer.MIN_VALUE);
        // System.out.println(Long.MAX_VALUE);
        // System.out.println(Long.MIN_VALUE);
        // System.out.println(Short.MAX_VALUE);
        // System.out.println(Short.MIN_VALUE);
        // System.out.println(Float.MAX_VALUE);
        // System.out.println(Float.MIN_VALUE);
        // System.out.println(Double.MAX_VALUE);
        // System.out.println(Double.MIN_VALUE);

        
        // System.out.println(Character.MAX_VALUE);
        // System.out.println(Character.MIN_VALUE);

        // System.out.println(Boolean.TRUE);
        // System.out.println(Boolean.FALSE);



        // Scanner sc = new Scanner(System.in);
        // System.out.println("请输入三角形的三个边长：");
        // int a = sc.nextInt();
        // int b = sc.nextInt();
        // int c = sc.nextInt();

        // if (a+b>c&&a+c>b&&b+c>a){
        //     if(a*a==b*b+c*c||b*b==c*c+a*a||c*c==a*a+b*b){  
        //         System.out.println("直角三角形");  
        //     }else if(a==b||b==c||c==a){  
        //         System.out.println("等腰三角形");  
        //     }else if(a==b&&b==c){ 
        //         System.out.println("等边三角形");  
        //     }
        // }
        // else{  
        //     System.out.println("不是三角形");  
        // }
        // sc.close();



        // int a=1;
        // for(int i=1;i<10;i++){
        //     int temp=a;
        //      a=(a+1)*2;
        //     System.out.println(a-temp);
        // }
        // System.out.println(a);


        Scanner scanner = new Scanner(System.in);
        
        System.out.print("请输入你的名字: ");
        String name = scanner.nextLine();
        
        System.out.print("请输入你的年龄: ");
        int age = scanner.nextInt();
        scanner.nextLine(); // 清除缓冲区中的换行符
        
        System.out.print("请输入你的身高（米）: ");
        double height = scanner.nextDouble();
        scanner.nextLine(); // 清除缓冲区中的换行符
        
        System.out.print("你是否喜欢编程 (true/false): ");
        boolean likesProgramming = scanner.nextBoolean();
        
        System.out.println("名字: " + name);
        System.out.println("年龄: " + age);
        System.out.println("身高: " + height);
        System.out.println("喜欢编程: " + likesProgramming);

        int c=scanner.nextInt();
        System.out.print(c);
        scanner.close();
    }
}
