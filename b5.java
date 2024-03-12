// TCP Client -
import java.io.*;
import java.net.*;
public class ContentsServer {
public static void main(String args[]) throws Exception {
// Establishing the connection with the server
ServerSocket sersock = new ServerSocket(4000);
System.out.println("Server ready for connection");
Socket sock = sersock.accept(); // Binding with port: 4000
System.out.println("Connection is successful and waiting for
chatting");
// Reading the file name from client InputStream
InputStream istream = sock.getInputStream();
BufferedReader fileRead = new BufferedReader(new
InputStreamReader(istream));
String fname = fileRead.readLine();
// Reading file contents
BufferedReader contentRead = new BufferedReader(new
FileReader(fname));
// Keeping output stream ready to send the contents
OutputStream ostream = sock.getOutputStream();
PrintWriter pwrite = new PrintWriter(ostream, true);
String str;
// Reading line-by-line from file
while ((str = contentRead.readLine()) != null) {
pwrite.println(str); // Sending each line to client
}
sock.close();
sersock.close(); // Closing network sockets
pwrite.close();
fileRead.close();
contentRead.close();
}
}
// TCP Server
import java.io.*;
import java.net.*;
public class ContentsClient {
public static void main(String[] args) throws Exception {
Socket sock = new Socket("127.0.0.1", 4000);
// Reading the file name from keyboard. Uses input stream
System.out.print("Enter the file name: ");
BufferedReader keyRead = new BufferedReader(new
InputStreamReader(System.in));
String fname = keyRead.readLine();
// Sending the file name to server. Uses PrintWriter
OutputStream ostream = sock.getOutputStream();
PrintWriter pwrite = new PrintWriter(ostream, true);
pwrite.println(fname);
// Receiving the contents from server. Uses input stream
InputStream istream = sock.getInputStream();
BufferedReader socketRead = new BufferedReader(new
InputStreamReader(istream));
String str;
while ((str = socketRead.readLine()) != null) { // Reading line-
by-line
System.out.println(str);
}
pwrite.close();
socketRead.close();
keyRead.close();
sock.close();
}
}
// Output -
// [root@localhost]# javac ContentsServer.java
// [root@localhost]# java ContentsServer
// Server ready for connection
// Connection is successful and waiting for chatting
// [root@localhost]# javac ContentsClient.java
// [root@localhost]# java ContentsClient
// Enter the file name: aa.txt
// Welcome to Network Lab
