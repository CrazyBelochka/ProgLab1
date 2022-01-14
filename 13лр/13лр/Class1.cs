using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
//using System.Windows.Forms;
using System.Text;



namespace _12
{
    class Program
    {
        static void re(string[] args)
        {
            // setlocale(LC_ALL, "Russian");
            int peopleAmount = ConstantProvider.MAX_PEOPLE + 1;
            while (peopleAmount > ConstantProvider.MAX_PEOPLE || peopleAmount < 1)
            {
                Console.WriteLine("Сколько людей вы хотите добавить?");
                peopleAmount = Convert.ToInt32(Console.ReadLine());
            }
            int sickPeopleAmount = 0;
            //Задаем количество больных людей, которое должно быть больше нуля, но меньше, чем всего людей
            while (sickPeopleAmount < 1 || sickPeopleAmount >= peopleAmount)
            {
                Console.WriteLine("Сколько из них заражены?");
                sickPeopleAmount = Convert.ToInt32(Console.ReadLine());
            }

            // Создаем здоровых агентов случайным способом
            Random rnd = new Random();
            List<human> people = new List<human>();
            for (int i = 0; i < (peopleAmount - sickPeopleAmount); i++)
            {
                human h = new human(rnd.Next() % ConstantProvider.HUMAN_MAX_SPEED + 1, rnd.Next() % ConstantProvider.FIELD_SIZE, false);
                people.Add(h);
            }

            for (int i = 0; i < sickPeopleAmount; i++)
            {
                human h = new human(rnd.Next() % ConstantProvider.HUMAN_MAX_SPEED + 1, rnd.Next() % ConstantProvider.FIELD_SIZE, true);
                people.Add(h);
            }

            int docAmount = ConstantProvider.MAX_DOCTORS + 1;

            // Количество может быть до MAX_DOCTORS

            while (docAmount > ConstantProvider.MAX_DOCTORS || docAmount < 1)
            {
                Console.WriteLine("Сколько докторов вы хотите добавить?");
                docAmount = Convert.ToInt32(Console.ReadLine());
            }

            List<doctor> doctors = new List<doctor>();
            for (int i = 0; i < docAmount; i++)
            {
                doctor d = new doctor(rnd.Next() % ConstantProvider.DOC_MAX_SPEED + 1, rnd.Next() % ConstantProvider.FIELD_SIZE);
                doctors.Add(d);
            }

            //сериализация



            


            char z1, z2, z3;

            char ch;

            int pos;

            Dictionary<int, char> modell = new Dictionary<int, char>();

            while (true)
            {



                model peopl;
                model doc;
                for (int i = 0; i < peopleAmount; i++)
                {
                    peopl = people[i];
                    peopl.UpdatePosition(1);
                }
                for (int i = 0; i < docAmount; i++)
                {
                    doc = doctors[i];
                    doc.UpdatePosition(1);
                }

                // Заражение
                for (int i = 0; i < peopleAmount; i++)
                {

                    if (people[i].Infected)
                    {
                        // Если человек болен, то ищем, кого он заражаеn
                        for (int j = 0; j < peopleAmount; j++)
                            if (i != j) people[j] = people[i].Infect(people[j], people[i]);

                    }

                }

                // Лечение

                for (int i = 0; i < peopleAmount; i++)
                {

                    if (people[i].Infected)
                    {
                        // Если человек болен, то ищем, кто его вылечит
                        for (int j = 0; j < docAmount; j++)
                        {

                            people[i] = doctors[j].Heal(people[i], doctors[j]);

                            if (!people[i].Infected)
                                break;
                        }
                    }
                }

                modell.Clear();
                for (int i = 0; i < peopleAmount; i++)
                {

                    //Если кто-то другой уже стоит в этом месте, перемещаемся на 1 позицию меньше

                    pos = people[i].Position;

                    // count считает, сколько раз встречается такая позиция в map. если она уже была, то надо уменьшить нашу позицию.

                    while (modell.ContainsKey(pos))
                    {
                        pos--;
                        if (pos < 0) pos = ConstantProvider.FIELD_SIZE - 1;

                    }

                    people[i].Position = pos;

                    // Если в этой позиции стоит больной человек, то ставим "S" (Sick), если  здоровый - "H"(Healthy)

                    if (people[i].Infected)
                        modell[people[i].Position] = 'S';
                    else
                        modell[people[i].Position] = 'H';
                }

                // Расставляем докторов аналогично

                for (int i = 0; i < docAmount; i++)
                {
                    // Если кто-то другой уже стоит в этом месте, перемещаемся на 1 позицию меньше
                    pos = doctors[i].Position;
                    // count считает, сколько раз встречается такая позиция в map. если она уже была, то надо уменьшить нашу позицию.

                    while (modell.ContainsKey(pos))
                    {
                        pos--;
                        if (pos < 0) pos = ConstantProvider.FIELD_SIZE - 1;
                    }

                    doctors[i].Position = pos;

                    // Ставим доктора в модели буквой "D" (Doctor)

                    modell[doctors[i].Position] = 'D';

                }

                // Выводим модель-карту

                for (int i = 0; i < ConstantProvider.FIELD_SIZE; i++)
                {
                    // Если кто-то стоит (кого-то нашли на карте), то выводим его букву, иначе "_"
                    if (modell.ContainsKey(i))
                        Console.Write(modell[i]);
                    else Console.Write("_");
                }
                Console.WriteLine();
                Console.WriteLine();
                Console.WriteLine("Хотите добавить агента?  (y(yes)/n(no))");
                z1 = Convert.ToChar(Console.ReadLine());
                if (z1 == 'y')
                {
                    Console.WriteLine("Кого вы хотите добавить? (d(doctor)/p(people))");
                    z2 = Convert.ToChar(Console.ReadLine());
                    if (z2 == 'p')
                    {
                        peopleAmount++;
                        human h = new human(rnd.Next() % ConstantProvider.HUMAN_MAX_SPEED + 1, rnd.Next() % ConstantProvider.FIELD_SIZE, false);
                        people.Add(h);
                    }
                    if (z2 == 'd')
                    {
                        docAmount++;
                        doctor d = new doctor(rnd.Next() % ConstantProvider.DOC_MAX_SPEED + 1, rnd.Next() % ConstantProvider.FIELD_SIZE);
                        doctors.Add(d);
                    }
                }
                Console.WriteLine("Хотите удалить агента?  (y(yes)/n(no))");
                z3 = Convert.ToChar(Console.ReadLine());
                if (z3 == 'y')
                {
                    Console.WriteLine("Кого вы хотите удалить? (d(doctor)/p(people))");
                    z2 = Convert.ToChar(Console.ReadLine());
                    if (z2 == 'p')
                    {
                        peopleAmount--;
                        people.RemoveAt(0);
                    }
                    if (z2 == 'd')
                    {
                        docAmount--;
                        doctors.RemoveAt(0);
                    }

                }

                Console.WriteLine("Хотите обновить модель ? (y(yes) / n(no)");
                ch = Convert.ToChar(Console.ReadLine());
                if (ch == 'n') break;
            }


        }

