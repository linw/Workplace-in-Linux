/*
 * =====================================================================================
 *
 *       Filename:    SimpleService.java
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012年3月20日22:15:50
 *       Compiler:    java
 *       Description: 
 *
 * =====================================================================================
 */
public class SimpleService
{
    public String getGreeting(String name)
    {
        int i = 10;
        double k = 0.1;
        return "你好 " + name;
    }   
    public int getPrice()
    {
        return new java.util.Random().nextInt(1000);
    }    
}
