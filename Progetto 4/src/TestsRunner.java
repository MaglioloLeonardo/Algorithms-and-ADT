import org.junit.runner.JUnitCore;
import org.junit.runner.Result;
import org.junit.runner.notification.Failure;

public class TestsRunner {
    public static void main(String [] args){
        Result result = JUnitCore.runClasses(GraphTests.class);
        for (Failure failure : result.getFailures()){
            System.out.println(failure.toString());
        }
        System.out.println("GraphTests passed:" + result.wasSuccessful());
        if(result.wasSuccessful()) {
            //Kruskal depend entirely on Graph class
            result = JUnitCore.runClasses(KruskalTest.class);
            for (Failure failure : result.getFailures()) {
                System.out.println(failure.toString());
            }
            System.out.println("KruskalTest passed:" + result.wasSuccessful());
        }
    }
}
