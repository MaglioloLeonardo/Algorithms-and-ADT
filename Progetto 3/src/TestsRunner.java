import org.junit.runner.JUnitCore;
import org.junit.runner.Result;
import org.junit.runner.notification.Failure;

public class TestsRunner {
    public static void main(String [] args){
        Result result = JUnitCore.runClasses(TreeTest.class);
        for (Failure failure : result.getFailures()){
            System.out.println(failure.toString());
        }
        System.out.println("TreeTests passed:" + result.wasSuccessful());
        if(result.wasSuccessful()) {
            //UnionFindSet depend entirely by tree class
            result = JUnitCore.runClasses(UnionFindSetTest.class);
            for (Failure failure : result.getFailures()) {
                System.out.println(failure.toString());
            }
            System.out.println("UnionFindSetTests passed:" + result.wasSuccessful());
        }
    }
}
