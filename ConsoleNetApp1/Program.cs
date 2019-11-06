using System;

namespace ConsoleNetApp1 {
    class Program {
        static void Main(string[] args) {
            var s1 = "string 1";
            var s2 = string.Empty;
            Console.WriteLine(s1);
            s2 = s1;
            s1 = "modify string 1";
            Console.WriteLine(s2);
            s2 = "modify string 2";
            Console.WriteLine(s1);
            Console.WriteLine(s2);

            //Console.WriteLine("Hello World!");
            Console.ReadKey();
        }
    }
}
