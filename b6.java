// UDP Client -
import java.net.*;
import java.io.*;
class ConnectionClient {
public static void main(String[] args) {
try {
InetAddress acceptorHost = InetAddress.getByName(args[0]);
int serverPortNum = Integer.parseInt(args[1]);
Socket clientSocket = new Socket(acceptorHost, serverPortNum);
BufferedReader br = new BufferedReader(new
InputStreamReader(clientSocket.getInputStream()));
System.out.println(br.readLine());
clientSocket.close();
} catch (Exception e) {
e.printStackTrace();
}
}
}
// UDP Server -
import java.net.*;
import java.io.*;
class ConnectionServer {
public static void main(String[] args) {
try {
String message = args[0];
int serverPortNumber = Integer.parseInt(args[1]);
ServerSocket connectionSocket = new
ServerSocket(serverPortNumber);
Socket dataSocket = connectionSocket.accept();
PrintStream socketOutput = new
PrintStream(dataSocket.getOutputStream());
socketOutput.println(message);
System.out.println("Sent response to client");
socketOutput.flush();
dataSocket.close();
connectionSocket.close();
} catch (Exception e) {
e.printStackTrace();
}
}
}
// Output -
// Server Side:
// [root@localhost]# javac ConnectionServer.java
// [root@localhost]# java ConnectionServer "Welcome to Computer Network Lab" 3956
// Server ready for connection
// Connection is successful and waiting for chatting
// Client Side:
// [root@localhost]# javac ConnectionClient.java
// [root@localhost]# java ConnectionClient localhost 3956
// Welcome to Computer Network Lab
