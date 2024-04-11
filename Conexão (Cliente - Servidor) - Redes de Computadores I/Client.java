import client.ClientConn;
import client.MainInterface;      
    
public class Client {
    public static void main(String[] args) {

        //Schedule a job for the event-dispatching thread:
        //creating and showing this application's GUI.
        javax.swing.SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                MainInterface mi = new MainInterface();
                new ClientConn(mi);
            }
        });
    }
}

