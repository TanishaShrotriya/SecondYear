package myVehicle;
import java.util.Scanner;

public class car extends vehicle {

	protected String name; 
	
	public car() {
		super();
		System.out.print("Enter name of car");
		Scanner x= new Scanner(System.in);
		name=x.next();
	
	    
	}
  /* 
   *    super can be used to refer immediate parent class instance variable.
    	super can be used to invoke immediate parent class method.
    	super() can be used to invoke immediate parent class constructor.

   */
	@Override
	public void start() {
		
		System.out.println("Car " + name + " has started");
		
	}

	@Override
	public void stop() {
	
		System.out.println("Car " + name + " has stopped");
		
	}


}
