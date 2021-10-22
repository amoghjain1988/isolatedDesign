package consumerproducer;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class ConsumerProducer {
    public static Random        rng = new Random();
    public static List<Integer> p   = new ArrayList<>();
    
    public static class Producer implements Runnable {
        public List<Integer> p;
        public int           i;
        
        public Producer(List<Integer> _p, int _i) {
            p = _p;
            i = _i;
        }

        @Override
        public void run() {
            System.out.println("Entering thread");
            for (int n = 0; n < i; ++n) {
                System.out.println("Adding " + i + " to the pipeline");
                p.add(n);
                try {
                    Thread.sleep(500 + rng.nextInt(500));
                }
                catch (InterruptedException ex) {
                }
            }
            p.add(-1);
            System.out.println("Exiting thread");
        }
    }
    
    public static class Consumer implements Runnable {
        public List<Integer> p;

        public Consumer(List<Integer> _p) {
            p = _p;
        }
        
        @Override
        public void run() {
            System.out.println("Entering thread");
            int n;
            do {
                n = p.get(0);
                System.out.println("Removing " + n + " from the pipeline");
                p.remove(0);
            } while (n > 0);            
            System.out.println("Exiting thread");
        }
    }    
  
    public static void main(String[] args) {
        try {
            Thread producerThread = new Thread(new Producer(p, Integer.parseInt(args[0])));
            producerThread.start();

            Thread consumerThread = new Thread(new Consumer(p));
            consumerThread.start();

            consumerThread.join();
            producerThread.join();
        }
        catch (InterruptedException ex) {
        }
    }    
}