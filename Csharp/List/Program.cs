using System;

namespace test {
    class Program {
        static void Main(string[] args) {
            List<string> list = new List<string>(new string[] {"vai", "lon", "luong"});
            List<string> temp = new List<string>(new string[] {"dau", "cac", "moi"});

            list.append(temp).reverse();
            list.print();
        }
    }
}
