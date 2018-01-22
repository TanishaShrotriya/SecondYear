import  myVehicle.* ;
import java.util.Scanner;

public class myVehicle {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int choice ;
		String ch="n";
		vehicle one=null;
		hifiCar two=null;
		car three=null;
		do{
         
			System.out.print("Choose operation:\n1. New Car entry");
			System.out.print("\n2. Show details");
			Scanner x= new Scanner(System.in);
			choice=x.nextInt();
			
			if (choice ==1) {
				
			}
			switch(choice) {
			case 1:  	int y;
						System.out.print("\nEnter type of car\n1. normal car\n2. hi-fi car");
						Scanner z= new Scanner(System.in);
						y=z.nextInt();
						if(y==1) 
							    one = new car();
				        else if (y==2) 
				                one = new hifiCar();        
				        one.info();
			            break;
			case 2:  one.start();
			         one.stop();
			         break;
		
			}
            
			System.out.println("Continue operations?? y/n\n");		
			Scanner r= new Scanner(System.in);
			ch=r.next();
			
		}
		while(ch.equals("y"));
	}

}
