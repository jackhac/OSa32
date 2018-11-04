//Andrew Buchanan
//Scott Martin

import java.net.*;
import java.io.*;

public class EchoClient
{
	public static void main(String[] args)
	{
		//initialize variables
		String name="";
		String line;
		//check if right number of arguments
		if (args.length!=1)
		{
			System.out.println("Usage: EchoClient host");
		}
		else
		{
			try 
			{
				//open socket to server using commandline arguement as the host
				Socket sock = new Socket(args[0], 6013);

				//loop through unless exit character pressed
				while(!name.equals("."))
				{
					//open buffereader for reading input from console
					BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
					//create printwriter to server
					PrintWriter pout = new PrintWriter(sock.getOutputStream(), true);
					
					//get input from server
					InputStream in = sock.getInputStream();
					//create bufferreader from inputstream
					BufferedReader bin = new BufferedReader(new InputStreamReader(in));

					//reset console input variable
					name="";
					//read console input to variable
					name = reader.readLine();
					
					if (name.equals("."))
					{
						break;
					}
					//print input to server
					pout.println(name);

					//reset server input variable
					line="";
					//readline from server
					line = bin.readLine();
					//print from server
					System.out.println(line);
				}
				//close connection to server once exit loop
				sock.close();
			}
			// IOException is thrown
			catch (IOException ioe)
			{
				System.err.println(ioe);	
			}
		}
	}
}
