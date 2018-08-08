import java.io.*;

class prime
{
	public static void main(String args[])
	{
		int x = 9;
		bool flag = true;
		for(int i = 2; i < x; i++)
		{
			if(x % i == 0)
			{
				flag = false;
				break;
			}

		}
		if(flag)
			System.out.println("Prime");
		else
			System.out.println("Not prime");
	}
}