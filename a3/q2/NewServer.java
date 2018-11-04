//Andrew Buchanan
//Scott Martin

import java.net.*;
import java.io.*;

class NewServer implements Runnable
{
	//initialize global variables
	private String line;
	private int exit;
	private Socket client;
	
	public NewServer(Socket client)
	{
		this.client = client;
	}
	
	public void run()
	{
		//initialize variables
		String line;
		int exit=0;
		BufferedReader bin=null;
		PrintWriter pout=null;
		
		try 
		{
			while (exit==0)
			{
				InputStream in = client.getInputStream();
				bin = new BufferedReader(new InputStreamReader(in));
				pout = new PrintWriter(client.getOutputStream(), true);

				line = bin.readLine();

				pout.println("Server: "+line);
				
				System.out.println(line);

				if (in.read()==-1)
				{
					exit=1;	
				}
			}
<<<<<<< HEAD
				client.close();
	     }
		// IOException is thrown
	    catch (IOException ioe)
		{
			System.err.println(ioe);	
		}
	}
=======
			client.close();
	        }
		// IOException is thrown
	        catch (IOException ioe)
		{
			System.err.println(ioe);	
		}
		}
>>>>>>> 8802683a40a6307f0a874fa3941c1c01bbb55849
}
