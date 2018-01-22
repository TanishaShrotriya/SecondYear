package assign12;

import java.util.Scanner;
public class Exception
{

	public static void main(String[] args) 
	{
		int size_;
		int model_no_;
		double cost_;
		int ans;
		Scanner s1 =new Scanner (System.in);
		Tele TV =new Tele();
		
		do
		{
		
		System.out.print("\n Enter The Model Number : ");
		model_no_=s1.nextInt();
		TV.set_model(model_no_);
		System.out.print("\n Enter The Size Number : ");
		size_=s1.nextInt();
		TV.set_size(size_);
		System.out.print("\n Enter The Cost Number : ");
		cost_=s1.nextDouble();
		TV.set_cost(cost_);




		
		model_no_=TV.get_model();
		size_=TV.get_size();
		cost_=TV.get_cost();
		
		System.out.println("\n ================TELEVISION SPECIFICATIONS==================");
		
		System.out.println("\n The Model Number Is : " + model_no_ );
		System.out.println("\n The Size Is : " + size_ + " inches" );
		System.out.println("\n The Cost Is : Rs. " + cost_ );
		
		System.out.println("\n Do Yo Want To Add Another Model ?");
		ans=s1.nextInt();
		}while(ans==1);
	}

}
