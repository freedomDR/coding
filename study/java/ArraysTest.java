import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class ArraysTest {
    public static void main(String[] args) {
        String ss = "asas \n    \n a b c \n asdasd";
        System.out.println(Arrays.stream(ss.split("\n")).filter(s -> !s.replaceAll(" ", "").equals("")).map(s -> s.strip()).collect(Collectors.joining("\n")));
        String ss1 = "\n\n\n";
        System.out.println(Arrays.stream(ss1.split("\n")).map(s -> s.trim()).filter(s -> !s.equals("")).collect(Collectors.joining("\n")));
        String ss2 = "";
        System.out.println(Arrays.stream(ss2.split("\n")).map(s -> s.trim()).filter(s -> !s.equals("")).collect(Collectors.joining("\n")));
    }
}