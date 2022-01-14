using System;
using System.Linq;
using System.Collections.Generic;

namespace _15LR
{
    class Program
    {
        static bool wintersummer(string s)
        {
            string[] ws = { "January", "February", "June", "July", "August", "December" };
            if (ws.Contains(s))
                return true;
            else return false;
        }

        static void Main(string[] args)
        {
            //1

            string[] months = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" }; //Все месяцы

            int n = 7;
            IEnumerable<string> L1 = months.Where(s => s.Length == n);//Длина n                                                                                                                                                           
            foreach (string k in L1)
                Console.Write(k + " ");

            Console.Write("\n");
            IEnumerable<string> L2 = months.Where(s => wintersummer(s)); //Лето зима
            foreach (string k in L2)
                Console.Write(k + " ");
            
            Console.Write("\n");
            IEnumerable<string> L3 = months.OrderBy(s => s);//алфавитный порядок
            foreach (string k in L3)
                Console.Write(k + " ");

            Console.Write("\n");
            IEnumerable<string> L4 = months.Where(s => (s.Contains("u") && s.Length >= 4));//Не менее 4 символов с буквой uz
            foreach (string k in L4)
                Console.Write(k + " ");
            Console.Write("\n");

            //2

            //3 
            List<circle> cir = new List<circle>();
            cir.Add(new circle(0, 0, 2));
            cir.Add(new circle(1, 5, 2));
            cir.Add(new circle(-3, 7, 7));
            cir.Add(new circle(-5, -2, 1));
            cir.Add(new circle(1, -1, 4));
            cir.Add(new circle(2, 2, 3));
            cir.Add(new circle(-5, 2, 10));

            foreach (circle circ in cir)
                Console.WriteLine("круг №" + cir.IndexOf(circ) + "("+circ.Center_x + "," + circ.Center_y + "," +circ.Radius + ")");

            //заданная прямая y = x
            IEnumerable<circle> Q1 = cir.Where(s => Math.Abs(s.Center_x) == Math.Abs(s.Center_y));
            Console.Write("На прямой y=x лежат центры данных окружностей: \n");
            foreach (circle circ in Q1)
                Console.Write("круг №"+cir.IndexOf(circ)+" ");

            Console.Write("\n");
            circle Q2 = cir.OrderBy(s => s.perimetr()).Last();
            Console.WriteLine("Наибольший по периметру объект: \nкруг №" + cir.IndexOf(Q2));

            Console.Write("\n");
            circle Q3 = cir.OrderBy(s => s.perimetr()).First();
            Console.WriteLine("Наименьший по периметру объект: \nкруг №" + cir.IndexOf(Q3));

            Console.Write("\n");
            int r = 2;
            int c = cir.Count(s => s.Radius == r);
            Console.WriteLine("Kоличество окружностей заданного радиуса: " + c);

            Console.Write("\n");
            circle Q4 = cir.First(s => s.Center_x > 0 && s.Center_y > 0);
            Console.WriteLine("Первая окружность, лежащая в первой четверти координат: \nкруг №" + cir.IndexOf(Q4));

            Console.Write("\n");
            IEnumerable<circle> Q5 = cir.OrderBy(s => s.area());
            Console.WriteLine("Упорядоченный список окружностей по площади");
            foreach (circle circ in Q5)
                Console.Write("круг №" + cir.IndexOf(circ) + " ");
            Console.ReadLine();

        }

        class circle
        {
            private float center_x;
            private float center_y;
            private float radius;

            public circle(float x, float y, float r)
            {
                if (r <= 0) throw new ArgumentException("The radius cannot be less than 0", "Radius");
                else radius = r;
                center_x = x;
                center_y = y;
            }

            public double perimetr()
            {
                return 2 * 3.1415926 * radius;
            }

            public double area()
            {
                return 3.1415926 * radius * radius;
            }
            public float Center_x//Чтение-установка имени
            {
                get
                {
                    return center_x;
                }
                set
                {
                    center_x = value;
                }
            }

            public float Center_y//Чтение-установка имени
            {
                get
                {
                    return center_y;
                }
                set
                {
                    center_y = value;
                }
            }

            public float Radius//Чтение-установка имени
            {
                get
                {
                    return radius;
                }
                set
                {
                    if (value <= 0) throw new ArgumentException("The radius cannot be less than 0", "Radius");
                    else radius = value;
                }
            }
        }
    }
}