        class ConstantProvider
        {
            public const int MAX_PEOPLE = 10;
            public const int MAX_DOCTORS = 7;
            public const int HUMAN_MAX_SPEED = 5;
            public const int DOC_MAX_SPEED = 3;
            public const int FIELD_SIZE = 40;
            public const int HEALING_DISTANCE = 10;
            public const int INFECTION_DISTANCE = 10;
        }
        [Serializable]
        class model
        {
            private int position;
            private int speed;
            public model(int speed, int position = 0)
            {
                this.position = position;
                this.speed = speed;
            }

            public int Speed
            {
                get
                {
                    return speed;
                }
                set
                {
                    speed = value;
                }
            }

            public int Position
            {
                get
                {
                    return position;
                }
                set
                {
                    position = value;
                }
            }

            public void AddPeople()
            { }

            public void DeletePeople()
            { }

            public void UpdatePosition(int period)
            {
                position = (position + speed * period) % ConstantProvider.FIELD_SIZE;
            }
        }
        [Serializable]
        class human : model
        {
            private bool infected;
            public human(int speed, int position = 0, bool infected = false)
                : base(speed, position)
            {
                this.infected = infected;
            }

            public bool Infected
            {
                get
                {
                    return infected;
                }
                set
                {
                    infected = value;
                }
            }

            public human Infect(human h, human h1)
            {
                if ((this.infected == true) && (Math.Abs(h1.Position - h.Position) <= ConstantProvider.INFECTION_DISTANCE))
                    h.Infected = true;
                return h;
            }
        }
        [Serializable]
        class doctor : model
        {
            public doctor(int speed, int position = 0)
                : base(speed, position) { }

            public human Heal(human h, doctor d)
            {
                if (Math.Abs(d.Position - h.Position) <= ConstantProvider.HEALING_DISTANCE)

                    h.Infected = false;
                return h;
            }
        }
    }
}
