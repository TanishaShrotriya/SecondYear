package myVehicle;

import java.util.Scanner;

public abstract class vehicle {

	protected int rNum,wNum;
	protected long cost;
	
	public abstract void start();
	public abstract void stop();
	
	vehicle() {
		rNum=0;
		wNum=0;
		cost=0;
	}
	public void info() {
		
		Scanner z= new Scanner(System.in);      
		System.out.println("\nEnter the registration number of car:\n");
		rNum=z.nextInt();
		System.out.println("\nEnter the number of wheels of car:\n");
		wNum=z.nextInt();
		System.out.println("\nEnter the cost of car:\n");	
		cost=z.nextLong();
	}
	

}
