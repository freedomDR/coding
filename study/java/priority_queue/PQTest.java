import java.util.PriorityQueue;
import java.util.Random;

class PQTest {
    public static void main(String[] args) {
        defaultTest();
    }

    static void defaultTest() {
        PriorityQueue<Integer> max_pq = new PriorityQueue<>((a, b) -> b-a);
        PriorityQueue<Integer> min_pq = new PriorityQueue<>((a, b) -> a-b);
        
        for (int i = 0; i < 10; i++) {
            Integer x = generateInt(100);
            max_pq.add(x);
            min_pq.add(x);
        }
        while (!max_pq.isEmpty()) {
            System.out.printf("%d ", max_pq.peek());
            max_pq.poll();
        }
        System.out.println();
        while (!min_pq.isEmpty()) {
            System.out.printf("%d ",min_pq.peek());
            min_pq.poll();
        }
        System.out.println();
    }

    static Integer generateInt(int limit) {
        Random rand = new Random();
        return rand.nextInt(limit);
    }
}