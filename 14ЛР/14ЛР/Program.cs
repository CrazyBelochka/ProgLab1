using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Collections.Specialized;

namespace laborat14
{
    class Program
    {
        static void Main(string[] args)
        {
            //Задание 1
            Console.WriteLine("Задание 1");
            const int NUM = 5;
            Random rnd = new Random();
            ArrayList list = new ArrayList();
            for (int i = 0; i < NUM; i++) //заполняем пятью случайными числами
            {
                list.Add(rnd.Next() % 10);
            }
            list.AddRange(new string[] { "Lab" }); //добавляем строку
            Console.WriteLine("Коллекция со словом:");
            for (int i = 0; i < list.Count; i++)
            {
                Console.Write(list[i] + ",");
            }
            Console.WriteLine("\nКакой элемент удалить?");//удаляем n-ый элемент
            while (true)
            {
                int DeleteOne = Convert.ToInt32(Console.ReadLine());
                if (DeleteOne < 6 && DeleteOne > 0)
                {
                    list.RemoveAt(DeleteOne - 1); break;
                }
                else Console.WriteLine("Введено неверное значение, попробуйте еще раз");
            }

            Console.WriteLine("Количество элементов в коллекции:" + list.Count); //Выводим количество элементов и саму коллекцию
            Console.WriteLine("Сама коллекция: ");
            foreach (object o in list)
            {
                Console.Write(o + ", ");
            }
            Console.WriteLine("\nПроверить наличие какого объекта?"); //Проверка наличия элемента
            string Check = Console.ReadLine();
            int x = 0;
            if (list.Contains(Check)) 
            { 
                Console.WriteLine("Элемент " + Check + " найден!");
                x = 1;
            }
            if (x!= 1 && list.Contains(Convert.ToInt32(Check)))
            {
                Console.WriteLine("Элемент " + Check + " найден!");
                x = 2;
            }
            if (x == 0)
            {
                Console.WriteLine("Элемент " + Check + " не найден!");
            }

            Console.WriteLine("Задание 2");
            List<float> FloatList = new List<float>(); //Создаем коллекцию

            float c = 0.2F;
            for (int i = 0; i < NUM; i++)
            {
                c = 2F / rnd.Next(1, 9);
                FloatList.Add(c); //Заполняем случайными элементами
            }
            Console.WriteLine("Коллекция: ");
            foreach (var i in FloatList) //Выводим коллекцию
                Console.Write(i + " ");

            Console.WriteLine("\nСколько элементов удалить?"); //Удаляем n элементов
            int DeleteTwo = Convert.ToInt32(Console.ReadLine());
            for (int i = 0; i < DeleteTwo; i++)
            {
                FloatList.RemoveAt(0);
            }
            Console.WriteLine("Новая коллекция:");
            foreach (var i in FloatList) //Выводим коллекцию
                Console.Write(i + " ");
            

            FloatList.AddRange(new[] { 0.001F, 5.12F }); //Добавление через AddRange
            Console.WriteLine("Новая коллекция:");
            foreach (var i in FloatList) //Выводим коллекцию
                Console.Write(i + " ");

            Dictionary<int, float> FloatDictionary = new Dictionary<int, float>(); //Создаем DicTianory
            int counter = 0;
            foreach (var el in FloatList) //Переносим все из List
            {
                FloatDictionary.Add(counter, el);
                counter++;
            }
            Console.WriteLine("\nНовая коллекция Dictianory");
            foreach (var elm in FloatDictionary) //Выводим новую коллекцию
                Console.WriteLine($"{elm.Key}: {elm.Value}");

            Console.Write("\nВведите индекс заданного значения: "); //Поиск по заданному индексу
            while (true)
            {
                int N = Convert.ToInt16(Console.ReadLine());
                if (N <= FloatDictionary.Count && N >= 0)
                {
                    Console.WriteLine($"Значение под индексом {N}: {FloatDictionary[N]}");
                    break;
                }
                else
                {
                    Console.Write("Введен неверный индекс, попробуйте ещё раз: ");
                }
            }
            //Задание 3
            Console.WriteLine("Задание 3");
            List<model> modelList = new List<model>();
            modelList.Add(new model(1, 2)); //Заполняем элементами
            modelList.Add(new model(3, 4));
            modelList.Add(new model(5, 6));
            modelList.Add(new model(7, 8));
            modelList.AddRange(new[] { new model(9, 10), new model(11, 12) });
            int Counter2 = 1;
            foreach (var i in modelList)
            { //Выводим коллекцию
                Console.WriteLine(Counter2 + "-ый элемент:");
                Console.Write("Speed= " + i.Speed + ", " + "Position= " + i.Position);
                Console.WriteLine();
                Counter2++;
            }

            Console.WriteLine("Сколько элементов удалить?"); //Удаляем n элементов
            int DeleteThree = Convert.ToInt32(Console.ReadLine());
            for (int i = 0; i < DeleteThree; i++)
            {
                modelList.RemoveAt(0);
            }
            Console.WriteLine("Новая коллекция: ");//выводим 
            int Counter3 = 1;
            foreach (var i in modelList)
            { //Выводим коллекцию
                Console.WriteLine(Counter3 + "-ый элемент:");
                Console.Write("Speed= " + i.Speed + ", " + "Position= " + i.Position);
                Counter3++;
            }

            Dictionary<int, model> modelDictionary = new Dictionary<int, model>();
            int counterTwo = 0;
            foreach (var el in modelList) //Переносим все из List
            {
                modelDictionary.Add(counterTwo, el);
                counterTwo++;
            }
            Console.WriteLine("\nНовая коллекция Dictianory");
            foreach (var elm in modelDictionary) //Выводим новую коллекцию
                Console.WriteLine($"{elm.Key}: {elm.Value}" + " :" + "Speed= " + elm.Value.Speed + ", " + "Position= " + elm.Value.Position);

            Console.Write("\nВведите индекс заданного значения: "); //Поиск по заданному индексу
            while (true)
            {
                int N = Convert.ToInt16(Console.ReadLine());
                if (N <= modelDictionary.Count && N >= 0)
                {
                    Console.WriteLine($"Значение под индексом {N}: {modelDictionary[N]}" + " :" + "Speed= " + modelDictionary[N].Speed + ", " + "Position= " + modelDictionary[N].Position);
                    break;
                }
                else
                {
                    Console.Write("Введен неверный индекс, попробуйте ещё раз: ");
                }
            }

            List<model> modelListTwo = new List<model>();
            for (int i = 0; i < modelDictionary.Count; i++)
                modelListTwo.Add((model)modelDictionary[i].Clone()); //Использование ICloneable
            //List<model>.Sort(modelListTwo);
            var mySortedDictionary1 = new Dictionary<int, model>(); //Сортировка по возрастанию через IComparable
            for (int i = 0; i < modelDictionary.Count; i++)
                mySortedDictionary1.Add(i, (model)modelListTwo[i].Clone()); //Использование ICloneable
            Console.WriteLine("\n\nОтсортированный Dictionary через IComparable\n");
            foreach (var elm in mySortedDictionary1)
                Console.WriteLine($"{elm.Key}: {elm.Value}" + " :" + "Speed= " + elm.Value.Speed + ", " + "Position= " + elm.Value.Position);

            modelListTwo.Sort(0,3, new modelComparer()); //Сортировка по возрастанию через IComparer
            var mySortedDictionary2 = new Dictionary<int, model>();
            for (int i = 0; i < modelDictionary.Count; i++)
                mySortedDictionary2.Add(i, (model)modelListTwo[i].Clone()); //Использование ICloneable
            Console.WriteLine("\n\nОтсортированный Dictionary по возрастанию через IComparer\n");
            foreach (var elm in mySortedDictionary2)
                Console.WriteLine($"{elm.Key}: {elm.Value}" + " :" + "Speed= " + elm.Value.Speed + ", " + "Position= " + elm.Value.Position);

            Console.WriteLine("Задание 4");
            ObservableCollection<model> models = new ObservableCollection<model>
            {
            new model(1,2),
            new model(3,4),
            new model(5,6),
            new model(7,8),
            };
            models.CollectionChanged += Users_CollectionChanged;
            models.Add(new model(1, 5));
            models.RemoveAt(1);
            models[0] = new model(2, 7);
            foreach (model user in models)
            {
                Console.WriteLine("Speed= " + user.Speed + ", " + "Position= " + user.Position);
            }
            Console.Read();
        }
        private static void Users_CollectionChanged(object sender, NotifyCollectionChangedEventArgs e)
        {
            switch (e.Action)
            {
                case NotifyCollectionChangedAction.Add: // если добавление
                    model newUser = e.NewItems[0] as model;
                    Console.WriteLine($"Добавлен новый объект: {newUser}" + ": Speed= " + newUser.Speed + ", " + "Position= " + newUser.Position);
                    break;
                case NotifyCollectionChangedAction.Remove: // если удаление
                    model oldUser = e.OldItems[0] as model;
                    Console.WriteLine($"Удален объект: {oldUser}" + ": Speed= " + oldUser.Speed + ", " + "Position= " + oldUser.Position);
                    break;
                case NotifyCollectionChangedAction.Replace: // если замена
                    model replacedUser = e.OldItems[0] as model;
                    model replacingUser = e.NewItems[0] as model;
                    Console.WriteLine($"Объект {replacedUser}" + ": Speed= " + replacedUser.Speed + ", " + "Position= " + replacedUser.Position  + "заменен объектом" + replacingUser + ": Speed= " + replacingUser.Speed + ", " + "Position= " + replacingUser.Position);
                    break;
            }
        }

        public interface ICloneable
        {
            object Clone();
        }

        public interface IComparable
        {
            int CompareTo(object o);
        }

        interface IComparer
        {
            int Compare(object o1, object o2);
        }

        class modelComparer : IComparer<model>
        {
            public int Compare(model m1, model m2)
            {
                if (m1.Speed > m2.Speed)
                    return 1;
                else if (m1.Speed < m2.Speed)
                    return -1;
                else
                    return 0;
            }
        }

        class model : IComparable, ICloneable
        {
            private int position;
            private int speed;
            public model(int speed = 0, int position = 0)
            {
                this.position = position;
                this.speed = speed;
            }
            public int Speed
            {
                get
                { return speed; }
                set
                { speed = value; }
            }

            public int Position
            {
                get
                { return position; }
                set
                { position = value; }
            }
            public object Clone()
            {
                return new model { speed = this.speed, position = this.position };
            }
            public int CompareTo(object o)
            {
                if (o == null) return 1;

                model p = o as model;
                if (p != null)
                    return this.Speed.CompareTo(p.Speed);
                else
                    throw new Exception("Невозможно сравнить два объекта");
            }


        }
    }
}