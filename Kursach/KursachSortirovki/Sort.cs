using System;
using System.Collections.Generic;
using System.Text;

namespace KursachSortirovki
{
    class Sort
    {

        public int amount_elements;
        public int[] array_of_numbers = new int[10];

        public bool Checker(int[] array, int amount)
        {
            bool check = true;
            for (int i = 0; i < amount - 1; i++)
            {
                if (array[i] < array[i + 1])
                { }
                else check = false;

            }
            return check;
        }
        public int[] RandElements(int amount)
        {
            Random rnd = new Random();
            array_of_numbers[0] = rnd.Next(1, amount);
            for (int i = 0; i < amount;)
            {
                int num = rnd.Next(1, amount + 1); // генерируем элемент
                int j;
                // поиск совпадения среди заполненных элементов
                for (j = 0; j < i; j++)
                {
                    if (num == array_of_numbers[j])
                        break; // совпадение найдено, элемент не подходит
                }
                if (j == i)
                { // совпадение не найдено
                    array_of_numbers[i] = num; // сохраняем элемент
                    i++; // переходим к следующему элементу
                }
            }
            return (array_of_numbers);
        }

        protected static void Swap(ref int e1, ref int e2)
        {
            var temp = e1;
            e1 = e2;
            e2 = temp;
        }

    }

    class BubbleSort : Sort
    {

        public int[] BSort(int[] array)
        {
            var len = array.Length;
            for (var i = 1; i < len; i++)
            {
                for (var j = 0; j < len - i; j++)
                {
                    if (array[j] > array[j + 1])
                    {
                        Swap(ref array[j], ref array[j + 1]);
                        return array;
                    }
                }
            }
            return array;
        }
    }

    class ShakerSort : Sort
    {

        //сортировка перемешиванием
        public int[] ShSort(int[] array)
        {
            for (var i = 0; i < array.Length / 2; i++)
            {
                var swapFlag = false;
                //проход слева направо
                for (var j = i; j < array.Length - i - 1; j++)
                {
                    if (array[j] > array[j + 1])
                    {
                        Swap(ref array[j], ref array[j + 1]);
                        swapFlag = true;
                    }
                }

                //проход справа налево
                for (var j = array.Length - 2 - i; j > i; j--)
                {
                    if (array[j - 1] > array[j])
                    {
                        Swap(ref array[j - 1], ref array[j]);
                        swapFlag = true;
                    }
                }

                //если обменов не было выходим
                if (!swapFlag)
                {
                    break;
                }
                return array;
            }

            return array;
        }

    }

    class InsertionSort : Sort
    {

        //сортировка вставками
        public int[] InsSort(int[] array) //здесь не меняется первый элемент
        {
            for (var i = 1; i < array.Length; i++)
            {
                var key = array[i];
                var j = i;
                while ((j > 0) && (array[j - 1] > key))
                {
                    Swap(ref array[j - 1], ref array[j]);
                    j--;
                    return array;
                }

                array[j] = key;
            }

            return array;
        }
    }
}
