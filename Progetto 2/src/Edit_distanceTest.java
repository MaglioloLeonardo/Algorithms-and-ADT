import org.junit.AfterClass;
import org.junit.Assert;
import org.junit.Test;
import static org.junit.Assert.*;

public class Edit_distanceTest {
    public String s1 = "prova";

    @Test
    public void edit_distance_same() {
        assertTrue(Edit_distance.edit_distance(s1,s1) == 0);
    }

    @Test
    public void edit_distance_empty() {
        Assert.assertEquals(Edit_distance.edit_distance(s1,""), s1.length());
        Assert.assertEquals(Edit_distance.edit_distance("",s1), s1.length());
    }

    @Test
    public void edit_distance_double() {
        Assert.assertEquals(Edit_distance.edit_distance(s1,s1+s1), s1.length());
    }

    @AfterClass
    public static void edit_distance_raccomanded() {
        Assert.assertEquals(Edit_distance.edit_distance("casa","cassa"), 1);
        Assert.assertEquals(Edit_distance.edit_distance("casa","cara"), 1);
        Assert.assertEquals(Edit_distance.edit_distance("vinaio","vino"), 2);
        Assert.assertEquals(Edit_distance.edit_distance("tassa","passato"), 3);
    }
    //_____________________edit_distance_dyn:_____________________
    @Test
    public void edit_distance_dyn_same() {
        assertTrue(Edit_distance.edit_distance_dyn(s1,s1) == 0);
    }

    @Test
    public void edit_distance_dyn_empty() {
        Assert.assertEquals(Edit_distance.edit_distance_dyn(s1,""), s1.length());
        Assert.assertEquals(Edit_distance.edit_distance_dyn("",s1), s1.length());
    }

    @Test
    public void edit_distance_dyn_double() {
        Assert.assertEquals(Edit_distance.edit_distance_dyn(s1,s1+s1), s1.length());
    }

    @AfterClass
    public static void edit_distance_dyn_raccomanded() {
        Assert.assertEquals(Edit_distance.edit_distance_dyn("casa","cassa"), 1);
        Assert.assertEquals(Edit_distance.edit_distance_dyn("casa","cara"), 1);
        Assert.assertEquals(Edit_distance.edit_distance_dyn("vinaio","vino"), 2);
        Assert.assertEquals(Edit_distance.edit_distance_dyn("tassa","passato"), 3);
    }

}