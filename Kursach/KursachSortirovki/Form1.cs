using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;
using System.Windows.Forms;

namespace KursachSortirovki
{
    public partial class Form1 : Form
    {
        Sort sort = new Sort();
        BubbleSort bubble = new BubbleSort();
        ShakerSort shaker = new ShakerSort();
        InsertionSort insertionSort = new InsertionSort();
        public int[] array_animation = new int[10];
        public Form1()
        {
            InitializeComponent();
        }
        private bool empty(TextBox box)
        {
            if (box.Text == "")
                return true;
            else
                return false;
        }
        private void button2_Click(object sender, EventArgs e)
        {
            var panels = new[] { panel1, panel2, panel3, panel4, panel5, panel6, panel7, panel8, panel9, panel10, };
            var locations = new[] {50, 106, 162, 218, 274, 330, 386, 442, 498, 554 };
            int amount_elements = 10;
            for (int i = 0; i < amount_elements; i++)
            {
                panels[i].Height = 100;
            }
            sort.amount_elements = amount_elements;
            sort.array_of_numbers = sort.RandElements(amount_elements);
            array_animation = sort.array_of_numbers;
            for (int i = 0; i < amount_elements; i++)
            {
                panels[i].Height = panels[i].Height + (array_animation[i] * 10);
            }

    
        }

        private void button1_Click(object sender, EventArgs e)
        {
            var panels = new[] { panel1, panel2, panel3, panel4, panel5, panel6, panel7, panel8, panel9, panel10, };
            bool checker;
            while (true)
            {
                sort.array_of_numbers = bubble.BSort(sort.array_of_numbers);
                checker = sort.Checker(sort.array_of_numbers, sort.amount_elements);
                array_animation = sort.array_of_numbers;
                
                for (int i = 0; i < sort.amount_elements; i++)
                {
                    panels[i].BackColor = Color.Red;
                    Thread.Sleep(20);
                    panels[i].Height = 100 + (array_animation[i] * 10);
                    panels[i].BackColor = Color.Blue;
                    Thread.Sleep(20);
                }
                if (checker == true)
                {
                    array_animation = sort.array_of_numbers;
                    break;
            
                }

            }
   
        }
        private void button3_Click(object sender, EventArgs e)
        {
            var panels = new[] { panel1, panel2, panel3, panel4, panel5, panel6, panel7, panel8, panel9, panel10, };
            bool checker;
            while (true)
            {
                sort.array_of_numbers = shaker.ShSort(sort.array_of_numbers);
                checker = sort.Checker(sort.array_of_numbers, sort.amount_elements);
                array_animation = sort.array_of_numbers;

                for (int i = 0; i < sort.amount_elements; i++)
                {
                    panels[i].BackColor = Color.Red;
                    Thread.Sleep(20);
                    panels[i].Height = 100 + (array_animation[i] * 10);
                    panels[i].BackColor = Color.Blue;
                    Thread.Sleep(20);
                }
                if (checker == true)
                {
                    array_animation = sort.array_of_numbers;
                    break;

                }

            }
        }
        private void button4_Click(object sender, EventArgs e)
        {
            var panels = new[] { panel1, panel2, panel3, panel4, panel5, panel6, panel7, panel8, panel9, panel10, };
            bool checker;
            while (true)
            {
                sort.array_of_numbers = insertionSort.InsSort(sort.array_of_numbers);
                checker = sort.Checker(sort.array_of_numbers, sort.amount_elements);
                array_animation = sort.array_of_numbers;

                for (int i = 0; i < sort.amount_elements; i++)
                {
                    panels[i].BackColor = Color.Red;
                    Thread.Sleep(20);
                    panels[i].Height = 100 + (array_animation[i] * 10);
                    panels[i].BackColor = Color.Blue;
                    Thread.Sleep(20);
                }
                if (checker == true)
                {
                    array_animation = sort.array_of_numbers;
                    break;

                }

            }
        }



    }
}
