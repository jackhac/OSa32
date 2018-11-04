//Andrew Buchanan
//Scott Martin

import java.net.*;
import java.io.*;

public class EchoServer
{
	public static void main(String[] args)
	{
		try 
		{
			//open server socket on port 6013
			ServerSocket sock = new ServerSocket(6013);
			//loop through indefinately
			while(true)
			{
				NewServer ns;
				ns = new NewServer(sock.accept());
				Thread thrd = new Thread(ns);
				thrd.start();
			}
		}
		catch (IOException ioe)
		{
			System.err.println(ioe);	
		}
	}
}

