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
    	
    	System.out.println("Hifi Car " + name + " has started");
    	isFlying();
    	showPosition();
    	
    }
    public void stop() {
    	
    	System.out.println("Hifi Car " + name + " has stopped");
    	
    }
	public void isFlying() {
		
		System.out.println("Is the car flying? y/n");
		Scanner y = new Scanner(System.in);
		String ans=y.next();
		if(ans.equals("y")) {
			this.showSpeed();
		}
		else {
			System.out.println("Okay, say what to do next");
		}
	}
    public void showSpeed() {
    	
    	System.out.println("Car is flying, should we display speed?");
    	Scanner y= new Scanner(System.in);
    	String x=y.next();
    	if(x.equals("y")) {
    		inSpeed();
    	}
    }
    public void inSpeed() {
    	
    	switch(flyType) {
    	case 1:	System.out.println("Car is fast flying, speed is 100-200 kmph");
    	        break;
    	case 2:	System.out.println("Car is slow flying, speed is 40-60 kmph");
    	        break;
    	case 3:	System.out.println("Car is medium flying, speed is 80-100 kmph");
    	        break;
    	default:System.out.println("Valid type not specified");
    		     break;
    	}
    }
    public void showPosition() {
    	
    	System.out.println("Car position is: ");
    	Scanner y= new Scanner(System.in);
    	String x=y.next();
    	if(x.equals("y")) {

        	switch(flyType) {
        	case 1:	System.out.println("200km from starting point");
        	        break;
        	case 2:	System.out.println("60 km from starting point");
        	        break;
        	case 3:	System.out.println("100 km from starting point");
        	        break;
        	}
    	}
    }
}
