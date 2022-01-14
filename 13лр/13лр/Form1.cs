using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _13лр
{

    public partial class Form1 : Form
    {
        int sickPeopleAmount = 0;
        int peopleAmount = 0;
        List<human> people = new List<human>();
        int docAmount = 0;
        List<doctor> doctors = new List<doctor>();
        Dictionary<int, char> modell = new Dictionary<int, char>();

        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int pos;
            model peopl;
            model doct;
            for (int i = 0; i < peopleAmount; i++)
            {
                peopl = people[i];
                peopl.UpdatePosition(1);
            }
            for (int i = 0; i < docAmount; i++)
            {
                doct = doctors[i];
                doct.UpdatePosition(1);
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
            string mod = "";
            for (int i = 0; i < ConstantProvider.FIELD_SIZE; i++)
            {
                // Если кто-то стоит (кого-то нашли на карте), то выводим его букву, иначе "_"
                if (modell.ContainsKey(i))
                   mod += modell[i];
                else mod += "_";
            }
            model.Text = "";
            model.Text = mod;
        }

        private void button5_Click(object sender, EventArgs e)
        {
            sickPeopleAmount = (int)peopleS.Value;
            peopleAmount = (int)peopleH.Value + (int)peopleS.Value;
            docAmount = (int)doc.Value;

            // Создаем здоровых агентов случайным способом
            Random rnd = new Random();
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

            for (int i = 0; i < docAmount; i++)
            {
                doctor d = new doctor(rnd.Next() % ConstantProvider.DOC_MAX_SPEED + 1, rnd.Next() % ConstantProvider.FIELD_SIZE);
                doctors.Add(d);
            }
        }

        private void add_peopleS_Click(object sender, EventArgs e)
        {
            sickPeopleAmount += 1;

            Random rnd = new Random();
            for (int i = 0; i < sickPeopleAmount; i++)
            {
                human h = new human(rnd.Next() % ConstantProvider.HUMAN_MAX_SPEED + 1, rnd.Next() % ConstantProvider.FIELD_SIZE, true);
                people.Add(h);
            }
        }

        private void add_peopleH_Click(object sender, EventArgs e)
        {
            peopleAmount += 1;

            Random rnd = new Random();
            for (int i = 0; i < (peopleAmount); i++)
            {
                human h = new human(rnd.Next() % ConstantProvider.HUMAN_MAX_SPEED + 1, rnd.Next() % ConstantProvider.FIELD_SIZE, false);
                people.Add(h);
            }
        }

        private void add_doc_Click(object sender, EventArgs e)
        {
            docAmount += 1;

            Random rnd = new Random();
            for (int i = 0; i < docAmount; i++)
            {
                doctor d = new doctor(rnd.Next() % ConstantProvider.DOC_MAX_SPEED + 1, rnd.Next() % ConstantProvider.FIELD_SIZE);
                doctors.Add(d);
            }
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
