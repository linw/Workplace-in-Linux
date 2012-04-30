/*
 * =====================================================================================
 *
 *       Filename:    change_num_to_text.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.co
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;
// string num_text_1[10] = {"zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
// string num_text_2[10] = {"Ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
// string num_text_3[10] = {"Ten","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety","hundred"};
// string num_text_4[] = {"hundred","thousand","million","billion"};

// string change_int_num_to_text(string num){
//     int count = strlen(num);
//     string text = "";
//     for(int i = count; i>=0; --i){

//     }
// }

// string change_num_to_text(float num){
//     string text = "";
//     int num_i = num;
//     float num_f = num - num_i;

//     return text;
// }


public class IndiaCurrencyConverter
{
    private Hashtable htPunctuation;
    private Dictionary<int> DictStaticSuffix;
    private Dictionary<int> DictStaticPrefix;
    private Dictionary<int> DictHelpNotation;
    private System.Drawing.Color color;

    public IndiaCurrencyConverter()
    {
        htPunctuation = new Hashtable();
        DictStaticPrefix = new Dictionary<int>();
        DictStaticSuffix = new Dictionary<int>();
        DictHelpNotation = new Dictionary<int>();
        Native = native;
        LoadStaticPrefix();
        LoadStaticSuffix();
        LoadHelpofNotation();
    }
    private void LoadStaticSuffix()
    {
        DictStaticSuffix.Add(1, "One ");
        DictStaticSuffix.Add(2, "Two ");
        DictStaticSuffix.Add(3, "Three ");
        DictStaticSuffix.Add(4, "Four ");
        DictStaticSuffix.Add(5, "Five ");
        DictStaticSuffix.Add(6, "Six ");
        DictStaticSuffix.Add(7, "Seven ");
        DictStaticSuffix.Add(8, "Eight ");
        DictStaticSuffix.Add(9, "Nine ");
        DictStaticSuffix.Add(10, "Ten ");
        DictStaticSuffix.Add(11, "Eleven ");
        DictStaticSuffix.Add(12, "Twelve ");
        DictStaticSuffix.Add(13, "Thirteen ");
        DictStaticSuffix.Add(14, "Fourteen ");
        DictStaticSuffix.Add(15, "Fifteen ");
        DictStaticSuffix.Add(16, "Sixteen ");
        DictStaticSuffix.Add(17, "Seventeen ");
        DictStaticSuffix.Add(18, "Eighteen ");
        DictStaticSuffix.Add(19, "Nineteen ");
        DictStaticSuffix.Add(20, "Twenty ");
        DictStaticSuffix.Add(30, "Thirty ");
        DictStaticSuffix.Add(40, "Forty ");
        DictStaticSuffix.Add(50, "Fifty ");
        DictStaticSuffix.Add(60, "Sixty ");
        DictStaticSuffix.Add(70, "Seventy ");
        DictStaticSuffix.Add(80, "Eighty ");
        DictStaticSuffix.Add(90, "Ninety ");
    }
    private void LoadStaticPrefix()
    {
        DictStaticPrefix.Add(2, "Thousand ");
        DictStaticPrefix.Add(3, "Lac ");
        DictStaticPrefix.Add(4, "Crore ");
        DictStaticPrefix.Add(5, "Arab ");
        DictStaticPrefix.Add(6, "Kharab ");
        DictStaticPrefix.Add(9, "Neel ");
        DictStaticPrefix.Add(8, "Padma ");
        DictStaticPrefix.Add(9, "Shankh ");
        DictStaticPrefix.Add(10, "Maha-shankh ");
        DictStaticPrefix.Add(11, "Ank ");
        DictStaticPrefix.Add(12, "Jald ");
        DictStaticPrefix.Add(13, "Madh ");
        DictStaticPrefix.Add(14, "Paraardha ");
        DictStaticPrefix.Add(15, "Ant ");
        DictStaticPrefix.Add(16, "Maha-ant ");
        DictStaticPrefix.Add(17, "Shisht ");
        DictStaticPrefix.Add(18, "Singhar ");
        DictStaticPrefix.Add(19, "Maha-singhar ");
        DictStaticPrefix.Add(20, "Adant-singhar ");
    }
    private void LoadHelpofNotation()
    {
        DictHelpNotation.Add(2, "=1,000 (3 Trailing Zeros)");
        DictHelpNotation.Add(3, "=1,00,000 (5 Trailing Zeros)");
        DictHelpNotation.Add(4, "=1,00,00,000 (7 Trailing Zeros)");
        DictHelpNotation.Add(5, "=1,00,00,00,000 (9 Trailing Zeros)");
        DictHelpNotation.Add(6, "=1,00,00,00,00,000 (11 Trailing Zeros)");
        DictHelpNotation.Add(7, "=1,00,00,00,00,00,000 (13 Trailing Zeros)");
        DictHelpNotation.Add(8, "=1,00,00,00,00,00,00,000 (15 Trailing Zeros)");
        DictHelpNotation.Add
    (9, "=1,00,00,00,00,00,00,00,000 (17 Trailing Zeros)");
        DictHelpNotation.Add(10, "=1,00,00,00,00,00,00,00,00,000 
                (19 Trailing Zeros)");
        DictHelpNotation.Add(11, "=1,00,00,00,00,00,00,00,00,00,000 
            (21 Trailing Zeros)");
        DictHelpNotation.Add(12, "=1,00,00,00,00,00,00,00,00,00,00,000 
            (23 Trailing Zeros)");
        DictHelpNotation.Add(13, "=1,00,00,00,00,00,00,00,00,00,00,00,000 
            (25 Trailing Zeros)");
        DictHelpNotation.Add(14, "=1,00,00,00,00,00,00,00,00,00,00,00,00,000 
            (27 Trailing Zeros)");
        DictHelpNotation.Add(15, "=1,00,00,00,00,00,00,00,00,00,00,00,00,00,000
            (29 Trailing Zeros)");
        DictHelpNotation.Add
    (16, "=1,00,00,00,00,00,00,00,00,00,00,00,00,00,00,000
                (31 Trailing Zeros)");
        DictHelpNotation.Add
    (17, "=1,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,000
                (33 Trailing Zeros)");
        DictHelpNotation.Add
    (18, "=1,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,000
                (35 Trailing Zeros)");
        DictHelpNotation.Add
    (19, "=1,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,000
                (37 Trailing Zeros)");
        DictHelpNotation.Add
    (20, "=1,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,000
                (39 Trailing Zeros)");
}
