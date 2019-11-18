//using System.Collections;
//using System.Collections.Generic;
//using System.Dynamic;
//using System.Linq;
using ClassLibrary1;
using System;

namespace ConsoleNetApp1 {
    class Program {


        static void Main(string[] args) {

            foreach (var l in new DYTest().GetRlt()) {
                Console.WriteLine(l.id);
                Console.WriteLine(l.text);
            }

            //Grid grid = new Grid();
            //int i = 0;
            //foreach (var b in grid.Buttons) {
            //    i++;
            //    b.Clicked = () => { Console.WriteLine(i.ToString()); };

            //}


            //grid.Buttons[3].Clicked();

            //var s1 = "string 1";
            //var s2 = string.Empty;
            //Console.WriteLine(s1);
            //s2 = s1;
            //s1 = "modify string 1";
            //Console.WriteLine(s2);
            //s2 = "modify string 2";
            //Console.WriteLine(s1);
            //Console.WriteLine(s2);

            //Console.WriteLine("Hello World!");
            Console.ReadKey();
        }

    }
}
