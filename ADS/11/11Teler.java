package assign12;

import java.util.Scanner;


public class Tele {

	int model_no;
	int size;
	double cost;
	Throwable ex;
	Scanner s1=new Scanner(System.in);
	
	public void set_model(int model_no_)
	{
	try
	{
		if(model_no>9999 || size<1000)
		{
			throw(ex); 
		}
		else
		{
			model_no=model_no_;	
		}
	
	}
	catch(Throwable ex)
	{
		System.out.print("\n !!!ERROR!!! INVALID SIZE \n\n Enter A valid Size : ");
		model_no_=s1.nextInt();
		model_no=model_no_;
	}
}
	
	public int get_model()
	{
		return model_no;
	}

	public void set_size(int n)
	{
		try
		{
			if(size>12 || size<10)
			{
				throw(ex); 
			}
			else
			{
				size=n;	
			}
		
		}
		catch(Throwable ex)
		{
			System.out.print("\n !!!ERROR!!! INVALID SIZE \n\n Enter A valid Size : ");
			n=s1.nextInt();
			size=n;
		}
	}
	
	public int get_size()
	{
		return size;
	}

	public void set_cost(double n)
	{
		try
		{
			if(n>50000 || n<5000)
			{
				throw(ex); 
			}
			else
			{
				cost=n;	
			}
		
		}
		catch(Throwable ex)
		{
			System.out.print("\n !!!ERROR!!! INVALID COST \n\n Enter A valid Cost : ");
			n=s1.nextDouble();
			cost=n;
		}

	}
	
	public double get_cost()
	{
		return cost;
	}

}
