package myVehicle;

import java.util.Scanner;

public class hifiCar extends car implements fly,PosSys {

 int flyType;
public
	hifiCar() {
	    
	    super ();
		System.out.println("Enter type of flying :\n1.Fast\n2.Slow\n3.Medium");
		Scanner x= new Scanner(System.in);
		flyType=x.nextInt();
	}
    hifiCar(int a, int b, int c,int d) {
    	rNum=a;
    	wNum=b;
    	cost=c;
		flyType=d;
    }
    public void start() {
    	
    	System.out.println("\nHifi Car " + name + " has started");
    	isFlying();
    
    	
    }
    public void stop() {
    	
    	System.out.println("\nHifi Car " + name + " has stopped");
    	
    }
	public void isFlying() {
		
		System.out.println("\nIs the car flying? y/n");
		Scanner y = new Scanner(System.in);
		String ans=y.next();
		if(ans.equals("y")) {
			this.showSpeed();
		}
		else {
			System.out.println("\nOkay, say what to do next");
		}
	}
    public void showSpeed() {
    	
    	System.out.println("\nCar is flying, should we display speed?");
    	Scanner y= new Scanner(System.in);
    	String x=y.next();
    	if(x.equals("y")) {
    		inSpeed();
    		showPosition();
            searchLocation();
    	}
    }
    public void inSpeed() {
    	
    	switch(flyType) {
    	case 1:	System.out.println("\nCar is fast flying, speed is 100-200 kmph");
    	        break;
    	case 2:	System.out.println("\nCar is slow flying, speed is 40-60 kmph");
    	        break;
    	case 3:	System.out.println("\nCar is medium flying, speed is 80-100 kmph");
    	        break;
    	default:System.out.println("\nValid type not specified");
    		     break;
    	}
    }
    public void showPosition() {
    	
    	System.out.println("\nCar position is: ");
  	switch(flyType) {
        	case 1:	System.out.println("\n200km from starting point");
        	        break;
        	case 2:	System.out.println("\n60 km from starting point");
        	        break;
        	case 3:	System.out.println("\n100 km from starting point");
        	        break;
        }
    	
    }
    public void searchLocation() {
        
        System.out.println("\nEnter the starting location");
    	Scanner y= new Scanner(System.in);
    	String x=y.next();
        switch(flyType) {
        
         	case 1:	System.out.println("\nCar is outside "+x);
        	        break;
        	case 2:	System.out.println("\nCar is within "+x);
        	        break;
        	case 3:	System.out.println("\nCar is outside "+x);
        	        break;
        }
    	
    }
}
