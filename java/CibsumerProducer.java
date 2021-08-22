
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
    