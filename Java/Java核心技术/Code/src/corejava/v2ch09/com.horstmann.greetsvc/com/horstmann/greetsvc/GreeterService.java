package corejava.v2ch09.com.horstmann.greetsvc.com.horstmann.greetsvc;

import java.util.Locale;

public interface GreeterService 
{
    String greet(String subject);
    Locale getLocale();
}
