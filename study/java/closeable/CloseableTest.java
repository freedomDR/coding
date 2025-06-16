import java.io.Closeable;
import java.io.IOException;

class CloseableTest {
    public static void main(String[] args) {

        A a = new A();
        try (A aa = new A()){
            
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

    static class A implements Closeable {

		@Override
		public void close() throws IOException {
            System.out.println("I am closing");
		}
        
    }
}